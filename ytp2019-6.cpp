#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
void no(){
	cout<<"Nothing To Do :)\n";
}
int main(){
	io
	multiset<ll> st;
	string in;
	while(cin>>in){
		if(in == "END")return 0;
		if(in == "POP_LARGE"){
			if(st.empty()){
				no();	
			}
			else{
				cout<<*st.rbegin()<<'\n';
				st.erase(st.find(*st.rbegin()));
			}
		}
		if(in == "INSERT"){
			ll k;
			cin>>k;
			st.insert(k);
		}
		if(in == "POP_SMALL"){
			if(st.empty())no();
			else{
				cout<<*st.begin()<<'\n';
				st.erase(st.find(*st.begin()));
			}
		}
	}
}

