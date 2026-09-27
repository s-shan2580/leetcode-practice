class Solution {
public:

    string findcommon(string s1, string s2) {
        int i = 0;

        while(i < s1.length() && i < s2.length() && s1[i] == s2[i]) {
            i++;
        }

        return s1.substr(0, i);
    }

    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];

        for(int i = 1; i < strs.size(); i++) {
            ans = findcommon(ans, strs[i]);

            if(ans.empty())
                return "";
        }

        return ans;
    }
};