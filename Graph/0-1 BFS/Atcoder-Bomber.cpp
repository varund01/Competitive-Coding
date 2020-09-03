/*

Problem - https://atcoder.jp/contests/abc176/tasks/abc176_e

*/


#include<bits/stdc++.h>
#define ll long long
#define mod (long long)(1e9+7)
#define endl "\n"
using namespace std;
 
void using_01bfs(string G[],ll h,ll w,ll srcx,ll srcy,ll destx,ll desty){
	
	ll dist[h][w];
	for(ll i=0;i<h;i++){
		for(ll j=0;j<w;j++){
			dist[i][j]=INT_MAX;
		}
	}
	
	
	auto legal=[&](ll r,ll c)->bool{
		if(r<0||c<0||r>=h||c>=w||G[r][c]=='#'){
			return 0;
		}
		return 1;
	};
	
	
	deque<pair<ll,ll> > q;
	q.push_front({srcx,srcy});
	dist[srcx][srcy]=0;
	while(!q.empty()){
		pair<ll,ll> p=q.front();
		ll x=p.first;
		ll y=p.second;
		q.pop_front();
		for(pair<ll,ll> P:vector<pair<ll,ll> >({{x,y+1},{x+1,y},{x-1,y},{x,y-1}})){
			if(legal(P.first,P.second)){
				if(dist[x][y]<dist[P.first][P.second]){
					dist[P.first][P.second]=dist[x][y];
					q.push_front({P.first,P.second});
				}
			}
		}
		for(ll i=x-2;i<=x+2;i++){
			for(ll j=y-2;j<=y+2;j++){
				if(legal(i,j)){
					if(dist[i][j]>dist[x][y]+1){
						dist[i][j]=dist[x][y]+1;
						q.push_back({i,j});
					}
				}
			}
		}
	}
	cout<<(dist[destx][desty]==INT_MAX?-1:dist[destx][desty])<<endl;
 
}
 
void solve(){
	ll h,w;
	cin>>h>>w;
	ll srcx,srcy;
	ll destx,desty;
	cin>>srcx>>srcy;
	cin>>destx>>desty;
	srcx--,srcy--,destx--,desty--;
	string G[h];
	for(ll i=0;i<h;i++){
		cin>>G[i];
	}
	using_01bfs(G,h,w,srcx,srcy,destx,desty);
}
 
 
int main(){
	ll t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}