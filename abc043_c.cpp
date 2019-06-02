//AtCoder ABC043 C - いっしょ / Be Together
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    int N;
    cin>>N;
    vector<int> atbl(N);
    for(auto&&a:atbl){
        cin>>a;
    }
    lli cost=INT64_MAX;
    for(int v=-100;v<=100;++v){
        lli cc=0;
        for(const auto&a:atbl){
            cc+=(a-v)*(a-v);
        }
        cost=min(cost,cc);
    }
    cout<<cost<<endl;
    return 0;
}