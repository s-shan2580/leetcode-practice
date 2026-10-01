class Solution {
public:
    bool check_substr(const string& s, const string& t) {
        return t.find(s) != string::npos;
    }

    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for (const string& s : patterns) {
            if (check_substr(s, word)) {
                count++;
            }
        }
        return count;
    }
};