class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0){
            return false;
        }
        
        int m = matrix.size(), n = matrix[0].size();
        
        if (target < matrix[0][0] || target > matrix[m-1][n-1]){
            return false;
        }
        
        int l = 0, r = m * n -1;
        
        while (l <= r)
        {
            int mid = (l + r)/2;
            int x = mid / n;
            int y = mid % n;
            if (matrix[x][y] == target){
                return true;
            }else if (matrix[x][y] > target){
                r = mid -1;
            }else{
                l = mid + 1;
            }
        }
        return matrix[l/n][l%n] == target;
    }
};