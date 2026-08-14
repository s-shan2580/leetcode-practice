class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
       int n=arr.size();
        unordered_map<int,int>prefix_sums;
        int currSum=0;
        int count=0;
        
        for(int i=0; i<n; i++){
            currSum += arr[i];
            
            if(currSum==k){
                count++;
            }
            
            if(prefix_sums.find(currSum-k)!=prefix_sums.end()){
                count += prefix_sums[currSum-k];
            }
            
            prefix_sums[currSum]++;
            
        }
        
        return count;
    }
};