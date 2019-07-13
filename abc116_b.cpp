//AtCoder ABC116 B - Collatz Problem
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
#if LOCAL&0
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll s; cin>>s;
    ll i=1;
    ll prev=s,next=s;
    vector<ll> tbl;
    //tbl.push_back(s);
    do{
        prev=next;
        tbl.push_back(prev);
        if (prev%2==0){
            next=prev/2;
        } else {
            next=3*prev+1;
        }
		++i;
    }while(find(tbl.begin(),tbl.end(),next)==tbl.end());
    cout<<i<<endl;
    return 0;
}