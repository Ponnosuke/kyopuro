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
    cout << fixed << setprecision(17);

    i64 T, iS, iD;
    cin >> T >> iS >> iD;
    double S = iS, D = iD;



    i64 itime = iD/iS;
    double dtime = D/S;
    bool isInt = false;
    i64 yoruTime = 0;
    if(iD % iS == 0){
        isInt = true;
    }
    if(isInt){
        debugWL(is int);
        yoruTime += (itime / 24)*12;
        itime %= 24;
        dtime = itime;
    }
    else{
        debugWL(is double);
        yoruTime += ((int)dtime / 24)*(12);
        dtime -= (int)(dtime / 24.0)*24;
    }
    double ans = yoruTime;
    double extraTime = 0.0;
    yoruTime = 0;
    debugV(itime);
    debugVL(dtime);

    if(T < 6){
        debugP();
        int cnt = 0;
        for(int rep = 0; rep < 2; rep++){
            debugP();
            while(T < 6){
                if(cnt >= itime){
                    extraTime = dtime - (cnt);
                    break;
                }
                cnt++;
                yoruTime++;
                T++;
            }
            debugP();
            while(T < 18){
                if(cnt >= itime){
                    break;
                }
                cnt++;
                T++;
            }
            debugP();
            while(T < 24){
                if(cnt >= itime){
                    extraTime = dtime - (cnt);
                    break;
                }
                cnt++;
                yoruTime++;
                T++;
            }
            T = 0; 
        }
    }
    else if(18 <= T){
        debugP();
        int cnt = 0;
        for(int rep = 0; rep < 2; rep++){
            debugP();
            while(T < 24){
                if(cnt >= itime){
                    extraTime = dtime - (cnt);
                    break;
                }
                debugP();
                cnt++;
                yoruTime++;
                T++;
            }
            debugP();
            T = 0;
            while(T < 6){
                if(cnt >= itime){
                    extraTime = dtime - (cnt);
                    break;
                }
                debugP();
                cnt++;
                yoruTime++;
                T++;
            }
            debugP();
            while(T < 18){
                if(cnt >= itime){
                    break;
                }
                debugP();
                cnt++;
                T++;
            }
        }
    }
    else{
        debugP();
        int cnt = 0;
        for(int rep = 0; rep < 2; rep++){
            debugP();
            while(T < 18){
                if(cnt >= itime){
                    break;
                }
                cnt++;
                T++;
            }
            debugP();
            while(T < 24){
                if(cnt >= itime){
                    extraTime = dtime - (cnt);
                    break;
                }
                cnt++;
                yoruTime++;
                T++;
            }
            debugP();
            T = 0;
            while(T < 6){
                if(cnt >= itime){
                    extraTime = dtime - (cnt);
                    break;
                }
                cnt++;
                yoruTime++;
                T++;
            }
        }
    }

    debugV(yoruTime);
    debugVL(extraTime);
    if(isInt){
        debugP();
        ans += min(yoruTime, itime);
    }
    else{
        debugP();
        ans += min((double)yoruTime, dtime);
    }
    ans += extraTime;

    cout << ans << endl;
}