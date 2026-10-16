class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string,vector<string>> hashmap;

        vector<vector<string>> res;

        for(auto &s : strs){
            auto pre_sort = s;
            sort(s.begin(),s.end());
            hashmap[s].push_back(pre_sort);
        }

        for(auto item : hashmap){
            res.push_back(item.second);
        }

        return res;

    }
};
