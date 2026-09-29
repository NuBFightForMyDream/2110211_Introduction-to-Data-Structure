# _viz

Step-by-step visualizer driven by your own solution code.

```bash
_viz/run.sh "Part 04 .../2.0 Restaurant ex00m1/ex00m1_restaurant_2.0.cpp"   # uses in.txt next to the .cpp
```

## Add a new problem

1. In the `.cpp`, add the no-op fallback (so the grader build still works):
   ```cpp
   #ifndef VIZ_ON
   #define VIZ(...)
   #define VIZ_SNAP(...)
   #endif
   ```
2. Add hooks where something meaningful happens:
   - `VIZ("setup", "key", value, ...)` : once, passed to `scene.init()`
   - `VIZ("any_name", "key", value, ...)` : one step in the viewer
   - `VIZ_SNAP("name", ds)` : shows the real `stack` / `queue` / `priority_queue` below the scene
   Values can be numbers, strings, `pair`, `vector`, and the three STL adaptors.
3. (Optional) Add `viz_scene.js` next to the `.cpp` to draw the problem's own picture:
   ```js
   window.VIZ_SCENE = {
     css: `...`,                        // extra styles; tokens: --chip --hl --hl-fg --line --muted ...
     title(setup)          { return '...'; },
     init(setup)           { return { /* state */ }; },
     apply(state, ev)      { /* mutate state for one step event */ },
     caption(ev, state)    { return 'html'; },   // ev is null at step 0
     render(state, root, ev) { root.innerHTML = '...'; },
   };
   ```
   Without a scene, the viewer still shows every step's event and all `VIZ_SNAP` panels.
