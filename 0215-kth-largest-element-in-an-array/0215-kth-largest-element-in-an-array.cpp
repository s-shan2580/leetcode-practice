class Solution {
public:

    int correct_pos_algo(vector <int>& nums,int l,int r){
        int i=l+1;
        int j=r;
        int p=nums[l];

        while(i<=j){
            if(nums[i]<p && nums[j]>p){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            if(nums[i]>=p) i++;
            if(nums[j]<=p) j--;
        }

        swap(nums[l],nums[j]);
        return j;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int p_idx=0;

        while(true){
            p_idx=correct_pos_algo(nums,l,r);

            if(p_idx==k-1){
                break;
            }
            else if(p_idx > k-1){
                r=p_idx-1;
            }
            else{
                l=p_idx+1;
            }
        }

        return nums[p_idx];
    }
};