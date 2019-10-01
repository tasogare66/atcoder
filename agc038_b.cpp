//https://atcoder.jp/contests/agc038/tasks/agc038_b
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    //std::ifstream in("./test/sample-3.in"); //input.txt
    std::ifstream in("./input.txt"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,K; cin>>N>>K; 
    vector<ll> pn(N);
    vector<ll> a(N+1);
    REP(i,N){
        cin>>pn[i];
        a[i+1]=pn[i];
    }
    for(auto&& p:pn){
        cin>>p;
    }
    map<ll,ll> mp;
	auto ins_mp = [&](ll pos) {
        auto p=pn.at(pos);
		auto prv = pos > 0 ? pn.at(pos - 1) : INT64_MAX;
		mp[p] = p>prv?1:0; //増えてたら1
        return mp[p];
	};
    //ll ans=1;
    ll ans=N-K+1;
    ll zouka_num=0;
	REP(i,K){
        auto p=pn[i];
        zouka_num += ins_mp(i);//mp[p]=1;
    }

#if LOCAL&01
    vector<ll> dp(N+1);
    vector<ll> cnt(N+1);
	dp[1] = 1;
	for (int i = 2; i <= N; i++){
		if (a[i - 1] < a[i]) dp[i] = dp[i - 1] + 1;
		else dp[i] = 1;
	}
	for (int i = 1; i <= N; i++){
		cnt[i] = cnt[i - 1];
		if (dp[i] >= K) cnt[i] ++;
	}
    ll tmp_a=0,tmp_b=0,tmp_c=0;
	ans = N - K + 1;
	set<int> myset;
	if (N == K) {cout << 1<<endl, 0;}
	for (int i = 1; i <= K + 1; i++){
		myset.insert(a[i]);
	}
	if (*(myset.rbegin()) == a[K + 1] && *(myset.begin()) == a[1]){
		ans--;
        tmp_a++;
	}
	for (int i = K + 2; i <= N; i++){
		myset.erase(a[i - (K + 1)]);
		myset.insert(a[i]);
		if (*(myset.rbegin()) == a[i] && *(myset.begin()) == a[i - K]) {
            ans --;tmp_b++;
        }
		else if(dp[i] >= K && cnt[i - K] > 0) {ans --;tmp_c++;}
	}
	cout << ans << ",a:"<<tmp_a<<",b:"<<tmp_b<<",c:"<<tmp_c<<endl;;
    //return 0;
 #endif

#if LOCAL&01
    for(ll i=0;i+K<=N;++i){
        auto tmp=pn;
        cout<<*(tmp.begin()+i)<<","<<*(tmp.begin()+i+K)<<";";
        sort(tmp.begin()+i,tmp.begin()+i+K);
        for(auto& v:tmp){
            cout<<v;
        }
        cout<<endl;
    }
 #endif   
    bool ava_flag=false;
    ans=N-K+1;
    for(ll i=0;i+K<N;++i){
        int minv = mp.begin()->first;
        int maxv = mp.rbegin()->first;
        ll cur = pn.at(i);
        ll cur2 = pn.at(i+1);
        ll nx = i+K;//pn.at(i+K);
        bool zouka_num_flag = false;
        if (zouka_num>=K-1){
            zouka_num_flag = ava_flag; //最初は適用させない
            ava_flag = true;
        }
        if (minv == pn.at(i) && maxv < pn.at(nx)){
            --ans;
        } else if(zouka_num_flag){
            --ans;
        }
        auto it = mp.find(cur);
        auto it2 = mp.find(cur2);
        zouka_num -= it2->second;
        mp.erase(it);
        zouka_num += ins_mp(i+K);//mp[nx]=1;
    }
    if (zouka_num>=K-1&&ava_flag){
        --ans;
    }
    cout<<ans<<endl;

    return 0;
}