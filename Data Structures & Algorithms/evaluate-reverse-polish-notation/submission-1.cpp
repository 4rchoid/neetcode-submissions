class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        set<string> op_set{"+", "-", "*", "/"};
        vector<int> num_stack{};
        for(auto &str: tokens){
            if(!op_set.count(str)){
                num_stack.push_back(stoi(str));
            }
            else{
                auto op2 = num_stack.back();
                num_stack.pop_back();
                auto op1 = num_stack.back();
                num_stack.pop_back();
                int result{};
                if(str=="+"){
                    result = op1+op2;
                }
                if(str=="-"){
                    result = op1-op2;
                }
                if(str=="*"){
                    result = op1*op2;
                }
                if(str=="/"){
                    result = op1/op2;
                }
                num_stack.push_back(result);

            }
        }

        return num_stack.back();

    }

};
