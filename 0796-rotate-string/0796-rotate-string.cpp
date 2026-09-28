class Solution {
public:
    bool rotateString(string s, string t) {

        int n = s.length();
        int i = 0;
        
        if(s.length() != t.length()) return false;

        while(i<n){
            string temp = s.substr(1) + s[0];
            if(temp == t) return true;
            else{
                s = temp;
                i++;
            }
        }

        return false;
    }
};