class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> lastseen(256, -1);
        int l = 0;
        int maxlen = 0;

        for(int r = 0; r<s.length(); r++){

            char c = s[r];

            if(lastseen[(unsigned char)c] >= l){
                l = lastseen[(unsigned char)c] + 1;
            }

            lastseen[(unsigned char)c] = r;

            maxlen = max(maxlen, r-l+1);

        }

        return maxlen;

    }
};