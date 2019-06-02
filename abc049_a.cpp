//AtCoder ABC049 A - 居合を終え、青い絵を覆う / UOIAUAI
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    string c;
    cin>>c;
    if(c[0]=='a'||c[0]=='e'||c[0]=='i'||c[0]=='o'||c[0]=='u'){
        cout<<"vowel"<<endl;
    } else{
        cout<<"consonant"<<endl;
    }
    return 0;
}