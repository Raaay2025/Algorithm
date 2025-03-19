//
// Created by Raaay on 24-12-17.
// 广度优先搜索实现Flood Fil算法【分支限界法】
//

#include <bits/stdc++.h>

using namespace std;
using LL = long long;

#define x first
#define y second
using PII = pair<int, int>;

const int N = 310;

int n, res;
char mp[N][N];
int g[N][N];
bool used[N][N];

int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1},
        dy[] = {1, 1, 1, 0, 0, -1, -1, -1};

void getNum(int x, int y) {
    if (mp[x][y] == '*') {
        g[x][y] = 9;
        return;
    }
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (mp[nx][ny] == '*') cnt++;
    }
    g[x][y] = cnt;
}

void bfs(PII start) {
    queue<PII> q;
    q.push(start);
    used[start.x][start.y] = true;

    while (!q.empty()) {
        PII f = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int x = f.x + dx[i], y = f.y + dy[i];
            if (x < 0 || y < 0 || x >= n || y >= n || used[x][y] || g[x][y] == 9) continue;

            used[x][y] = true;
            if (g[x][y] == 0) q.push({x, y});
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> mp[i];

    // typedef std::chrono::high_resolution_clock Clock;
    // auto t1 = Clock::now(); //计时开始

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            getNum(i, j);
        }
    }
    res = 0;
    memset(used, 0, sizeof used); // 全部set为false
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!used[i][j] && g[i][j] == 0) {
                bfs({i, j});
                res++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!used[i][j] && g[i][j] != 9) res++;
        }
    }

    // auto t2 = Clock::now(); //计时结束
    // cout << chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << "ns.\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << g[i][j];
        }
        cout << '\n';
    }
    cout << "Minimum number of clicks to win is " << res << ".\n";
    return 0;
}


/*
测试数据1
3
..*
..*
**.
测试结果：2


测试数据2
5
..*..
..*..
.*..*
.*...
.*...
测试结果：8


测试数据3：
10
*.........
..*..*..**
..........
.......*..
*.*.....*.
.*........
*.........
.*..*...*.
....**....
.......*.*
测试结果：45

*/