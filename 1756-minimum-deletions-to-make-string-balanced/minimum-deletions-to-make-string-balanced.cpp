class Solution {
public:
    int minimumDeletions(string s){

        int n = s.length();
        stack<char> st;
        int count = 0;

        for(char ch: s){

            if(st.empty())
                st.push(ch);
            else if((st.top() == ch) || ((st.top() == 'a') && (ch == 'b')))
                st.push(ch);
            else {
                st.pop();
                count++;
            }
        }
        
        return count;
    }
};