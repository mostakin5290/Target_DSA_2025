
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";

        string ans = "";
        
        int nines = sum / 9;
        int rem = sum % 9;

        ans.append(nines, '9');

        if (rem > 0) {
            ans += to_string(rem);
        }

        ans.append(num - ans.length(), '0');

        return ans;
    }
};
