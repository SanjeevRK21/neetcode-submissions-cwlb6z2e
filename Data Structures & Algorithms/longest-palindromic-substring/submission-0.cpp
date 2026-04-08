class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 1) return s;
        string t = s;
        reverse(t.begin(),t.end());
        return lcsnum(s,t);
    }
    string lcsnum(string&s,string&t){
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,0));
        int ans = 0;
        int start = 0;
        for(int i =1; i<n+1;i++){
            for(int j =1; j<m+1;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                    int starts = i-dp[i][j];
                    int len = dp[i][j];
                    string pal = s.substr(starts,len);
                    string rev = pal;
                    reverse(rev.begin(),rev.end());
                    if(len>ans && pal==rev){
                        ans = len;
                        start = starts;
                    } 
                }
                else{dp[i][j]=0;
                }
            }
        }
        return s.substr(start,ans);
    }
};