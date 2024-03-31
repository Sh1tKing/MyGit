#include<stdio.h>
#include"location.h"
#include<Windows.h>
#include<stdlib.h>
struct StuinfoA
{
	char sfz[40], xm[20], xb[10], date[20];
	int xh;
	struct StuinfoA* next;
};
char* Int2String(int num, char* str)
{
	int i = 0;
	if (num < 0)
	{
		num = -num;
		str[i++] = '-';
	}
	do
	{
		str[i++] = num % 10 + 48;
		num /= 10;
	} while (num);
	str[i] = '\0';
	int j = 0;
	if (str[0] == '-')
	{
		j = 1;
		++i;
	}
	for (; j < i / 2; j++)
	{
		str[j] = str[j] + str[i - 1 - j];
		str[i - 1 - j] = str[j] - str[i - 1 - j];
		str[j] = str[j] - str[i - 1 - j];
	}
	return str;
}
void ShowFileStuinfo()
{
	FILE* fpstuinfo;
	char buff[100];
	fpstuinfo = fopen("data\\BasicInfoD.txt", "r+");
	if (fpstuinfo == NULL)
	{
		perror("file open error:failed");
		system("pause");
		return;
	}
	while (fgets(buff, 99, fpstuinfo)!=NULL)
	{
		//fgets(buff, 99, fpstuinfo);
		puts(buff);
	}
	system("pause");
	fclose(fpstuinfo);
}
void ShowStuinfoAP(struct StuinfoA* pstu)
{
	printf("身份证号:\t%s\n", pstu->sfz);
	printf("学号:\t%d\n", pstu->xh);
	printf("姓名:\t%s\n", pstu->xm);
	printf("性别:\t%s\n", pstu->xb);
	printf("出生日期:\t%s\n", pstu->date);
	printf("-------------------------\n");
}
void ShowStuinfoListAll(struct StuinfoA* head)
{
	struct StuinfoA* p = head;
	while (p != NULL)
	{
		ShowStuinfoAP(p);
		p = p->next;
	}
}
void createE(char* p) {
	FILE* fp;
	char url[50];
	char url1[30] = "data\\score\\";
	char url2[5] = ".txt";
	char* pp = url;
	pp = strcat(url1, p);
	pp = strcat(pp, url2);
	fp = fopen(pp, "w+");
	fprintf(fp, "21102703 程序设计 0 0 0 0 0 0\n10100615 高等数学 0 0 0 0 0 0\n10500113 大学英语 0 0 0 0 0 0\n21104902 计算机科学导论 0 0 0 0 0 0\n21102901 程序设计课程设计 0 0 0 0 0 0\n11400111 体育 0 0 0 0 0 0\n11900504 马克思主义 0 0 0 0 0 0");
	fclose(fp);
}
void addnewyxinfo()
{
	FILE* fpstuinfo;
	char yes = ' ';
	struct StuinfoA stu;
	fpstuinfo = fopen("data\\BasicInfoD.txt", "a + ");
	if (fpstuinfo == NULL)
	{
		fpstuinfo = fopen("data\\BasicInfoD.txt", "w+");
		if (fpstuinfo == NULL)
		{
			perror("file open error:failed");
			system("pause");
			return;
		}
	}
	yes = 'y';
	while (yes == 'y')
	{
		printf("身份证号 学号 姓名 性别 出生日期\n");
		scanf("%s%d%s%s%s", &stu.sfz, &stu.xh, &stu.xm, &stu.xb, &stu.date);
		if (stu.xh > 0)
		{
			if (fprintf(fpstuinfo, "%s %d %s %s %s\n", stu.sfz, stu.xh, stu.xm, stu.xb, stu.date))
			{
				printf("添加成功，");
			}
			else
			{
				printf("添加失败，");
			}
		}
		char xh[20];
		Int2String(stu.xh, xh);
		createE(xh);
		getchar();
		printf("是否继续（y/n）?");
		yes = getchar();

	}
	
	rewind(fpstuinfo);
	while (fscanf(fpstuinfo, "%s%d%s%s%s", &stu.sfz, &stu.xh, &stu.xm, &stu.xb, &stu.date))
	{
		if (feof(fpstuinfo))break;
		printf("%s %d %s %s %s\n", stu.sfz, stu.xh, stu.xm, stu.xb, stu.date);
		
	}
	fclose(fpstuinfo);
	//ShowFileStuinfo();
	system("pause");
}
struct StuinfoA* creatstuinfolist()
{
	FILE* fpdec;
	char c = ' ';
	typedef struct StuinfoA stuinfo;
	stuinfo* stup, * head, * P;
	fpdec = fopen("data\\BasicInfoD.txt", "r+");
	if (fpdec == NULL)
	{
		perror("file open error:failed");
		return head = NULL;
	}
	head = NULL;
	P = head;
	while (!feof(fpdec))
	{
		stup = (stuinfo*)malloc(sizeof(stuinfo));
		fscanf(fpdec, "%s%d%s%s%s", &stup->sfz, &stup->xh, &stup->xm, &stup->xb, &stup->date);
		stup->next = NULL;
		if (head == NULL)
		{
			head = stup;
			P = head;

		}
		else
		{
			P->next = stup;
			P = P->next;
		}

	}
	fclose(fpdec);
	return head;
}
void Showstuinfolist(struct StuinfoA* stuinfo)
{
	struct StuinfoA* stup = stuinfo;
	while (stup != NULL)
	{
		printf("%s %d %s %s %s\n",  stup->sfz,  stup->xh, stup->xm,  stup->xb,  stup->date);
		stup = stup->next;
	}
}
void WriteStuinfolist(struct StuinfoA* listhead)
{
	FILE* fpstuinfo;
	struct StuinfoA  * temp, stu;
	fpstuinfo = fopen("data\\BasicInfoD.txt", "w+");
	if (fpstuinfo == NULL)
	{
		perror("file open error:failed");
		system("pause");
		return;
	}

	temp = listhead;
	while (temp != NULL)
	{
		if (temp->xh > 0)
			fprintf(fpstuinfo, "%s %d %s %s %s\n", temp->sfz, temp->xh, temp->xm, temp->xb, temp->date);
		temp = temp->next;
	}
	fflush(fpstuinfo);


	rewind(fpstuinfo);
	while (fscanf(fpstuinfo, "%s%d%s%s%s", &stu.sfz, &stu.xh, &stu.xm, &stu.xb, &stu.date))
	{
		if (feof(fpstuinfo))break;
		printf("%s %d %s %s %s\n", stu.sfz, stu.xh, stu.xm, stu.xb, stu.date);

	}
	fclose(fpstuinfo);
}
void editstuinfo()
{
	int xh;
	//FILE* fpstuinfo;
	char yes = ' ';
	int xhtemp=0;
	struct StuinfoA *listhead,*temp,*newstu;
	listhead=creatstuinfolist();
	temp = listhead;
	yes = 'y';
	printf("输入你要修改的学号：");
	scanf("%d",&xh);
	while (temp!=NULL)
		{
			if (xh == temp->xh)
			{
				break;
			}
			temp = temp->next;
		}
	if (temp != NULL)
	{
		ShowStuinfoAP(temp);
		newstu = (struct StuinfoA*)malloc(sizeof(struct StuinfoA));
		printf("身份证号 学号 姓名 性别 出生日期\n");
		scanf("%s%d %s%s%s", &temp->sfz, &temp->xh, &temp->xm, &temp->xb, &temp->date);
		ShowStuinfoAP(temp);
		
		system("pause");
				
	}
	WriteStuinfolist(listhead);
	
}
void DelStuinfo()
{
	int xh;
	//FILE* fpstuinfo;
	struct StuinfoA* listhead, * temp;
	listhead = creatstuinfolist();
	temp = listhead;
	printf("输入你要删除的学号：");
	scanf("%d", &xh);
	while (temp!= NULL)
	{
		if (xh == temp->next->xh)
		{
			break;
		}
		temp = temp->next;
	}
	struct StuinfoA* tm = temp->next;
	temp->next = tm->next;
	free(tm);
	WriteStuinfolist(listhead);

}
void stuinfomenu()
{
	gotoxy(20,3);

	printf("------学生基本信息管理----------\n");
	gotoxy(20, 5);
	printf("-----1.添加学生基本信息 ----------\n");
	gotoxy(20, 7);
	printf("-----2.修改学生基本信息 ----------\n");
	gotoxy(20, 9);
	printf("-----3.删除学生基本信息 ----------\n");
	gotoxy(20, 11);
	printf("-----4.查询学生基本信息 ----------\n");
	gotoxy(20, 13);
	printf("-----0.返回         ----------\n");
}
void BasicInfo()
{
	int choice;
	stuinfomenu();
	choice =5;
	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
			addnewyxinfo();
			break;
		case 2:
			editstuinfo();
			break;
		case 3:
			DelStuinfo();
			break;
		case 4:
			ShowFileStuinfo();
			break;
		default:
			break;
		}
		system("cls");
		stuinfomenu();
		printf("请输入（0-4）：");
		scanf("%d", &choice);
	}

}