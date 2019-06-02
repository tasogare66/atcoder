//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

struct Sousa {
    int mai=0;
    int C=0;
};

int main() {
    int N,M;
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    cin>>N>>M;
    vector<int> atbl(N,0);
    for(int i=0;i<N;++i){
        cin>>atbl[i];
    }
    sort(atbl.begin(),atbl.end(),std::greater<int>());

    vector<Sousa> stbl(M);
    for(auto&& s:stbl){
        cin>>s.mai>>s.C;
    }
    //sousaをソート
    sort(stbl.begin(),stbl.end(),[](const Sousa& a,const Sousa& b){ return (a.C > b.C); });

    int pos=0;
    vector<int> chtbl(N,0);
    for(const auto& s:stbl){
        for(int i=0;i<s.mai;++i){
            if(pos>=N)break;
            chtbl[pos]=s.C;
            ++pos;
        }
        if(pos>=N)break;
    }
    sort(chtbl.begin(),chtbl.end());
    //いれていく
    for(int i=0;i<N;++i){
        if (chtbl[i] < atbl[i]){
            chtbl[i]=atbl[i];
        } else{
            break;
        }
    }

    lli ans=0;
    for(const auto& n:chtbl){
		ans += n;
	}
    cout<<ans<<endl;
    return 0;
}