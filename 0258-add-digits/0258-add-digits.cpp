class Solution {
public:
    int addDigits(int num) {
        
        while(num>9){
            int ans=0;
            int rem;
            while(num!=0){
                rem=num%10;
                ans=ans+rem;
                num=num/10;
            }
            num=ans;

        }
    return num;
    }
};