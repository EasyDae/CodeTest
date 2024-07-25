//map 사용

#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

map<string, int> m;
string arr[10001];

bool comp(string s1, string s2) {
    return m[s1] < m[s2];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    m["ZRO"] = 0;
    m["ONE"] = 1;
    m["TWO"] = 2;
    m["THR"] = 3;
    m["FOR"] = 4;
    m["FIV"] = 5;
    m["SIX"] = 6;
    m["SVN"] = 7;
    m["EGT"] = 8;
    m["NIN"] = 9;

    for (int i = 1; i <= 1; ++i) {
        string TC; cin >> TC;
        cout << TC << '\n';
        int n; cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        sort(arr, arr + n, comp);
        for (int i = 0; i < n; ++i)
            cout << arr[i] << ' ';
        cout << '\n';
    }
}

//if 조건문 사용

#include<iostream>

using namespace std;

string arr[10] = {"ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN"};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    for (int i = 1; i <= t; ++i) {
        string tc, s;
        int count[10] = {0, };
        int n;
        cin >> tc >> n;
        
        for(int j = 0; j < n; j++)
        {
            cin >> s;
            if(s == "ZRO")
                count[0]++;
            else if(s == "ONE")
                count[1]++;
            else if(s == "TWO")
                count[2]++;
            else if(s == "THR")
                count[3]++;
            else if(s == "FOR")
                count[4]++;
            else if(s == "FIV")
                count[5]++;
            else if(s == "SIX")
                count[6]++;
            else if(s == "SVN")
                count[7]++;
            else if(s == "EGT")
                count[8]++;
            else if(s == "NIN")
                count[9]++;
        }
        
        cout << tc << endl;
        for(int j = 0; j < 10; j++)
            if(count[j] != 0)
                for(int k = 0; k < count[j]; k++)
                    cout << arr[j] << " ";
        
        cout << '\n';
    }
}
