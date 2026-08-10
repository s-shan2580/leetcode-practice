class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return;
        int i=0;
        int k=0;
        while(k<n){
            if(arr[k]==0){
                break;
            }
            k++;
        }
        for(int i=k+1;i<n;i++){
            if(arr[i]!=0){
                swap(arr[i],arr[k]);
                k++;
            }
        }
    }
};