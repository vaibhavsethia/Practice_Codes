// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//        unordered_map<int, pair<int, vector<int>>> Map;
        
//         for(int i=0; i<nums.size(); i++){
//             if(Map.find(nums[i]) == Map.end()){
//                 vector<int> Temp{i};
//                 Map.insert(make_pair(nums[i], make_pair(1, Temp)));
//             } else{
//                 Map.find(nums[i])->second.second.push_back(i);
//             }
//         }
        
//         for(auto itr = Map.begin(); itr != Map.end(); itr++){
//             cout<<itr->first<<" : "<<itr->second.first<<", "<<itr->second.second[0]<<endl;
//         }
        
//         vector<int> Sol;
        
//         for(auto itr = Map.begin(); itr != Map.end(); itr++){
//             cout<<itr->first<<" "<<target - itr->first<<endl;
//             if(target == 2*itr->first && Map.find(itr->first)->second.second.size() > 1){
//                 Sol.push_back(Map.find(itr->first)->second.second[0]);
//                 Sol.push_back(Map.find(itr->first)->second.second[1]);
//             } else if(Map.find(target - itr->first) != Map.end()){
//                 Sol.push_back(itr->second.second[0]);
//                 Sol.push_back(Map.find(target - itr->first)->second.second[0]);
//                 break;
//             }
//         }
        
//         return Sol;
//     }
// };