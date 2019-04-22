//Tenka1 Programmer Beginner Contest 2019
//B - *e**** ********e* *e****e* ****e**
#include <bits/stdc++.h>
using namespace std;
template<size_t SIZE, class T> inline size_t array_size(T (&arr)[SIZE]) {
    return SIZE;
}
int main() {
    int N,K;
    string S;
    cin>>N;
    cin>>S;
    cin>>K;
    auto c = S[K-1];
    for (int i= 0;i<S.length();++i) {
        if (S[i] != c) {
            S[i] = '*';
        }
    }
    cout<<S<<endl;
    return 0;
}