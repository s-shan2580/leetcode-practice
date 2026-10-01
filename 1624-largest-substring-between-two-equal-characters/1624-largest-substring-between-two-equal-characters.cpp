class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {

        unordered_map<char, pair<int, int>> mp;

        for(int i=0; i<s.length(); i++){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]]={i,i};
            }
            else{
                mp[s[i]].second = i;
            }
        }
        
        int count=-1;

        for(auto const& [key, val] : mp){
            if((val.second - val.first - 1) > count){
                count = (val.second - val.first - 1);
            }
        }

         return count;
    }
};