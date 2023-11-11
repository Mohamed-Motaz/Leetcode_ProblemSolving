class Solution {
public:
    vector<vector<pair<int, int>>> adjList; //node, cost
    vector<int> dist;
    vector<int> prev;
    
    void dijkestra(int source){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //cost, node
        
        dist[source] = 0;
        pq.push({0, source});
        
        while (pq.size()){
            int node = pq.top().second;
            int cost = pq.top().first;
            pq.pop();
            
            //ignore if already visited
            if (dist[node] < cost) continue;
            
            for (auto child: adjList[node]){

                int newCost = child.second + cost;
                if (dist[child.first] <= newCost) continue;
                dist[child.first] = newCost;
                pq.push({newCost, child.first});
                prev[child.first] = source;
            }
        }
        
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        dist.resize(n + 1, 1e9);
        prev.resize(n + 1, -1);
        
        adjList.resize(n + 1, vector<pair<int, int>>());
        for (auto &v: times){
            adjList[v[0]].push_back({v[1], v[2]});
        }
        
        dijkestra(k);
        
        // for (int i = 1; i <= n; i++) cout << prev[i] << " ";
        // cout << endl;
        
        int mx = 0;
        for (int i = 1; i <= n; i++)
            mx = max(mx, dist[i]);
        
        return (mx == 1e9) ? -1 : mx;
    }
};