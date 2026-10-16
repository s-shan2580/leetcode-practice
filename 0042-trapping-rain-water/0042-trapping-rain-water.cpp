class Solution {
public:
    vector<int> get_left_max(vector<int>& arr, int n){
        vector<int> res(n);
        res[0] = arr[0];
        for(int i=1; i<n; i++){
            res[i] = max(res[i-1], arr[i]);
        }
        return res;
    }

    vector<int> get_right_max(vector<int>& arr, int n){
        vector<int> res(n);
        res[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--){
            res[i] = max(res[i+1], arr[i]);
        }
        return res;
    }

    int trap(vector<int>& height) {

        int n = height.size();
        vector<int> leftmax = get_left_max(height, n);
        vector<int> rightmax = get_right_max(height, n);

        int width = 1;
        int water_stored = 0;

        for(int i=0; i<n; i++){
            
            water_stored += (min(leftmax[i], rightmax[i]) - height[i]) * width;
        }

        return water_stored;

    }
};