# 用处
处理多源

# Floyd-Warshall算法
```
let V = number of vertices in graph
let dist = V × V array of minimum distances
for each vertex v
    dist [v][v] + 0

for each edge (u,v)
    dist [u][v] + weight(u,v)

for k from 1 to V
    for i from 1 to V
        for j from 1 to V
            if dist [i][j] > dist [i][k] + dist[k][j]
                dist [i][j] + dist [i][k] + dist[k][l]
end if
```