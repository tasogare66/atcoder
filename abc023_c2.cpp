//ABC023 C - 収集王
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
using Pos=pair<lli,lli>;
int main() {
    lli R,C,K,N;
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    cin>>R>>C>>K;
    cin>>N;
    vector<lli> vy(R+1,0);
	vector<lli> vx(C+1, 0);
    vector<Pos> v; //row,col
    v.reserve(N);
    for(int i=0;i<N;++i){
        lli r,c;
        cin>>r>>c;
        ++vy[r];
        ++vx[c];
        v.push_back({r,c});
    }

    map<lli,lli> y,x;
    for (int i=1;i<=R;++i){ //i=0をいれちゃってた
        y[vy[i]]++;
    }
    for (int i=1;i<=C;++i){ //i=0をいれちゃってた
        x[vx[i]]++;
    }
    lli ans=0;
    for(int i=0;i<=K;++i){
        ans += (y[i]*x[K-i]);
    }
    for(const auto& p:v){
        auto r=p.first;
        auto c=p.second;
        lli tmp=vy[r]+vx[c];
        if (tmp==K) --ans;
        if (tmp==K+1) ++ans;
    }
    cout<<ans<<endl;
	return 0;
}