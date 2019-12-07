using namespace std;
template<typename T> void view(ostringstream& os, T e){os << e;}
template<typename T1,typename T2> void view(ostringstream& os, const pair<T1,T2>& e){os<<e.first<<":"<<e.second;}
template<typename T> void view(ostringstream& os, const std::vector<T>& v){for(const auto& e : v){ view(os,e); os<< " "; }}
template<typename T> void view(ostringstream& os, const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(os,v); os<<endl;} }
template<typename T> void view(ostringstream& os, const std::deque<T>& v){for(const auto& e : v){ view(os,e); os<< " "; }}

queue<string> argment_contents; //global変数だよ
void set_args_con() {}
template<class First, class... Rest>
void set_args_con(const First& first, const Rest&... rest) {
    ostringstream ss;
    view(ss,first);
    argment_contents.push(ss.str());
    set_args_con(rest...);
}
string gen_string(string s) {
    s+=',';
    string ret="";
    int par=0;
    for(int i=0; i<(int)s.size(); i++) {
        if(s[i]=='(' || s[i]=='<' || s[i]=='{') par++;
        else if(s[i]==')' || s[i]=='>' || s[i]=='}') par--;
        if(par==0 && s[i]==',') {
            ret+="="+argment_contents.front();
            argment_contents.pop();
            if(i!=(int)s.size()-1) {
                ret+=",";
            }
        }
        else ret+=s[i];
    }
    return ret;
}
#define dump(...) {set_args_con(__VA_ARGS__);cerr<<gen_string(#__VA_ARGS__)<<endl;}
