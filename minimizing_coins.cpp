#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int f(int ind, int target, vector<int>&coins, vector<vector<int>>&dp){
    //base case
    if(target==0) return 0;
    if(ind==0){
        if(target%coins[ind]==0) return (target/coins[ind]);
        return 1e9;
    }

    if(dp[ind][target]!=-1) return dp[ind][target];

    int take = 1e9;
    if(coins[ind]<=target) take = 1 + f(ind,target-coins[ind],coins,dp);
    
    int not_take = f(ind-1,target,coins,dp);

    return dp[ind][target] = min(take,not_take);
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,target;
    cin>>n>>target;
    vector<int> coins(n);
    for(int i=0; i<n; i++) cin>>coins[i];

    vector<vector<int>> dp(n,vector<int>(target+1,0));
    // int ans = f(n-1,target,a,dp);
    // if(ans!=1000000000) cout<<ans<<'\n';
    // else cout<<-1<<'\n';

    //base case
    for(int i=0; i<n; i++) dp[i][0]=0;
    for(int t=0; t<=target; t++){
        if(t%coins[0]==0) dp[0][t]=t/coins[0];
        else dp[0][t]=1e9;
    }

    for(int i=1; i<n; i++){
        for(int t=1; t<=target; t++){
            int take = 1e9;
            if(coins[i]<=t) take = 1 + dp[i][t-coins[i]];
            
            int not_take = dp[i-1][t];

            dp[i][t] = min(take,not_take);
        }
    }

    if(dp[n-1][target]!=1e9) cout<<dp[n-1][target]<<'\n';
    else cout<<-1<<'\n';
    return 0;
}