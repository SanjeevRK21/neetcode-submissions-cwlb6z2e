class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int j =0;
        while(j<9){
            unordered_map<char, int> a;
            unordered_map<char, int> b;
            for(int i=0; i<9; i++){
                a[board[i][j]]++;
                b[board[j][i]]++;
            }
            if(inval(a) == false) return false;
            if(inval(b) == false) return false;
            j++;
        }
        int i = 0;
        j = 0;
        while(j<9){
            i = 0;
            while(i<9){
            unordered_map<char, int>c;
            for(int k = 0;k<3; k++){
                for(int m=0; m<3; m++){
                    c[board[i+k][j+m]]++;
                }
            }
            if(inval(c)==false) return false;
            i = i+3;
            }
            j = j+3;
        }
        return true;
    }

    bool inval(unordered_map<char, int> a){
        for(auto &x : a){
            if(x.first != '.' && x.second > 1) return false;
        }
        return true;
    }
};
