class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int n = s.size();
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        for(int i =0 ; i<(n+1)/2; i++){
            if(s[i]!=t[i] || s[n-i-1]!=t[n-1-i]) return false;
        }
        return true;
    }
};
