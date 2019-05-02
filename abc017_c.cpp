//ABC017 C - ハイスコア
#include <bits/stdc++.h>
using namespace std;
struct Iseki{
    int sc;
    int st,ed;
	Iseki(int isc, int ist, int ied) : sc(isc), st(ist), ed(ied) {}
};
int main() {
    int N,M; //N:遺跡
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    cin>>N>>M;
    std::vector<Iseki> data;
    for (int i=0;i<N;++i) {
        int s,e,score;
        cin>>s>>e>>score;
        data.emplace_back(score,s,e);
    }
#if 1
    //imosu?
    std::vector<int64_t> sctbl(M+2,0);
    int64_t total=0;
    for (auto& d:data) {
        sctbl[d.st] += d.sc;
        sctbl[d.ed+1] -= d.sc;
        total += d.sc;
    }
    int64_t smin=INT64_MAX;
    int64_t smax=0;
    int64_t sc=0;
    for (int i=1;i<=M;++i) {
        sc += sctbl[i];
        smin=std::min(sc,smin);
        smax=std::max(sc,smax);
    }
    cout<<total-smin<<endl;
#else
    int max=0;
    for (int i=1;i<=M;++i) {
        //1,2,...を立てない点数
        int val=0;
        for (int l=0;l<N;++l) {
            const auto&d=data[l];
            if (d.st <= i && i <= d.ed) {
            } else {
                val += d.sc;                
            }
        }
        max = std::max(val,max);
    }
    cout<<max<<endl;
#endif
    return 0;
}
