//https://atcoder.jp/contests/abc139/tasks/abc139_e
//#include <bits/stdc++.h>

//#if __cplusplus >= 201103L
//#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

//#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N; cin>>N;
    //vector<deque<ll>> ain(N+1);
    ll ain[1000+1][1000+1]={};
    ll aidx[1000+1]={};
    FOR(i,1,N+1){
        FOR(j,1,N){
            ll aij; cin>>aij;
            //ain[i].push_back(aij);
            ain[i][j] = aij;
        }
    }
    ll day=0;

    auto get_front=[&](ll i){
        ll p=aidx[i]+1;
        if (p>N-1) return (ll)-1;
        //if (ain[i].size()<=0) return (ll)-1;
        ll ret = ain[i][p];//.front();
        return ret;
    };
    auto pop_front=[&](ll i){
        //ain[i].pop_front();
        aidx[i]++;
    };
    ll all = N*(N-1)/2;
    vector<int> flag(N+1,-1);

    deque<ll> candidate[2]; //次の探索候補をつむ
    FOR(i,1,N+1){ //初回は全部つむ
        candidate[day].push_back(i);
    }

    while(all>0){
        ll siai=0;

        //FOR(i,1,N+1){
        for(const auto& i:candidate[day%2]){
            if (flag.at(i)==day) continue;
            auto e = get_front(i); //eと戦いたい
            if (e>0){
                if (flag.at(e)==day) continue;
                //if(e>0 && get_front(e) == i) {
                if(get_front(e) == i) {
                    pop_front(i);
                    pop_front(e);
                    flag.at(e)=day;
				    flag.at(i)=day;
				    ++siai;
                    auto nx_candi_id=(day+1)%2;
                    candidate[nx_candi_id].push_back(i);
                    candidate[nx_candi_id].push_back(e);
                }
            }
        }
        candidate[day%2].clear();
        ++day;
        all -= siai;
        if(siai==0){
            cout<<-1<<endl;
            return 0; //終わり
        }
    }
    cout<<day<<endl;
    return 0;
}