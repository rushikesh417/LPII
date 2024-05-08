#include <bits/stdc++.h>
using namespace std;

int heu(vector<vector<int>> &state, vector<vector<int>> &grid, int level)
{
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (state[i][j] != grid[i][j])
                count++;
        }
    }
    return count + level;
}

int main()
{
    vector<vector<int>> start(3, vector<int>(3));
    vector<vector<int>> end(3, vector<int>(3));
    vector<vector<vector<int>>> all;

    vector<int> temp = {-1, 1, 2, 3, 4, 5, 6, 7, 8};

    do
    {
        vector<vector<int>> tempx(3, vector<int>(3));
        for (int i = 0; i < 9; i++)
        {
            tempx[i / 3][i % 3] = temp[i];
        }
        all.push_back(tempx);
    } while (next_permutation(temp.begin(), temp.end()));
    // for (auto it : all){
    //     for (auto it1 : it){
    //         for (auto i : it1) cout<<i<<" ";
    //         cout<<endl;
    //     }
    // }

    map<vector<vector<int>>, int> mp;

    for (int i = 0; i < all.size(); i++)
        mp[all[i]] = i;
    vector<int> visited(all.size(), 0);

    cout << all.size() << " " << mp.size() << " " << visited.size() << endl;

    cout << "start state" << endl;
    for (auto &it : start)
    {
        for (auto &i : it)
            cin >> i;
    }
    cout << "end state" << endl;
    for (auto &it : end)
    {
        for (auto &i : it)
            cin >> i;
    }
    cout << endl;

    priority_queue<pair<int, pair<int, vector<vector<int>>>>, vector<pair<int, pair<int, vector<vector<int>>>>>, greater<pair<int, pair<int, vector<vector<int>>>>>> pq;
    pq.push({heu(start, end, 0), {0, start}});
    visited[mp[start]] = 1;

    while (!pq.empty())
    {
        // cout<<endl;
        // cout<<"selected operation"<<endl;
        int val = pq.top().first;
        int level = pq.top().second.first;
        vector<vector<int>> state = pq.top().second.second;
        pq.pop();
        // for (auto it :state){
        //     for (auto i : it) cout<<i<<" ";
        //     cout<<endl;
        // }
        // cout<<"evualtion function "<<val<<endl;
        // cout<<"heuritistic value :"<<val-level<<endl;
        // cout<<"level : "<<level<<endl;
        // cout<<endl;
        if (state == end)
        {
            cout << "final state is reached" << endl;
            break;
        }
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        // cout<<"possible moves"<<endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (state[i][j] == -1)
                {
                    for (int a = 0; a < 4; a++)
                    {
                        int ni = i + delrow[a];
                        int nj = j + delcol[a];

                        if (ni >= 0 && ni < 3 && nj >= 0 && nj < 3)
                        {
                            vector<vector<int>> temp = state;
                            swap(temp[i][j], temp[ni][nj]);
                            if (visited[mp[temp]])
                                continue;
                            pq.push({heu(temp, end, level + 1), {level + 1, temp}});
                            visited[mp[temp]] = 1;
                            // for (auto it : temp){
                            //     for (auto i : it) cout<<i<<" ";
                            //     cout<<endl;
                            // }
                            // cout<<"evualtion function "<<heu(temp,end,level+1)<<endl;
                            // cout<<"heuritistic value :"<<heu(temp,end,level+1)-level-1<<endl;
                            // cout<<"level : "<<level+1<<endl;
                            // cout<<endl;
                        }
                    }
                }
            }
        }
    }
    cout << "end of possible moves you are not reached" << endl;
}