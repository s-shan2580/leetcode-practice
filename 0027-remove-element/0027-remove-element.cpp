class Solution {
public:
    int removeElement(vector<int>& arr, int v) {
        int n=arr.size();
        int i=0;
        int j=n-1;
        if(n==0){
            return 0;
        }
        if(n==1 && arr[i]==v){
            return 0;
        }
        if(n==1 && arr[i]!=v){
            return 1;
        }
        

        while(i<j){
            if(arr[i]==v && arr[j]!=v){
                swap(arr[i],arr[j]);
                i++; j--;
            }
            else if(arr[i]!=v && arr[j]==v){
                i++; j--;
            }
            else if(arr[i]!=v && arr[j]!=v){
                i++;
            }
            else if(arr[i]==v && arr[j]==v){
                 j--;
            }
        }
        
        int count=0;
        for(int k=0;k<n;k++){
            if(arr[k]!=v){
                count++;
            }
            else{
                break;
            }
        }
        return count;
    }
};