#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

//Top-down Memoization
// int f(int ind, int x, int n, vector<int>&pages, vector<int>&price, vector<vector<int>> &dp){
//     //base case
//     if(x==0) return 0;
//     if(ind==0){
//         if(price[ind]<=x) return pages[ind];
//         return 0;
//     }

//     if(dp[ind][x]!=-1) return dp[ind][x];

//     int take = 0;
//     if(price[ind]<=x) take = pages[ind]+f(ind-1,x-price[ind],n,pages,price,dp);

//     int not_take = f(ind-1,x,n,pages,price,dp);

//     return dp[ind][x] = max(take,not_take);
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
    vector<int> price(n),pages(n);
    for(int i=0; i<n; i++) cin>>price[i];
    for(int i=0; i<n; i++) cin>>pages[i];

    //bottom-up Tabulation
    vector<vector<int>> dp(n,vector<int>(x+1,0));

    //base case
    for(int i=0; i<n; i++) dp[i][0]=0;
    for(int tp=0; tp<=x; tp++){
        if(price[0]<=tp) dp[0][tp]=pages[0];
        else dp[0][tp]=0;
    }

    for(int ind=1; ind<n; ind++){
        for(int tp=1; tp<=x; tp++){
            int take = 0;
            if(price[ind]<=tp) take = pages[ind]+dp[ind-1][tp-price[ind]];

            int not_take = dp[ind-1][tp];

            dp[ind][tp] = max(take,not_take);
        }
    }

    //cout<<f(n-1,x,n,pages,price,dp)<<'\n';
    cout<<dp[n-1][x]<<'\n';
    return 0;
}