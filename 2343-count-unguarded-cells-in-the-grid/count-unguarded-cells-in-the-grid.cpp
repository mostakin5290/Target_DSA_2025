class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> cells(m, vector<int>(n, 0));
        int ans = 0;

        for (auto& it : walls) {
            int i = it[0];
            int j = it[1];
            cells[i][j] = 1;
        }

        for (auto& it : guards) {
            int i = it[0];
            int j = it[1];
            cells[i][j] = 2;
        }

        for (auto& it : guards) {

            int i = it[0];
            int j = it[1];

            // up
            for (int k = i - 1; k >= 0; k--) {
                if (cells[k][j] == 1 || cells[k][j] == 2)
                    break;
                cells[k][j] = 3;
            }
            // down

            for (int k = i + 1; k < m; k++) {
                if (cells[k][j] == 1 || cells[k][j] == 2)
                    break;
                cells[k][j] = 3;
            }

            // left
            for (int k = j - 1; k >= 0; k--) {
                if (cells[i][k] == 1 || cells[i][k] == 2)
                    break;
                cells[i][k] = 3;
            }

            // right
            for (int k = j + 1; k < n; k++) {
                if (cells[i][k] == 1 || cells[i][k] == 2)
                    break;
                cells[i][k] = 3;
            }
        }

        // for(int i = 0 ; i < m;i++){
        //     for(int j=0 ; j < n ;j++){
        //         cout<<cells[i][j]<<" ";
        //         if(cells[i][j]==0)
        //         ans++;
        //     }
        //     cout<<endl;
        // }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (cells[i][j] == 0)
                    ans++;

        return ans;
    }
};