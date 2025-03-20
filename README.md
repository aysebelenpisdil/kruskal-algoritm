# kruskal-algoritm Pseudo Code

```
KRUSKAL(G, w)
 A = ∅
 for each vertex v in G.V
  MAKE-SET(v)
 sort G.E by weight w (nondecreasing order)
 for each (u, v) in G.E (in sorted order)
  if FIND-SET(u) ≠ FIND-SET(v)
   A = A ∪ {(u, v)}
   UNION(u, v)
 return A

```

