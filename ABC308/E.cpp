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

i64 get_mex(i64 A_i, i64 A_j, i64 A_k){
    i64 ret = 0;
    for(i64 num = 0; num <= 3; num++){
        bool OK = true;

        if(A_i == num){
            OK = false;
            continue;
        }
        if(A_j == num){
            OK = false;
            continue;
        }
        if(A_k == num){
            OK = false;
            continue;
        }

        if(OK){
            ret = num;
            break;
        }
    }

    return ret;
}

const string TARGET = "MEX";

void dfs(char now_char, i64 &ans, int now_idx, int N, vector<int> &now_vec, vector<i64> &A, string &S){

    if(now_char == 'X' && (int)now_vec.size() == 3){
        int i = now_vec.at(0), j = now_vec.at(1), k = now_vec.at(2);
        ans += get_mex(A.at(i), A.at(j), A.at(k));

        debugV(i);
        debugV(j);
        debugVL(k);
        debugVL(ans);
        debugWL();

        now_vec.pop_back();
        return;
    }

    int now_char_idx = 0;
    for(int i = 0; i < 3; i++){
        if(now_char == TARGET.at(i)){
            now_char_idx = i;
            break;
        }
    }

    char next_char = TARGET.at(now_char_idx + 1);
    for(int nxt = now_idx + 1; nxt < N; nxt++){
        if(next_char == S.at(nxt)){
            now_vec.push_back(nxt);
            dfs(next_char, ans, nxt, N, now_vec, A, S);
        }
    }

    now_vec.pop_back();
    return;
}

int main() {
    i64 N;
    cin >> N;
    vector<i64> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    string S;
    cin >> S;

    i64 ans = 0;
    vector<int> now_vec;
    for(int i = 0; i < N; i++){
        if(S.at(i) == 'M'){
            now_vec.push_back(i);
            dfs('M', ans, i, N, now_vec, A, S);
        }
    }

    cout << ans << endl;
}