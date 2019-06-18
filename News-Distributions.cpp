// News Distribution (CodeForces)
// https://codeforces.com/contest/1167/problem/C

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MX 1000005

ll parent[MX];
ll siz[MX];

void init(ll n){

	for(ll i=1;i<=n;i++){
		parent[i]=i;
		siz[i]=1;
	}
}

ll getRoot(ll a){

	while(a!=parent[a])
		a=parent[a];
	return a;
}

void getUnion(ll a, ll b){

	a=getRoot(a);
	b=getRoot(b);

	if(a!=b){
		if(siz[b] > siz[a])
			swap(a,b);
		siz[a]+=siz[b];
		parent[b]=a;
	}
	return;
}

int main(){

	ll n,m;
	cin>>n>>m;

	init(n);

	std::vector<ll> v;

	for(ll i=1;i<=m;i++){
		ll x;
		cin>>x;
		if(x==0){
			v.clear();
			continue;
		}
		while(x--){
			ll p;
			cin>>p;
			v.push_back(p);
		}
		for(int i=0;i<v.size()-1;i++)
			getUnion(v[i],v[i+1]);

		v.clear();
	}
	for(int i=1;i<=n;i++){
		cout<<siz[getRoot(i)];
		cout<<" ";
	}
	return 0;
}