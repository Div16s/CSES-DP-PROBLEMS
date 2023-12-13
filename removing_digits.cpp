#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int f(int num, vector<int> &dp){
    //base case
    if(num==0) return 0;
    if(num<0) return 1e9;

    if(dp[num]!=-1) return dp[num];

    string str = to_string(num);
    int ans = 1e9;
    for(int i=0; i<str.size(); i++){
        if((str[i]-'0')!=0){
            ans = min(ans, 1+f(num-(str[i]-'0'),dp));
        }
    }

    return dp[num] = ans;
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