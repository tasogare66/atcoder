//AtCoder ABC122 A - Double Helix
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    char b; cin>>b;
    char ans;
    switch(b){
        case 'A': ans='T';break;
        case 'T': ans='A';break;
        case 'G':ans='C';break;
        case 'C':ans='G';break;
    }
    cout<<ans<<endl;
    return 0;
}