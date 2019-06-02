//AtCoder ABC050 C - Lining Up
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
constexpr lli MOD=1e9+7;

int main() {
    int N;
    cin>>N;
    vector<int> atbl(N);
    for(auto&& a:atbl){
        cin>>a;
    }
    sort(atbl.begin(),atbl.end());
    int st=(N%2==0?1:0);
    int cnt=(N%2==0?0:1);
    bool dis=false;
    for(const auto& a: atbl){
        if(a==st){
            ++cnt;
            if(cnt%2==0) st+=2;
        }else{
            dis=true;//0
            break;
        }
    }
    lli ans=dis?0:1;
	for(int i = 1; i <= N / 2; ++i) {
		ans = ans * 2 % MOD;
	}
    cout<<ans<<endl;
	return 0;
}