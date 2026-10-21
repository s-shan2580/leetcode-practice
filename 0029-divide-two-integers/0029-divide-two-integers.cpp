class Solution {
public:
    int divide(int dividend, int divisor) {
        // Only overflow case
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        bool negative = (dividend < 0) != (divisor < 0);

        // Use long long so abs(INT_MIN) doesn't overflow
        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);

        long long quotient = 0;
        while (a >= b) {
            int shift = 0;
            while (a >= (b << (shift + 1))) {
                shift++;
            }
            a -= b << shift;
            quotient += 1LL << shift;
        }

        return negative ? -quotient : quotient;
    }
};