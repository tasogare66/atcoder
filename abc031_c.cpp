//AtCoder ABC031 C - 数列ゲーム
#include <bits/stdc++.h>
using namespace std;
using li=int64_t;

int main() {
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    int N;
    cin>>N;
    vector<int> at(N+1);
    vector<int> od(N+1);
    vector<int> ev(N+1);
    for(int i=1;i<=N;++i){
        cin>>at[i];
    }
    int ttl_o=0;
    int ttl_e=0;
    for(int i=0;i<at.size();++i){
        if((i%2)==0){
            ttl_e+=at[i];
        }else{
            ttl_o+=at[i];
        }
        od[i]=ttl_o;
        ev[i]=ttl_e;
    }
#if 01
	auto calc_score = [&](int a, int t) {
		int l = min(a, t);
		int r = max(a, t);
        int flag = l%2;
        int ed=r;
        int st=l-1;
        int o = (flag?od[ed]-od[st]:ev[ed]-ev[st]);
        int e = (flag?ev[ed]-ev[st]:od[ed]-od[st]);
        return make_pair(o,e); //高橋、青木
	};
    auto aoki = [&](int t) {
        int score=INT_MIN;
        int tscore;
        for(int i=1;i<=N;++i){
            if(i==t) continue;
            auto p = calc_score(i,t);
            if (score < p.second){
                score = p.second;
				tscore = p.first;
			}
        }
        return tscore;
	};
	int ans=INT_MIN;
    for(int i=N;i>=1;--i){
        int v = aoki(i);
        ans = max(ans,v);
        //cout<<v<<endl;
    }
    cout<<ans<<endl;
#endif
    return 0;
}