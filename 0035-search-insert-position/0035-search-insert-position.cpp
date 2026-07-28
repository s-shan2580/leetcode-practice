class Solution {
public:
    int searchInsert(vector<int>& arr, int key) {
        int n=arr.size();
        int start=0;
        int end=n-1;
        while(start<=end){
            int mid= start + (end-start)/2 ;
            if(arr[mid]==key){
                return mid;
            }
            else if(arr[mid]<key){
                start=mid+1;
            }
            else if(arr[mid]>key){
                 end=mid-1;
            }
            
        }
        return start;
        
        
    }
};