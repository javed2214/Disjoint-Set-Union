// Friends and Foes (HackerEarth)
// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/friends-and-foes/description/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MX 100005

ll parent[MX];
ll size[MX];

void init(ll n){

	for(ll i=1;i<=n;i++){
		parent[i]=i;
		size[i]=1;
	}
}

ll getRoot(ll a){

	while(a!=parent[a])
		a=parent[a];

	return a;
}

void Union(ll a, ll b){

	a=getRoot(a);
	b=getRoot(b);

	if(a!=b){
		if(size[b] > size[a])
			swap(a,b);
		size[a]+=size[b];
		parent[b]=a;
	}
}

int main(){

	ll n,m1,m2;
	cin>>n>>m1;

	init(n);

	while(m1--){

		ll a,b;
		cin>>a>>b;

		Union(a,b);
	}
	cin>>m2;

	unordered_map<ll,bool> Map;

	while(m2--){

		ll a,b;
		cin>>a>>b;

		a=getRoot(a);
		b=getRoot(b);

		if(a==b) Map[a]=true;
	}
	
	ll mx=0;

	for(ll i=1;i<=n;i++){
		if(Map[i]==true) continue;
		if(i==parent[i]) mx=max(mx,size[i]);
	}
	cout<<mx;
}