class Solution {
public:
    bool solve(vector<vector<char>>& board, string word,int idx,int row,int col){
        if(row<0 || row>=board.size() || col<0 || col>=board[0].size()) return false;
        if(board[row][col]!=word[idx]) return false;
        if(idx==word.size()-1) return true;
        char temp=board[row][col];
        board[row][col]='#';
        bool found= solve(board,word,idx+1,row-1,col) ||
                    solve(board,word,idx+1,row+1,col) ||
                    solve(board,word,idx+1,row,col+1) ||
                    solve(board,word,idx+1,row,col-1) ;
        board[row][col]=temp;
        return found;
        
    }
    bool exist(vector<vector<char>>& board, string word) {

    for(int row = 0; row < board.size(); row++) {
        for(int col = 0; col < board[0].size(); col++) {

            if(solve(board, word, 0, row, col))
                return true;
        }
    }

    return false;
}
    
};