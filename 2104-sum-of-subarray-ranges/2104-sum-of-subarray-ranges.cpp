class Solution {
public:
    vector<int> get_nbl(vector<int>& arr){
        int n = arr.size();
        stack<int> stk;
        vector<int> nbl(n);

        for(int i=0; i<n; i++){
            while(!stk.empty() && arr[i]>=arr[stk.top()]){
                stk.pop();
            }
            nbl[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        return nbl;
    }

    vector<int> get_nbr(vector<int>& arr){
        int n = arr.size();
        stack<int> stk;
        vector<int> nbr(n);

        for(int i=n-1; i>=0; i--){
            while(!stk.empty() && arr[i]>arr[stk.top()]){
                stk.pop();
            }
            nbr[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }

        return nbr;
    }

    vector<int> get_nsl(vector<int>& arr){
        int n = arr.size();
        stack<int> stk;
        vector<int> nsl(n);

        for(int i=0; i<n; i++){
            while(!stk.empty() && arr[i]<=arr[stk.top()]){
                stk.pop();
            }
            nsl[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        return nsl;
    }

    vector<int> get_nsr(vector<int>& arr){
        int n = arr.size();
        stack<int> stk;
        vector<int> nsr(n);

        for(int i=n-1; i>=0; i--){
            while(!stk.empty() && arr[i]<arr[stk.top()]){
                stk.pop();
            }
            nsr[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }

        return nsr;
    }

    long long subarr_maxsum(vector<int>& arr){
        int n = arr.size();
        vector<int> nbl = get_nbl(arr);
        vector<int> nbr = get_nbr(arr);
        long long sum = 0;

        for(int i=0; i<n; i++){
            long long ls = i - nbl[i];
            long long rs = nbr[i] - i;
            sum += ls * rs * arr[i];
        }

        return sum;
    }

    long long subarr_minsum(vector<int>& arr){
        int n = arr.size();
        vector<int> nsl = get_nsl(arr);
        vector<int> nsr = get_nsr(arr);
        long long sum = 0;

        for(int i=0; i<n; i++){
            long long ls = i - nsl[i];
            long long rs = nsr[i] - i;
            sum += ls * rs * arr[i];
        }

        return sum;
    }

    long long subArrayRanges(vector<int>& arr) {
        return subarr_maxsum(arr) - subarr_minsum(arr);
    }
};