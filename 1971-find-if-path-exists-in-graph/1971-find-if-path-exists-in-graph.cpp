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
    
    vector<int> parents;
    vector<int> sz;
    
    void initUnionFind(int n){
        parents.resize(n);
        sz.resize(n);
        
        for (int i = 0; i < n;i++){
            parents[i] = i;
            sz[i] = 1;
        }
    }
    
    int find(int p){
        int root = p;
        while (parents[root] != root){
            root = parents[root];
        }
        
        //path compression
        while (p != parents[p]){
            int next = parents[p];
            parents[p] = root;
            p = next;
        }
        return root;
    }
    void unionify(int p, int q){
        
        int pp = find(p);
        int qq = find(q);
        if (pp == qq) return;
        
        if (sz[pp] > sz[qq]){
            sz[pp] += sz[qq];
            parents[qq] = pp;
        }else{
            sz[qq] += sz[pp];
            parents[pp] = qq;
        }
        
    }
    bool connected(int p, int q){
        return find(p) == find(q);
    }
    
    bool solveUnionFind(int n, vector<vector<int>>& adjList, int source, int destination){
        initUnionFind(n);
        for (int i = 0; i < adjList.size(); i++){
            for (int child: adjList[i]){
                unionify(i, child);
            }
        }
        return connected(source, destination);
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // vis.resize(n);
        // adjList.resize(n, vector<int>());
        // for (auto &i: edges) adjList[i[0]].push_back(i[1]), adjList[i[1]].push_back(i[0]);
        // //return dfs(source, adjList, destination);
        // return bfs(source, adjList, destination);
        
        adjList.resize(n, vector<int>());
        for (auto &i: edges) adjList[i[0]].push_back(i[1]), adjList[i[1]].push_back(i[0]);
        return solveUnionFind(n, adjList, source, destination);
    }
};