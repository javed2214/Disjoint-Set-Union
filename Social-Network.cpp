// Social Network Problem (CodeChef)
// https://www.codechef.com/problems/AUSF

#include<bits/stdc++.h>
#include<cstring>
#include<stdio.h>
using namespace std;
#define MOD1 1000000007
#define MOD2 1000000009
#define DB(x) cout<<#x<<"="<<x<<"\n";
#define DB2(x,y) cout<<#x<<"="<<x<<"  "<<#y<<"="<<y<<"\n";
#define FASTREAD ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define SORTV(a) sort(a.begin(),a.end())
#define SORTA(a,n) sort(a,a+n)
#define TEST(t) ll t; cin>>t; while(t--)
#define PI 2*acos(0.0)
#define FOR(i,n) for(int i=0;i<(n);i++)
#define RFOR(i,n) for(int i=(n)-1;i>=0;i--)
#define endl cout<<"\n";
#define co cout<<
#define SS cout<<"*";
#define REPLACE(str,start,count,new_str) str.replace(start,count,new_str)
#define COUNT(str,ch) count(str.begin(),str.end(),ch)
#define ERASE(str,index) str.erase(str.begin()+index)
#define MAXA(a,n) *max_element(a,a+n)
#define MINA(a,n) *min_element(a,a+n)
#define REV(v) reverse(v.begin(),v.end())
#define SUM(v) accumulate(v.begin(),v.end(),0)
#define MAXV(v) *max_element(v.begin(),v.end())
#define MINV(v) *min_element(v.begin(),v.end())
#define ull unsigned long long
#define ll long long int
#define ld long double
#define SIZE 100000001
#define INF 0x7fffffff
#define MX 1000005

unordered_map<string,string> parent;
unordered_map<string,ll> size;

void init(string a){

	parent[a]=a;
	size[a]=1;
}

string getRoot(string ch){

	while(ch!=parent[ch])
		ch=parent[ch];

	return ch;
}

void Union(string a, string b){

	a=getRoot(a);
	b=getRoot(b);

	if(a!=b){
		if(size[a] < size[b])
			swap(a,b);
		size[a]+=size[b];
		parent[b]=a;
	}
}


void SOLVE_QUESTION(){	

	ll test;
	cin>>test;

	while(test--){

		string u,v;
		cin>>u>>v;

		if(parent.count(u)==0) init(u);
		if(parent.count(v)==0) init(v);

		u=getRoot(u);
		v=getRoot(v);

		if(u==v) cout<<"Found in friend list";
		else cout<<"Found by random";

		Union(u,v);

		endl;
	}

	return;
}


int main(void){

	FASTREAD;
	SOLVE_QUESTION();

	return 0;
}