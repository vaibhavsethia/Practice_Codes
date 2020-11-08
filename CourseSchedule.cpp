class Solution {
public:
    vector<bool> Running;
    vector<bool> Visited;
    vector<vector<int>> Adj;    
    
    bool canFinish(int NumCourses, vector<vector<int>>& Pre) {
        Adj = vector<vector<int>>(NumCourses);
        Visited= vector<bool>(NumCourses, false);
        Running = vector<bool>(NumCourses, false);
        
        for(int i=0; i<Pre.size(); i++){
            Adj[Pre[i][0]].push_back(Pre[i][1]);
        }
        
        for(int i = 0 ; i<NumCourses; i++){
            if(!Visited[i]){                
                if(detect(i)){
                    return false;
                }              
            }
            
        }
        
        return true;
        
    }
    
    bool detect(int i){
        Visited[i] = true;
        Running[i] = true;
                
        for(int j: Adj[i]){
            if(!Visited[j]){
                if(detect(j)){
                    return true;
                }
            } else{
                if(Running[j]){
                    return true;
                }
            }
        }
        
        Running[i] = false;        
        return false;
    } 
};