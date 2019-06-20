// Fire Escape Routes (CodeChef)
// https://www.codechef.com/problems/FIRESC

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MX 100005

ll parent[MX];
ll siz[MX];

void init(ll n){

	for(int i=1;i<=n;i++){
		parent[i]=i;
		siz[i]=1;
	}
}

ll getRoot(ll a){

	while(a!=parent[a])
		a=parent[a];

	return a;
}

void takeUnion(ll a, ll b){

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

	ll test;
	cin>>test;

	while(test--){

		ll n,e;
		cin>>n>>e;

		init(n);

		for(int i=1;i<=e;i++){
			ll a,b;
			cin>>a>>b;

			takeUnion(a,b);
		}
		ll count=0,s=1;
		for(int i=1;i<=n;i++){
			if(i==parent[i]){
				count++;
				s=(s % MOD * siz[i] % MOD) % MOD;
			}
		}
		cout<<count<<" "<<s<<"\n";
	}
	return 0;
}