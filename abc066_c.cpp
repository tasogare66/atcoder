//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll n=10;
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    cin>>n;
    vector<ll> atbl(n,0);
    for(auto&& a:atbl){
        cin>>a;
    }
#if 0
    vector<ll> btbl;
    for(int i=1;i<=n;++i){
        btbl.push_back(i);
        std::reverse(btbl.begin(),btbl.end());
    }
#endif
    vector<ll> bs;
    for(ll i=n;i>0;i-=2){
        bs.push_back(i);
    }
    for(ll i=n%2+1;i<n;i+=2){
        bs.push_back(i);
    }
	for(int i = 0; i < bs.size(); ++i) {
		ll no = bs[i] - 1;
		if(i == 0)
			cout << atbl[no];
		else
			cout << " " << atbl[no];
	}
	cout << endl;
#if 0
    //output
	auto output = [](const vector<ll>& tbl) {
		for(int i = 0; i < tbl.size(); ++i) {
			if(i == 0)
				cout << tbl[i];
			else
				cout << " " << tbl[i];
		}
		cout << endl;
	};
    //output(btbl);
    output(bs);
#endif
    return 0;
}