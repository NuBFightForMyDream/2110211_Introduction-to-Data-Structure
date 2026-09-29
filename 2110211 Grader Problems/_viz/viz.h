// viz.h : trace hooks for the visualizer
// Force-included by _viz/run.sh (clang++ -DVIZ_ON -include viz.h). Never included when submitting to grader.
//
//   VIZ("seat", "customer", c, "chair", j)   -> one step in the viewer (key, value pairs)
//   VIZ("setup", "chefs", t, "customers", m) -> type "setup" is passed to scene.init() instead of being a step
//   VIZ_SNAP("pq", pq)                       -> show the real stack / queue / priority_queue under the scene
//
// Every event is one JSON line on stderr, so stdout (the grader answer) is untouched.
#pragma once
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

namespace viz {

constexpr long long LIMIT = 5000; // stop tracing after this many events (keeps big inputs usable)

inline long long &count() { static long long n = 0; return n; }

// read the protected container `c` of std adaptors without copying / popping
template <class A> struct Peek : A {
  static const typename A::container_type &get(const A &a) { return a.*(&Peek::c); }
};

// ---- JSON writers (declare all first so the templates can find each other) ----
inline void put(std::ostream &o, const std::string &s);
inline void put(std::ostream &o, const char *s);
inline void put(std::ostream &o, char ch);
inline void put(std::ostream &o, bool b);
template <class T> std::enable_if_t<std::is_arithmetic_v<T>> put(std::ostream &o, T v);
template <class A, class B> void put(std::ostream &o, const std::pair<A, B> &p);
template <class T, class Al> void put(std::ostream &o, const std::vector<T, Al> &v);
template <class T, class C> void put(std::ostream &o, const std::stack<T, C> &s);
template <class T, class C> void put(std::ostream &o, const std::queue<T, C> &q);
template <class T, class C, class Cmp> void put(std::ostream &o, const std::priority_queue<T, C, Cmp> &q);
template <class Range> void put_range(std::ostream &o, const Range &r);

inline void put(std::ostream &o, const std::string &s) {
  o << '"';
  for (char ch : s) {
    if (ch == '\n') { o << "\\n"; continue; }
    if (ch == '"' || ch == '\\') o << '\\';
    o << ch;
  }
  o << '"';
}
inline void put(std::ostream &o, const char *s) { put(o, std::string(s)); }
inline void put(std::ostream &o, char ch) { put(o, std::string(1, ch)); }
inline void put(std::ostream &o, bool b) { o << (b ? "true" : "false"); }
template <class T> std::enable_if_t<std::is_arithmetic_v<T>> put(std::ostream &o, T v) { o << +v; }
template <class A, class B> void put(std::ostream &o, const std::pair<A, B> &p) {
  o << '['; put(o, p.first); o << ','; put(o, p.second); o << ']';
}
template <class Range> void put_range(std::ostream &o, const Range &r) {
  o << '[';
  bool first = true;
  for (const auto &x : r) { if (!first) o << ','; put(o, x); first = false; }
  o << ']';
}
template <class T, class Al> void put(std::ostream &o, const std::vector<T, Al> &v) { put_range(o, v); }
// stack : bottom -> top , queue : front -> back , priority_queue : heap array (index 0 = top)
template <class T, class C> void put(std::ostream &o, const std::stack<T, C> &s) { put_range(o, Peek<std::stack<T, C>>::get(s)); }
template <class T, class C> void put(std::ostream &o, const std::queue<T, C> &q) { put_range(o, Peek<std::queue<T, C>>::get(q)); }
template <class T, class C, class Cmp> void put(std::ostream &o, const std::priority_queue<T, C, Cmp> &q) {
  put_range(o, Peek<std::priority_queue<T, C, Cmp>>::get(q));
}

template <class T, class C> const char *kind(const std::stack<T, C> &) { return "stack"; }
template <class T, class C> const char *kind(const std::queue<T, C> &) { return "queue"; }
template <class T, class C, class Cmp> const char *kind(const std::priority_queue<T, C, Cmp> &) { return "pq"; }

inline void kv(std::ostream &) {}
template <class V, class... R> void kv(std::ostream &o, const char *key, const V &v, const R &...rest) {
  o << ','; put(o, key); o << ':'; put(o, v);
  kv(o, rest...);
}

template <class... A> void emit(const char *type, const A &...args) {
  static_assert(sizeof...(A) % 2 == 0, "VIZ: pass \"key\", value pairs after the event type");
  if (++count() > LIMIT) {
    if (count() == LIMIT + 1) std::cerr << "{\"type\":\"truncated\"}\n";
    return;
  }
  std::cerr << "{\"type\":"; put(std::cerr, type);
  kv(std::cerr, args...);
  std::cerr << "}\n";
}

} // namespace viz

#define VIZ(...) ::viz::emit(__VA_ARGS__)
#define VIZ_SNAP(name, ds) ::viz::emit("snap", "name", name, "kind", ::viz::kind(ds), "data", ds)
