class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        stack<int> stk;
        vector<int> dir(n);
        vector<int> res;

        for(int i = 0; i < n; i++){
            if(arr[i] >= 0) dir[i] = 1;
            else dir[i] = 0;
        }

        int i = 0;

        while(i < n){
            if(stk.empty()){
                stk.push(i);
                i++;
                continue;
            }
            // Collision ONLY happens if stack top moves right (1) and current moves left (0)
            else if(dir[stk.top()] == 1 && dir[i] == 0){
                if(abs(arr[i]) == abs(arr[stk.top()])){
                    stk.pop();
                    i++; // Both explode, move to next asteroid
                    continue;
                }
                else if(abs(arr[i]) > abs(arr[stk.top()])){
                    stk.pop(); // Stack asteroid explodes, do NOT increment i (current fights next in stack)
                }
                else{
                    i++; // Current asteroid explodes, move to next
                    continue;
                }
            }
            else{
                stk.push(i);
                i++; // Only advance after pushing
            }
        }

        // Reconstruct result from stack indices
        while(!stk.empty()){
            res.push_back(arr[stk.top()]);
            stk.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};