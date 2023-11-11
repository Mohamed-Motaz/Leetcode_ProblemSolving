class Solution {
public:
    int rows, cols;
    vector<vector<int>> dist;
    
    
    bool ok(int x, int y){
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }
    
    //up down left right
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int dijkestra(vector<vector<int>>& heights){
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        pq.push({0, {0, 0}});
        while (pq.size()){
            auto node = pq.top();
            pq.pop();
            if (node.first > dist[node.second.first][node.second.second])
                continue;
            
            for (int i = 0; i < 4; i++){
                int newX = dx[i] + node.second.first;
                int newY = dy[i] + node.second.second;
                if (!ok(newX, newY))
                    continue;
                int newCost = max(node.first, abs(heights[newX][newY] - heights[node.second.first][node.second.second]));
                if (newCost < dist[newX][newY]){
                    dist[newX][newY] = newCost;
                    pq.push({newCost, {newX, newY}});
                }
            }
            
        }
        
        
        return dist[rows - 1][cols - 1] == INT32_MAX ? 0 :dist[rows - 1][cols - 1] ;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        
        dist.resize(rows, vector<int>(cols, INT32_MAX));
        
        return dijkestra(heights);
    }
};