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
int main()
{
    SPEED;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
    ll n;
    cin>>n;
    ll a[n];
    rep(i,0,n)
    cin>>a[i];
    //taking this when all the numbers in the array are negative
    ll curr_best=a[0],over_all=a[0];    
    
    rep(i,1,n)
    {
        if(a[i]+curr_best>a[i])
        {
            curr_best+=a[i];
        }
        else
        {
            curr_best=a[i];
        }
        if(curr_best>over_all)
        over_all=curr_best;

        /* 
        also can be written as
        curr_best=max(curr_best+a[i],a[i]);
        over_all=max(voer_all,curr_best);
        */
    }
    cout<<over_all<<endl;
    return 0;
}



