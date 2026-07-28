class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        const int n=2*nums.size();
        vector<int>temp(n,0);
        for(int i=0;i<n;i++){
            if(i<n/2){
                temp[i]=nums[i];
            }
            else{
                temp[i]=nums[i-n/2];
            }

        }
        return temp;
    }
};