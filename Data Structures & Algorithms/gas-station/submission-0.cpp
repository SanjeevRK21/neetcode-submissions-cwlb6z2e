class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int currTank = 0;
        int start = 0;

        for(int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];

            total += diff;
            currTank += diff;

            if(currTank < 0) {
                start = i + 1;
                currTank = 0;
            }
        }

        if(total < 0) return -1;
        return start;
    }
};