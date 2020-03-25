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
 		if(n%2==0)
 		{
 			for(ll i=0;i<n;i+=2)
 				cout<<i+2<<" "<<i+1<<" ";
 			cout<<endl;
 		}
 		else
 		{
 			for(ll i=0;i<n-3;i+=2)
 			{
 				cout<<i+2<<" "<<i+1<<" ";
 			}
 			cout<<n-1<<" "<<n<<" "<<n-2<<endl;
 		}
 	}   
    return 0;
}