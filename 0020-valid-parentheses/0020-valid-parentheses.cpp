class Solution {
public:
    bool isValid(string s) {
        stack <int> stk;
        for(char x : s){
            if( x=='(' || x=='[' || x=='{'){
                stk.push(x);
            }
            else if(x==')'){
                if(!stk.empty()){
                    if(stk.top()=='(') stk.pop();
                    else return false;
                }
                else return false;
            }

            else if(x=='}'){
                if(!stk.empty()){
                    if(stk.top()=='{') stk.pop();
                    else return false;
                }
                else return false;
            }

            else if(x==']'){
                if(!stk.empty()){
                    if(stk.top()=='[') stk.pop();
                    else return false;
                }
                else return false;
            }
        }

        if(stk.empty()) return true;
        return false;
    }
};