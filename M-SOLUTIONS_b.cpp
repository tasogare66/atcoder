//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    string S;
    cin>>S;
    int num=S.size();
    int cnt=0;
    int rest=15-num;
    for(auto&& s:S){
        if(s=='o')++cnt;
    }
    cout<<(cnt+rest>=8?"YES":"NO")<<endl;
    return 0;
}