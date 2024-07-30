#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int n; cin >> n;
        cout << '#' << test_case << ' ';

        if (n % 2 == 0)
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }
    return 0;
}
