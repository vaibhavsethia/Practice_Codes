class Solution {
    void getPermutation(vector<int>& cur, vector<int>& nums, vector<vector<int>> &result) {
        if (0 == nums.size()) {
            result.push_back(cur);
        } else {
            for (int i = 0; i < nums.size(); i++) {
                int cur_num = nums[i];
                cur.push_back(cur_num);
                nums.erase(nums.begin() + i);
                
                getPermutation(cur, nums, result);
                
                nums.insert(nums.begin() + i, cur_num);
                cur.pop_back();
                
            }
            
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur;
        getPermutation(cur, nums, result);
        
        return result;
    }
};


