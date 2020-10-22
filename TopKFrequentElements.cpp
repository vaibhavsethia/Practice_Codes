class Solution {
public:
    static bool Comp(pair<int, int> A, pair<int, int> B){
        return A.second > B.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> Map;
        vector<pair<int, int>> A;
        
        for(int i=0; i<nums.size(); i++){
            Map[nums[i]]++;
        }
        
        for(auto itr = Map.begin(); itr != Map.end(); itr++){
            A.push_back(make_pair(itr->first, itr->second));
        }
        
        vector<int> Sol;
        sort(A.begin(), A.end(), Comp);
        
        for(int i=0; i<k; i++){
            Sol.push_back(A[i].first);
        }
        
        return Sol;
    }   
};