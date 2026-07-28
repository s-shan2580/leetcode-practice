class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int start=0, end=arr.size()-1 ;

        while(start<=end){

            //here we calc mid in different way to avoid invalid index
            //as we encouter (mid-1) index in our comparison which coud go
            // out of range such as (mid-1)<start=0 for some cases
            //dry ryn for[1 6 3 2 1] by normal mid calc and this way.
            int mid=end+(start-end)/2;

            //peak index check
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                return mid;
            }

            //uphill slope check
            else if(arr[mid]>arr[mid-1]){
                start=mid+1;
            }

            //downhill slope check
            else{          //condition: arr[mid]>arr[mid-1] 
                end=mid-1;
            }

        }

        return -1;
    }

};