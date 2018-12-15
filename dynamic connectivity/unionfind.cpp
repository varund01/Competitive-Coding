#include <bits/stdc++.h>     
using namespace std;
typedef long long ll;
bool connected(ll* a,ll p,ll q)
{
	return a[p]==a[q];
}
void unionobj(ll* a,ll p,ll q,ll n)
{
	ll pid=a[p];
	ll qid=a[q];
	for(i=0;i<n;i++)
	{
		if(a[i]==pid)
			a[i]=qid;
	}
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
			if(!connected(id,p,q))
				unionobj(id,p,q,n);
		}
		else
		{
			if(connected(id,p,q))
				cout<<"connected\n";
			else
				cout<<"not connected\n";
		}
	}
}