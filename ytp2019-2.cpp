#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	int n,t;
	cin>>n>>t;
	int s,e;
	cin>>s>>e;
	vector<int> v(t+1,0);
	v[s]++;
	v[e+1]--;
	for(int i = 0;i<n-1;i++){
		int l,r;
		cin>>l>>r;
		v[l]++;
		v[r+1]--;
	}
	int now = 0;
	for(int i = 0;i<s;i++)now += v[i];
	int ans = 0;
	for(int i = s;i<=e;i++){
		now += v[i];
		if(now>=(n+1)/2)ans++;
	}
	cout<<ans;
}

