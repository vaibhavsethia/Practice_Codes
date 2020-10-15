/*You are required to complete this function*/
vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
    vector<vector<int>> Sol;
    
    map<int, int> Map;
    vector<int> Temp;
    
    for(int i=0; i<row; i++){
        Temp.clear();
        int Val = 0;
        
        for(int j=0; j<col; j++){
            if(M[i][j] == 1){
                Val += pow(2,j);
            }
            Temp.push_back(M[i][j]);
        }
        
        if(Map.find(Val) == Map.end()){
            Sol.push_back(Temp);
            Map[Val]++;
        }
    }
    
    return Sol;
}