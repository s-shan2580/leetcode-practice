class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n=arr.size();
        int count=0;
        int element;

        for(int i=0; i<n; i++){
            if(count==0){
                element=arr[i];
                count=1;
            }
            else if(arr[i]==element) count++;
            else{
                count--;
            }
        }
        return element;

    }
};