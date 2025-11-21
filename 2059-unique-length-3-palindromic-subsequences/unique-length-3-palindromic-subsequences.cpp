class Solution {
public:
    static int countPalindromicSubsequence(const string& s) {
        int first[26] = {0};
        int last[26] = {0};
        for (int i = 1; i < s.length(); ++i) {
            const int j = s[i] - 97;
            if (first[j] == 0) first[j] = i;
            last[j] = i;
        }
        first[s[0] - 97] = 0;
        int count = 0;
        for (int j = 0; j < 26; ++j) {
            unsigned int bits = 0;
            for (int i = first[j] + 1; i < last[j]; bits |= 1 << (s[i++] - 97));
            count += popcount(bits);
        }
        return count;
    }
};