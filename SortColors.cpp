class Solution {
public:
    void sortColors(vector<int>& nums) {
        int Zero = 0;
        int One = 0;
        int Two = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                Zero++;
            } else if(nums[i] == 1){
                One++;
            } else{
                Two++;
            }
        }
        
        int i = 0;
        
        for(int j=0; j<Zero; j++){
            nums[i++] = 0;
        }
        for(int j=0; j<One; j++){
            nums[i++] = 1;
        }
        for(int j=0; j<Two; j++){
            nums[i++] = 2;
        }
    }
};