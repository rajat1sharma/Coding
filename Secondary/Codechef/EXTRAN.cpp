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
 	ll t ;
 	cin>>t;
 	while(t--)
 	{
 		ll n;
 		cin>>n;
 		ll a[n];
 		rep(i,0,n)
 		cin>>a[i];
 		sort(a,a+n);
 		rep(i,0,n-1)
 		if(a[i]-a[i+1]!=-1)
 		{
 			if(i==n-2)
 				cout<<a[i+1];
 			else
 				cout<<a[i];
 			break;
 		}
 		cout<<endl;
 	}   
    return 0;
}