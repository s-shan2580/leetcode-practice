class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        int n=arr.size()/2;
        vector<int> a;
        vector<int> b;
        vector<int> res;

        for(int i=0; i<2*n; i++){
            if(arr[i]>=0) a.push_back(arr[i]);
            else b.push_back(arr[i]);
        }

        for(int i=0; i<n; i++){
            res.push_back(a[i]);
            res.push_back(b[i]);
        }

        return res;

    }
};