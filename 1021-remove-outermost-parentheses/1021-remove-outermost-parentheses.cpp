class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int open_count=0;

        for(char c : s){
            if(c == '('){
                open_count++;
                if(open_count >= 2){
                    ans.push_back('(');
                }
            }
            if(c == ')'){
                open_count--;
                if(open_count >= 1){
                    ans.push_back(')');
                }
            }
        }

        return ans;

    }
};