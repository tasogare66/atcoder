//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

struct Dat{
    string n;
    int p;
    int ans;
    int no;
};
int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    int N;
    cin>>N;
    vector<Dat> tbl(N);
    int n=0;
    for(auto&& d:tbl){
        cin>>d.n>>d.p;
        d.no=n++;
    }
    sort(tbl.begin(),tbl.end(),[](auto& a,auto &b){
        if(a.n==b.n){
            return a.p>b.p;
        }
        return (a.n<b.n);
    }
    );

    int a=1;
    for(auto&& d:tbl){
        d.ans=a++;
    }
    // sort(tbl.begin(),tbl.end(),[](auto &a,auto &b){
    //     return (a.no<b.no);
    // }
    // );

    for(auto&& d:tbl){
        cout<<d.no+1<<endl;
    }

    return 0;
}