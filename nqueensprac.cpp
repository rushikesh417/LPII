#include <bits/stdc++.h>
using namespace std;

bool isOk(int row, int col, vector<string> &board)
{
    for (int i = 0; i < row; ++i)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }

    
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

 
    for (int i = row, j = col; i >= 0 && j < board.size(); --i, ++j)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    return true;
}

void solve(int row, int n, vector<string> &board, vector<vector<string>> &ans)
{
    if (row == n)
    {
        ans.push_back(board);
        return;
    }

    for (int col = 0; col < n; ++col)
    {
        if (isOk(row, col, board))
        {
            board[row][col] = 'Q';
            solve(row+1 ,n ,board, ans);
            board[row][col] = '.';
        }
    }
}


bool isOkBB(int row, int col ,vector<int>&cols){

    for(int i=0;i<row;i++){
        if(cols[i] == col || abs(i-row) == abs(cols[i]-col) ){
            return false;
        }
    }
    return true;
}

void solveBB(int row ,int n, vector<int>&cols ,vector<vector<int>>&ans1){

    if (row == n)
    {
        ans1.push_back(cols);
        return;
    }

    for (int col = 0; col < n; ++col)
    {
        if(isOkBB(row, col ,cols)){
            cols[row]=col;
            solveBB(row+1 , n ,cols, ans1);
        }
    }
}

int main()
{
    int n;
    cout << "Enter size of grid: ";
    cin >> n;


    //-----------------------------------------------------
    // solution by backtracking.....

    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    solve(0, n, board, ans);

    cout<<endl;
    cout<<"Sloution by backtracking...."<<endl;
    cout << "Number of solutions : " << ans.size() << endl;
    for (auto &it : ans)
    {
        for (auto &row : it)
        {
            for(auto i:row){
                cout<<i<<" ";
            }
            cout<< endl;
        }
        cout << endl;
    }


    //-----------------------------------------------------
    // solution by branch and  bound..........

    vector<vector<int>>ans1;
    vector<int>v(n,-1);
    solveBB( 0 , n ,v, ans1);

    cout << endl;
    cout << "Sloution by Branch and bound...." << endl;
    cout << "Number of solutions : " << ans.size() << endl;
    for(auto it:ans1){
        for(int row=0 ;row<it.size() ;row++){
            for(int col=0;col<it.size() ;col++){
                if(it[row] == col){
                    cout<<"Q ";
                }
                else{
                    cout<<". ";
                }
            }
            cout<<endl;
        }
        cout<<endl;
    }

    return 0;
}
