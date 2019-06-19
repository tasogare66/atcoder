//AtCoder ABC086 B - 1 21
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    string a,b;
    cin>>a>>b;
    string c=a+b;
    const ll v=stoi(c);
    bool ans=false;
    for(ll i=1;i*i<=v;++i){
        if(i*i==v){
            ans=true;
            break;
        }
    }
    cout<<(ans?"Yes":"No")<<endl;
    return 0;
}