class Solution {
public:
    
   
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        // vector<vector<pair<int, int>>> adjList(n + 1);
        // for (int i = 0; i < flights.size(); i++)
        // {
        //     adjList[flights[i][0]].push_back(make_pair(flights[i][1], flights[i][2]));
        // }
               
        vector<int> dist(n, INT32_MAX);
        dist[src] = 0;
        for (int x = 0; x < k + 1; x++){
            vector<int> copy = dist;
            for (int i = 0; i < flights.size(); i++){
                    int src = flights[i][0];
                    int dst = flights[i][1];
                    int cost = flights[i][2];
                
                    
                    if (dist[src] == INT32_MAX)
                        continue;
                    
                    copy[dst] = min(copy[dst], dist[src] + cost);
                    
            }
            dist = copy;
        }
        
        return dist[dst] == INT32_MAX ? -1 : dist[dst];
        
    }
};