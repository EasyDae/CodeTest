#include<iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
 
pair<int, int> comp, home;
vector<pair<int, int>> vec;
bool visited[10];
int n, Min = 2147483647;
 
int Dist(pair<int, int> a, pair<int, int> b)
{
    return abs(b.first - a.first) + abs(b.second - a.second);
}
 
void DFS(pair<int, int> cur, int cnt, int dist)
{
    if(dist >= Min)
        return;
     
    if(cnt == n)
    {
        dist += Dist(cur, home);
        Min = min(dist, Min);
        return;
    }
     
    for(int i=0; i<n; ++i)
    {
        if(!visited[i])
        {
            visited[i] = 1;
            DFS(vec[i], cnt+1, dist + Dist(cur, vec[i]));
            visited[i] = 0;
        }
    }
}
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
 
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> n;
        for(int i=0; i<n; ++i)
            visited[i] = 0;
        Min = 2147483647;
         
        vec = vector<pair<int, int>>(n);
         
        cin >> comp.first >> comp.second;
        cin >> home.first >> home.second;
         
        for(int i=0; i<n; ++i)
            cin >> vec[i].first >> vec[i].second;
         
        DFS(comp, 0, 0);
         
        cout << '#' << test_case << ' ' << Min << '\n';
    }
    return 0;
}
