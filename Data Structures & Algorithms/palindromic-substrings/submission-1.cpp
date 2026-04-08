class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int r,l;
        int palins = 0;
        for(int i =0; i<n; i++){
            r = i;
            l = i;
            while(l>=0 && r<n && s[r]==s[l]){
                palins++;
                l--;
                r++;
            }
            r = i+1;
            l = i;
            while(l>=0 && r<n && s[r]==s[l]){
                palins++;
                r++;
                l--;
            }
        }
        return palins;
        
    }
};
