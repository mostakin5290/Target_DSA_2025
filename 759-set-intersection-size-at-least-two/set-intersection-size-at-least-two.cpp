class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }

    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int a = intervals[0][1] - 1;
        int b = intervals[0][1];
        int cnt = 2;

        for(int i = 1; i < intervals.size(); i++) {
            int l = intervals[i][0], r = intervals[i][1];
            int inside = (a >= l) + (b >= l);

            if (inside == 2) continue;
            if (inside == 1) { 
                cnt++;
                if(r==b)a=r-1;
                else{
                    a = b;
                    b = r;
                }
            }
            else {
                cnt += 2;
                a = r - 1;
                b = r;
            }
        }
        return cnt;
    }
};