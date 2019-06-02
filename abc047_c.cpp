//AtCoder ABC047 C - 一次元リバーシ / 1D Reversi
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    string S;
    cin>>S;
    string cmp;
    char p=0;
    for(auto c:S){
        if(p!=c){
            cmp.push_back(c);
            p=c;
        }
    }
    cout<<cmp.size()-1<<endl;
    return 0;
}