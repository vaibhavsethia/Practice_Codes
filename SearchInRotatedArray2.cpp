class Solution {
public:
    int GCD(int A, int B){
        if(B == 0){
            return A;
        } else{
            return GCD(B, A % B);
        }
    }
    
    void Rotate(vector<int>& A, int N, int D){
        D = D % N;
        
        for (int i = 0; i < GCD(D, N); i++) { 
            int Temp = A[i]; 
            int j = i; 

            while (1) { 
                int k = j + D; 
                if (k >= N) 
                    k = k - N; 

                if (k == i) 
                    break; 

                A[j] = A[k]; 
                j = k; 
            } 
            A[j] = Temp; 
        } 
    }
    
    bool search(vector<int>& nums, int target) {     
        if(nums.size() == 0){
            return false;
        }
        int pivot = 0;
        
        for(; pivot<nums.size()-1; pivot++){
            if(nums[pivot] > nums[pivot+1]){
                break;
            }
        }
        
        Rotate(nums, nums.size(), pivot+1);  
        
        int start = 0, end = nums.size() - 1;
        
        while(start <= end){
            int mid = (start + end)/2;
            
            if(nums[mid] == target){
                return true;
            } else if(nums[mid] > target){
                end = mid - 1;
            } else{
                start = mid + 1;
            }
        }
        
        return false;
    }
};