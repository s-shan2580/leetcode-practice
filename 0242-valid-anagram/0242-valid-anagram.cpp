class Solution {
public:
    bool isAnagram(string s1, string t1) {
        unordered_map<char,int>mpp;
        if(s1.size()!=t1.size()){
            return false;
        }
        for(char s:s1){
            mpp[s]++;
        }
        for(char t : t1){
            if(mpp[t]>0){
                mpp[t]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};