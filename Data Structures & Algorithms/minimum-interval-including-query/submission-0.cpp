class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        
        // Sort intervals by left endpoint
        sort(intervals.begin(), intervals.end());
        
        int n = intervals.size();
        int q = queries.size();
        
        // Store queries with original index
        vector<pair<int,int>> qIdx;
        for (int i = 0; i < q; i++) {
            qIdx.push_back({queries[i], i});
        }
        
        // Sort queries
        sort(qIdx.begin(), qIdx.end());
        
        // Min heap: {length, right}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        
        vector<int> ans(q, -1);
        
        int i = 0; // pointer for intervals
        
        for (auto &it : qIdx) {
            int query = it.first;
            int idx = it.second;
            
            // Add intervals whose left <= query
            while (i < n && intervals[i][0] <= query) {
                int left = intervals[i][0];
                int right = intervals[i][1];
                int len = right - left + 1;
                
                pq.push({len, right});
                i++;
            }
            
            // Remove intervals that can't cover query
            while (!pq.empty() && pq.top().second < query) {
                pq.pop();
            }
            
            // If heap not empty, top has smallest interval
            if (!pq.empty()) {
                ans[idx] = pq.top().first;
            }
        }
        
        return ans;
    }
};