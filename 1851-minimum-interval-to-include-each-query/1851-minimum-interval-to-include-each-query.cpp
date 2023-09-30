class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> res(queries.size());
        vector<int> sortedQueries = queries;
        unordered_map<int, vector<int>> originalIdxes;
        for (int i = 0; i < queries.size(); i++){
            originalIdxes[queries[i]].push_back(i);
        }
        
        sort(sortedQueries.begin(), sortedQueries.end());
        sort(intervals.begin(), intervals.end());
        
        int intervalsIdx = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; //sz, and end
        
        for (int i = 0; i < sortedQueries.size(); i++){
            int toFind = sortedQueries[i];
            while (intervalsIdx < intervals.size() && 
                   toFind >= intervals[intervalsIdx][0]){
                pq.push(make_pair(
                    intervals[intervalsIdx][1] - intervals[intervalsIdx][0] + 1,
                    intervals[intervalsIdx][1]));
                intervalsIdx++;
            }
            //cout << toFind << " " << pq.size() << endl;
            while (pq.size() && pq.top().second < toFind){
                pq.pop();
            }
            //cout << toFind << " " << pq.size() << endl; 

            int idx = originalIdxes[toFind].back();
            originalIdxes[toFind].pop_back();
            pq.size() ? res[idx] = pq.top().first : res[idx] = -1;
        }
        
        
        return res;
    }
};