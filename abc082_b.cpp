//AtCoder ABC082 B - Two Anagrams
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    string s,t;
    cin>>s>>t;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end(),[](auto&a,auto&b){return a>b;});
    cout<<(s<t?"Yes":"No")<<endl;
    return 0;
}