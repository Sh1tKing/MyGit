#include<iostream>
using namespace std;
#define ll long long
int main() {
    int a[100005] = { 0 }, b[100005] = { 0 };
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)cin >> a[i];

    for (int j = 1; j <= n; j++)
    {
        b[j] = a[j] - a[j - 1];
    }
    while (m--)
    {
        int l, r, c;
        cin >> l >> r >> c;
        b[l] = b[l] + c;
        b[r + 1] = b[r + 1] - c;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {

        sum = sum + b[i];
        cout << sum << " ";
    }
}