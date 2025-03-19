//
// Created by Raaay on 24-12-17.
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 9;

int n, m;
int a[N], tr[N];

int lowbit(int x) {  // 求2^x
    return x & -x;
}

void add(int x, int v) {  // 更新树状数组：在x的位置加v
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += v;
}

int query(int x) {  // 求前缀和
    int res = 0;
    for (int i = x; i > 0; i -= lowbit(i)) res += tr[i];
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);  // 读入原数组
    for (int i = 1; i <= n; i++) add(i, a[i]);  // 初始化树状数组

    while (m--) {
        int k, x, y;
        scanf("%d%d%d", &k, &x, &y);
        if (k == 0) printf("%d\n", query(y) - query(x - 1));
        else add(x, y);
    }
    return 0;
}