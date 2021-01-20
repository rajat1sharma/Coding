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
vector<int> subarraySum(int a[],int n,int s)
{
    int start=0,end=0;
    int sum_so_far=a[0];
    for(int i=1;i<=n;i++)
    {
//cout<<sum_so_far<<" "<<start<<endl;
   if(sum_so_far==s)
        break;
     
        end=i;
        sum_so_far+=a[i];
        while(sum_so_far>s && start<i)
        {
            sum_so_far-=a[start];
            start++;
        }
    }
    vector<int> v;
    v.push_back(start+1);
    v.push_back(end+1);
    if(end+1==n+1)
    {
        v.clear();
        v.push_back(-1);
    }
    // if(n==12433)
    // cout<<start<<" "<<end<<" "<<v[0]<<endl;
    return v;
}
int main()
{
    SPEED;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    int n,s;
    cin>>n>>s;
    int a[n];
    rep(i,0,n)
    cin>>a[i];
    vector<int> v=subarraySum(a,n,s);
    rep(i,0,v.size())
    cout<<v[i]<<" ";
    return 0;
}
