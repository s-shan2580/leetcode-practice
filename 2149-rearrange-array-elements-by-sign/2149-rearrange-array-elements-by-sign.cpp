class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        int n=arr.size();
        int posidx=0;
        int negidx=1;
        vector<int> res(n,0);
        for(int x: arr){
            if(x>=0){
                res[posidx]=x;
                posidx +=2;
            }
            else{
                res[negidx]=x;
                negidx +=2;
            }
        }

        return res;

    }
};