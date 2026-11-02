class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxcount = 0;
        string temp = "";

        for (char c : s) {
            auto pos = temp.find(c);
            if (pos != string::npos) {
                // Drop everything up to and including the duplicate character
                temp = temp.substr(pos + 1);
            }
            temp.push_back(c);
            maxcount = max(maxcount, (int)temp.length());
        }

        return maxcount;
    }
};