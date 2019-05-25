//AtCoder ABC030 A - 勝率計算
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
int main() {
#if LOCAL&01
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    int A,B,C,D;
    cin>>A>>B>>C>>D;
    float t = (float)B/(float)A;
    float a = (float)D/(float)C;
    if (abs(t-a)<=FLT_EPSILON) {
        cout<<"DRAW"<<endl;
    } else if (t>a){
        cout<<"TAKAHASHI"<<endl;
    } else {
        cout<<"AOKI"<<endl;
    }
    return 0;
}