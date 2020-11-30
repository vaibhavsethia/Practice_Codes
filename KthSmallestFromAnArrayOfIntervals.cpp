#include <bits/stdc++.h>
using namespace std;

int KthSmallestNum(pair<int, int> arr[], int n, int k)
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>> pq;
 
    for (int i = 0; i < n; i++) {
        pq.push({ arr[i].first, arr[i].second });
    } 

    int cnt = 1;
 
    while (cnt < k) {
        pair<int, int> interval = pq.top();
 
        pq.pop();

        if (interval.first < interval.second) {
            pq.push({ interval.first + 1, interval.second });
        }
 
        cnt++;
    }

    return pq.top().first;
}
 
int main()
{
    pair<int, int> arr[]
        = { { 5, 11 },
            { 10, 15 },
            { 12, 20 } };
 
    int n = sizeof(arr) / sizeof(arr[0]);
 
    int k = 12;
 
    cout << KthSmallestNum(arr, n, k);
}