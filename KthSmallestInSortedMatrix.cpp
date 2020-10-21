class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int minVal = matrix[0][0], maxVal = matrix[n-1][n-1];
        
        while(minVal <= maxVal){
            int mid = minVal + (maxVal - minVal)/2;
            int x = 0;
            for(int i = 0; i < n; i++){
                x += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if(x < k)minVal = mid + 1;
            else maxVal = mid - 1;
        }
        return minVal;
    }
};

class Solution {
    public:
        int kthSmallest(vector<vector<int>>& matrix, int k) {
            priority_queue<int> pq;
            
            for(int i = 0; i < matrix.size(); i++) {
                for(int j = 0; j < matrix[0].size(); j++) {
                    pq.push(matrix[i][j]);
                    if(pq.size() > k) {
                        pq.pop();
                    }
                }
            }
            return pq.top();

        }
};