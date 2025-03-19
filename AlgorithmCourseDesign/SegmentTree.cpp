#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int w[N];

typedef struct Node {
    int l, r;
    int sum;
} SegmentTree;

SegmentTree tr[N];

void push_up(int u) { // 用左右两个儿子算一下当前节点信息
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum; // 2*u和2*u+1
}

void build(int u, int l, int r) { // u：根节点下标，l：左边界，r：右边界
    if (l == r) tr[u] = {l, r, w[r]}; // 叶节点：直接赋值
    else { // 不是叶节点：平分当前区间，递归下去
        tr[u] = {l, r}; // 给左右边界赋初值
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        push_up(u);
    }
}

int query(int u, int l, int r) {  // u：根节点编号，l、r：查询区间
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;

    int mid = tr[u].l + tr[u].r >> 1; // 树中的中点
    int sum = 0;
    if (l <= mid) sum += query(u << 1, l, r); // 和左边有交集
    if (r > mid) sum += query(u << 1 | 1, l, r); // 和右边有交集
    return sum;
}

void modify(int u, int x, int v) { // u为根节点编号，在x的位置上加v
    if (tr[u].l == tr[u].r) tr[u].sum += v;
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);
        push_up(u);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    build(1, 1, n);
    int k, a, b;
    while (m--) {
        scanf("%d%d%d", &k, &a, &b);
        if (k == 0) printf("%d\n", query(1, a, b));
        else modify(1, a, b);
    }
    return 0;
}
