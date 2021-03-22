#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

int main()
{
     string s;
     cin >> s;
     // 水たまりの面積
     deque<pair<int, int> > water;  
     deque<int> deq;
     for (int i = 0; i < s.size(); i++)
     {
         if (s[i] == '\\') deq.push_back(i);    // 下向きの場合
         else if (s[i] == '/' && !deq.empty())  // 上向きかつ空じゃない場合
         {
             int num = deq.back();
             deq.pop_back();
             int area = i - num;
             while (!water.empty() && num <= water.back().first)
             {
                area += water.back().second;
                water.pop_back();
             }
             water.push_back(make_pair(num, area));
         }
     }
     // 水たまりの総面積
     int sum = 0;
     int sz = water.size();
     for (int i = 0; i < sz; i++)
     {
         sum += water[i].second;
     }
     cout << sum << endl;
     cout << sz;
     for (int i = 0; i < sz; i++)
     {
         cout << " " << water[i].second;
     }
     cout << endl;
     return 0;
}