class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> Map; 
        vector<int> Sol; 
        
        for(int i=0; i<nums1.size(); i++){
            Map[nums1[i]]++;
        }     
        
        for(int i=0; i<nums2.size(); i++){
            if(Map.find(nums2[i]) != Map.end()){
                Sol.push_back(nums2[i]);
                Map.erase(nums2[i]);
            }
        }     
        
        return Sol;
    }
};