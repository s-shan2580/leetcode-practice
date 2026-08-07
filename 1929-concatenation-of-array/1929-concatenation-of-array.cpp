class Solution {
public:
    vector<int> getConcatenation(vector<int>& arr) {
        int n=arr.size();
        vector<int>res(2*n,0);
        for(int i=0;i<n;i++){
            res[i]=arr[i];
            res[n+i]=arr[i];
        }
        return res;
    }
};