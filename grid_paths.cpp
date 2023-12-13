#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int f(int r, int c, int n, vector<vector<char>> &grid, vector<vector<int>>&dp){
    //base case
    if(r==0 && c==0 && grid[r][c]!='*'){
        return 1;
    }
    if(grid[r][c]=='*') return 0;
    if(dp[r][c]!=-1) return dp[r][c];

    //going left
    int left = 0;
    if(c-1>=0) left = f(r,c-1,n,grid,dp)%MOD;

    //going up
    int up = 0;
    if(r-1>=0) up = f(r-1,c,n,grid,dp)%MOD;

    return dp[r][c] = (left+up)%MOD;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<vector<char>> grid(n,vector<char>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<f(n-1,n-1,n,grid,dp)<<'\n';
    return 0;
}