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
int equilibriumPoint(long long a[], int n) {

if(n==1)
return 1;
    // Your code here
    long long sum=0;
    for(int i=0;i<n;i++)
    sum+=a[i];
    sum-=a[0];
    int flag=0;
    long long presum=a[0];
    for(int i=1;i<n;i++)
    {
        sum-=a[i];
        if(presum==sum)
        {
            flag=i;
            break;
        }
        presum+=a[i];
    }
    if(flag!=0)
    return flag+1;
    else
    {
        return -1;
    }
    

}
int main()
{
    SPEED;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    int n;
    cin>>n;
    ll a[n];
    rep(i,0,n)
    {
        cin>>a[i];
    }
    int ans=equilibriumPoint(a,n);
    cout<<ans;
    return 0;
}
