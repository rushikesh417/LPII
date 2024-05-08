#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstraj(int src, vector<pair<int, int>> adj[] ,int n)
{

    vector<int>ans(n ,INT_MAX);

    priority_queue<pair<int,int> ,vector<pair<int,int>> ,greater<pair<int,int>> >pq;

    pq.push({0 ,src});
    ans[src]=0;
   
    while(!pq.empty()){

        int val = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            int adjnode = it.first;
            int newDist = val + it.second;
            if (newDist < ans[adjnode])
            {
                ans[adjnode] = newDist;
                pq.push({newDist, adjnode});
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

    int src;cout<<"Enter the source node : ";cin>>src; 

    vector<int> ans = dijkstraj(src,adj, n);

    for(int i=0;i<ans.size();i++){
        cout<<"minimum distance from "<<src<<"th node to "<<i<<"th node is : "<<ans[i]<<endl;
    }

    return 0;
}

// Enter no.of nodes : 3 
// Enter no.of edges : 3 
// Enter the edges such that(src, dst, value) : 0 1 1 1 2 2 0 2 4
