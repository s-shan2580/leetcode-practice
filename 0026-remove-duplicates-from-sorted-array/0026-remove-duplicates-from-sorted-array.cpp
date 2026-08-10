class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n=arr.size();
        int k=1;
        if(n==0) return 0;
        for(int i=k;i<n;i++){
            if(arr[i]!=arr[k-1]){
                arr[k]=arr[i];
                k++;
            }
        }
        return k;
    }
};