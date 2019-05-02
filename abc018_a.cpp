//ABC018 A - 豆まき
#include <bits/stdc++.h>
using namespace std;
int main() {
    int A,B,C;
    cin>>A>>B>>C;
    auto jyuni=[](int a,int b, int c){
        if (a>b&&a>c){
            return 1;
        }
        if (a<b&&a<c){
            return 3;
        }
        return 2;
    };
    cout<<jyuni(A,B,C)<<endl;
    cout<<jyuni(B,A,C)<<endl;
    cout<<jyuni(C,A,B)<<endl;
    return 0;
}