class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> hashmap;
        //getting the hashmap
        for(int i ; i <nums.size();i++){
            if (!hashmap.count(nums[i])){
                hashmap[nums[i]] = i;
            }
        }
        for(int i ; i < nums.size();i++){
            int compliment = target-nums[i];
            if (hashmap.count(compliment) && hashmap[compliment]!= i ){
                if (i > hashmap[target-nums[i]]){
                    vector<int> solution = {hashmap[target-nums[i]],i};
                    return solution;
                }
                vector<int> solution = {i,hashmap[target-nums[i]]};
                return solution;
            }
        }
    }
};
