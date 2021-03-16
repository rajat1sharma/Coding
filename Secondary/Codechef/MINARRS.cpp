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
/*
#ifndef ONLINE_JUDGE
    freopen("input22.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
*/
int main()
{
    SPEED;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
 	ll t;
 	cin>>t;
 	while(t--)
 	{
 		ll n;
 		cin>>n;
 		ll a[n],a1[n];
 		rep(i,0,n)
 		cin>>a1[i];
 		rep(i,0,n)
 		a[i]=a1[i];
 		ll ans=0;
 		rep(j,0,64)
 		{
 			ll f=0;
 			rep(i,0,n)
 			{
 				ll h=a[i]&1;
 				if(h==1)
 					f++;
 				a[i]=a[i]>>1;
 			}
 			
 			if(f>n/2)
 				ans+=pow(2,j);
 		}
 		ll sum=0;
 		rep(i,0,n)
 		sum+=(a1[i]^ans);
 		cout<<sum<<endl;
 	}   
    return 0;
}


