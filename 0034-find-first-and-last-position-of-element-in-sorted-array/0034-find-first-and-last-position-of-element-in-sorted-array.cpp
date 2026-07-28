class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int key) {
        
        int start=0;
        int end=arr.size()-1;
        int first=-1;
        int last=-1;
        while(start<=end){
            int mid= start + (end-start)/2 ;
            if(arr[mid]==key){
                first=mid;
                end=mid-1;
            }
            else if(arr[mid]<key){
                start=mid+1;
            }
            else{
                 end=mid-1;
            }
            
        }
         start=0;
         end=arr.size()-1;

        while(start<=end){
            int mid= start + (end-start)/2 ;
            if(arr[mid]==key){
                last=mid;
                start=mid+1;
            }
            else if(arr[mid]<key){
                start=mid+1;
            }
            else {
                 end=mid-1;
            }
            
        }

        // vector<int>nums(2);
        // nums[0]=first;
        // nums[1]=last;
        return {first,last};
        
    }
};