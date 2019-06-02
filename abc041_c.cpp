//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
struct Data{
    int a;
    int no;
};

int main() {
    int N;
    cin>>N;
    vector<Data> tbl(N);
    int no=1;
    for(auto&& t:tbl){
        cin>>t.a;
        t.no=no++;
    }
    sort(tbl.begin(),tbl.end(),[](auto& a,auto &b){ return a.a > b.a;});
    for(auto&& t:tbl){
        cout<<t.no<<endl;
    }
    return 0;
}