//AtCoder AGC034 A - Kenken Race
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N,A,B,C,D; cin>>N>>A>>B>>C>>D;
    string S; cin>>S;    
    S.insert(0," ");
    //--N; --A; --B; --C; --D;
    vector<char> a(N+1,0); //aがいけるところ
    vector<char> b(N+1,0); //bが
    a[A]=1;
    for(ll i=A+1;i<=C;++i){
        if(S[i]=='.')
            if(a[i-1]||a[i-2]) a[i]=1;
    }
    if(!a[C]) {
        cout<<"No"<<endl;
        return 0;
    }
    b[B]=1;
    for(ll i=B+1;i<=D;++i){
        if(S[i]=='.')
            if(b[i-1]||b[i-2]) b[i]=1;
    }
    if(!b[D]) {
        cout<<"No"<<endl;
        return 0;
    }
    if(C<D) { //こえなくてよい
        cout<<"Yes"<<endl;
    } else {
        bool ans=false;
        for(ll i=B; i<=D;++i){
            if(b[i] && a[i-1] && a[i+1]){
                ans=true;
            }
        }
        cout<<(ans?"Yes":"No")<<endl;
    }
    return 0;
}
