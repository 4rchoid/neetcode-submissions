class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> pre;
        vector<int> post;
        int product = 1;
        int post_product = 1;
        for (int i = 0; i < nums.size(); i++){
            product *= nums[i];
            pre.push_back(product);
            post_product *= nums[nums.size()-1-i];
            post.insert(post.begin(),post_product);
        }
        
        vector<int> res;

        for (int i = 0; i < nums.size(); i++){

            if(i==0){
                res.push_back(post[i+1]);
            }else if (i==nums.size()-1){
                res.push_back(pre[i-1]);
            }else{
                res.push_back(post[i+1]*pre[i-1]);
        }


    }
            return res;

    }
};
