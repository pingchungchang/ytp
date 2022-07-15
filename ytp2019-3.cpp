#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define int ll
main(){
	int n;
	cin>>n;
	map<int,int> mp;
	int ans = 0;
	vector<int> arr(n);
	for(int i = 0;i<n;i++)cin>>arr[i];
	int V;
	cin>>V;
	for(int i = 0;i<n;i++){
		ans += mp[V-arr[i]];
		mp[arr[i]]++;
	}
	cout<<ans<<'\n';
}

