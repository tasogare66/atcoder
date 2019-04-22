//Tenka1 Programmer Beginner Contest 2019
//C - Stones
#include <bits/stdc++.h>
using namespace std;
template<size_t SIZE, class T> inline size_t array_size(T (&arr)[SIZE]) {
    return SIZE;
}
int main() {
    int N;
    string S;
#if 0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    cin>>N>>S;
    int least = INT_MAX;
    int num_l_b=0; //左,黒、memoしていきながらずらす
    int num_r_w=0; //右,白
    //白の数
    for (int i=0;i<N;++i) {
        if (S[i]=='.') ++num_r_w;
    }
    least = num_l_b + num_r_w;
    for (int i=0;i < N;++i) {
        //0,#####
        //1,.####
        //2,..###
        //3,...##
        //4,....#
        //5,.....
        int num =0;
#if 1
        if(S[i]=='#'){
            num_l_b++;
        } else {
            num_r_w--;
        }
        num = num_l_b + num_r_w;
#else
        for(int j=0;j<N;++j){
            if(j >= i){
				if(S[j] != '#') {
					++num;
				}
			} else {
				if(S[j] != '.') {
					++num;
				}
            }
        }
#endif
        least = std::min(least,num);
    }
	cout << least << endl;
	return 0;
}