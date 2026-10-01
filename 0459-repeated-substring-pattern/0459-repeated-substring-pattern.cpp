class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();

        string sub = "";

        for (int j = 0; j < n-1; j++) {
            sub += s[j];
            int len = sub.length();
            if (n % len == 0) {
                int repeat_len = n / len;
                string temp = "";
                for (int k = 0; k < repeat_len; k++) {
                    temp += sub;
                }
                if (temp == s)
                    return true;
            }
        }

        return false;
    }

    

};
