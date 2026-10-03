class Solution {
public:
    bool isvalid(int r,int c,vector<vector<char>>& board,char k){
        for(int j=0;j<9;j++){
            if(board[r][j]==k){
                return false;
            }
        }
        for(int i=0;i<9;i++){
            if(board[i][c]==k){
                return false;
            }
        }
        int sr = (r / 3) * 3;
        int sc = (c / 3) * 3;

        for (int i = sr; i < sr + 3; i++) {
            for (int j = sc; j < sc + 3; j++) {
                if (board[i][j] == k)
                    return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        int r=-1;
        int c=-1;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    r=i;
                    c=j;break;
                }
            }
            if(r!=-1){
                break;
            }
        }
        if(r==-1){
            return true;
        }
        for(char k='1';k<='9';k++){
            if(isvalid(r,c,board,k)){
                board[r][c]=k;
                if(solve(board)){
                    return true;
                }
                board[r][c]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};