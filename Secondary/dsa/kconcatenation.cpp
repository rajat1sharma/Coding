#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define re(i,n) for(ll i = 0 ; i < n ; ++i)
#define ree(n) for(ll i = 0 ; i < n ; i++)
#define rep(i , j , n) for(ll i = j ; i < n ; i++)
#define per(i , j , n) for(ll i = j ; i >= n ; i--)
#define mod 1000000007
ll kadane(ll a[],ll n)
{
    ll cur=a[0],gl=a[0];
    rep(i,1,n)
    {
        if(cur+a[i]>a[i])
        {
            cur=cur+a[i];
        }
        else
        {
            cur=a[i];
        }
        if(cur>gl)
        gl=cur;
        
    }
    return gl;
}
int main()
{
    SPEED;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,k;
        cin>>n>>k;
        ll a[n];
        rep(i,0,n)
        cin>>a[i];
        ll sum=0;
        rep(i,0,n)
        sum+=a[i];
        if(k==1)
        
            cout<<kadane(a,n)<<endl;
        
        else
        {
            ll a1[2*n];
            rep(i,0,n)
            {a1[i]=a[i];
            a1[n+i]=a[i];}
            if (sum < 0)
            
                cout<<kadane(a1,2*n)<<endl;
            
            else
            
                cout<<kadane(a1,2*n)+(k-2)*sum<<endl;
        }
        
        
    }
    
    return 0;
}
