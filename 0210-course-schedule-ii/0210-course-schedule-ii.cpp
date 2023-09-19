class Solution {
public:
    vector<vector<int>> adjList;
    queue<int> sources;
    vector<int> inDegrees;
    
    
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        adjList.resize(numCourses, vector<int>());
        inDegrees.resize(numCourses, 0);
        
        for (vector<int> &v: prerequisites){
            adjList[v[1]].push_back(v[0]);
            inDegrees[v[0]]++;
        }    
        
        for (int i = 0; i < numCourses; i++){
            if (!inDegrees[i]) sources.push(i);
        }
        if (sources.empty()) return {};
        
        
        vector<int> sol;
        while (sources.size()){
            int cur = sources.front();
            sources.pop();

            sol.push_back(cur);

            for (int child: adjList[cur]){
                inDegrees[child]--;
                if (!inDegrees[child])
                    sources.push(child);
            }
        }
        return sol.size() < numCourses ? vector<int>() : sol;
    }
};