class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        int start = 0;
        int end = n-1;

        if(n==1) return arr[0];

        while(start <= end){

            if(arr[start] == arr[start+1]){
                start = start + 2;
            }
            else{
                return arr[start];
            }

            if(arr[end] == arr[end - 1]){
                end = end - 2;
            }
            else{
                return arr[end];
            }
        }

        return -1;
    }
};