class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> Sol;
        sort(nums.begin(),nums.end());

        set<vector<int>> s;
        set<int> elements;
        
        for(int i=0;i<nums.size();i++){
            int a=nums[i];        

            if(elements.find(a)!=elements.end())
                continue;
            elements.insert(a);

            int low=i+1, high=nums.size()-1;

            while(low<high){
                int sum=a+nums[low]+nums[high];
                if(sum==0){
                    vector<int>ans;

                    ans.push_back(a);
                    ans.push_back(nums[low]);
                    ans.push_back(nums[high]);

                    if(s.find(ans)==s.end())
                    {   
                        Sol.push_back(ans);
                        s.insert(ans);
                    }
                    
                    low++;
                    high--;
                }
                else if(sum>0){
                    high--;
                }
                else
                    low++;
            }
        }
        return Sol;
    }
};