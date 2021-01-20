#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,l;
	    cin>>n>>l;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    map<int,int> m;
	    for(auto i:a)
	    m[i]++;
	    int flag=-1;
	    for(int i=0;i<n;i++)
	    {
	        if(m[abs(a[i]+l)])
	        {
	            flag=1;
	            break;
	        }
	    }
	    cout<<flag<<endl;
	}
	return 0;
}