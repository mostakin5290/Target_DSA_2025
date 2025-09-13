class Solution {
public:
    int maxFreqSum(string s) {
        int freq[26]={0};

        for(char c : s){
            freq[c - 'a']++;
        }

        set<char>vowals={'a','e','i','o','u'};

        int maxVowals = 0;
        int maxConsonant = 0;

        for(char c : vowals){
            maxVowals = max(maxVowals,freq[c - 'a']);
        }

        for(int i = 0;i<26;i++){
            char c = 'a'+i;
            if(!vowals.count(c)){
                maxConsonant = max(maxConsonant,freq[i]);
            }
        }

        return maxVowals+maxConsonant;
    }
};