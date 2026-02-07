class Solution {
public:
    int minimumDeletions(string s) {
        
        int n = s.length();
        int total_count_A = 0;
        int left_count_B = 0;
        int count = INT_MAX;

        for(char ch: s) {
            if(ch == 'a')
               total_count_A++; 
        }

        for(char ch: s) {

            if(ch == 'a')
                total_count_A--;
            
            int del = (total_count_A + left_count_B);
            count = min(count, del);

            if(ch == 'b')
               left_count_B++; 
        }

        return count;
    }
};