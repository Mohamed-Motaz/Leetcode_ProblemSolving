class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<pair<int, int>> qIndexes;
        for (int i = 0; i < queries.size(); i++) qIndexes.push_back(make_pair(queries[i], i));
        
        sort(qIndexes.begin(), qIndexes.end());
        sort(intervals.begin(), intervals.end());
        
        vector<int> res(queries.size());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; //sz, end
        
        int idx = 0;
        for (auto &[q, resIdx]: qIndexes){
            while (idx < intervals.size() && q >= intervals[idx][0]){
                pq.push({intervals[idx][1] - intervals[idx][0] + 1,
                        intervals[idx][1]});
                idx++;
            }
            while (pq.size() && pq.top().second < q){
                pq.pop();
            }
            
            res[resIdx] = pq.size() ? pq.top().first : -1;
        }
        
        return res;
    }
};