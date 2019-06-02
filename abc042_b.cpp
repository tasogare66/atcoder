//AtCoder ABC042 B - 文字列大好きいろはちゃんイージー / Iroha Loves Strings (ABC Edition)
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    int N,L;
    cin>>N>>L;
    vector<string> S(N);
    for(auto&& s:S){
        cin>>s;
    }
    sort(S.begin(),S.end());
    for(const auto& s:S){
        cout<<s;
    }
    cout<<endl;
    return 0;
}