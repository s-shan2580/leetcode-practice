class Solution {
public:
    bool isAnagram(string s1, string t1) {

        int freq[26]={0};

        if(s1.size()!=t1.size()) return false;

        for(char s: s1){
            freq[int(s-'a')]++;
        }

        for(char t: t1){
            if(freq[int(t-'a')]>0){
                  freq[int(t-'a')]--;
            }
            else{
                return false;
            }
          
        }

        return true;
    }
};