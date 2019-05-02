//ABC015 A - 高橋くんの研修
#include <bits/stdc++.h>
using namespace std;
int main() {
    string A,B;
    cin>>A;
    cin>>B;
    cout<<((A.size() > B.size())?A:B)<<endl;
    return 0;
}