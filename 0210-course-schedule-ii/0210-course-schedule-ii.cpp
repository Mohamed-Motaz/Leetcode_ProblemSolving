class Solution {
public:

    vector<int> bfs_kahn_algo(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>> adjList(numCourses, vector<int>());
        vector<int> inDegree(numCourses);
        for (vector<int> &v: prerequisites){
            adjList[v[1]].push_back(v[0]);
            inDegree[v[0]]++;
        }
        
        queue<int> q;
        vector<int> res;
        for (int i = 0; i < numCourses; i++){
            if (!inDegree[i]) q.push(i);
        }
        
        while (q.size()){
            int cur = q.front();
            q.pop();
            res.push_back(cur);
            for (int i: adjList[cur]){
                inDegree[i]--;
                if (!inDegree[i]) q.push(i);
            }
        }
        
        return res.size() == numCourses ? res : vector<int>();
    }
    
    void dfs_topo(int node, vector<int>& res, vector<int>& inDegree, vector<vector<int>> &adjList){
        res.push_back(node);
        inDegree[node] = -1;
        for (int i: adjList[node]){
            if (!(--inDegree[i]))
                dfs_topo(i, res, inDegree, adjList);
        }
        return;
    }
    
    vector<int> dfs_top_sort(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>> adjList(numCourses, vector<int>());
        vector<int> inDegree(numCourses);
        for (vector<int> &v: prerequisites){
            adjList[v[1]].push_back(v[0]);
            inDegree[v[0]]++;
        }
        
        vector<int> res;
        for (int i = 0; i < numCourses; i++){
            if (!inDegree[i])
                dfs_topo(i, res, inDegree, adjList);
        }
        return res.size() == numCourses ? res : vector<int>();
    }
    
    bool dfs(int cur, vector<vector<int>>& adjList, vector<bool> &vis, vector<bool>& curStack,
            vector<int>& result){
        if (curStack[cur] == 1) return 0; //found a cycle
        if (vis[cur] == 1) return 1; //visited before, but not in cur stack
        vis[cur] = 1;
        curStack[cur] = 1;
        for (int child: adjList[cur]){
            if (!dfs(child, adjList, vis, curStack, result)) return 0;
        }
        
        curStack[cur] = 0;
        result.push_back(cur);
        return 1;
    }
    
    vector<int> dfs_sol(int numCourses, vector<vector<int>>& prerequisites){
        //try to search for a cycle
        vector<vector<int>> adjList(numCourses, vector<int>());
        for (vector<int> &v: prerequisites){
            adjList[v[1]].push_back(v[0]);
        }
        
        vector<bool> vis(numCourses);
        vector<bool> curStack(numCourses);
        vector<int> result;
        
        for (int i = 0; i < numCourses; i++){
            if (!dfs(i, adjList, vis, curStack, result)) return {};
        }
        reverse(result.begin(), result.end());
        return result;
    }
    

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //return bfs_kahn_algo(numCourses, prerequisites);
        //return dfs_top_sort(numCourses, prerequisites);
        return dfs_sol(numCourses, prerequisites);
    }
};