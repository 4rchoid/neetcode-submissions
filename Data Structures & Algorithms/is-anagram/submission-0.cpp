class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }
        unordered_map<char, int> mp_1;
        unordered_map<char, int> mp_2;

        for (int i = 0; i < s.size(); i++){
            if (mp_1.count(s[i])){
                auto val_1 = mp_1[s[i]];
                mp_1[s[i]] = val_1 + 1;
            }
            else{
                mp_1[s[i]] = 1;
            }

            if (mp_2.count(t[i])){
                auto val_2 = mp_2[t[i]];
                mp_2[t[i]] = val_2 + 1;
            }
            else{
                mp_2[t[i]] = 1;
            }
        }

        for(auto& [key,value]: mp_1){
            if (mp_1[key]!= mp_2[key]){
                return false;
            }
        }
        return true;

    }
};
