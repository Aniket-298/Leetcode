class Solution {
public:

    bool isSafe(vector<string> &boards,int row,int col, int n){
        for(int i=row;i>=0;i--){
            if(boards[i][col]=='Q') return false;
        }
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(boards[i][j]=='Q') return false;
        }
        for(int i=row,j=col;i>=0&&j<n;i--,j++){
            if(boards[i][j]=='Q') return false;
        }
        return true;
    }
    void solve(vector<string> &boards,vector<vector<string>> &ans,int row,int n){
        if(row==n){
            ans.push_back(boards);
            return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(boards,row,i,n)){
                boards[row][i]='Q';
                solve(boards,ans,row+1,n);
                boards[row][i]='.';
            }
        }
    } 
    int totalNQueens(int n) {
        vector<string> boards(n,string(n,'.'));
        vector<vector<string>> ans;
        solve(boards,ans,0,n);
        return ans.size();
    }
};