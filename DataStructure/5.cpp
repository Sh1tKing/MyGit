#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int furthestDistanceFromOrigin(string moves) {
    int num = moves.length();
    char a[51];
    int left = 0, right = 0, ans = 0, i;
    for (i = 0; i < moves.length(); i++) {
        a[i] = moves[i];
    }
    a[i] = '\0';
    for (int i = 0; i < num; i++) {
        if (a[i] == 'L') left++;
        if (a[i] == 'R') right++;
    }
    if (left == right) ans = num - left - right;
    else if (left < right) ans = num - left - left;
    else ans = num - right - right;
    return ans;
}
int main() {       // 0,1,2,3,0,4,2
    string n = "RLR_LLL";
    cout<<furthestDistanceFromOrigin(n);
}