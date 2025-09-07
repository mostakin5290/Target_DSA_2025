class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int rowStart = row;
        int rowEnd = 0;

        int colStart = col;
        int colEnd = 0;

        for(int i=0; i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    colStart = min(colStart ,j);
                    colEnd = max(colEnd,j);

                    rowStart = min(rowStart , i);
                    rowEnd = max(rowEnd,i);
                }
            }
        }

        int colAns = (colEnd - colStart)+1;
        int rowAns = (rowEnd - rowStart)+1;

        return colAns * rowAns;
    }
};