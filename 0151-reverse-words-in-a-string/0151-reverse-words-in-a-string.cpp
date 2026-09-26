class Solution {
public:
    string rev_chars(string word) {
        int left = 0;
        int right = word.length() - 1;

        while (left < right) {
            swap(word[left], word[right]);
            left++;
            right--;
        }

        return word;
    }

    string reverseWords(string s) {
        string word = "";
        string ans = "";
        int n = s.length() - 1;

        for (int i = n; i >= 0; i--) {
            if (s[i] == ' ') {
                if (!word.empty()) {
                    string temp = rev_chars(word);
                    ans = ans + temp;
                    ans = ans + " ";
                    word = "";
                }
                continue;
            } else {
                word.push_back(s[i]);
            }
        }

        if (!word.empty()) {
            string temp = rev_chars(word);
            ans = ans + temp;
        }

        if (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;
    }
};