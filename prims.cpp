#include <bits/stdc++.h>
using namespace std;

int prims(vector<pair<int, int>> adj[], int n)
{

    int ans=0;
    vector<int>vis(n,0);
    priority_queue<pair<int,int> ,vector<pair<int,int>> ,greater<pair<int,int>> >pq;
         // val,node
    pq.push({0 , 0});

    while(!pq.empty()){

        int val = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(vis[node]>0){
            continue;
        }

        vis[node]++;
        ans+=val;

        for(auto it:adj[node]){

            int dst = it.first;
            int vall = it.second;

            if(vis[dst]==0){
                pq.push({vall ,dst});
            }
        }
    }

    return ans;
    
    
}

int main()
{
    int n;
    cout << "Enter no. of nodes : ";
    cin >> n;

    int e;
    cout << "Enter no. of edges : ";
    cin >> e;

    vector<pair<int, int>> adj[n];

    cout << "Enter the edges such that (src , dst ,value) : " << endl;
    for (int i = 0; i < e; i++)
    {
        int src, dst, value;
        cin >> src >> dst >> value;
        adj[src].push_back({dst, value});
        adj[dst].push_back({src, value});
    }

    int ans = prims(adj, n);

    cout << "minimum sum : " << ans << endl;

    return 0;
}

// Enter no.of nodes : 6
// Enter no.of edges : 9
// Enter the edges such that(src, dst, value) :
//  0 3 1 0 1 2 1 2 3 1 3 3 0 4 4 2 3 5 1 5 7 2 5 8 3 4 9

// Enter no.of nodes : 5
// Enter no.of edges : 6
// 0 1 2 0 2 1 1 2 1 2 3 2 3 4 1 4 2 2
