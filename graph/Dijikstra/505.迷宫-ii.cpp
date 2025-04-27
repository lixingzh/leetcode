struct State {
    vector<int> point;
    int dist;
};
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<vector<int>> dist(maze.size(), vector<int>(maze[0].size(), INT_MAX));
        dist[start[0]][start[1]] = 0;
        auto comparator = [&] (State &a, State& b) {
            return a.dist > b.dist;
        };
        State st(start, 0);

        priority_queue<State, vector<State>, decltype(comparator)> pq(comparator);
        pq.push(st);

        auto findNext = [&] (State &st) -> vector<State> {
            vector<State> rst;
            vector<int> dx{1,0,-1,0};
            vector<int> dy{0,1,0,-1};

            int idx = 0;
            for(int i = 0; i < dx.size(); ++i) {
                vector<int> point = st.point;
                int dist = 0;
                bool isNeighbor = false;
                while(point[0]+dy[i] >= 0 && point[0]+dy[i] < maze.size() && point[1] + dx[i] >= 0 && point[1] + dx[i] < maze[0].size() && maze[point[0]+dy[i]][point[1]+dx[i]] == 0) {
                    point[0] += dy[i];
                    point[1] += dx[i]; 
                    ++dist;
                    isNeighbor = true;
                }
                if(isNeighbor) 
                    rst.emplace_back(point, dist);
            }
            return rst;
        };

        while(!pq.empty()) {
            State curState(pq.top());
            pq.pop();

            vector<int> point(curState.point);
            int curDist = curState.dist;

            if (curDist > dist[point[0]][point[1]]) {
                // 已经有一条更短的路径到达 curNode 节点了
                continue;
            }            
            vector<State> neighbors = findNext(curState);
            for(State & st: neighbors) {
                const vector<int> & nextPoint = st.point;
                int &nextDist = dist[nextPoint[0]][nextPoint[1]];
                if(curDist + st.dist > nextDist) {
                    continue;
                }

                nextDist = curDist + st.dist;
                pq.emplace(nextPoint, nextDist);
            }
        }

        return dist[destination[0]][destination[1]] == INT_MAX ? -1 : dist[destination[0]][destination[1]];
    }
};