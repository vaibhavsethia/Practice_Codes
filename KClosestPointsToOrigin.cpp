class Solution {
public:
    static bool Comp(const vector<int> A, const vector<int> B){
        int Dist1 = A[0]*A[0] + A[1]*A[1];
        int Dist2 = B[0]*B[0] + B[1]*B[1];
        
        return Dist1 < Dist2;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), Comp);
        
        vector<vector<int>> Sol;
        
        for(int i=0; i<K; i++){
            Sol.push_back(points[i]);
        }
        
        return Sol;
    }
};