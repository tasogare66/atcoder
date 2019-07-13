//AtCoder ABC109 B - Shiritori
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N; cin>>N;
    vector<string> wn(N);
    unordered_set<string> us;
    for(auto&& w:wn){
        cin>>w;
        us.insert(w);
    }
    bool ans=us.size()==wn.size();
    for(int i=0;i<wn.size()-1;++i){
        if(wn[i].back()!=wn[i+1].front()) ans=false;
    }
    cout<<(ans?"Yes":"No")<<endl;
    return 0;
}