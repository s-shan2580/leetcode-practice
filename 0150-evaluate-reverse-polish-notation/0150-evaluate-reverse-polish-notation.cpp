class Solution {
public:
    bool isOperator(const string& op) {
    return (op == "+" || op == "-" || op == "*" || 
            op == "/" || op == "^" || op == "%");
}

    int calc_Exp(int x, int y, const string& s){
        if(s == "+") return (x + y);
        if(s == "-") return (y - x);
        if(s == "*") return (x * y);
        if(s == "/") return (y / x);
        else return -1;
    }

    int evalRPN(vector<string>& s) {

        stack<int> stk;

        for (int i =0; i<s.size(); i++) {

            if (isOperator(s[i])) {

                int op1 = stk.top();
                stk.pop();
                int op2 = stk.top();
                stk.pop();

                int exp =calc_Exp(op1, op2, s[i]);

                stk.push(exp);
            }

            else {

                stk.push(stoi(s[i]));
            }
        }

        return stk.top();
    }
};