class Solution {
public:
    string removeWhitespaces(string str) {
        string result = "";
        for (char c : str) {
            if (isalpha(c)) {
                result += tolower(c);
            }
            else if(isdigit(c))
                result += c;
        }
        return result;
    }

    bool isPalindrome(string s) {
        // transform(s.begin(), s.end(), s.begin(), ::tolower);
        s=removeWhitespaces(s);
        // cout<<s;
        int start = 0;
        int end = s.length()-1;
        while(start<end){
            if(s[start]==s[end]){
                start++;
                end--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};