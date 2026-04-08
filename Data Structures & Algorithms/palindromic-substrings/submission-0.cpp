class Solution {
public:
    int countSubstrings(string s) {
                int n = s.size();
        int res =0;
        int resLen = 0;

        for (int i = 0; i < n; i++) {

            // -------- odd length palindrome --------
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > resLen) {
                    res ++;
                }
                l--;
                r++;
            }

            // -------- even length palindrome --------
            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > resLen) {
                    res ++;
                }
                l--;
                r++;
            }
        }
        return res;
    }
};
