#!/usr/bin/env bash
# usage : _viz/run.sh path/to/solution.cpp [input.txt]
#   - input defaults to in.txt next to the .cpp (otherwise reads from the terminal)
#   - scene defaults to viz_scene.js next to the .cpp (otherwise only VIZ_SNAP panels are shown)
#   - result : <problem>/output/viz/index.html   (set VIZ_NO_OPEN=1 to skip opening the browser)
set -euo pipefail

VIZ_DIR="$(cd "$(dirname "$0")" && pwd)"
SRC="${1:?usage: _viz/run.sh path/to/solution.cpp [input.txt]}"
DIR="$(cd "$(dirname "$SRC")" && pwd)"
NAME="$(basename "$SRC" .cpp)"
IN="${2:-}"
[[ -z "$IN" && -f "$DIR/in.txt" ]] && IN="$DIR/in.txt"

OUT="$DIR/output/viz"
mkdir -p "$OUT"

clang++ -std=c++17 -O1 -DVIZ_ON -include "$VIZ_DIR/viz.h" "$SRC" -o "$OUT/$NAME"

if [[ -n "$IN" ]]; then
  "$OUT/$NAME" < "$IN" > "$OUT/stdout.txt" 2> "$OUT/stderr.txt"
else
  echo "(type the input, then Ctrl-D)"
  "$OUT/$NAME" > "$OUT/stdout.txt" 2> "$OUT/stderr.txt"
fi

{
  echo "window.VIZ_TRACE = ["
  grep '^{"type":' "$OUT/stderr.txt" | sed 's/$/,/' || true
  echo "];"
  printf 'window.VIZ_STDOUT = `'
  sed -e 's/\\/\\\\/g' -e 's/`/\\`/g' -e 's/\$/\\$/g' "$OUT/stdout.txt"
  echo '`;'
} > "$OUT/trace.js"

cp "$VIZ_DIR/viewer.html" "$OUT/index.html"
if [[ -f "$DIR/viz_scene.js" ]]; then cp "$DIR/viz_scene.js" "$OUT/scene.js"; else rm -f "$OUT/scene.js"; fi

echo "events : $(grep -c '^{"type":' "$OUT/stderr.txt" || true)"
echo "viewer : $OUT/index.html"
[[ -z "${VIZ_NO_OPEN:-}" ]] && open "$OUT/index.html"
exit 0
