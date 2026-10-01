class Solution {
public:

    int myAtoi(string s) {

        long long ans = 0;

        bool dig_seen = false;
        bool sign_seen = false;

        int sign = 1;

        for(char c : s) {

            // Leading spaces
            if(c == ' ') {

                if(!dig_seen && !sign_seen)
                    continue;
                else
                    break;
            }

            // Sign
            if(c == '-' || c == '+') {

                if(!sign_seen && !dig_seen) {

                    sign_seen = true;

                    if(c == '-')
                        sign = -1;
                }
                else {
                    break;
                }
            }

            // Digit
            else if(c >= '0' && c <= '9') {

                dig_seen = true;

                int digit = c - '0';

                // Check overflow BEFORE multiplying
                if(ans > INT_MAX / 10 ||
                   (ans == INT_MAX / 10 && digit > INT_MAX % 10)) {

                    if(sign == -1)
                        return INT_MIN;
                    else
                        return INT_MAX;
                }

                ans = ans * 10 + digit;
            }

            // Anything else
            else {
                break;
            }
        }

        ans *= sign;

        if(ans < INT_MIN)
            return INT_MIN;

        if(ans > INT_MAX)
            return INT_MAX;

        return (int)ans;
    }
};