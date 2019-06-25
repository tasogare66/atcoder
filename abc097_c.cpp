//AtCoder ABC097 C - K-th Substring
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    string s; cin>>s;
    ll K; cin>>K;
    auto sorted=s;
    sort(sorted.begin(),sorted.end());
    unordered_set<char> sett;
    ll idx=0;
    while(idx<sorted.size()&&K>sett.size()){
        sett.insert(sorted[idx++]);
    }
    unordered_set<string> candidate_set;
    for(auto&& c:sett){
        for(ll i=0;i<s.size();++i){
            if(s[i]==c){
                for(ll l=1;l<=K;++l){
                    candidate_set.insert(string(s,i,l));
                }
            }
        }
    }
    //vectorへ
	vector<string> vec(candidate_set.size());
    std::copy(candidate_set.begin(), candidate_set.end(), vec.begin());
    sort(vec.begin(),vec.end());
    cout<<vec[K-1]<<endl;
    return 0;
}