# Bellman-ford
计算带权有向 单源最短路径

``` java
//T(n) = O(E * K), where E is the length of flights.
final int MAX = 100000000;
public int bellmanFord(int n, int[]l] flights, int src, int dst, int K) {
    int[] cost = new int[n];
    Arrays. fill(cost, MAX);
    cost [src] = 0;
    int res = MAX;
    for (int i = 0; i <= n - 1; i++) {
        int[] cur = Arrays.copyOf(cost, n);
        for (int[] flight: flights) {
            cur[flight[1]] = Math.min(cur [flight[1]], cost[flight[0]] + flight[2]);
        }
        res = Math.min(res, cur[dst]);
        cost = cur;
    }
    return res == MAX? -1 : res;
}
```