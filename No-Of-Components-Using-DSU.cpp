// Program to Find Number of Components Using DSU
// Disjoint Set Union

#include<bits/stdc++.h>
using namespace std;
#define MX 101

int parent[MX];
int siz[MX];

void init(){

	for(int i=0;i<MX;i++){
		siz[i] = 1;
		parent[i] = i;
	}
}

int getRoot(int a){

	while(a != parent[a])
		a = parent[a];

	return a;
}

void takeUnion(int a, int b){

	a = getRoot(a);
	b = getRoot(b);

	if(a != b){

		if(siz[b] > siz[a]) swap(a,b);
		siz[a] += siz[b];
		parent[b] = a;
	}
	return;
}

int main(){

	int n,m;
	cin>>n>>m;

	int c = 0;

	init();

	for(int i=0;i<m;i++){
		
		int u,v;
		cin>>u>>v;

		takeUnion(u,v);
	}
	for(int i=1;i<=n;i++){
		if(i == parent[i])
			c++;
	}
	cout<<c;

	return 0;
}