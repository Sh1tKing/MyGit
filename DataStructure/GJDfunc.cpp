#include<iostream>
#include<string>
using namespace std;
void jia()
{
	int a[301]={0}, b[301] = { 0 }, c[302] = { 0 };
	string s1,s2;
	cin >> s1;
	cin >> s2;	
	int lena = s1.length();
	int lenb = s2.length();
	for (int i = 0; i < lena; i++)
		a[i] = s1[lena - 1 - i] - '0';
	for (int i = 0; i < lenb; i++)
		b[i] = s2[lenb - 1 - i] - '0';
	int lenc = max(lena, lenb);
	for (int i = 0; i < lenc; i++)
	{
		c[i] += a[i] + b[i];
		if (c[i] >= 10)
		{
			c[i + 1]++;
			c[i] %= 10;
		}
	}
	while (c[lenc] == 0 && lenc > 0)
		lenc--;
	for (int i = lenc; i >= 0; i--)
		cout << c[i];
}
void jian() {
	int a[301] = { 0 }, b[301] = { 0 }, c[302] = { 0 };
	string s1, s2;
	cin >> s1;
	cin >> s2;
	int lena = s1.length();
	int lenb = s2.length();
	for (int i = 0; i < lena; i++)
		a[i] = s1[lena - 1 - i] - '0';
	for (int i = 0; i < lenb; i++)
		b[i] = s2[lenb - 1 - i] - '0';
	int lenc = max(lena, lenb);
	if (lena < lenb || (lena == lenb && s1 < s2))
	{
		swap(a, b);
		cout << "-";
	}
	for (int i = 0; i < lenc; i++)
	{
		c[i] += a[i] - b[i];
		if (c[i] < 0)
		{
			c[i + 1]--;
			c[i] += 10;
		}
	}
	lenc--;
	while (c[lenc] == 0 && lenc > 0)
		lenc--;
	for (int i = lenc; i >= 0; i--)
		cout << c[i];

}
void cheng() {
	int a[301] = { 0 }, b[301] = { 0 }, c[602] = { 0 };
	char n1[105], n2[105], lena, lenb, lenc, j, i, x;

	std::memset(a, 0, sizeof(a));
	std::memset(b, 0, sizeof(b));
	std::memset(c, 0, sizeof(c));

	std::cin >> n1 >> n2;

	lena = std::strlen(n1);
	lenb = std::strlen(n2);

	for (i = 0; i <= lena - 1; i++) a[lena - i] = n1[i] - 48;
	for (i = 0; i <= lenb - 1; i++) b[lenb - i] = n2[i] - 48; // ���򴢴�

	for (i = 1; i <= lena; i++) {
		x = 0;
		for (j = 1; j <= lenb; j++) {
			c[i + j - 1] = c[i + j - 1] + x + a[i] * b[j];
			x = c[i + j - 1] / 10; // ��λ
			c[i + j - 1] %= 10; // ʣ��
		}
		c[i + lenb] = x; // ��λ����
	}

	lenc = lena + lenb;
	while (c[lenc] == 0 && lenc > 1) {
		lenc--; // ɾ��ǰ��0
	}

	for (i = lenc; i >= 1; i--) {
		std::cout << c[i];
	}
}
int main() {
	cheng();
}