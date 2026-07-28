class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        unordered_map<int,int> mp;
        vector<int> res;

        for (int x : a) {
            mp[x]++;
        }

        for (int x : b) {
            if (mp[x] > 0) {
                res.push_back(x);
                mp[x]--;
            }
        }

        return res;
    }
};