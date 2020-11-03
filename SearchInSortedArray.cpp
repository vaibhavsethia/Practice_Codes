class Solution {
public:
    int GCD(int A, int B){
        if(B == 0){
            return A;
        } else{
            return GCD(B, A % B);
        }
    }
    
    void Rotate(vector<pair<int, int>>& A, int N, int D){
        D = D % N;
        
        for (int i = 0; i < GCD(D, N); i++) { 
            int Temp1 = A[i].first; 
            int Temp2 = A[i].second; 
            int j = i; 

            while (1) { 
                int k = j + D; 
                if (k >= N) 
                    k = k - N; 

                if (k == i) 
                    break; 

                A[j].first = A[k].first; 
                A[j].second = A[k].second; 
                j = k; 
            } 
            A[j].first = Temp1; 
            A[j].second = Temp2; 
        } 
    }
    
    int search(vector<int>& nums, int target) {     
        if(nums.size() == 0){
            return -1;
        }
        
        vector<pair<int, int>> A;
        for(int i=0; i<nums.size(); i++){
            A.push_back({nums[i], i});
        }
        
        int pivot = 0;
        
        for(; pivot<nums.size()-1; pivot++){
            if(nums[pivot] > nums[pivot+1]){
                break;
            }
        }
        
        Rotate(A, A.size(), pivot+1);  
        
        int start = 0, end = nums.size() - 1;
        
        while(start <= end){
            int mid = (start + end)/2;
            
            if(A[mid].first == target){
                return A[mid].second;
            } else if(A[mid].first > target){
                end = mid - 1;
            } else{
                start = mid + 1;
            }
        }
        
        return -1;
    }
};