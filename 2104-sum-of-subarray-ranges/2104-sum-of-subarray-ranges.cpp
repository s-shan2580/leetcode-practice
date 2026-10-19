#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    // Next Smaller to Left (Index)
    vector<int> get_nsl(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> nsl(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nsl[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return nsl;
    }

    // Next Smaller to Right (Index)
    vector<int> get_nsr(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> nsr(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            nsr[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nsr;
    }

    // Next Greater to Left (Index)
    vector<int> get_ngl(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> ngl(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            ngl[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ngl;
    }

    // Next Greater to Right (Index)
    vector<int> get_ngr(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> ngr(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            ngr[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ngr;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;

        vector<int> nsl = get_nsl(arr, n);
        vector<int> nsr = get_nsr(arr, n);

        for (int i = 0; i < n; i++) {
            long long ls = i - nsl[i];
            long long rs = nsr[i] - i;
            long long total_subarrays = ls * rs;
            sum += (long long)arr[i] * total_subarrays;
        }

        return sum;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;

        vector<int> ngl = get_ngl(arr, n);
        vector<int> ngr = get_ngr(arr, n);

        for (int i = 0; i < n; i++) {
            long long ls = i - ngl[i];
            long long rs = ngr[i] - i;
            long long total_subarrays = ls * rs;
            sum += (long long)arr[i] * total_subarrays;
        }

        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};