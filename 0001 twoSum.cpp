class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    int len = nums.size();
    int need;
    std::multimap<int, int> hash;
    std::multimap<int, int>::iterator it;

    for (int i = 0; i < len; ++i) {
      hash.insert({nums[i], i});
    }

    for (int i = 0; i < len; ++i) {
      need = target - nums[i];
      it = hash.find(need);
      if (it != hash.end() && it->second != i) return {i, it->second};
    }

    return {0, 0};
  }
};