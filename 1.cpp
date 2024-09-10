#include <bits/stdc++.h>
#define ll long long
using namespace std;
double p[4][45]; // i种地j作物的利润/亩
ll s[65]; // 地的面积
ll sum[4]; // 种类地的总面积
ll dp[10][65]; // 第i年,第j块地的最大收益
bool vis[10][4][65]; // 第k年,第i种地是否存在第j种作物
struct node
{
    int a,b,c;
    double value;
}ans[10]; 
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m,x;
    double y;
    cin >> n; // 地数量
    cin >> m; // 作物种类数
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= 6; i++) sum[1] += s[i];
    for (int i = 7; i <= 20; i++) sum[2] += s[i];
    for (int i = 21; i <= 26; i++) sum[3] += s[i];
    for (int i = 1; i <= n; i++) // 处理2023年旱，梯，坡地的作物占地情况
    {
        cin >> x;
        vis[0][x][i] = true; // 标记
    }

    // 旱地
    for (int i = 1; i <= m; i++) cin >> p[1][i];

    // 梯田
    for (int i = 1; i <= m; i++) cin >> p[2][i];

    // 山坡地
    for (int i = 1; i <= m; i++) cin >> p[3][i];

    for (int i = 1; i <= 7; i++)
    {
        double temp = -99999999;
        int index = 0;
        for (int j = 1; j <= m; j++)
        {
            if (vis[i-1][1][j]) continue;
            if (p[1][j] > temp)
            {
                index = j;
                temp = p[1][j];
            }
        }
        // 记录方案并累加答案
        ans[i].a = index;
        ans[i].value += temp*s[1];
        vis[i][1][index] = true;

        //初始化
        temp = -99999999;
        index = 0;
        for (int j = 1; j <= m; j++)
        {
            if (vis[i-1][2][j]) continue;
            if (p[2][j] > temp)
            {
                index = j;
                temp = p[2][j];
            }
        }
        ans[i].b = index;
        ans[i].value += temp*s[2];
        vis[i][2][index] = true;
        temp = -99999999;
        index = 0;
        for (int j = 1; j <= m; j++)
        {
            if (vis[i-1][3][j]) continue;
            if (p[3][j] > temp)
            {
                temp = p[3][j];
                index = j;
            }
        }
        ans[i].c = index;
        ans[i].value += temp*s[3];
        vis[i][3][index] = true;
        vis[i][3][index] = true;
    }
    for (int i = 1; i <= 7; i++)
    {
        cout << i + 2023 << ":\n";
        cout << ans[i].a << " " << " " << ans[i].b << " " << ans[i].c << " " << ans[i].value << "\n";
    }    
    return 0;
}