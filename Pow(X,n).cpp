class Solution {
public:
    double myPow(double x, int N) {
        long long int n = N;
        
        if (n==0 || x == 1){
            return 1;
        }
        
        if(n<0){
            x = 1/x;
            n = -n;
        }
        
        double val = pow(x, n/2);
        
        double ret;
        if (n%2 == 0) {
            ret = val*val;
        } else {
            ret = val*val*x;
        }
        return ret;
    }
};

