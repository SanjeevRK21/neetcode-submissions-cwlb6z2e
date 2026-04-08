class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0) return 1;
        if(s[0]=='0') return 0;
        if(s.size() == 1) return 1;
        string s1,s2;
        s1.append(s,1);
        s2.append(s,2);
        if(s.size()>=2){
            if(((s[0]-'0')*10 + (s[1]-'0')) <27)
            return numDecodings(s1) + numDecodings(s2);
        }
        return numDecodings(s1);
    }
};