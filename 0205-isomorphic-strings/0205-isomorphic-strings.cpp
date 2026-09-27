class Solution {
public:
    bool isIsomorphic(string s, string t) { 
        int n= s.length(); 
        unordered_map <char, char> mp;

        for(int i=0; i<n; i++){
            if( mp.find(s[i]) == mp.end() ){
                mp[s[i]] = t[i];
                for(int j=0; j<i; j++){
                    if( mp[s[j]] == t[i] ) return false;
                }
            }
            else if( mp[s[i]] == t[i]  ){
                continue;
            }
            else{
                return false;
            }
        }

        return true;
    }
};