class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int c_start = c;
        int c_end = 0;
        int r_start = r;
        int r_end = 0;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==1){
                    c_start = min(c_start,j);
                    c_end = max(c_end,j);
                    r_start = min(r_start,i);
                    r_end = max(r_end,i);
                }
                
            }
        }
        int c_ans = (c_end - c_start) + 1;
        int r_ans = (r_end - r_start) + 1;

        return c_ans*r_ans;
    }
};