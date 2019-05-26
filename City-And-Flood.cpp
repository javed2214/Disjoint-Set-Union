// City and Flood (HackerEarth)
// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll parent[100002];

void init(ll n){

	for(int i=1;i<=n;i++)
		parent[i]=i;
}

ll getRoot(ll a){

	while(a != parent[a])
		a=parent[a];

	return a;
}

void Union(ll a, ll b){

	a=getRoot(a);
	b=getRoot(b);

	if(a != b)
		parent[a]=b;
}

int main(){

	ll n,k;
	cin>>n>>k;

	init(n);

	for(int i=1;i<=k;i++){
		ll a,b;
		cin>>a>>b;
		Union(a,b);
	}
	ll c=0;

	for(int i=1;i<=n;i++){
		if(getRoot(i)==i)
			c++;
	}
	cout<<c;
}