class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        map<int,int>mp;
        int n= arr.size();
        for(int i=0;i<n;i++){
            int num=arr[i];
            int need=target-num;
            if(mp.find(need)!=mp.end()){
                return {i,mp[need]};
            }
            mp[num]=i;
        }

        return {-1,-1};

    }
};