//ABC005 C - おいしいたこ焼きの売り方
#include <bits/stdc++.h>
using namespace std;
int main() {
    int T,N,M;
    cin>>T>>N;
    std::vector<int> A(N,0);
    for(int i=0;i<N;++i){
        cin >> A[i];
    }
    cin>>M;
    std::vector<int> B(M,0);
    for (int i = 0; i < M;++i)
    {
        cin >> B[i];
    }
    //客を捌いていく
    int apos=0;
    for (int i=0; i<M;++i){
        bool ok_flag = false;
        while(apos < N){
            if (A[apos] <= B[i] && B[i] <= A[apos] + T)
            {
                ++apos;
                ok_flag = true;
                break; //売れた
            }
            ++apos;
        }
        if (!ok_flag) {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    return 0;
}