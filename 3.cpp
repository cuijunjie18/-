#include <bits/stdc++.h>
#define ll long long
#define MAXN 100005
using namespace std;
ll tree[MAXN<<1];
int ls[MAXN<<1],rs[MAXN<<1];
int rt,tot;
ll n,md;
int Build(int l,int r)
{
    int root = ++tot;
    if (l == r)
    {
        tree[root] = 1;
        return root;
    }
    int mid = (l + r) >> 1;
    ls[root] = Build(l,mid);
    rs[root] = Build(mid + 1,r);
    tree[root] = tree[ls[root]]*tree[rs[root]];
    return root;
}
void update(int root,int l,int r,int pos,ll k)
{
    if (l == r)
    {
        tree[root] = k;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) update(ls[root],l,mid,pos,k);
    else update(rs[root],mid + 1,r,pos,k);
    tree[root] = tree[ls[root]]*tree[rs[root]]%md;
}
void Solve()
{
    ll c,x;
    cin >> n >> md;
    tot = 0;
    rt = Build(1,n);
    for (int i = 1; i <= n; i++)
    {
        cin >> c >> x;
        if (c == 1)
        {
            update(rt,1,n,i,x);
            cout << tree[rt] << "\n";
        }
        else if (c == 2)
        {
            update(rt,1,n,x,1);
            cout << tree[rt] << "\n";
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
