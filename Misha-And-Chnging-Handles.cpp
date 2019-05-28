// Misha and Changing Handles (CodeForces)
// http://codeforces.com/contest/501/problem/B

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
#define MX 1003

unordered_map<string,string> Map,M;
unordered_map<string,int> size;

void init(string s1, string s2){

	Map[s1]=s1;
	Map[s2]=s2;
	size[s1]=1;
	size[s2]=1;
}

string getRoot(string s){

	while(s!=Map[s])
		s=Map[s];

	return s;
}

void Union(string s1, string s2){

	s1=getRoot(s1);
	s2=getRoot(s2);

	if(s1!=s2){
		if(size[s1] < size[s2])
			swap(s1,s2);
		size[s1]+=size[s2];
		Map[s2]=s1;
		M[s1]=s2;
	}
}

void SOLVE_QUESTION(){	

	ll n;
	cin>>n;
	string s1[n],s2[n];
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
		init(s1[i],s2[i]);
	}
	for(int i=0;i<n;i++)
		Union(s1[i],s2[i]);
	int c=0;
	for(int i=0;i<n;i++){
		if(s1[i]==Map[s1[i]])
			c++;
	}
	cout<<c;
	endl;
	for(int i=0;i<n;i++){
		if(s1[i]==Map[s1[i]]){
			cout<<s1[i]<<" "<<M[s1[i]];
			endl;
		}
	}

	return;
}


int main(void){

	FASTREAD;
	SOLVE_QUESTION();

	return 0;
}