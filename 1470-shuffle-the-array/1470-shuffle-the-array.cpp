class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        //int *p2=&nums[n];
        vector<int> temp(nums.size(),0);
        for(int i=0;i<nums.size();i++){
          if(i%2==0){
            temp[i]=nums[i/2];
          }
          else{
            temp[i]=nums[n+i/2];
            
          }
        }
        return temp;
    }
};