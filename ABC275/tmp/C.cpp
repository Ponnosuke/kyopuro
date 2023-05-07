#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

vector<int> dr = {0, 1, 1};
vector<int> dc = {1, 1, 0};

vector<vector<bool>> seen(81, vector<bool>(81, false));

int main() {
    vector<string> S(9);
    for(int i = 0; i < 9; i++){
        cin >> S.at(i);
    }

    set<pair<pair<int, int>, pair<int, int>>> sp;

    i64 ans = 0;
    for(int r = 0; r < 9; r++){
        for(int c = 0; c < 9; c++){

            if(S.at(r).at(c) == '#'){
                for(int i = 0; i < 9; i++){
                    for(int j = 0; j < 9; j++){

                        if((r == i) && (c == j)){
                            continue;
                        }

                        if(S.at(i).at(j) == '#'){
                            pair<pair<int, int>, pair<int, int>> pair1 = make_pair(make_pair(r, c), make_pair(i, j));
                            pair<pair<int, int>, pair<int, int>> pair2 = make_pair(make_pair(i, j), make_pair(r, c));
                            if(sp.count(pair1) || sp.count(pair2)){
                                continue;
                            }
                            else{
                                sp.insert(pair1);
                                sp.insert(pair2);
                            }

                            int vecR = i - r, vecC = j - c;
                            int nR1 = -vecC, nC1 = vecR;
                            int nR2 = -nR1, nC2 = -nC1;

                            // debug
                            // cerr << "r, c, i, j = " << r + 1 << " " << c + 1 << " " << i + 1 << " " << j + 1 << '\n';


                            if((0 <= (r + nR1)) && ((r + nR1) < 9) && (0 <= (i + nR1)) && ((i + nR1) < 9)){
                                if((0 <= (c + nC1)) && ((c + nC1) < 9) && (0 <= (j + nC1)) && ((j + nC1) < 9)){

                                    pair<pair<int, int>, pair<int, int>> pair3 = make_pair(make_pair(r + nR1, c + nC1), make_pair(i + nR1, j + nC1));
                                    pair<pair<int, int>, pair<int, int>> pair4 = make_pair(make_pair(i + nR1, j + nC1), make_pair(r + nR1, c + nC1));
                                    if((!sp.count(pair3)) && (!sp.count(pair4))){
                                        if(S.at(r + nR1).at(c + nC1) == '#'){
                                            if(S.at(i + nR1).at(j + nC1) == '#'){
                                                ans++;

                                                // debug
                                                // cerr << "ans!" << '\n';
                                                // cerr << "r, c, i, j = " << r + 1 << " " << c + 1 << " " << i + 1 << " " << j + 1 << '\n';

                                            }
                                        }
                                    }
                                }
                            }

                            if((0 <= (r + nR2)) && ((r + nR2) < 9) && (0 <= (i + nR2)) && ((i + nR2) < 9)){
                                if((0 <= (c + nC2)) && ((c + nC2) < 9) && (0 <= (j + nC2)) && ((j + nC2) < 9)){

                                    pair<pair<int, int>, pair<int, int>> pair3 = make_pair(make_pair(r + nR2, c + nC2), make_pair(i + nR2, j + nC2));
                                    pair<pair<int, int>, pair<int, int>> pair4 = make_pair(make_pair(i + nR2, j + nC2), make_pair(r + nR2, c + nC2));
                                    if((!sp.count(pair3)) && (!sp.count(pair4))){
                                        if(S.at(r + nR2).at(c + nC2) == '#'){
                                            if(S.at(i + nR2).at(j + nC2) == '#'){
                                                ans++;

                                                // debug
                                                // cerr << "ans!\n";
                                                // cerr << "r, c, i, j = " << r + 1 << " " << c + 1 << " " << i + 1 << " " << j + 1 << '\n';

                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << ans / 2 << '\n';
}