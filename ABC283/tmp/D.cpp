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

    int N = S.size();
    // vector<int> leftPos(N, 0);
    // int lastLeftIndex = 0;
    // int lCnt = 0;
    // // vector<int> rightPos(N, 0);
    // // int lastRightIndex = 0;
    // int lrCnt = 0;
    deque<char> boxD, leftPos;
    set<char> boxS;
    int lrCnt = 0, cmb = 1;
    bool OK = true;

    debugP(point33);

    for(int i = 0; i < N; i++){

        debugL(i);
        debugP(point37);

        if(S.at(i) == '('){

            debugP(routeA);

            leftPos.push_back(i);
            lrCnt++;

            debugP(routeA);
        }
        else if(S.at(i) == ')'){

            debugP(routeB);

            if(boxD.empty()){
                continue;
            }

            lrCnt--;
            int nowLeftPos = leftPos.back();
            leftPos.pop_back();
            int subSize = i - nowLeftPos + 1;
            subSize -= cmb*2;
            set<char> eraSet;

            debugP(pointB1);

            for(int repI = 0; repI < subSize; repI++){

                debugL(repI);
                debugP(pointB2);

                if(boxD.empty()){
                    break;
                }

                if(eraSet.count(boxD.back())){
                    continue;
                }
                else{
                    eraSet.insert(boxD.back());
                    boxS.erase(boxD.back());
                    boxD.pop_back();
                }

                debugP(pointB3);
            }

            if(lrCnt > 0){
                cmb++;
            }
            else{
                cmb = 1;
            }

            debugP(routeB);
        }
        else{
            debugP(routeC);

            if(boxS.count(S.at(i))){
                OK = false;
                break;
            }
            else{
                boxS.insert(S.at(i));
                boxD.push_back(S.at(i));
            }

            debugP(routeC);
        }
    }

    debugP(point81);

    cout << (OK ? "Yes" : "No") << '\n';
}