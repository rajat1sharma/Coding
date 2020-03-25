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
 		string f,ba,l,r,t,b;
 		cin>>f>>ba>>l>>r>>t>>b;

 		if((l==f&&f==b)||(f==r&&r==b)||(r==ba&&ba==b)||(ba==l)&&(l==b)||(l==f&&f==t)||(f==r&&r==t)||(r==ba&&ba==t)||(ba==l)&&(l==t))
 			cout<<"YES"<<endl;
 		else
 			cout<<"NO"<<endl;
 	}   
    return 0;
}