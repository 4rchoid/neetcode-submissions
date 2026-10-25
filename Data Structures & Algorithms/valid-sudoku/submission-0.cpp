class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,set<int>> col_map;
        unordered_map<int,set<int>> row_map;
        using tuple_t = tuple<int, int>;
        map<tuple_t,set<int>> grid_map;


        for(int row = 0; row<9;row++){

            for(int col = 0; col<9;col++){
                if (board[row][col]==char{'.'}){
                    continue;
                }

                if(row_map[row].count(board[row][col])){
                    return false;
                }
                else{
                    row_map[row].insert(board[row][col]);
                }

                if(col_map[col].count(board[row][col])){
                    return false;
                }
                else{
                    col_map[col].insert(board[row][col]);
                }

                if(grid_map[tuple_t{row/3,col/3}].count(board[row][col])){
                    return false;
                }
                else{
                    grid_map[tuple_t{row/3,col/3}].insert(board[row][col]);
                }
            
            }
        }

        return true;
    }



};
