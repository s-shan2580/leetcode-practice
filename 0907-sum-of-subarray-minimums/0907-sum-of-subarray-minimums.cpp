class Solution {
public:
    vector<int> get_nsl(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> nsl(n);
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                nsl[i] = -1;
            } else {
                while (!st.empty() && arr[i] <= arr[st.top()]) {
                    st.pop();
                }
                nsl[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }

        return nsl;
    }

    vector<int> get_nsr(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> nsr(n);
        for (int i = n-1; i >= 0; i--) {
            if (st.empty()) {
                nsr[i] = n;
            } else {
                while (!st.empty() && arr[i] < arr[st.top()]) {
                    st.pop();
                }
                nsr[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }

        return nsr;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;
        long long mod = 1e9 + 7;
        long long total_subarrays = 0;

        vector<int> nsl = get_nsl(arr, n);
        vector<int> nsr = get_nsr(arr, n);

        for (int i = 0; i < n; i++) {

            long long ls = i - nsl[i];
            long long rs = nsr[i] - i;
            total_subarrays = ls * rs;
            sum = (sum + arr[i] * total_subarrays) % mod;
        }

        return sum;
    }
};