class Solution {
public:
    string findcommon(string s1, string s2){
        int n= s1.length();
        int m= s2.length();
        int i=0, j=0;
        string ans= "";

        while(i<n || j<m){
            if(s1[i]==s2[j]){
                ans.push_back(s1[i]);
                i++;
                j++;
            }
            else{
                break;
            }
        }

        if(!ans.empty()) return ans;
        else return "";
    }

    string longestCommonPrefix(vector<string>& strs) {
        int n= strs.size();

        if(n==1) return strs[0];

        if(n==2) return findcommon(strs[0], strs[1]);

        int i= 2;

        string ans = findcommon(strs[0], strs[1]);
        
        while(i<n){
            ans = findcommon(ans, strs[i]);
            if(ans=="") return "";

            else{
                i++;
            }
        }

        return ans;
    }
};