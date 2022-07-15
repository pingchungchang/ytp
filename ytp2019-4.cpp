#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

string s;
map<char,int> mp;
bool pal(int l,int r){
	for(int i = 0;i<r-l+1;i++){
		if(l+i>r-i)break;
		if(mp[s[l+i]] + mp[s[r-i]] != 0)return false;
	}
	return true;
}
int main(){
	for(char i = '1';i<='9';i++)
	for(char i = 'a';i<='z';i++)mp[i] = 100;
	mp['b'] = 1;
	mp['d'] = -1;
	mp['m'] = 0;
	mp['x'] = mp['v'] = mp['o'] = mp['8'] = 0;
	mp['p'] = 1;
	mp['q'] = -1;
	cin>>s;
	string ans;
	int n = s.size();
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			if(pal(i,j)){
				if(ans.size()<j-i+1)ans = s.substr(i,j-i+1);
			}
		}
	}
	if(ans.size() ==0)cout<<"...\n";
	else cout<<ans<<'\n';
}

