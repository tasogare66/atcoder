//AtCoder ABC045 B - 3人でカードゲームイージー / Card Game for Three (ABC Edit)
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    string st[3];
    int pt[3]={};
    for(auto&&s:st){
        cin>>s;
    }
    int who=0;
    while(pt[who] < st[who].size()){
        auto s = st[who];
        who=s[pt[who]++]-'a';
    }
    cout<<(char)('A'+who)<<endl;
    return 0;
}