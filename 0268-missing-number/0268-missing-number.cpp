class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int mx=arr.size();
        int sum_reqd=(mx*(mx+1))/2;
        int sum=0;
        for(int x:arr){
            sum+=x;
        }
        return sum_reqd-sum;
    }
};