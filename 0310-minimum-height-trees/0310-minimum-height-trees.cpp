class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        vector<int> inDegree(n, 0);
        for (vector<int> &v: edges){
            adjList[v[0]].push_back(v[1]);
            adjList[v[1]].push_back(v[0]);
            inDegree[v[0]]++;
            inDegree[v[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++){
            if (inDegree[i] == 1) q.push(i), inDegree[i]--;
        }
        
        //go around removing leaves level by level, and meet in the middle
        vector<int> ans;
        while (q.size()){
            ans.clear();
            int sz = q.size();
            for (int i = 0; i < sz; i++){
                int cur = q.front();
                ans.push_back(cur);
                q.pop();
                for (int child: adjList[cur]){
                    --inDegree[child];
                    if (inDegree[child] == 1) q.push(child);
                }
            }
        }
        if (n == 1) ans.push_back(0);
        return ans;
    }
};