/*
    愚直解
    O(|T| ^ 2) でこれだと間に合わない TLE
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef LOCAL_DEBUG
    #define debug(X) std::cerr << X << " "
    #define debugV(X) std::cerr << #X << " = " << X << ", "
    #define debugVL(Y) std::cerr << #Y << " = " << Y << '\n'
    #define debugWL(Z) std::cerr << #Z << '\n'
#else
    #define debug(X)
    #define debugV(X)
    #define debugVL(Y)
    #define debugWL(Z)
#endif

const int T_SIZE = 3;
const int S_SIZE = T_SIZE + 2;
const int LOOP = 100;

i64 myRnd64(i64 L, i64 R){
    random_device seedGen;
    mt19937_64 rd(seedGen());

    i64 ret = L + (rd() % (R - L + 1));

    return ret;
}

char myGetChar(){
    int num = myRnd64(0, 50);
    if(num >= 26){
        return '?';
    }
    else{
        return (char)('a' + num);
    }
}

pair<string, string> genST(){
    string retS = "", retT = "";
    for(int i = 0; i < S_SIZE; i++){
        retS += myGetChar();
    }
    for(int i = 0; i < T_SIZE; i++){
        retT += myGetChar();
    }

    return make_pair(retS, retT);
}

// 愚直解
vector<bool> solve1(string S, string T){
    int Tsize = T.size();
    int Ssize = S.size();
    vector<bool> flags(Tsize + 1, true);

    for(int x = 0; x <= Tsize; x++){

        string now = "";
        if(x > 0){
            now += S.substr(0, x);
        }
        now += S.substr(Ssize - (Tsize - x), Tsize - x);

        debugV(x);
        debugVL(now);

        for(int i = 0; i < Tsize; i++){
            char nowS = now.at(i), nowT = T.at(i);
            if(nowS == '?' || nowT == '?' || nowS == nowT){
                continue;
            }
            else{
                debugVL(i);
                debugV(nowS);
                debugVL(nowT);
                flags.at(x) = false;
                break;
            }
        }
    }

    return flags;
}

vector<bool> solve2(string S, string T){
    int Tsize = T.size(), Ssize = S.size();

    vector<bool> ret(Tsize + 1, false);

    // vector<bool> isMatch(Tsize + 1, false);
    int matchCnt = 0;
    bool OK = true;
    for(int x = 0; x <= Tsize; x++){
        if(x == 0){
            string Sdash = S.substr(Ssize - (Tsize - x), Tsize - x);

            for(int i = 0; i < Tsize; i++){
                char nowSdash = Sdash.at(i), nowT = T.at(i);
                if(nowSdash == '?' || nowT == '?' || nowSdash == nowT){
                    matchCnt++;
                }
            }

            if(matchCnt == Tsize){
                ret.at(x) = true;
            }
            else{
                ret.at(x) = false;
            }
        }
        else{
            char nowS = S.at(x-1), nowT = T.at(x-1);

            debugVL(x);
            debugV(nowS);
            debugVL(nowT);
            debugWL(before);
            debugVL(matchCnt);

            if(nowS == nowT || nowS == '?' || nowT == '?'){
                matchCnt = min(matchCnt + 1, Tsize);
            }
            else{
                OK = false;
                matchCnt = max(matchCnt - 1, 0);
            }

            debugWL(after);
            debugVL(matchCnt);

            if(matchCnt == Tsize && OK){
                ret.at(x) = true;
            }
            else{
                ret.at(x) = false;
            }

            debugWL();
        }
    }

    return ret;
}

int main() {
    for(int rep = 0; rep < LOOP; rep++){
        pair<string, string> p = genST();
        string S = p.first, T = p.second;
        vector<bool> flags1 = solve1(S, T);
        vector<bool> flags2 = solve2(S, T);

        if(flags1 == flags2){
            continue;
        }
        else{
            cout << "NG" << '\n';
            debugV(S);
            debugVL(T);
            debugWL(solve1);
            for(auto flag : flags1){
                cout << (flag ? "Yes" : "No") << '\n';
            }
            debugWL(solve2);
            for(auto flag : flags2){
                cout << (flag ? "Yes" : "No") << '\n';
            }
            break;
        }
    }

    cout << "finish" << '\n';

    return 0;
}