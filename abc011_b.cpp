//ABC011 B - 名前の確認
#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    cin>>S;
    for (int i=0;i<S.size();++i) {
        S[i] = ((i==0)?toupper(S[i]):tolower(S[i]));
    }
    cout<<S<<endl;
    return 0;
}