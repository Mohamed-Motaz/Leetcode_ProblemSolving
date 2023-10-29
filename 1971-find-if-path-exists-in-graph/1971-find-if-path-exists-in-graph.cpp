class Solution {
public:
    
    vector<bool> vis;
    vector<vector<int>> adjList;
    bool dfs(int cur, int par, vector<vector<int>>& adjList,  int destination) {
        if (cur == destination) return 1;
        if (vis[cur]) return 0;
        vis[cur] = 1;
        for (int child: adjList[cur]){
            if (child == par)
                continue;
            if (dfs(child, cur, adjList, destination))
                return 1;
        }
        return 0;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vis.resize(n);
        adjList.resize(n, vector<int>());
        for (auto &i: edges) adjList[i[0]].push_back(i[1]), adjList[i[1]].push_back(i[0]);
        return dfs(source, -1, adjList, destination);
    }
};