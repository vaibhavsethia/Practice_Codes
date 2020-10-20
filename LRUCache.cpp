#include<bits/stdc++.h> 
using namespace std; 
  
int CountPageFaults(vector<int> Pages, int Capacity){ 
    unordered_set<int> S; 
    unordered_map<int, int> Indexes; 
    int Faults = 0, N = Pages.size();

    for (int i=0; i<N; i++){ 
        if (S.size() < Capacity){ 
            if (S.find(Pages[i]) == S.end()){ 
                S.insert(Pages[i]); 
                Faults++; 
            } 
            Indexes[Pages[i]] = i; 
        } else{ 
            if (S.find(Pages[i]) == S.end()){ 
                int LRU = INT_MAX, Val; 

                for (auto itr=S.begin(); itr!=S.end(); itr++){ 
                    if (Indexes[*itr] < LRU){ 
                        LRU = Indexes[*itr]; 
                        Val = *itr; 
                    } 
                } 

                S.erase(Val); 
                S.insert(Pages[i]); 
                Faults++; 
            } 
            Indexes[Pages[i]] = i; 
        } 
    } 
  
    return Faults; 
} 
  
int main() 
{ 
    vector<int> Pages{7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2}; 
    cout << CountPageFaults(Pages, 4); 
    return 0; 
} 