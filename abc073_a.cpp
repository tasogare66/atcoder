//AtCoder ABC073 A - September 9
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    string N;
    cin>>N;
    bool ans=false;
    for(auto& s:N){
        if (s=='9') ans=true; 
    }
    cout<<(ans?"Yes":"No")<<endl;
    return 0;
}