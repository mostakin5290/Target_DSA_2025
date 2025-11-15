class Solution {
public:
    long long numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> zeros;
        for (int i = 0; i < n; i++)
            if (s[i] == '0')
                zeros.push_back(i);

        long long ans = 0;

        long long run = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                run++;
            else {
                ans += run * (run + 1) / 2;
                run = 0;
            }
        }
        ans += run * (run + 1) / 2;

        int m = zeros.size();
        if (m == 0)
            return ans;

        int maxZ = sqrt(n) + 2;
        for (int z = 1; z <= maxZ; z++) {
            long long need = 1LL * z * z + z;
            if (need > n)
                break;

            for (int i = 0; i + z - 1 < m; i++) {

                int L = zeros[i];
                int R = zeros[i + z - 1];

                int leftBound = (i == 0 ? 0 : zeros[i - 1] + 1);
                int rightBound = (i + z == m ? n - 1 : zeros[i + z] - 1);

                long long minStart = leftBound;
                long long maxStart = L;

                if (minStart > maxStart)
                    continue;

                for (long long st = minStart; st <= maxStart; st++) {
                    long long rmin = max((long long)R, st + need - 1);
                    if (rmin <= rightBound)
                        ans += (rightBound - rmin + 1);
                }
            }
        }
        return ans;
    }
};
