//AtCoder ABC054 B - Template Matching
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    int N,M;
    cin>>N>>M;
    vector<string> nt(N);
    vector<string> mt(M);
    for(auto&&n :nt){
        cin>>n;
    }
    for(auto&&m :mt){
        cin>>m;
    }
    //
    auto check_func = [&](int x,int y){
        bool ret = true;
        for(int yy=0;yy<mt.size();++yy){
            if (strncmp(&nt[y+yy][x],&mt[yy][0],mt[0].size())!=0){
                ret = false;
                break;
            }
        }
        return ret;
    };
    bool ans=false;
    for(int x=0;x<nt[0].size()-mt[0].size()+1;++x){
        for(int y=0;y<nt.size()-mt.size()+1;++y) {
            if(check_func(x,y)){
                ans=true;
                break;
            }
        }
    }
    cout<<(ans?"Yes":"No")<<endl;
    return 0;
}