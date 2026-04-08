class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int> anagram;
        for(char c : s) anagram[c]++;
        for(char c : t) anagram[c]--;
        for(auto &c : anagram){
            if(c.second != 0) return false;
        }
        return true;
    }
};
