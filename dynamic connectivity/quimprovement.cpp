#include <bits/stdc++.h>     
using namespace std;
typedef long long ll;
ll root(ll* a,ll p)
{
	while(p!=a[p])
		p=a[p];
	return p;
}
bool connected(ll* a,ll p,ll q,ll n,ll size)
{
	return root(a,p)==root(a,q);
}
void unionobj(ll* a,ll p,ll q,ll n,ll size)
{
	ll i=root(p);
	ll j=root(q);
	if(i==j)
		return;
	if(size[i]<size[j])
	{
		a[i]=j;
		size[j]+=size[i];
	}
	else
		a[i]=j;
}
main()
{
	ll n;
	cin>>n;
	ll id[n];
	ll i;
	ll size[n]={0};
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