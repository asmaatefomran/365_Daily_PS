//Day4  8/5/2026
//https://leetcode.com/problems/champagne-tower/description/
//Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {

        vector<vector<double>> v(101, vector<double>(101, 0.0));

        queue<pair<int,int>> q;
        set<pair<int,int>> done;

        v[0][0] = poured;
        q.push({0, 0});
        done.insert({0, 0});

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            if (i >= 100) continue;

            if (v[i][j] > 1.0) {
                double extra = v[i][j] - 1.0;
                v[i][j] = 1.0;

                if (j <= i) {
                    v[i + 1][j] += extra / 2.0;
                    if (!done.count({i + 1, j})) {
                        q.push({i + 1, j});
                        done.insert({i + 1, j});
                    }
                }

                if (j + 1 <= i + 1) {
                    v[i + 1][j + 1] += extra / 2.0;
                    if (!done.count({i + 1, j + 1})) {
                        q.push({i + 1, j + 1});
                        done.insert({i + 1, j + 1});
                    }
                }
            }
        }

        return min(1.0, v[query_row][query_glass]);
    }
};
