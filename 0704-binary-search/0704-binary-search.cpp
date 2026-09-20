class Solution {
public:

    int search(vector<int>& arr, int x){
        int n= arr.size();
        int start=0;
        int end=n-1;
        return b_search(arr, start, end, x);
    }

    int b_search(vector<int>& arr, int start, int end, int x) {

        while(start<=end){
            int mid= start + (end-start)/2;
            if(arr[mid]==x){
                return mid;
            }
            else if(arr[mid]<x){
               start= mid+1;
               return b_search(arr, start, end, x);
            }
            else{
                end= mid-1;
                return b_search(arr, start, end, x);
            }
        }

        return -1;
    }
};