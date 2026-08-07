class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        int min_price=arr[0];
        int max_profit=0;
        for(int i=0; i<n; i++){
            if(arr[i]>min_price){
                int p=arr[i]-min_price;
                if(max_profit<p) max_profit=p;
            }
            else{
               if(arr[i]<min_price){
                min_price=arr[i];
               }
            }
        }
        return max_profit;
    }
};