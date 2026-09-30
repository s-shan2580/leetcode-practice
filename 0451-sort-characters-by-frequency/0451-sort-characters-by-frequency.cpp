class Solution {
public:
        typedef pair<char, int> P;

       string frequencySort(string s) {

        unordered_map<char, int> mp;

        for (char c : s) {
            mp[c]++;
        }

        vector <P> arr(mp.begin(), mp.end());

        sort(arr.begin(), arr.end(),
             [](P& a, P& b) { return a.second > b.second; });

        string res = "";

        for (auto x : arr) {
            for(int i=0; i<x.second; i++){
                res.push_back(x.first);
            }
        }

        return res;
    }
};