class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n=arr.size();
        int r=k%n;
        int d=n-r;
        reverse(arr.begin(), arr.begin()+d);
        reverse(arr.begin()+d, arr.begin()+n);
        reverse(arr.begin(), arr.begin()+n);
    }
};