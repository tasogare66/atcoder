//ABC028 A - テスト評価
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
int main() {
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    int N;
    cin>>N;
    if (N<=59){
        cout<<"Bad"<<endl;
    } else if (N <= 89) {
        cout<<"Good"<<endl;
    } else if (N <= 99) {
        cout<<"Great"<<endl;
    } else {
        cout<<"Perfect"<<endl;
    }
    return 0;
}