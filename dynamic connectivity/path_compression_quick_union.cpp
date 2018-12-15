#include <bits/stdc++.h>     
using namespace std;
typedef long long ll;
ll root(ll* a,ll p)
{
	while(p!=a[p]){
		a[p]=a[a[p]];
		p=a[p];
	}
	return p;
}
bool connected(ll* a,ll p,ll q,ll n)
{
	return root(a,p)==root(a,q);
}
void unionobj(ll* a,ll p,ll q,ll n)
{
	a[root(a,p)]=root(a,q);
}
main()
{
	ll n;
	cin>>n;
	ll id[n];
	ll i;
	for(i=0;i<n;i++)
		id[i]=i;
	ll m;
	cin>>m;
	for(i=0;i<m;i++)
	{
		ll x,p,q;
		cin>>x>>p>>q;
		if(x==1)
		{
			if(!connected(id,p,q,n))
				unionobj(id,p,q,n);
		}
		else
		{
			if(connected(id,p,q,n))
				cout<<"connected\n";
			else
				cout<<"not connected\n";
		}
	}
}