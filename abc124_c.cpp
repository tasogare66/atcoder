//
#include <bits/stdc++.h>
using namespace std;
template<size_t SIZE, class T> inline size_t array_size(T (&arr)[SIZE]) {
    return SIZE;
}
int main() {
    string str;
    cin>>str;
    char c[]={'0','1'};
    int64_t c_a=0;
    int64_t c_b=0;
    for(int64_t i= 0;i<str.length();++i){
        //0101
        if (str[i] != c[i%2]) {
            ++c_a;
        }
        //1010
        if (str[i] != c[(i+1)%2]) {
            ++c_b;
        }
    }
    cout<<(c_a<c_b?c_a:c_b)<<endl;
    return 0;
}