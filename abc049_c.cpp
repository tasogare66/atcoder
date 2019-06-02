//AtCoder ABC049 C - 白昼夢 / Daydream
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    string S;
    cin>>S;
    string tbl[]={
        "dream", "dreamer", "erase", "eraser"
    };

    auto check_func = [&](int pt){
        int ret=-1;
        for(const auto& cs:tbl){
            auto tmp=pt-cs.size();
            if (tmp<0) continue;
            if (strncmp(&cs[0], &S[tmp], cs.size())==0){
                ret = tmp;
                break;
            }
        }
        return ret;
    };

    int endpt=S.size();//終端から一致を確認していく
    while(endpt > 0){
        endpt = check_func(endpt);
    }
    cout<<(endpt==0?"YES":"NO")<<endl;
    return 0;
}