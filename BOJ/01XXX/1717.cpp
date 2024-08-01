//https://www.acmicpc.net/problem/1717

#include<iostream>

using namespace std;

int n, m;
int parent[1000001];

int getP(int num) {
    if (parent[num] == num)
        return num;
    else
        return parent[num] = getP(parent[num]);
}

void unionP(int a, int b) {
    a = getP(a);
    b = getP(b);
    if (a > b)
        parent[a] = b;
    else
        parent[b] = a;
}

void findP(int a, int b) {
    a = getP(a);
    b = getP(b);
    if (a == b)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        parent[i] = i;

    for (int i = 0; i < m; ++i) {
        bool flag;
        int a, b; cin >> flag >> a >> b;
        if (!flag)
            unionP(a, b);
        else
            findP(a, b);
    }
}
