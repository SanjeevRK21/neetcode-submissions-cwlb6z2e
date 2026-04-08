class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(string x : strs){
            s = s + to_string(x.size()) + "#" + x;
        }
        return s;
    }

    vector<string> decode(string s) {
        int n = s.size();
        if(n == 0) return {};
        vector<string> strs;
        int i=0;
        while(i < n){
            int k =i;
            int j =0;
            while(s[k]!='#'){
                k++;
                j++;                
            }
            int len = stoi(s.substr(i,j));
            strs.push_back(s.substr(i+j+1,len));
            i = i+j+len+1;
        }
        return strs;
    }
};
