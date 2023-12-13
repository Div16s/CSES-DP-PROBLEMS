#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int f(int ind, int limit, vector<int>&a){
    //base case
    if(ind==0){
        if()
    }

    int ans=0;
    for(int i=1; i<=100; i++){
        if(a[ind]==0){
            if((ind-1)>=0 && a[ind-1]);
        }
    }
    

    return 0;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif

    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    cout<<f(n-1,m,a)<<'\n';

    
    return 0;
}