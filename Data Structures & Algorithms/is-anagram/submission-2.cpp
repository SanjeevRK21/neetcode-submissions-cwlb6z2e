class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char, int>finds;
        for(int i=0; i<s.size();i++){
            finds[s[i]]++;
            finds[t[i]]--;
        }
        for(auto &c : finds){
            if(c.second!=0) return false;
        }
        return true;
    }
};
