#include<stdio.h>
#include"location.h"
#include<Windows.h>
struct StuinfoB
{	
	int xh;
	char xm[20], xy[20], zy[20],bj[10],add[20],phno[20],rx[20];
	struct StuinfoB* next;
};
void ShowFileStuinfoB()
{
	FILE* fpstuinfo;
	char buff[130];
	fpstuinfo = fopen("data\\YxInfoD.txt", "r+");
	if (fpstuinfo == NULL)
	{
		perror("file open error:failed");
		system("pause");
		return;
	}
	struct StuinfoB t;
	while (fscanf(fpstuinfo,"%d%s%s%s%s%s%s%s", &t.xh, &t.xm, &t.xy, &t.zy, &t.bj, &t.add, &t.phno, &t.rx) != EOF)
	{
		printf("%d %s %s %s %s %s %s %s\n", t.xh, t.xm, t.xy, t.zy, t.bj, t.add, t.phno, t.rx);
	}
	system("pause");
	fclose(fpstuinfo);
}
void ShowStuinfoPB(struct StuinfoB* pstu)
{
	printf("学号:\t%d\n", pstu->xh);
	printf("姓名:\t%s\n", pstu->xm);
	printf("学院:\t%s\n", pstu->xy);
	printf("专业:\t%s\n", pstu->zy);
	printf("班级:\t%s\n", pstu->bj);
	printf("住址:\t%s\n", pstu->add);
	printf("电话:\t%s\n", pstu->phno);
	printf("入学时间:\t%s\n", pstu->rx);
	printf("-------------------------\n");
}
void ShowstuinfolistAllB(struct StuinfoB* head)
{
	struct StuinfoB* p = head;
	while (p != NULL)
	{
		ShowStuinfoPB(p);
		p = p->next;
	}
}
void addnewyxinfoB()
{
	FILE* fpstuinfo;
	char yes = ' ';
	struct StuinfoB stu;
	fpstuinfo = fopen("data\\YxInfoD.txt", "a + ");
	if (fpstuinfo == NULL)
	{
		fpstuinfo = fopen("data\\YxInfoD.txt", "w+");
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
		printf("学号 姓名 学院 专业 班级 现住址 电话 入学时间\n");
		scanf("%d%s%s%s%s%s%s%s", &stu.xh, &stu.xm, &stu.xy, &stu.zy, &stu.bj, &stu.add, &stu.phno, &stu.rx);
		if (stu.xh > 0)
		{
			if (fprintf(fpstuinfo, "%d %s %s %s %s %s %s %s\n",  stu.xh,  stu.xm,  stu.xy,  stu.zy,  stu.bj,  stu.add,  stu.phno,  stu.rx))
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
	while (fscanf(fpstuinfo, "%d%s%s%s%s%s%s%s", &stu.xh, &stu.xm, &stu.xy, &stu.zy, &stu.bj, &stu.add, &stu.phno, &stu.rx))
	{
		if (feof(fpstuinfo))break;
		printf("%d %s %s %s %s %s %s %s\n",  stu.xh,  stu.xm, stu.xy,  stu.zy,  stu.bj,  stu.add,  stu.phno,  stu.rx);

	}
	fclose(fpstuinfo);
	//ShowFileStuinfoB();
	system("pause");
}

struct StuinfoB* creatstuinfolistB()
{
	FILE* fpdec;
	char c = ' ';
	typedef struct StuinfoB stuinfo;
	stuinfo* stup, * head, * P;
	fpdec = fopen("data\\YxInfoD.txt", "r+");
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
		fscanf(fpdec, "%d%s%s%s%s%s%s%s", &stup->xh, &stup->xm, &stup->xy, &stup->zy, &stup->bj, &stup->add, &stup->phno, &stup->rx);
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
void ShowstuinfolistB(struct StuinfoB* stuinfo)
{
	struct StuinfoB* stup = stuinfo;
	while (stup != NULL)
	{
		printf("%d %s %s %s %s %s %s %s\n", stup->xh, stup->xm, stup->xy, stup->zy, stup->bj, stup->add, stup->phno, stup->rx);
		stup = stup->next;
	}
}
void WriteStuinfolistB(struct StuinfoB* listhead)
{
	FILE* fpstuinfo;
	struct StuinfoB* temp, stu;
	fpstuinfo = fopen("data\\YxInfoD.txt", "w+");
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
			fprintf(fpstuinfo, "%d %s %s %s %s %s %s %s\n", temp->xh, temp->xm, temp->xy, temp->zy, temp->bj, temp->add, temp->phno, temp->rx);
		temp = temp->next;
	}
	fflush(fpstuinfo);


	rewind(fpstuinfo);
	while (fscanf(fpstuinfo, "%d%s%s%s%s%s%s%s", &stu.xh, &stu.xm, &stu.xy, &stu.zy, &stu.bj, &stu.add, &stu.phno, &stu.rx))
	{
		if (feof(fpstuinfo))break;
		printf("%d %s %s %s %s %s %s %s\n", stu.xh, stu.xm, stu.xy, stu.zy, stu.bj, stu.add, stu.phno, stu.rx);

	}
	fclose(fpstuinfo);
}
void editstuinfoB()
{
	int xh;
	//FILE* fpstuinfo;
	char yes = ' ';
	int xhtemp = 0;
	struct StuinfoB* listhead, * temp,*newstu;
	listhead = creatstuinfolistB();
	temp = listhead;
	yes = 'y';
	printf("输入你要修改的学号：");
	scanf("%d", &xh);
	while (temp != NULL)
	{
		if (xh == temp->xh)
		{
			break;
		}
		temp = temp->next;
	}
	if (temp != NULL)
	{
		ShowStuinfoPB(temp);
		newstu = (struct StuinfoB*)malloc(sizeof(struct StuinfoB));
		printf("学号 姓名 学院 专业 班级 现住址 电话 入学时间\n");
		scanf("%d%s%s%s%s%s%s%s", &temp->xh, &temp->xm, &temp->xy, &temp->zy, &temp->bj, &temp->add, &temp->phno, &temp->rx);
		ShowStuinfoPB(temp);

		system("pause");

	}
	WriteStuinfolistB(listhead);

}
void DelStuinfoB()
{
	int xh;
	//FILE* fpstuinfo;
	struct StuinfoB* listhead, * temp;
	listhead = creatstuinfolistB();
	temp = listhead;
	printf("输入你要删除的学号：");
	scanf("%d", &xh);
	while (temp != NULL)
	{
		if (xh == temp->next->xh)
		{
			break;
		}
		temp = temp->next;
	}
	struct StuinfoB* tm = temp->next;
	temp->next = tm->next;
	free(tm);
	WriteStuinfolistB(listhead);

}
void stuinfomenuB()
{
	gotoxy(20, 3);

	printf("------学生院系信息管理----------\n");
	gotoxy(20, 5);
	printf("-----1.添加学生院系信息 ----------\n");
	gotoxy(20, 7);
	printf("-----2.修改学生院系信息 ----------\n");
	gotoxy(20, 9);
	printf("-----3.删除学生院系信息 ----------\n");
	gotoxy(20, 11);
	printf("-----4.查询学生院系信息 ----------\n");
	gotoxy(20, 13);
	printf("-----0.返回         ----------\n");
}
void YxInfo()
{
	int choice;
	stuinfomenuB();
	choice = 5;
	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
			addnewyxinfoB();
			break;
		case 2:
			editstuinfoB();
			break;
		case 3:
			DelStuinfoB();
			break;
		case 4:
			ShowFileStuinfoB();
			break;
		default:
			break;
		}
		system("cls");
		stuinfomenuB();
		printf("请输入（0-4）：");
		scanf("%d", &choice);
	}

}