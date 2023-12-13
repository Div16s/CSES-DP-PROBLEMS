#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

// int f(int ind, int sum, int n, vector<int>&coins, vector<vector<int>>&dp){
//     //base case
//     if(ind>=n){
//         if(sum==0) return 1;
//         return 0;
//     }

//     if(sum==0) return 1;

//     if(dp[ind][sum]!=-1) return dp[ind][sum];

//     int take=0;
//     for(int i=0; i<n; i++){
//         if(sum-coins[i]>=0){
//             take = (take + f(i,sum-coins[i],n,coins,dp)%MOD)%MOD;
//         }
//         else break;
//     }

//     return dp[ind][sum]=take;
// }

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

    // sort(coins.begin(), coins.end());
    // vector<vector<int>> dp(n,vector<int>(x+1,-1));
    // cout<<f(n-1,x,n,coins,dp)<<'\n';

    vector<int> dp(x+1,0);

    //base case
    dp[0]=1;

    for(int target=1; target<=x; target++){ //O(x) number of states/subproblems
        for(int j=0; j<n; j++){ //O(n), trying out each coin
            if(coins[j]<=target){
                dp[target] = (dp[target]+dp[target-coins[j]])%MOD;
            }
        }
    }

    cout<<dp[x]%MOD<<'\n';

    return 0;
}