//https://www.acmicpc.net/problem/14719

#include <iostream>

using namespace std;

int h, w;
int arr[501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> h >> w;

    int Max = 0, idx = 0;
    for (int i = 0; i < w; ++i)
    {
        cin >> arr[i];
        if(arr[i] > Max)
        {
            Max = max(Max, arr[i]);
            idx = i;
        }
    }

    int ans = 0;
    Max = arr[0];
    for (int i = 1; i < idx; ++i)
    {
        if (arr[i] > Max)
            Max = arr[i];
        else
            ans += Max - arr[i];
    }
    Max = arr[w - 1];
    for (int i = w - 1; i >= idx; --i)
    {
        if (arr[i] > Max)
            Max = arr[i];
        else
            ans += Max - arr[i];
    }

    cout << ans;
}
