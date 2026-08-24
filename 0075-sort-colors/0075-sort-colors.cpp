class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n= arr.size();
        int red=0, white=0, blue=0;

        for(int i=0; i<n; i++){
            if(arr[i]==0) red++;
            else if(arr[i]==1) white++;
            else if(arr[i]==2) blue++;
        }

        int i=0;

        while(red){
            arr[i]=0;
            i++;
            red--;
        }

        while(white){
            arr[i]=1;
            i++;
            white--;
        }

        while(blue){
            arr[i]=2;
            i++;
            blue--;
        }
    }
};