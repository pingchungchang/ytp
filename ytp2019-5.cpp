#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

//is this greedy right?
ll gcd(ll a,ll b){
	if(b>a)swap(a,b);
	while(b != 0){
		a %= b;
		swap(a,b);
	}
	return a;
}
int main(){
	int n;
	cin>>n;
	vector<ll> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	ll p1 = 0,p2 = n-1;
	ll total = 0;
	for(auto i:v)total += i;
	ld avg = (ld)total/n;
	short flag = 3;
	while(p2-p1>=2){
//		cout<<p1<<' '<<p2<<' '<<(flag&2)<<' '<<avg<<endl;
		if((flag&1) != 0){
			flag ^= 1;
			ll tmp = 0;
			ll len = 0;
			for(int i = p2;i>p1+1;i--){
				len++;
				tmp+=v[i];
				if((ld)tmp/len<avg){
					for(int k = p2;k>i;k--){
						total -= v[k];
					}
					flag |=1;
					p2 = i-1;
					break;
				}
			}
		}
		else if((flag&2) != 0){
			flag ^=2;
			ll tmp = 0;
			ll len = 0;
			for(int i = p1;i<p2-1;i++){
				len++;
				tmp += v[i];
				if((ld)tmp/len<avg){
					flag |=2;
					p1 = i+1;
					for(int k = p1;k<i;k++){
						total -= v[k];
					}
					break;
				}
			}
		}
		else break;
		avg = total/(p2-p1+1);
	}
	total = 0;
	for(ll i = p1;i<=p2;i++){
		total += v[i];
	}
	ll k = gcd(total,p2-p1+1);
	cout<<total/k<<'/'<<(p2-p1+1)/k;
}

