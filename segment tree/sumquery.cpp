#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll tree[400000];
void constructtree(ll* a,ll left,ll right,ll node)
{
	if(left==right)
	{
		tree[node]=a[left];
		return;
	}
	ll mid=(left+right)/2;
	constructtree(a,left,mid,2*node+1);
	constructtree(a,mid+1,right,2*node+2);
	tree[node]=tree[2*node+1]+tree[2*node+2];
}
void update(ll* a,ll left,ll right,ll node,ll index,ll value)
{
	if(left==right)
	{
		a[index]+=value;
		tree[node]+=value;
	}
	else
	{
		ll mid=(left+right)/2;
		if(left<=index&&index<=right)
		{
			update(a,left,mid,2*node+1,index,value);
			update(a,mid+1,right,2*node+2,index,value);
		}
	}
}
ll query(ll left,ll right,ll node,ll qleft,ll qright)
{
	if(left>=qleft&&qright>=right)
		return tree[node];
	if(right<qleft||left>qright)
		return 0;
	ll mid=(left+right)/2;
	return query(left,mid,2*node+1,qleft,qright)+query(mid+1,right,2*node+2,qleft,qright);
}
main()
{
	ll n;
	cin>>n;
	ll i,a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	constructtree(a,0,n-1,0);
	ll queries;
	cin>>queries;
	while(queries--)
	{
		ll option,qleft,qright;
		cin>>option>>qleft>>qright;
		if(option==2)
		{
			//update
			//qleft is index and qright is value
			update(a,0,n-1,0,qleft,qright);
		}
		else
		{
			//range-----[qleft,qright]
			cout<<query(0,n-1,0,qleft,qright)<<endl;
		}
	}
}