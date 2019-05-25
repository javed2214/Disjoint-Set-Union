// Disjoint Set Implementation

#include<bits/stdc++.h>
using namespace std;

int parent[1001];

int find(int a){

	while(parent[a] > 0)
		a=parent[a];

	return a;
}

void Union(int a, int b){

	parent[a]+=parent[b];
	parent[b]=a;
}

int main(){

	int n,m;
	cin>>n>>m;

	for(int i=1;i<=n;i++)
		parent[i]=-1;

	while(m--){

		int a,b;
		cin>>a>>b;

		a=find(a);
		b=find(b);

		if(a!=b) Union(a,b);
	}

	int res=1;

	for(int i=1;i<=n;i++){
		if(parent[i] < 0)
			res=res*abs(parent[i]);
	}
	cout<<res;

	return 0;
}