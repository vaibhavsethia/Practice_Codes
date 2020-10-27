vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    vector<int> Sol;
    
    int Rows = A.size();
    int Cols = A[0].size();
    int Top = 0;
    int Bottom = Rows-1;
    int Left = 0;
    int Right = Cols-1;
    int Dir = 0; 
    
    while(Top <= Bottom && Left <= Right){
        if(Dir == 0){
            for(int j = Left; j <= Right; j++){
                Sol.push_back(A[Top][j]);
            }

            Dir = 1;
            Top++;
            continue;
        } else if(Dir == 1){
            for(int i = Top; i <= Bottom; i++){
                Sol.push_back(A[i][Right]);
            }

            Right--;
            Dir = 2;
            continue;
        } else if(Dir == 2){
            for(int j = Right; j >= Left; j--){
                Sol.push_back(A[Bottom][j]);
            }
            
            Bottom--;
            Dir = 3;
            continue;
        } else if(Dir == 3){
            for(int i = Bottom; i >= Top; i--){
                Sol.push_back(A[i][Left]);
            }

            Left++;
            Dir = 0;
            continue;
        }
    }
    
    return Sol;
}