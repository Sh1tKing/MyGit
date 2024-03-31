#include<stdio.h>
#include"location.h"
#include<Windows.h>
struct StuinfoD
{
	int bh;
	char mc[30],xf[10],xq[20];
	struct StuinfoD* next;
};
void ShowFileStuinfoD()
{
	FILE* fpstuinfo;
	fpstuinfo = fopen("data\\PyInfoD.txt", "r+");
	if (fpstuinfo == NULL)
	{
		perror("file open error:failed");
		system("pause");
		return;
	}
	struct StuinfoD t;
	while (fscanf(fpstuinfo, "%d%s%s%s", &t.bh, &t.mc, &t.xf, &t.xq) != EOF)
	{
		printf("%d %s %s %s\n",  t.bh,  t.mc,  t.xf,  t.xq);
	}
	system("pause");
	fclose(fpstuinfo);
}
void ShowStuinfoPD(struct StuinfoD* pstu)
{
	printf("课程编号:\t%d\n", pstu->bh);
	printf("课程名称:\t%s\n", pstu->mc);
	printf("学分:\t%s\n", pstu->xf);
	printf("开课学期:\t%s\n", pstu->xq);
	printf("-------------------------\n");
}
void ShowstuinfolistAllD(struct StuinfoD* head)
{
	struct StuinfoD* p = head;
	while (p != NULL)
	{
		ShowStuinfoPD(p);
		p = p->next;
	}
}
void addnewyxinfoD()
{
	FILE* fpstuinfo;
	char yes = ' ';
	struct StuinfoD stu;
	fpstuinfo = fopen("data\\PyInfoD.txt", "a + ");
	if (fpstuinfo == NULL)
	{
		fpstuinfo = fopen("data\\PyInfoD.txt", "w+");
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
		printf("课程编号 课程名称 学分 开课学期\n");
		scanf("%d%s%s%s", &stu.bh, &stu.mc, &stu.xf, &stu.xq);
		if (stu.bh > 0)
		{
			if (fprintf(fpstuinfo, "%d %s %s %s\n",  stu.bh,  stu.mc,  stu.xf,  stu.xq))
			{
				printf("添加成功，");
			}
			else
			{
				printf("添加失败，");
			}
		}
		getchar();
		printf("是否继续（y/n）?");
		yes = getchar();

	}

	rewind(fpstuinfo);
	while (fscanf(fpstuinfo, "%d%s%s%s", &stu.bh, &stu.mc, &stu.xf, &stu.xq))
	{
		if (feof(fpstuinfo))break;
		printf("%d %s %s %s\n", stu.bh, stu.mc, stu.xf, stu.xq);

	}
	fclose(fpstuinfo);
	system("pause");
}

struct StuinfoD* creatstuinfolistD()
{
	FILE* fpdec;
	char c = ' ';
	typedef struct StuinfoD stuinfo;
	stuinfo* stup, * head, * P;
	fpdec = fopen("data\\PyInfoD.txt", "r+");
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
		fscanf(fpdec, "%d%s%s%s", &stup->bh, &stup->mc, &stup->xf, &stup->xq);
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
void ShowstuinfolistD(struct StuinfoD* stuinfo)
{
	struct StuinfoD* stup = stuinfo;
	while (stup != NULL)
	{
		printf("%d %s %s %s\n",  stup->bh,  stup->mc, stup->xf, stup->xq);
		stup = stup->next;
	}
}
void WriteStuinfolistD(struct StuinfoD* listhead)
{
	FILE* fpstuinfo;
	struct StuinfoD* temp, stu;
	fpstuinfo = fopen("data\\PyInfoD.txt", "w+");
	if (fpstuinfo == NULL)
	{
		perror("file open error:failed");
		system("pause");
		return;
	}

	temp = listhead;
	while (temp != NULL)
	{
		if (temp->bh > 0)
			fprintf(fpstuinfo, "%d %s %s %s\n", temp->bh, temp->mc, temp->xf, temp->xq);
		temp = temp->next;
	}
	fflush(fpstuinfo);


	rewind(fpstuinfo);
	while (fscanf(fpstuinfo, "%d%s%s%s", &stu.bh, &stu.mc, &stu.xf, &stu.xq))
	{
		if (feof(fpstuinfo))break;
		printf("%d %s %s %s\n",  stu.bh,  stu.mc,  stu.xf,  stu.xq);

	}
	fclose(fpstuinfo);
}
void editstuinfoD()
{
	int bh;
	//FILE* fpstuinfo;
	char yes = ' ';
	int xhtemp = 0;
	struct StuinfoD* listhead, * temp, * newstu;
	listhead = creatstuinfolistD();
	temp = listhead;
	yes = 'y';
	printf("输入你要修改的课程编号：");
	scanf("%d", &bh);
	while (temp != NULL)
	{
		if (bh == temp->bh)
		{
			break;
		}
		temp = temp->next;
	}
	if (temp != NULL)
	{
		ShowStuinfoPD(temp);
		newstu = (struct StuinfoD*)malloc(sizeof(struct StuinfoD));
		printf("课程编号 课程名称 学分 开课学期\n");
		scanf("%d%s%s%s", &temp->bh, &temp->mc, &temp->xf, &temp->xq);
		ShowStuinfoPD(temp);

		system("pause");

	}
	WriteStuinfolistD(listhead);

}
void DelStuinfoD()
{
	int xh;
	//FILE* fpstuinfo;
	struct StuinfoD* listhead, * temp;
	listhead = creatstuinfolistD();
	temp = listhead;
	printf("输入你要删除的课程编号：");
	scanf("%d", &xh);
	while (temp != NULL)
	{
		if (xh == temp->next->bh)
		{
			break;
		}
		temp = temp->next;
	}
	struct StuinfoD* tm = temp->next;
	temp->next = tm->next;
	free(tm);
	WriteStuinfolistD(listhead);

}
void stuinfomenuD()
{
	gotoxy(20, 3);

	printf("------学生培养计划管理----------\n");
	gotoxy(20, 5);
	printf("-----1.添加学生培养计划 ----------\n");
	gotoxy(20, 7);
	printf("-----2.修改学生培养计划 ----------\n");
	gotoxy(20, 9);
	printf("-----3.删除学生培养计划 ----------\n");
	gotoxy(20, 11);
	printf("-----4.查询学生培养计划 ----------\n");
	gotoxy(20, 13);
	printf("-----0.返回         ----------\n");
}
void PyInfo()
{
	int choice;
	stuinfomenuD();
	choice = 5;
	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
			addnewyxinfoD();
			break;
		case 2:
			editstuinfoD();
			break;
		case 3:
			DelStuinfoD();
			break;
		case 4:
			ShowFileStuinfoD();
			break;
		default:
			break;
		}
		system("cls");
		stuinfomenuD();
		printf("请输入（0-4）：");
		scanf("%d", &choice);
	}

}