//https://www.acmicpc.net/problem/2470

#include <iostream>
#include <algorithm>

using namespace std;

long long arr[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    sort(arr, arr + n);

    int left = 0, right = n - 1;
    long long a = arr[left], b = arr[right];
    int diff = abs(a + b);

    while (left < right)
    {
        int tmp = arr[left] + arr[right];

        if (abs(tmp) < diff)
        {
            diff = abs(tmp);
            a = arr[left], b = arr[right];
        }

        if (tmp >= 0)
            right--;
        else
            left++;
    }

    cout << a << ' ' << b;
}
