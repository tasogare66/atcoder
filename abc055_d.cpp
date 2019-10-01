//https://atcoder.jp/contests/abc055/tasks/arc069_b
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&0
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    string s; cin>>s;
    vector<bool> sw(N+1); //trueだと狼
	auto sheep = [&](ll p)->bool {
        ll prev = p-1;
        if(prev<0) prev += N;
		if(s.at(p) == 'o') {
            return sw.at(prev);
		} else {
            return !sw.at(prev);
		}
	};
	auto get_next = [&](ll p)->bool {
        return sw.at(p)==false ? sheep(p) : !sheep(p);
	};
    //fillsw
    auto fill_sw = [&](){
        for(ll i=1;i<N;++i){
            sw.at(i+1) = get_next(i);
        }
    };

    auto check_and_ans = [&](){
        fill_sw();
        if (sw.at(0)==sw.at(N) && get_next(0)==sw[1]){
            REP(i,N){
                cout<<(sw.at(i)?"W":"S");
            }
            cout<<endl;
            exit(0);
        }
    };

    sw[0]=true; sw[1]=false;
    check_and_ans();
    sw[0]=true; sw[1]=true;
    check_and_ans();

    sw[0]=false; sw[1]=false;
    check_and_ans();
    sw[0]=false; sw[1]=true;
    check_and_ans();

    cout<<-1<<endl;
    return 0;
}
