//AtCoder ABC032 C - 列
#include <bits/stdc++.h>
using namespace std;
using li=int64_t;

int main() {
#if LOCAL&01
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    li N,K;
    cin>>N>>K;
    vector<li> st(N);
    bool exist_zero=false;
    for(auto&&s:st){
        cin>>s;
        exist_zero|=(s==0);
    }
    //0ある場合は特殊処理
    if(exist_zero){
        cout<<st.size()<<endl; //全部ok
        return 0;
    }
    if (K==0){
        cout<<0<<endl; //全部ng
        return 0;
    }
    li ans=0;
    li s=0, t=0, mul=1;
    for(;;){
        while(t<N && mul<=K){
            mul *= st[t++];
        }
        if (mul<=K) {
            ans = max(ans, t-s);
            break;
        }
        ans = max(ans, t-s-1);
        mul /= st[s++];
    }
    //if (ans>N) ans=0; //こたえなし
    cout<<ans<<endl;
    return 0;
}