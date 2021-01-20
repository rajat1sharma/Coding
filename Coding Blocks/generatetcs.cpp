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
string nature_of_roots(int a, int b, int c) 
{ 
    if (a == 0)
        return "Invalid"; 
    int D = b * b - 4 * a * c; 
    if (D > 0) 
        return "Real Roots";
    else if (D == 0)
        return "Equal Roots";
    else 
        return "Imaginary Roots";
} 
void boundarytc()
{
  cout<<"====================================================\n";
	cout<<"====================Boundary Case===================\n";
	cout<<"====================================================\n";
  int a[4]={0,1,99,100};
  rep(i,0,4)
    cout<<"testcases("<<a[i]<<","<<50<<","<<50<<",\""<<nature_of_roots(a[i],50,50)<<"\"),\n";
  rep(i,0,4)
    cout<<"testcases("<<50<<","<<a[i]<<","<<50<<",\""<<nature_of_roots(50,a[i],50)<<"\"),\n";
  rep(i,0,4)
    cout<<"testcases("<<50<<","<<50<<","<<a[i]<<",\""<<nature_of_roots(50,50,a[i])<<"\"),\n";
  rep(i,0,1)
    cout<<"testcases("<<50<<","<<50<<","<<50<<",\""<<nature_of_roots(50,50,50)<<"\")\n";
}
void worsttc()
{
  cout<<"====================================================\n";
	cout<<"====================Worse Case======================\n";
	cout<<"====================================================\n";
  int a[6]={-1,0,1,99,100,101};
  rep(i,0,6)
    cout<<"testcases("<<a[i]<<","<<50<<","<<50<<",\""<<nature_of_roots(a[i],50,50)<<"\"),\n";
  rep(i,0,6)
    cout<<"testcases("<<50<<","<<a[i]<<","<<50<<",\""<<nature_of_roots(50,a[i],50)<<"\"),\n";
  rep(i,0,6)
    cout<<"testcases("<<50<<","<<50<<","<<a[i]<<",\""<<nature_of_roots(50,50,a[i])<<"\"),\n";
  rep(i,0,1)
    cout<<"testcases("<<50<<","<<50<<","<<50<<",\""<<nature_of_roots(50,50,50)<<"\")\n";
}
void robusttc()
{
  	cout<<"====================================================\n";
	cout<<"====================Robust Case=====================\n";
	cout<<"====================================================\n";
  int a[5]={0,1,50,99,100};
  rep(i,0,5)
  rep(j,0,5)
  rep(k,0,5)
    cout<<"testcases("<<a[i]<<","<<a[j]<<","<<a[k]<<",\""<<nature_of_roots(a[i],a[j],a[k])<<"\"),\n";
}

void robustworsetc()
{
  	
	cout<<"====================================================\n";
	cout<<"====================Robust-Worse Case===============\n";
	cout<<"====================================================\n";
  int a[7]={-1,0,1,50,99,100,101};
  rep(i,0,7)
  rep(j,0,7)
  rep(k,0,7)
    cout<<"testcases("<<a[i]<<","<<a[j]<<","<<a[k]<<",\""<<nature_of_roots(a[i],a[j],a[k])<<"\"),\n";
}
int main()
{
  SPEED;
  #ifndef ONLINE_JUDGE
  freopen("generatetc.txt", "w", stdout);
  #endif
  boundarytc();
  worsttc();
  robusttc();
  robustworsetc();
  return 0;
}
