//
// Created by Raaay on 24-12-17.
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

using PII = pair<int, int>;
#define x first
#define y second

const int N = 400 + 9;

int n, m, x, y;
int mp[N][N];

int dx[] = {-1, -1, 1, 1, -2, -2, 2, 2},
    dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

void bfs() {
    memset(mp, -1, sizeof mp);
    mp[x][y] = 0;
    queue<PII> q;
    q.push({x, y});

    while (!q.empty()) {
        PII t = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = t.x + dx[i], ny = t.y + dy[i];
            if (nx < 1 || ny < 1 || nx > n || ny > m) continue;  // 出界
            if (mp[nx][ny] != -1) continue;  // 之前走过
            mp[nx][ny] = mp[t.x][t.y] + 1;
            q.push({nx, ny});
        }
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &x, &y);
    bfs();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) printf("%-5d", mp[i][j]);
        puts("");
    }
    return 0;
}


/*
 *
输入数据
3 3 1 1
正确结果
0    3    2
3    -1   1
2    1    4

*/