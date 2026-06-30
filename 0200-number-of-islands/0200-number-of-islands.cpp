class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int rows= grid.size();
        int cols = grid[0].size();
        int islands=0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    islands++;
                    dfs(grid,i,j,rows,cols);
                }
            }
        }
        return islands;
    }
    
    private:
    void dfs(vector<vector<char>>& grid, int i, int j, int rows, int cols) {
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0'; 

        dfs(grid, i + 1, j, rows, cols); 
        dfs(grid, i - 1, j, rows, cols); 
        dfs(grid, i, j + 1, rows, cols); 
        dfs(grid, i, j - 1, rows, cols); 
    }

};