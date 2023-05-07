#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
    #define debugP() std::cerr << "Line:" << __LINE__ << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
    #define debugP()
#endif

int main() {
    string X;
    cin >> X;
    int N;
    cin >> N;
    vector<string> S(N);
    for(int i = 0; i < N; i++){
        cin >> S.at(i);
    }

    stack<int> st;
    for(int i = 0; i < N; i++){
        string now = S.at(i);
        if(now == "+" || now == "-" || now == "*"){
            char op = now.at(0);
            int num1, num2;
            num1 = st.top();
            st.pop();
            num2 = st.top();
            st.pop();

            int ret;
            if(op == '+'){
                ret = num2 + num1;
            }
            if(op == '-'){
                ret = num2 - num1;
            }
            if(op == '*'){
                ret = num2 * num1;
            }

            st.push(ret);
        }
        else{
            int num = stoi(now);
            st.push(num);
        }
    }

    cout << X << '=' << st.top() << endl;
}