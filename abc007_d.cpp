//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

//[決めた桁][未満フラグ,未満のとき1][4,9含まれるとき1]
ll dp_b[20][2][2]={}; //b以下
ll dp_a[20][2][2]={}; //a未満

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    string A;
    string B;
    cin>>A>>B;
#if 01
    //B以下
    dp_b[0][0][0]=1;
    for(ll k=0;k<B.size();++k){ //桁
        ll digit = B[k]-'0';
        for(ll f=0;f<2;++f){ //has49
            for(ll d=0;d<=9;++d){ //未満フラグ1
                ll has49=f|(d==4||d==9);
                dp_b[k+1][1][has49] += dp_b[k][1][f];
            }
            for(ll d=0;d<=digit;++d){ //未満フラグ0
                ll has49=f|(d==4||d==9);
                dp_b[k+1][(d<digit)][has49] += dp_b[k][0][f]; //未満フラグ0は桁数があっているとき
            }
        }
    }
    ll bnum= dp_b[B.size()][0][1]+dp_b[B.size()][1][1];
    //A未満
    dp_a[0][0][0]=1;
    for(ll k=0;k<A.size();++k){ //桁
        ll digit = A[k]-'0';
        for(ll f=0;f<2;++f){ //has49
            for(ll d=0;d<=9;++d){ //未満フラグ1
                ll has49=f|(d==4||d==9);
                dp_a[k+1][1][has49] += dp_a[k][1][f];
            }
            for(ll d=0;d<=digit;++d){ //未満フラグ0
                if (k==A.size()-1&&d==digit) continue; //最後の桁のdigitは含まない
                ll has49=f|(d==4||d==9);
                dp_a[k+1][(d<digit)][has49] += dp_a[k][0][f]; //未満フラグ0は桁数があっているとき
            }
        }
    }
    ll anum= dp_a[A.size()][0][1]+dp_a[A.size()][1][1];
    cout<<bnum-anum<<endl;
#endif
    return 0;
}