class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for(int r = 0; r<m; ++r){
            for(int c = 0; c<n; ++c){
                if (matrix[r][c] == 0){
                    dist[r][c]=0;
                    q.push({r, c});
                }
            }
        }

        vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while(!q.empty()){
            auto[r, c]=q.front();
            q.pop();

            for(auto& dir : directions){
                int nr = r + dir.first;
                int nc = c + dir.second;

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && dist[nr][nc]==-1 ){
                    dist[nr][nc] = dist[r][c] + 1 ;
                    q.push({nr,nc});
                }
            }
        }
        return dist;
    }
};