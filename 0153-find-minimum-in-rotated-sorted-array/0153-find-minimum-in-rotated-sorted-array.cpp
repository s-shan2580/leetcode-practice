class Solution {
public:
    int findMin(vector<int>& arr) {
         int n = arr.size();

        int start = 0;
        int end = n - 1;
        int ans = arr[0];

        while (start <= end) {

            int mid = start + (end - start) / 2;

            if(arr[start] <= arr[end]){
                ans=min(ans,arr[start]);
                break;
            }

            if (arr[start] <= arr[mid]) {

                ans =min(ans, arr[start]); 
                start = mid + 1;
            }

            else{
                end = mid ;
            }

        }  

        return ans;
    }
};