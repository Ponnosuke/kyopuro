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
    int N, Q;
    cin >> N >> Q;
    
    vector<int> ballPos(N);  // [i] := ボール i の位置の番号 (i := 0-indexed, 位置 := 0-indexed)
    vector<int> ballIndex(N); // [i] := 位置 i にあるボールの番号 (どっちも 0-indexed)
    for(int i = 0; i < N; i++){
        ballPos.at(i) = i;
        ballIndex.at(i) = i;
    }

    for( ;Q--; ){
        int x;
        cin >> x;
        x--;

        int xPos = ballPos.at(x);
        if(xPos == N-1){
            int targetIndex = ballIndex.at(N-2);
            swap(ballPos.at(x), ballPos.at(targetIndex));
            swap(ballIndex.at(N-1), ballIndex.at(N-2));
        }
        else{
            int targetIndex = ballIndex.at(xPos + 1);  // 交換するボールの番号
            swap(ballPos.at(x), ballPos.at(targetIndex));
            swap(ballIndex.at(xPos), ballIndex.at(xPos + 1));
        }
    }

    for(int i = 0; i < N; i++){
        cout << ballIndex.at(i) + 1;

        if(i < N-1){
            cout << " ";
        }
    }
    cout << endl;
}