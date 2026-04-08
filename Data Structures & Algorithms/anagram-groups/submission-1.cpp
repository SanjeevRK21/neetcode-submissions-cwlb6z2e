class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*
         here we are basically creating an unordered map 
         and then saving the elements in the form of 
         keys - sorted strings 
         values - original string
         since the sorted string for any anagram strings are same
         and thus the values for each key will have all 
         the anagram words.
         later we push the map.second values into a
         vector<vector<string>> and then return it.
         */
        unordered_map<string, vector<string>> ana; 
        for(string s : strs){
            string c = s;
            sort(c.begin(),c.end());
            ana[c].push_back(s);
        }
        vector<vector<string>> final;
        for(auto& f : ana){
            final.push_back(f.second);
        }
        return final;
    }
};

