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
    
    void dfs(int node, vector<int>& res, vector<int>& inDegree, vector<vector<int>> &adjList){
        res.push_back(node);
        inDegree[node] = -1;
        for (int i: adjList[node]){
            if (!(--inDegree[i]))
                dfs(i, res, inDegree, adjList);
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
                dfs(i, res, inDegree, adjList);
        }
        return res.size() == numCourses ? res : vector<int>();
    }
    

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //return bfs_kahn_algo(numCourses, prerequisites);
        return dfs_top_sort(numCourses, prerequisites);
    }
};