class Solution {
public:
    string fractionToDecimal(int num, int den) {
        if (num == 0) return "0";

        string result = "";

        // Handle sign
        if ((long long)num  * (long long) den < 0) result += "-";

        // Work with positive values as long long
        long long absNum = llabs((long long)num);
        long long absDen = llabs((long long)den);

        // Integer part
        long long ans = absNum / absDen;
        result += to_string(ans);

        long long rem = absNum % absDen;
        if (rem == 0) return result;  // no fractional part

        result += ".";

        unordered_map<long long, int> mp;  // remainder -> index in result
        while (rem != 0) {
            if (mp.count(rem)) {
                result.insert(mp[rem], "(");
                result += ")";
                break;
            }

            mp[rem] = result.length();
            rem *= 10;
            long long dig = rem / absDen;
            result += to_string(dig);
            rem %= absDen;
        }

        return result;
    }
};
