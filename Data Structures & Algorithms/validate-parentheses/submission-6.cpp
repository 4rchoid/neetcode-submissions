class Solution {
public:
    bool isValid(string s) {
        set<char> pre{'(','{','['};
        set<char> post{')','}',']'};
        unordered_map<char, char> charMap = {
            {')','('},
            {'}','{'},
            {']','['},
        };        
        vector<char> stack{};

        for(int i=0;i<s.size();i++){
            if (pre.count(s[i])){
                stack.push_back(s[i]);
            }
            else if (post.count(s[i])&&stack.size()>0){
                auto last = stack.back();
                if(charMap[s[i]]==last){
                    stack.pop_back();
                }else{
                    return false;
                }
            }else{
                return false;
            }
        } 
        if(stack.size()==0){
            return true;
        }
        return false;
    }
};
