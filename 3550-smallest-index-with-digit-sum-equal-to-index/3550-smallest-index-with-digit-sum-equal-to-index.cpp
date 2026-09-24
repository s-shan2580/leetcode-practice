class Solution {
public:
    int calc_digit_sum(int x){
        int rem = 0;

        while(x>0){
            rem += x % 10;
            x = x/10;
        }

        return rem;
    }
    int smallestIndex(vector<int>& arr) {
        
        int n = arr.size();

        for(int i=0; i<n; i++){
            if(calc_digit_sum(arr[i])==i){
                return i;
            }
        }

        return -1;
    }
};