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
    i64 N, K, Q;
    cin >> N >> K >> Q;
    vector<i64> X(Q), Y(Q);
    for(int i = 0; i < Q; i++){
        cin >> X.at(i) >> Y.at(i);
        X.at(i)--;
    }

    map<i64, i64> up_map, down_map;  // first := value,  second := cnt
    i64 up_size = K, down_size = 0;
    up_map[0] = K;
    down_map[0] = N-K;
    i64 now_sum = 0;
    vector<i64> A(N, 0);
    for(int query = 0; query < Q; query++){
        i64 target_index = X.at(query), alt_value = Y.at(query);

        i64 prev_value = A.at(target_index);
        bool target_up = false;
        if(up_map.count(prev_value)){
            up_map[prev_value]--;
            if(up_map[prev_value] == 0){
                up_map.erase(prev_value);
            }

            now_sum -= prev_value;

            target_up = true;
        }
        else{
            down_map[prev_value]--;
            if(down_map[prev_value] == 0){
                down_map.erase(prev_value);
            }
        }

        if(target_up){
            // up K-1, down N-K
            i64 down_map_max = down_map.rbegin()->first;
            if(alt_value >= down_map_max){
                up_map[alt_value]++;
                now_sum += alt_value;
            }
            else{
                down_map[down_map_max]--;
                if(down_map[down_map_max] == 0){
                    down_map.erase(down_map_max);
                }

                up_map[down_map_max]++;
                down_map[alt_value]++;
                now_sum += down_map_max;
            }
        }
        else{  // up K, down N-K-1
            i64 up_map_min = up_map.begin()->first;
            if(alt_value > up_map_min){  // 上に追加
                up_map[up_map_min]--;
                if(up_map[up_map_min] == 0){
                    up_map.erase(up_map_min);
                }

                now_sum -= up_map_min;
                up_map[alt_value]++;
                now_sum += alt_value;
                down_map[up_map_min]++;
            }
            else{
                down_map[alt_value]++;
            }
        }

        A.at(target_index) = alt_value;

        cout << now_sum << '\n';
    }
}