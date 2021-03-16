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
 		ll a[n];
 		ll sum=0;
 		rep(i,0,n)
 		{
 			cin>>a[i];
 			a[i]%=4;
 			sum+=a[i];
 		}
 		sort(a,a+n);
 		if(sum%4!=0)
 			cout<<-1<<endl;
 		else
 		{
			ll one=0,two=0,three=0;
 			rep(i,0,n)
 			{
 				if(a[i]==1)
 				one++;
 				if(a[i]==2)
 				two++;
 				if(a[i]==3)
 				three++;
 			}
			ll ans=one>three?three:one;
			ans+=abs(three-one);
			two=two-abs(three-one)/2;
			ans+=two/2;
			cout<<ans<<endl;
 		}
 	}   
    return 0;
}