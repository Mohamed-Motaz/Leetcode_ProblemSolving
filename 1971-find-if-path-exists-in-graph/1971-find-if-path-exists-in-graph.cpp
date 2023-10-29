class Solution {
public:
    
    vector<bool> vis;
    vector<vector<int>> adjList;
    bool dfs(int cur, vector<vector<int>>& adjList,  int destination) {
        if (cur == destination) return 1;
        if (vis[cur]) return 0;
        vis[cur] = 1;
        for (int child: adjList[cur]){
            if (dfs(child, adjList, destination))
                return 1;
        }
        return 0;
    }
    
    bool bfs(int cur, vector<vector<int>>& adjList, int destination){
        queue<int> q;
        q.push(cur);
        
        while (q.size()){
            int node = q.front(); q.pop();
            if (node == destination)
                return 1;
            if (vis[node]) continue;
            vis[node] = 1;
            for (int child: adjList[node]){
                q.push(child);
            }
        }
        return 0;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vis.resize(n);
        adjList.resize(n, vector<int>());
        for (auto &i: edges) adjList[i[0]].push_back(i[1]), adjList[i[1]].push_back(i[0]);
        //return dfs(source, adjList, destination);
        return bfs(source, adjList, destination);
    }
};