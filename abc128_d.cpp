//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    int N,K;
    cin>>N>>K;
    vector<int> vtbl(N,0);
    for(auto&& v:vtbl){
        cin>>v;
    }

    int ans=0;
    for(int t=min(K,N);t>=0;--t){
        for(int l=0;l<=t;++l){
            int r=t-l;
            vector<int> dt(t);
            copy(vtbl.begin(),vtbl.begin()+l,dt.begin());
            copy(vtbl.rbegin(),vtbl.rbegin()+r,dt.begin()+l);
            sort(dt.begin(),dt.end());
            int val=0;
            for(int i=0;i<dt.size();++i){
                if(dt[i]<0 && i<K-t){
                    //すてる
                } else{
					val += dt[i];
				}
            }
            ans=max(ans,val);
        }
    }
    cout<<ans<<endl;
    return 0;
}