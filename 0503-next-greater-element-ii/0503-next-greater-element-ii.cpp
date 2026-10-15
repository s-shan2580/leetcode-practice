class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        stack <int> stk;
        for(int i = nums.size()-1; i>=0; i--){
            stk.push(nums[i]);
        }
        vector<int> temp;
        
        for(int i = nums.size()-1; i>=0; i--){
            while(!stk.empty() && nums[i]>=stk.top()){
                stk.pop();
            }
            if(stk.empty()){
                temp.push_back(-1);
            }
            else{
                temp.push_back(stk.top());
            }
            stk.push(nums[i]);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};