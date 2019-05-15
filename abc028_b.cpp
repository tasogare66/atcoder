//ABC028 B - 文字数カウント
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
int main() {
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    string S;
    cin>>S;
    int num[6]={};
    for (int i=0;i<S.size();++i){
        num[S[i]-'A']++;
    }
    cout<<num[0]<<" ";
    cout<<num[1]<<" ";
    cout<<num[2]<<" ";
    cout<<num[3]<<" ";
    cout<<num[4]<<" ";
    cout<<num[5]<<endl;
    return 0;
}