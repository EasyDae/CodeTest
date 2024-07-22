#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

vector<vector<int>> vec;
bool visited[10001];
int parent[10001];
int Tsize;

void CalcSize(int n) {
    visited[n] = 1;
    Tsize++;

    for (int x : vec[n])
        if (!visited[x])
            CalcSize(x);
}

int Find(int a, int b) {
    memset(visited, 0, sizeof(visited));

    while (a) {
        visited[a] = 1;
        a = parent[a];
    }

    while (!visited[b])
        b = parent[b];

    return b;
}

int main(int argc, char** argv){
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case){
        int v, e, A, B; cin >> v >> e >> A >> B;
        vec = vector<vector<int>>(v + 1);

        for (int i = 0; i < e; ++i) {
            int a, b; cin >> a >> b;
            vec[a].push_back(b);
            parent[b] = a;
        }

        int P = Find(A, B);

        memset(visited, 0, sizeof(visited));
        Tsize = 0;
        CalcSize(P);

        cout << "#" << test_case << " " << P << " " << Tsize << endl;
    }
    return 0;
}
