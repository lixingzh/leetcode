#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

// 加权有向图的通用实现（邻接表）
class WeightedDigraph {
public:
    // 存储相邻节点及边的权重
    struct Edge {
        int to;
        int weight;

        Edge(int to, int weight) {
            this->to = to;
            this->weight = weight;
        }
    };

private:
    // 邻接表，graph[v] 存储节点 v 的所有邻居节点及对应权重
    vector<vector<Edge>> graph;

public:
    WeightedDigraph(int n) {
        // 我们这里简单起见，建图时要传入节点总数，这其实可以优化
        // 比如把 graph 设置为 Map<Integer, List<Edge>>，就可以动态添加新节点了
        graph = vector<vector<Edge>>(n);
    }

    // 增，添加一条带权重的有向边，复杂度 O(1)
    void addEdge(int from, int to, int weight) {
        graph[from].emplace_back(to, weight);
    }

    // 删，删除一条有向边，复杂度 O(V)
    void removeEdge(int from, int to) {
        for (auto it = graph[from].begin(); it != graph[from].end(); ++it) {
            if (it->to == to) {
                graph[from].erase(it);
                break;
            }
        }
    }

    // 查，判断两个节点是否相邻，复杂度 O(V)
    bool hasEdge(int from, int to) {
        for (const auto& e : graph[from]) {
            if (e.to == to) {
                return true;
            }
        }
        return false;
    }

    // 查，返回一条边的权重，复杂度 O(V)
    int weight(int from, int to) {
        for (const auto& e : graph[from]) {
            if (e.to == to) {
                return e.weight;
            }
        }
        throw invalid_argument("No such edge");
    }

    // 查，返回某个节点的所有邻居节点，复杂度 O(1)
    const vector<Edge>& neighbors(int v) {
        return graph[v];
    }
};

class State {
public:
    // 图节点的 id
    int id;
    // 从 start 节点到当前节点的距离
    int distFromStart;

public:
    State(int id, int distFromStart) {
        this->id = id;
        this->distFromStart = distFromStart;
    }
};

vector<int> dijkstra(int start, WeightedDigraph graph) {
    // 图中节点的个数
    int V = graph.size();
    // 记录最短路径的权重，你可以理解为 dp table
    // 定义：distTo[i] 的值就是节点 start 到达节点 i 的最短路径权重
    int distTo[V];
    // 求最小值，所以 dp table 初始化为正无穷
    memset(distTo, INT_MAX, sizeof(distTo));
    // base case，start 到 start 的最短距离就是 0
    distTo[start] = 0;

    auto comparator = [](State& a, State& b) {
        return a.distFromStart > b.distFromStart;
    };

    // 优先级队列，distFromStart 较小的排在前面
    priority_queue<State, vector<State>, decltype(&comparator)> pq(&comparator);

    // 从起点 start 开始进行 BFS
    pq.push(State(start, 0));

    while (!pq.empty()) {
        State curState = pq.top();
        pq.pop();

        int curNodeID = curState.id;
        int curDistFromStart = curState.distFromStart;

        if (curDistFromStart > distTo[curNodeID]) {
            // 已经有一条更短的路径到达 curNode 节点了
            continue;
        }
        // 将 curNode 的相邻节点装入队列
        for (auto & edge: graph.neighbors(curNodeID)) {
            int nextNodeID = edge.to;
            // 看看从 curNode 达到 nextNode 的距离是否会更短
            int distToNextNode = distTo[curNodeID] + graph.weight(curNodeID, nextNodeID);
            if (distTo[nextNodeID] > distToNextNode) {
                // 更新 dp table
                distTo[nextNodeID] = distToNextNode;
                // 将这个节点以及距离放入队列
                pq.push(State(nextNodeID, distToNextNode));
            }
        }
    }
    vector<int> result;
    for (int i = 0; i < V; i++) {
        result.push_back(distTo[i]);
    }
    return result;
}