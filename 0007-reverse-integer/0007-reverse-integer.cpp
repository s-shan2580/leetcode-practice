class Solution {
public:
    int reverse(int x) {
        long long res=0;
        while(x!=0){
            int p=x%10;
            res=res*10 + p;
            x=x/10;
        }
        if(res>INT_MAX){
            return 0;
        }
        else{
            int result=res;
            return result;
        }

    }
};