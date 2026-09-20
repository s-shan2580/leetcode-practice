class Solution {
public:
    int searchInsert(vector<int>& arr, int x) {
        int n = arr.size();
		int start = 0;
		int end = n - 1;
		int ans = -1;
		
		while (start <= end) {
			int mid = start + (end - start)/2 ;
			
            if(arr[mid] == x){
                return mid;
            }
			else if (arr[mid] > x) {
				ans = mid ;
				end = mid - 1 ;
			}
			else {
				
				start = mid + 1;
				
			}
		}
		if(start>end) return start;
		else return ans;
    }
};