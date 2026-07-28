class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0;
        int r=n-1;
        int res=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]>mid){
                res=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }

        }
        return res;
    }
};