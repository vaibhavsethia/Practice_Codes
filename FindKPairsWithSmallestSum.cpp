class Solution {
public:
    static bool Comp(pair<int, int> A, pair<int, int> B){
        return (A.first + A.second < B.first + B.second);
    }
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> Sol;
        vector<pair<int, int>> Pairs;
        
        if(nums1.size() == 0 || nums2.size() == 0){
            return Sol;
        }
        
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                Pairs.push_back({nums1[i], nums2[j]});
            }
        }
        
        sort(Pairs.begin(), Pairs.end(), Comp);
        
        int N = Pairs.size()>k?k:Pairs.size();
        
        for(int i=0; i<N; i++){
            Sol.push_back({Pairs[i].first, Pairs[i].second});
        }
        
        return Sol;
    }
};