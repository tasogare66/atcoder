//ABC007 B - 辞書式順序
#include <bits/stdc++.h>
using namespace std;
int main() {
    string A;
    cin>>A;
    if (A.size()>1){
        A.pop_back();
    }else{
        if (A[0]=='a') {
            cout<<-1<<endl;
            return 0;
        }
        --A[0];
    }
    cout<<A<<endl;
    return 0;
}