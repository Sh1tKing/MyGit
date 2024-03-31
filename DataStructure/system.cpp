#define _CRT_NO_SECURE_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int n = 1;
double weg[7];//rank
int cal[30];
double price[30][8];//0num 1price 2tprice 3discount 4dsell 5dincome 6zsell 7zincome
char fruit[30][10];
void Show() {
	int ln = 0;
	printf("                 菜单\n");
	for (int i = 1; i <= n - 1; i++) {
		printf("%s %.1f￥/斤", fruit[i], price[i][2]);
		ln++;
		if (ln % 2 == 0) printf("\n");
		else printf("   ");

	}
	printf("\n");
	printf("----------------------------------------\n");
	printf("             系统界面\n");
	printf("          1.添加水果\n");
	printf("          2.查看各类水果基本情况\n");
	printf("          3.修改价格\n");
	printf("          4.结账\n");
	printf("          5.展示排行榜\n");
	printf("          6.显示销售情况\n");
	printf("          7.退出系统\n");
	printf("          请选择：\n");
}
void AddFruit() {
	printf("请输入（水果编号：水果名称):\n");
	scanf("%s", &fruit[n]);
	printf("请输入销售价格：\n");
	scanf("%lf", &price[n][1]);
	price[n][2] = price[n][1];
	n++;
}
void CalBasicPrice() {
	for (int i = 1; i <= n - 1; i++) {
		price[i][3] = price[i][2] / price[i][1];
		printf("%s   销售价格：%.2f￥   当天销售价格：%.2f￥   优惠折扣：%.2f    销售量%.1f斤    销售金额%.2f\n", fruit[i], price[i][1], price[i][2], price[i][3], price[i][4], price[i][5]);
	}
}
void ChangePrice() {
	int num;
	printf("请输入水果编号：\n");
	scanf("%d", &num);
	price[num][0] = num;
	printf("请输入当天销售价格：\n");
	scanf("%lf", &price[num][2]);
}
void Check() {
	double z = 0, zz;
	while (1) {
		int num;
		printf("请输入水果编号：\n");
		scanf("%d", &num);
		cal[num]++;
		double weight;
		printf("请输入水果重量：\n");
		scanf("%lf", &weight);
		zz = price[num][2] * weight;
		z += price[num][2] * weight;
		weg[num] += zz;
		price[num][5] += zz;
		price[num][7] += zz;
		price[num][4] += weight;
		price[num][6] += weight;
		printf("1.继续添加 2.退出\n");
		scanf("%d", &num);
		if (num == 1) continue;
		else {
			printf("总共%.2f￥\n", z);
			system("pause");
			system("cls");
			break;
		}
	}
}
void Rank() {
	int p[30] = { 0 };
	for (int i = 1; i <= n - 1; i++) p[i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i; j++) {
			if (weg[j] < weg[j + 1]) {
				swap*
			}
		}
	}
	for (int i = 1; i <= n - 1; i++) printf("%s  销售量：%.1f\n", fruit[i], weg[i]);
}
void AllIncome() {
	double num = 0;
	for (int i = 1; i <= n - 1; i++) {
		printf("%s   当天销售总量：%.1f斤   当天销售金额：%.2f￥  总销售金额：%.2f￥\n", fruit[i], price[i][4], price[i][5], price[i][7]);
		num += price[i][5];
	}
	printf("总共营业额:%.2f￥\n", num);
}
int main() {
	int num = 0;
	while (1) {
		Show();
		scanf("%d", &num);
		switch (num) {
		case 1: {
			AddFruit();
			system("cls");
			break;
		}
		case 2: {
			CalBasicPrice();
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			ChangePrice();
			system("cls");
			break;
		}
		case 4: {
			Check();
			system("cls");
			break;
		}
		case 5: {
			Rank();
			system("pause");
			system("cls");
			break;
		}
		case 6: {
			AllIncome();
			for (int i = 1; i <= n - 1; i++) { weg[i] = 0; price[i][4] = 0; price[i][5] = 0; }
			system("pause");
			system("cls");
			break;
		}
		case 7: {
			printf("系统已退出\n");
			system("pause");
			return 0;
		}
		}
	}
}