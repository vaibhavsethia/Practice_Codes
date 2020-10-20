class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> Version1, Version2;
        int Num = 0;

        for(int i=0; i<version1.length(); i++){
          if(version1[i] == '.'){
                Version1.push_back(Num);
                Num = 0;
            }else{
                Num = Num*10 + (version1[i] - '0');
            }
        }
        Version1.push_back(Num);
        Num = 0;

        for(int i=0; i<version2.length(); i++){
          if(version2[i] == '.'){
                Version2.push_back(Num);
                Num = 0;
            }else{
                Num = Num*10 + (version2[i] - '0');
            }
        }
        Version2.push_back(Num);

        int N = Version1.size() - 1;
        int M = Version2.size() - 1;

        while(N >= 0 && Version1[N] == 0){
          N--;
        }
        while(M >= 0 && Version2[M] == 0){
          M--;
        }

        for(int i = 0; i <= min(N, M); i++){
            if(Version1[i] == Version2[i]){
              continue;
            }
            if(Version1[i] > Version2[i]){
                return 1;
            }
            if(Version1[i] < Version2[i]){
              return -1;
            }
        }
        
        if(N == M){
          return 0;
        }
        if(N < M){
          return -1;
        }
        return 1;
    }
};