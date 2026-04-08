class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>lily;
        vector<int> freq;
        for(int x : nums){
             lily[x]++;
        }
        for(int i = 1; i<=k; i++){
            int j = INT_MIN;
            int h;
            for(auto& x : lily){
                if(x.second > j){
                    j = x.second;
                    h = x.first;
                }
            }
            freq.push_back(h);
            lily.erase(h);
        }
        return freq;
    }
};
