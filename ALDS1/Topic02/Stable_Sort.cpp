#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9
#define INFL 1e18
#define MOD 1e9 + 7
#define EPS 1e-10

/* 安定なソート 
(キーが同じである要素が2つ以上存在するデータをソートした場合、
 ソート前とソート後でそれらの要素の順番が変わらないようなソート) */

struct TRAMP {
    char mark;
    int number;
};              

int main()
{
    int n;
    cin >> n;
    TRAMP select[n], bubble[n];

    for (int i = 0; i < n; i++) 
    {
        string s;
        cin >> s;
        select[i].mark = s[0];          // トランプのマークと数字を入力
        select[i].number = s[1] - '0';
        bubble[i] = select[i];
    }

    // バブルソート
    for (int i = n - 1; i >= 0; i--) 
    {
        for (int j = 0; j < i; j++) 
        {
            if (bubble[j].number > bubble[j + 1].number)
                swap(bubble[j], bubble[j + 1]);
        }
    }

    // 選択ソート
    for (int i = 0; i < n - 1; i++) 
    {
        int mini = i;
        for (int j = i + 1; j < n; j++)
        {
            if (select[j].number < select[mini].number)
                mini = j;
        }
        if (i != mini)
            swap(select[i],select[mini]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << bubble[i].mark << bubble[i].number;
        if (i == n - 1) cout << endl;
        else    cout << " ";
    }
    // バブルソートは常に安定
    cout << "Stable" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << select[i].mark << select[i].number;
        if (i == n - 1) cout << endl;
        else    cout << " ";
    }

    // バブルソートと同じ値なら安定したソート
    string ans = "Stable";
    for (int i = 0; i < n; i++)
    {
        if (select[i].number != bubble[i].number || select[i].mark != bubble[i].mark)
            ans = "Not stable";
    }
    cout << ans << endl;
    return 0;
}