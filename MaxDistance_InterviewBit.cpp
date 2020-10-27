int Solution::maximumGap(const vector<int> &num) {
            if (num.size() == 0){
                return -1;
            }
            if (num.size() == 1){
                return 0;
            }
            
            vector<pair<int, int> > Nums; 
            for (int i = 0; i < num.size(); i++) {
                Nums.push_back(make_pair(num[i], i));
            }
            
            sort(Nums.begin(), Nums.end());
            
            int N = Nums.size();
            int maxIndex = Nums[N - 1].second;
            int ans = 0;
            
            for (int i = N - 2; i >= 0; i--) {
                ans = max(ans, maxIndex - Nums[i].second);
                maxIndex = max(maxIndex, Nums[i].second);
            }
            
            return ans;
        }