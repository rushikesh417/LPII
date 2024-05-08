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

    priority_queue < pair<int,pair<int,vector<vector<int>>>


    return 0;

}