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

int ope(int now, int num, char ch){
    if(ch == '+'){
        return now + num;
    }
    else{
        return now - num;
    }
}

int main() {
    vector<int> num(4, 0);
    for(int i = 0; i < 4; i++){
        char ch;
        cin >> ch;
        num.at(i) = (int)(ch - '0');
    }

    char op1, op2, op3;
    string list = "+-";
    bool stop = false;
    for(auto ch1 : list){
        for(auto ch2 : list){
            for(auto ch3 : list){
                int now = num.at(0);
                now = ope(now, num.at(1), ch1);
                now = ope(now, num.at(2), ch2);
                now = ope(now, num.at(3), ch3);

                if(now == 7){
                    op1 = ch1;
                    op2 = ch2;
                    op3 = ch3;
                    stop = true;
                    break;
                }
            }

            if(stop){
                break;
            }
        }

        if(stop){
            break;
        }
    }

    cout << num.at(0) << op1 << num.at(1) << op2 << num.at(2) << op3 << num.at(3) << "=7" << endl;

    return 0;
}