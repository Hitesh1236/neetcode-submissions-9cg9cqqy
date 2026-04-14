class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row check
        for(int row = 0; row < 9; row++){
            unordered_set<int> set;
            for(int col = 0; col < 9; col++){
                if(set.find(board[row][col]) != set.end()) return false;
                if(board[row][col]!='.')set.insert(board[row][col]);
            }
        }
        // column check
        for(int col = 0; col < 9; col++){
            unordered_set<int> set;
            for(int row = 0; row < 9; row++){
                if(set.find(board[row][col]) != set.end()) return false;
                if(board[row][col]!='.')set.insert(board[row][col]);
            }
        }
        // box check
        for(int rowStart = 0; rowStart < 9; rowStart+=3){
            for(int colStart = 0; colStart < 9; colStart+=3){
                unordered_set<int> set;
                for(int curRow = rowStart; curRow < rowStart + 3; curRow++){
                    for(int curCol = colStart; curCol < colStart + 3; curCol++){
                        if(set.find(board[curRow][curCol]) != set.end()) return false;
                        if(board[curRow][curCol]!='.') set.insert(board[curRow][curCol]);
                    }
                }
            }
        }
        return true;
    }
};
