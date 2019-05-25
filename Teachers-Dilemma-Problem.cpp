// Teacher's Dilemma Problem (HackerEarth)
// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/teachers-dilemma-3/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD1 1000000007

ll parent[100001];
ll size[100001];

void init(ll n){

	for(ll i=1;i<=n;i++){
		parent[i]=i;
		size[i]=1;
	}
}

ll getRoot(ll a){

	while(a != parent[a])
		a=parent[a];

	return a;
}

void Union(ll a, ll b){

	a=getRoot(a);
	b=getRoot(b);

	if(a != b){

		if(size[b] > size[a])
			swap(a,b);
		parent[b]=a;
		size[a]+=size[b];
	}
}

int main(){

	ll n,m;
	cin>>n>>m;

	init(n);

	for(ll i=1;i<=m;i++){
		ll a,b;
		cin>>a>>b;

		Union(a,b);
	}

	ll res=1;

	for(ll i=1;i<=n;i++){
		if(i==parent[i])
			res=(res*size[i]) % MOD1;
	}

	cout<<res;

	return 0;
}
