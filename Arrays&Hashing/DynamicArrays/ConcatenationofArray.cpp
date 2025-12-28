// URL : https://neetcode.io/problems/concatenation-of-array/question?list=neetcode150

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(size*2);
        for(int i = 0; i < size; i++)
        {
          ans[i] = nums[i];
          ans[i+size] = nums[i];
        }
        return ans;
    }
};