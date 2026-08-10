class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int max_count = 0;

        for(int x : nums) {
            if(x == 1) {
                count++;
            }
            else {
                if(count > max_count)
                    max_count = count;

                count = 0;
            }
        }

        if(count > max_count)
            max_count = count;

        return max_count;
    }
};