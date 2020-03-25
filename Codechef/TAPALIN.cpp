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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
*/
ll power(ll x, unsigned ll y, ll p)  
{  
    ll res = 1;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
    while (y > 0)  
    {  
        if (y & 1)  
            res = (res*x) % p;  
        y = y>>1; // y = y/2  
        x = (x*x) % p;  
    }  
    return res;  
} 
ll modInverse(ll a, ll m) 
{ 
    ll m0 = m; 
    ll y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    { 
        // q is quotient 
        ll q = a / m; 
        ll t = m; 
  
        // m is remainder now, process same as 
        // Euclid's algo 
        m = a % m, a = t; 
        t = y; 
  
        // Update y and x 
        y = x - q * y; 
        x = t; 
    } 
  
    // Make x positive 
    if (x < 0) 
       x += m0; 
  
    return x; 
} 
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
 		ll ans=0;
 		if(n%2==0)
 		{
 			ans=(power(26,n/2,mod)-1+mod)%mod;
 			ans=ans*2*26;
 			ans%=mod;
 			ans=(ans*modInverse(25,mod))%mod;
 		}
 		else
 		{
 			n++;
 			ans=(power(26,n/2,mod)-1+mod)%mod;
 			ans=ans*2*26;
 			ans%=mod;
 			ans=(ans*modInverse(25,mod))%mod;
 			ans-=(power(26,n/2,mod));
 			ans=(ans+mod)%mod;		
 		}
 		cout<<ans<<endl;
 	}
 	//26 26 676 676 


//	2(26+26^2+26^3...) 	    
//	26(26^n-1)/(25)
    return 0;
}