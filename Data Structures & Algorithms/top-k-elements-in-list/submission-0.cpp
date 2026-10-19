class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    map<int, vector<int>> bucket;
    map<int, int> freq;

    for (int i = 0; i < nums.size(); i++) {
      if (freq.count(nums[i])) {
        freq[nums[i]] += 1;
      } else {
        freq[nums[i]] = 1;
      }
    }

    for (auto &item : freq) {
      bucket[item.second].push_back(item.first);
    }
    vector<int> found;
    for (int i = 0; i < nums.size(); i++) {
      auto appear_count = nums.size() - i;
      if (bucket.count(appear_count)) {
        auto arr = bucket[appear_count];
        for (int &index : arr) {
          if (found.size()== k) {
            break;
          }else {
            found.push_back(index);
          }
        }
      }
    }

    return found;
  }
};

