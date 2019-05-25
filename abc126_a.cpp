//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    int N,K;
    string S;
    cin>>N>>K;
    cin>>S;
    //cout<<K<<endl;
    S[K-1]=tolower(S[K-1]);
    cout<<S<<endl;
    return 0;
}