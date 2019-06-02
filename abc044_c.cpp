//AtCoder ABC044 C - 高橋君とカード / Tak and Cards
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
#if LOCAL&01
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    int N,A;
    cin>>N>>A;
    vector<int> xtbl(N);
    for(auto&& x:xtbl){
        cin>>x;
    }
    //bit探索?
    lli max=1ull<<N;
    lli ans=0;
    for(lli bs=1;bs<max;++bs){
        lli sum=0;
        int cnt=0;
        for(int i=0;i<N;++i){
            if (bs&(1ull<<i)) {
                sum+=xtbl[i];
                ++cnt;
            }
        }
        if(sum==A*cnt)++ans;
    }
    cout<<ans<<endl;
    return 0;
}