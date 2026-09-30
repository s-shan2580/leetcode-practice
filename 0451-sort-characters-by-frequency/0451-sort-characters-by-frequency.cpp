class Solution {
public:
    typedef pair<char, int> P;

    string frequencySort(string s) {

        unordered_map<char, int> mp;

        // Count frequency
        for (char c : s) {
            mp[c]++;
        }

        // Convert map to vector
        vector<P> arr(mp.begin(), mp.end());

        // Sort by frequency in descending order
        sort(arr.begin(), arr.end(),
             [](const P& a, const P& b) {
                 return a.second > b.second;
             });

        string res = "";

        // Add each character according to its frequency
        for (auto x : arr) {
            for (int i = 0; i < x.second; i++) {
                res.push_back(x.first);
            }
        }

        return res;
    }
};