#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int f(int ind, int sum, int n, vector<int>&coins, vector<vector<int>>&dp){
    //base case
    if(sum==0) return 1;
    if(ind==0){
        if(sum%coins[0]==0) return 1;
        return 0;
    }

    if(dp[ind][sum]!=-1) return dp[ind][sum];

    int take = 0;
    if(coins[ind]<=sum) take = f(ind,sum-coins[ind],n,coins,dp)%MOD;

    int not_take = f(ind-1,sum,n,coins,dp)%MOD;

    return dp[ind][sum] = (take+not_take)%MOD;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int i=0; i<n; i++) cin>>coins[i];
    vector<vector<int>> dp(n,vector<int>(x+1,0));
    for(int i=0; i<n; i++) dp[i][0]=1;
    for(int t=1; t<=x; t++){
        if(t%coins[0]==0) dp[0][t]=1;
    }

    for(int i=1; i<n; i++){
        for(int t=1; t<=x; t++){
            int take = 0;
            if(coins[i]<=t) take = dp[i][t-coins[i]]%MOD;

            int not_take = dp[i-1][t]%MOD;
            dp[i][t] = (take+not_take)%MOD;
        }
    }

    cout<<dp[n-1][x]<<'\n';

    return 0;
}