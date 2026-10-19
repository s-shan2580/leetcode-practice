class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";

        for (char c : num) {
            while (!res.empty() && c < res.back() && k > 0) {
                res.pop_back();
                k--;
            }
            res.push_back(c);
        }

        // Truncate remaining k digits from the tail
        while (k > 0 && !res.empty()) {
            res.pop_back();
            k--;
        }

        // Find the first non-zero digit
        int idx = 0;
        while (idx < res.size() && res[idx] == '0') {
            idx++;
        }

        // Take the substring starting from the first non-zero character
        res = res.substr(idx);

        return res.empty() ? "0" : res;
    }
};