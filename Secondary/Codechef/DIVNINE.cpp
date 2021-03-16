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
 		string s;
 		cin>>s;
 		ll sum=0;
 		{
	 		rep(i,0,s.length())
	 			sum+=(s[i]-'0');
	 		if(sum<=4&&s.length()!=1)
	 			cout<<9-sum<<endl;
	 		else{
	 		ll ans=sum%9>4?9-sum%9:sum%9;
	 		cout<<ans<<endl;}
 		}
 	}   
    return 0;
}