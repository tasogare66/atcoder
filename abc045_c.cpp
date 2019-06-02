//AtCoder ABC045 C - たくさんの数式 / Many Formulas
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
#if LOCAL&01
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    string s;
    cin>>s;
    int N=s.size()-1;
    lli max=1ull<<N;
	lli sum = 0;
	for(lli bs=0;bs<max;++bs){
        int pt=0;
        for(int i=0;i<N;++i){
            if (bs&(1ull<<i)) {
                sum += std::stol(string(&s[pt],i-pt+1));
                pt = i+1;
            }
        }
        sum += std::stol(string(&s[pt]));//終端
    }
    cout<<sum<<endl;
    return 0;
}