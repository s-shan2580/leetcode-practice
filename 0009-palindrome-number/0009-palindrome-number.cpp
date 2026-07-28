class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int temp=x;
        int rem,res=0;
        while(x!=0){
            rem=x%10;
            if(res>INT_MAX/10)
            return false;
            res=res*10 + rem;
            x=x/10;

        }
        if(temp==res){
            return true;
        } 
        else{
            return false;
        }
        
    }

};