#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int f(int sum, vector<int>&dp){
    //base case
    if(sum==0) return 1;
    if(sum<0) return 0;

    if(dp[sum]!=-1) return dp[sum];

    int ans=0;
    for(int i=1; i<=6; i++){
        if(i<=sum){
            ans = (ans + f(sum-i,dp)%MOD)%MOD;
        }
    }

    return dp[sum] = ans;
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
    vector<int> dp(n+1,-1);
    cout<<f(n,dp)<<'\n';

    return 0;
}