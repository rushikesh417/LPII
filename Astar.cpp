#include <bits/stdc++.h>
using namespace std;

int heu(vector<vector<int>> &state, vector<vector<int>> &grid, int level)
{
    int count = 0;

    for (int i = 0; i < state.size(); i++)
    {
        for (int j = 0; j < state.size(); j++)
        {
            if (state[i][j] != grid[i][j] && state[i][j] != -1)
                count++;
        }
    }
    return count + level;
}

int main()
{
    cout << "Enter the value of n: ";
    int n;
    cin >> n;
    vector<vector<int>> start(n, vector<int>(n));
    vector<vector<int>> end(n, vector<int>(n));
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

    priority_queue<pair<int, pair<int, vector<vector<int>>>>, vector<pair<int, pair<int, vector<vector<int>>>>>, greater<pair<int, pair<int, vector<vector<int>>>>>> pq;
    pq.push({heu(start, end, 0), {0, start}});

    while (!pq.empty())
    {
        cout << "selected operation" << endl;
        int val = pq.top().first;
        int level = pq.top().second.first;
        vector<vector<int>> state = pq.top().second.second;
        pq.pop();
        for (auto it : state)
        {
            for (auto i : it)
                cout << i << " ";
            cout << endl;
        }
        cout << "level : " << level << endl;
        cout << "heuritistic value :" << val - level << endl;

        cout << "evualtion function " << val << endl;
        cout << endl;
        if (state == end)
        {
            cout << "final state is reached" << endl;
            break;
        }
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        cout << "possible moves" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (state[i][j] == -1)
                {
                    for (int a = 0; a < 4; a++)
                    {
                        int ni = i + delrow[a];
                        int nj = j + delcol[a];

                        if (ni >= 0 && ni < n && nj >= 0 && nj < n)
                        {
                            vector<vector<int>> temp = state;
                            swap(temp[i][j], temp[ni][nj]);
                            pq.push({heu(temp, end, level + 1), {level + 1, temp}});
                            for (auto it : temp)
                            {
                                for (auto i : it)
                                    cout << i << " ";
                                cout << endl;
                            }
                            cout << "level : " << level + 1 << endl;
                            cout << "heuritistic value :" << heu(temp, end, level + 1) - level - 1 << endl; 
                            cout << "evualtion function " << heu(temp, end, level + 1) << endl;
                            cout << endl;
                        }
                    }
                }
            }
        }
    }
}