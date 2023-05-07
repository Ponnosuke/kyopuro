#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
  #define debug(X) std::cerr << #X << " = " << X << ", "
  #define debugL(Y) std::cerr << #Y << " = " << Y << '\n'
  #define debugP(Z) std::cerr << #Z << '\n'
#else
  #define debug(X) 3389
  #define debugL(Y) 3390
  #define debugP(Z) 3391
#endif

int main() {
    string S;
    cin >> S;

    stack<string> st;
    set<char> box;
    bool OK = true;
    st.emplace("");
    for(char ch : S){
        if(ch == '('){
            st.emplace("");
        }
        else if(ch == ')'){
            string tmp = st.top();
            st.pop();
            for(char ele : tmp){
                box.erase(ele);
            }
        }
        else{
            if(box.count(ch)){
                OK = false;
                break;
            }

            box.insert(ch);
            st.top() += ch;
        }
    }

    cout << (OK ? "Yes" : "No") << '\n';
}