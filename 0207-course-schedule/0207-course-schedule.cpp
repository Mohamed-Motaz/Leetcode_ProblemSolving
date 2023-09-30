class Solution {
public:
    bool bfs_kahn_algo(int numCourses, vector<vector<int>>& prerequisites){
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
        
        return res.size() == numCourses ? 1 : 0;
    }
    
    bool dfs(int cur, vector<vector<int>>& adjList, vector<bool> &vis, vector<bool>& curStack){
        if (curStack[cur] == 1) return 0; //found a cycle
        if (vis[cur] == 1) return 1; //visited before, but not in cur stack
        vis[cur] = 1;
        curStack[cur] = 1;
        for (int child: adjList[cur]){
            if (!dfs(child, adjList, vis, curStack)) return 0;
        }
        
        curStack[cur] = 0;
        return 1;
    }
    
    bool dfs_sol(int numCourses, vector<vector<int>>& prerequisites){
        //try to search for a cycle
        vector<vector<int>> adjList(numCourses, vector<int>());
        for (vector<int> &v: prerequisites){
            adjList[v[1]].push_back(v[0]);
        }
        
        vector<bool> vis(numCourses);
        vector<bool> curStack(numCourses);
        
        for (int i = 0; i < numCourses; i++){
            if (!dfs(i, adjList, vis, curStack)) return 0;
        }
        return 1;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // return bfs_kahn_algo(numCourses, prerequisites);
        return dfs_sol(numCourses, prerequisites);
    }
};