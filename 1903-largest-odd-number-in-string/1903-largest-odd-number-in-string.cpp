class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();

        if(n==0) return "";

        if(n==1) return ((num[0]-'0') % 2 != 0) ? num : "";

        for(int i=n-1; i>=0; i--){
            if((num[i]-'0') % 2 != 0){
                return num.substr(0,i+1);
            }
            else{
                continue;
            }
        }

        return "";
           
        


    }
};