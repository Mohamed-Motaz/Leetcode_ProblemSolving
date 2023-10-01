class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        unordered_map<int, vector<int>> qIndexes(queries.size());
        for (int i = 0; i < queries.size(); i++) qIndexes[queries[i]].push_back(i);
        
        sort(queries.begin(), queries.end());
        sort(intervals.begin(), intervals.end());
        
        vector<int> res(queries.size());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; //sz, end
        
        int idx = 0;
        for (int q: queries){
            while (idx < intervals.size() && q >= intervals[idx][0]){
                pq.push({intervals[idx][1] - intervals[idx][0] + 1,
                        intervals[idx][1]});
                idx++;
            }
            while (pq.size() && pq.top().second < q){
                pq.pop();
            }
            
            int idx = qIndexes[q].back();
            qIndexes[q].pop_back();
            res[idx] = pq.size() ? pq.top().first : -1;
        }
        
        return res;
    }
};