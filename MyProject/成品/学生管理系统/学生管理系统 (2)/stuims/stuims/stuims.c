#define _CRT_SECURE_NO_WARNINGS
#include"BasicInfo.h"
#include"YxInfo.h"
#include"JGInfo.h"
#include"PyInfo.h"
#include"ScoreInfo.h"
void menu() {
	gotoxy(20, 3);
	printf("------学生管理系统----------\n");
	gotoxy(20, 5);
	printf("-----1.管理学生基本信息 ----------\n");
	gotoxy(20, 7);
	printf("-----2.管理学生院系信息 ----------\n");
	gotoxy(20, 9);
	printf("-----3.管理学生籍贯信息 ----------\n");
	gotoxy(20, 11);
	printf("-----4.管理培养计划 ----------\n");
	gotoxy(20, 13);
	printf("-----5.管理学生成绩 ----------\n");
	gotoxy(20, 15);
	printf("-----0.退出系统 ----------\n");
	gotoxy(20, 17);
	printf("请输入（0~5）：\n");
}
int main()
{
	int c = -1;
	while (c != 0) {
		menu();
		scanf("%d", &c);
		switch (c) {
				case 1: {
					BasicInfo();
					break;
				}
				case 2: {
					YxInfo();
					break;
				}
				case 3: {
					JGInfo();
					break;
				}
				case 4: {
					PyInfo();
					break;
				}
				case 5: {
					ScoreInfo();
					break;
				}
				default:break;
		}
		system("cls");
	}
	

}