#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter no. of nodes : ";
    cin >> n;

    int e;
    cout << "Enter no. of edges : ";
    cin >> e;

    vector<pair<int,int>>adj[n];

    vector<pair<int,pair<int,int>>>vec;

    cout<<"Enter the edges such that (src , dst ,value) : "<<endl;
    for(int i=0;i<e;i++){

        int src,dst,value;cin>>src>>dst>>value;
        adj[src].push_back({dst ,value});
        adj[dst].push_back({src, value});
        vec.push_back({value , {src,dst}});

        vec.push_back({value, {dst, src}});
    }

    sort(vec.begin() ,vec.end());

    int ans=0;

    int cnt=0;

    vector<int>vis(n , 0);

    for(int i=0;i<vec.size();i++){
        if(cnt==n-1){
            break;
        }
        int src = vec[i].second.first;
        int dst = vec[i].second.second;
        int val = vec[i].first;
        if(vis[src]==0 || vis[dst]==0){
            ans+=val;
            cnt++;
            if(vis[src]==0){
                vis[src]++;
            }
            if (vis[dst] == 0)
            {
                vis[dst]++;
            }
        }
    }


    cout<<"minimum ans : "<<ans<<endl;

    return 0;
}

// Enter no.of nodes : 6 
// Enter no.of edges : 9 
// Enter the edges such that(src, dst, value) :
//  0 3 1 0 1 2 1 2 3 1 3 3 0 4 4 2 3 5 1 5 7 2 5 8 3 4 9

// 0 1 2 0 2 1 1 2 1 2 3 2 3 4 1 4 2 2