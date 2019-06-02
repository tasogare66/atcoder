//AtCoder ABC046 A - AtCoDeerくんとペンキ / AtCoDeer and Paint Cans
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    std::unordered_set<int> col;
    for(int i=0;i<3;++i){
        int c;
        cin>>c;
        col.insert(c);
    }
    cout<<col.size()<<endl;
    return 0;
}