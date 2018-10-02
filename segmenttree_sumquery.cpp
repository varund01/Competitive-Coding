/*------------varun duduku--------*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll tree[100000];
void treeconst(ll*,ll,ll,ll);
void update(ll*,ll,ll,ll,ll,ll);
ll query(ll*,ll,ll,ll,ll,ll);
void treeconst(ll* a,ll low,ll high,ll node)
{
	if(low==high)
	{
		tree[node]=a[low];
		cout<<node<<" "<<tree[node]<<endl;
	}
	else
	{
		ll mid=low+(high-low)/2;
		treeconst(a,low,mid,2*node+1);
		treeconst(a,mid+1,high,2*node+2);
		tree[node]=tree[2*node+1]+tree[2*node+2];
		cout<<node<<" "<<tree[node]<<endl;
	}
}
void update(ll* a,ll idx,ll val,ll low,ll high,ll node)
{
	if(low==high)
	{
		a[idx]+=val;
		tree[node]+=val;
		cout<<node<<" "<<tree[node]<<endl;
	}
	else
	{
		ll mid=low+(high-low)/2;
		if(low<=idx&&idx<=high)
			update(a,idx,val,low,mid,2*node+1);
		else
			update(a,idx,val,mid+1,high,2*node+2);
		tree[node]=tree[2*node+1]+tree[2*node+2];
		cout<<node<<" "<<tree[node]<<endl;
	}
}
ll query(ll* a,ll start,ll end,ll low,ll high,ll node)
{
	if(end<low||start>high)
	{
		return 0;
	}
	if(start<=low&&high<=end)
	{
		return tree[node];
	}
	ll mid=low+(high-low)/2;
	return (query(a,start,end,low,mid,2*node+1)+query(a,start,end,mid+1,high,2*node+2));
}
main()
{
	ll i,n;
	cin>>n;
	ll a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	treeconst(a,0,n-1,0);
	ll quries;
	cin>>quries;
	while(quries--)
	{
		ll x;
		cin>>x;
		if(x==1)//update
		{
			ll c,s;
			cin>>c;
			cin>>s;
			update(a,c,s,0,n-1,0);
		}
		else//query
		{
			ll c,s;
			cin>>c>>s;
			cout<<query(a,c,s,0,n-1,0)<<endl;
		}
	}
}
