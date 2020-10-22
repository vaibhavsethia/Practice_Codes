vector<int> MergeKArrays(vector<vector<int>> A) { 
    vector<int> Sol; 
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > Heap; 
  
    for (int i = 0; i < A.size(); i++) 
        Heap.push({ A[i][0], { i, 0 } }); 

    while (Heap.empty() == false) { 
        pair<int, pair<int, int>> Curr = Heap.top(); 
        Heap.pop(); 

        int i = Curr.second.first; 
        int j = Curr.second.second; 
  
        Sol.push_back(Curr.first); 

        if (j + 1 < A[i].size()) 
            Heap.push({ A[i][j + 1], { i, j + 1 } }); 
    } 
  
    return Sol; 
} 