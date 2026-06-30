class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();

        int maxArea = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    int area = dfs(grid,i,j,rows,cols);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }

    private:
    int dfs(vector<vector<int>>& grid,int i,int j,int rows,int cols){
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0){
            return 0;
        }
        grid[i][j]=0;
        int area=1;

        area += dfs(grid,i+1,j,rows,cols);
        area += dfs(grid,i-1,j,rows,cols);
        area += dfs(grid,i,j+1,rows,cols);
        area += dfs(grid,i,j-1,rows,cols);

        return area;
    }  
};
