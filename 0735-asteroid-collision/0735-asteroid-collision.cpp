class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        stack<int> stk;
        vector<int> res;

        int i = 0;

        while(i < n){
            if(stk.empty()){
                stk.push(arr[i]);
                i++;
                continue;
            }
            // Collision ONLY happens when top moves right (+) and incoming moves left (-)
            else if(stk.top() > 0 && arr[i] < 0){
                if(abs(arr[i]) == abs(stk.top())){
                    stk.pop();
                    i++; // Both destroy each other
                    continue;
                }
                else if(abs(arr[i]) > abs(stk.top())){
                    stk.pop(); // Stack asteroid destroyed; i stays same to fight next
                }
                else{
                    i++; // Incoming asteroid destroyed
                    continue;
                }
            }
            else{
                stk.push(arr[i]);
                i++;
            }
        }

        // Pop elements directly into res
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};