class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int n1 = m;
        int n2 = n;

        vector<int> res;

        int i = 0;
        int j = 0;

        while (i < n1 && j < n2) {
            if (a[i] <= b[j]) {

                res.push_back(a[i]);

                i++;
            } else {

                res.push_back(b[j]);

                j++;
            }
        }

        while (i < n1) {

            res.push_back(a[i]);

            i++;
        }

        while (j < n2) {

            res.push_back(b[j]);

            j++;
        }

        a=res;
    }
};