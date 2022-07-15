#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

string orphan;
void solve(){
	map<string,int> mp;
	for(int i = 0;i<14;i++){
		string s;
		cin>>s;
		mp[s]++;
	}
	bool p = true,o = true;
	for(auto i:mp){
		if(i.sc %2 != 0)p = false;
	}
	int total = 0;
	string a = "19";string b = "mspz";
	for(auto i:a){
		for(auto j:b){
			string tmp = string(1,i)+j;
			if(tmp == "9z")continue;
			if(mp.count(tmp) == 0)o = false;
			total += mp[tmp];
		}
	}
	for(char i = '2';i<='7';i++){
		string tmp = string(1,i)+'z';
		if(mp.count(tmp) == 0)o = false;
		total += mp[tmp];
	}
	if(o&&total == 14){
		cout<<"kokushi musou(Thirteen orphans)\n";
	}
	else if(p)cout<<"chiitoitsu(Seven pairs)\n";
	else cout<<"none\n";
	return;
}
int main(){
	int t;
	cin>>t;
	while(t--)solve();
}

