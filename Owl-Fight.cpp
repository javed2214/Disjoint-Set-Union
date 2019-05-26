// Owl Fight Problem (HackerEarth)
// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/owl-fight/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll parent[100001];

void init(ll n){

	for(int i=1;i<=n;i++){
		parent[i]=i;
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
		if(a < b) swap(a,b);
		parent[b]=a;
	}
}

int main(){

	ll n,m;
	cin>>n>>m;

	init(n);

	while(m--){

		ll a,b;
		cin>>a>>b;

		Union(a,b);
	}
	ll q;
	cin>>q;

	while(q--){

		ll a,b,x,y;
		cin>>a>>b;

		x=getRoot(a);
		y=getRoot(b);

		if(x==y) cout<<"TIE";
		else if(x > y) cout<<a;
		else cout<<b;
		cout<<endl;
	}
	return 0;
}