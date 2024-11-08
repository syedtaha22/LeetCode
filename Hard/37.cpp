#include<vector>
using namespace std;

class Solution {
public:
    bool isValid(int row, int column, int c, vector<vector<char>>& grid){
        for(int i = 0; i < 9; i++){ 
            if( grid[row][i] == c) return false;
            if( grid[i][column] == c) return false; 
            if( grid[3*(row/3)+(i/3)][3*(column/3)+(i%3)] == c) return false;
        }
        return true;
    }

    // //Recursive Function to Solve Puzzle
    bool solve(vector<vector<char>>& grid){
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if (grid[i][j] == '.'){ 
                    for(char c='1'; c<='9'; c++){
                        if(isValid(i,j,c,grid)){
                            grid[i][j] = c;
                            if(solve(grid)) return true;
                            else grid[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& grid){ solve(grid); }

};

