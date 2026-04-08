class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;

        // Step 1: sort by end time
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 0;
        int prevEnd = intervals[0][1];

        // Step 2: iterate through intervals
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < prevEnd) {
                // overlap → remove
                count++;
            } else {
                // no overlap → update prevEnd
                prevEnd = intervals[i][1];
            }
        }

        return count;
    }
};