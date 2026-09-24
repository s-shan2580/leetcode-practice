class Solution {
public:

    int checkadj(vector<int>& arr, int days, int m, int k){
        int adj_ok = 0; int count = 0;
        
        for(int i=0; i<arr.size(); i++){
            
            if(arr[i]<=days ){
                adj_ok++ ;
                if(adj_ok == k){
                    adj_ok = 0;
                    count++;
                }
            }
            else{
                adj_ok = 0;
            }

           
        }
       
        return count >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long totalflowers = 1LL * m * k;

        if (totalflowers > n || (n==1 && totalflowers > n)) return -1;

        int start = *min_element(bloomDay.begin(), bloomDay.end());
        int end = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = end;

        while(start<=end){
            
            int mid = start + (end-start)/2;

            if(checkadj(bloomDay, mid, m, k)){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }

        return ans;
    }
};