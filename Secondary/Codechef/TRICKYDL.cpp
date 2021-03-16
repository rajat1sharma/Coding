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
	ll b[64]={0};
	b[0]=1;
	rep(i,1,65)
	{
		b[i]=b[i-1]*2;
	}
	while(t--)
	{
		ll a;
		cin>>a;
		ll max=0;
		ll d1,d2;
		rep(i,0,64)
		{
			if(a*i-(ll)b[i]+1>0)
			{
				d1=i;
			}
			if(a*i-(ll)b[i]+1>max)
			{
				max=a*i-b[i]+1;
				d2=i;
			}
		}
		cout<<d1<<" "<<d2<<endl;
			
	}    
    return 0;
}