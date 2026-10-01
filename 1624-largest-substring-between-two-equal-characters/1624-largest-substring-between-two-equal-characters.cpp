class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {

        unordered_map<char, int> first;
        int ans = -1;

        for (int i = 0; i < s.length(); i++) {

            if (first.find(s[i]) == first.end()) {
                first[s[i]] = i;
            }
            else {
                ans = max(ans, i - first[s[i]] - 1);
            }
        }

        return ans;
    }
};