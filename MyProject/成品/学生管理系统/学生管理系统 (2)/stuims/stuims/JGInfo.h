#include<stdio.h>
#include"location.h"
#include<Windows.h>
struct StuinfoC
{
	int xh;
	char xm[20], xy[20], zy[20],bj[10],add[20],xb[15],phno[20],jt[60];	
	struct StuinfoC* next;
};
void ShowFileStuinfoC()
{
	FILE* fpstuinfo;
	fpstuinfo = fopen("data\\JGInfoD.txt", "r+");
	if (fpstuinfo == NULL)
	{
		perror("file open error:failed");
		system("pause");
		return;
	}
	struct StuinfoC t;
	while (fscanf(fpstuinfo,"%d%s%s%s%s%s%s%s%s",&t.xh, &t.xm, &t.xy, &t.zy, &t.bj, &t.add, &t.xb, &t.phno, &t.jt)!=EOF)
	{
		printf("%d %s %s %s %s %s %s %s %s\n", t.xh, t.xm, t.xy, t.zy, t.bj, t.add, t.xb, t.phno, t.jt);
	}
	system("pause");
	fclose(fpstuinfo);
}
void ShowStuinfoPC(struct StuinfoC* pstu)
{
	printf("学号:\t%d\n", pstu->xh);
	printf("姓名:\t%s\n", pstu->xm);
	printf("学院:\t%s\n", pstu->xy);
	printf("专业:\t%s\n", pstu->zy);
	printf("班级:\t%s\n", pstu->bj);
	printf("现住址:\t%s\n", pstu->add);
	printf("性别:\t%s\n", pstu->xb);
	printf("电话:\t%s\n", pstu->phno);
	printf("家庭地址:\t%s\n", pstu->jt);
	printf("-------------------------\n");
}
void ShowstuinfolistAllC(struct StuinfoC* head)
{
	struct StuinfoC* p = head;
	while (p != NULL)
	{
		ShowStuinfoPC(p);
		p = p->next;
	}
}
void addnewyxinfoC()
{
	FILE* fpstuinfo;
	char yes = ' ';
	struct StuinfoC stu;
	fpstuinfo = fopen("data\\JGInfoD.txt", "a + ");
	if (fpstuinfo == NULL)
	{
		fpstuinfo = fopen("data\\JGInfoD.txt", "w+");
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
		printf("学号 姓名 学院 专业 班级 现住址 性别 电话 家庭地址\n");
		scanf("%d%s%s%s%s%s%s%s%s", &stu.xh, &stu.xm, &stu.xy, &stu.zy, &stu.bj, &stu.add, &stu.xb, &stu.phno, &stu.jt);
		if (stu.xh > 0)
		{
			if (fprintf(fpstuinfo, "%d %s %s %s %s %s %s %s %s\n",  stu.xh,  stu.xm,  stu.xy, stu.zy,  stu.bj,  stu.add,  stu.xb,  stu.phno, stu.jt))
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
	while (fscanf(fpstuinfo, "%d%s%s%s%s%s%s%s%s", &stu.xh, &stu.xm, &stu.xy, &stu.zy, &stu.bj, &stu.add, &stu.xb, &stu.phno, &stu.jt))
	{
		if (feof(fpstuinfo))break;
		printf("%d %s %s %s %s %s %s %s %s\n", stu.xh, stu.xm, stu.xy, stu.zy, stu.bj, stu.add, stu.xb, stu.phno, stu.jt);

	}
	fclose(fpstuinfo);
	//ShowFileStuinfoC();
	system("pause");
}

struct StuinfoC* creatstuinfolistC()
{
	FILE* fpdec;
	char c = ' ';
	typedef struct StuinfoC stuinfo;
	stuinfo* stup, * head, * P;
	fpdec = fopen("data\\JGInfoD.txt", "r+");
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
		fscanf(fpdec, "%d%s%s%s%s%s%s%s%s", &stup->xh, &stup->xm, &stup->xy, &stup->zy, &stup->bj, &stup->add, &stup->xb, &stup->phno, &stup->jt);
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
void ShowstuinfolistC(struct StuinfoC* stuinfo)
{
	struct StuinfoC* stup = stuinfo;
	while (stup != NULL)
	{
		printf("%d %s %s %s %s %s %s %s %s\n", stup->xh, stup->xm, stup->xy, stup->zy, stup->bj, stup->add, stup->xb, stup->phno, stup->jt);
		stup = stup->next;
	}
}
void WriteStuinfolistC(struct StuinfoC* listhead)
{
	FILE* fpstuinfo;
	struct StuinfoC* temp, stu;
	fpstuinfo = fopen("data\\JGInfoD.txt", "w+");
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
			fprintf(fpstuinfo, "%d %s %s %s %s %s %s %s %s\n", temp->xh, temp->xm, temp->xy, temp->zy, temp->bj, temp->add, temp->xb, temp->phno, temp->jt);
		temp = temp->next;
	}
	fflush(fpstuinfo);


	rewind(fpstuinfo);
	while (fscanf(fpstuinfo, "%d%s%s%s%s%s%s%s%s", &stu.xh, &stu.xm, &stu.xy, &stu.zy, &stu.bj, &stu.add, &stu.xb, &stu.phno, &stu.jt))
	{
		if (feof(fpstuinfo))break;
		printf("%d %s %s %s %s %s %s %s %s\n", stu.xh, stu.xm, stu.xy, stu.zy, stu.bj, stu.add, stu.xb, stu.phno, stu.jt);

	}
	fclose(fpstuinfo);
}
void editstuinfoC()
{
	int xh;
	//FILE* fpstuinfo;
	char yes = ' ';
	int xhtemp = 0;
	struct StuinfoC* listhead, * temp, * newstu;
	listhead = creatstuinfolistC();
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
		ShowStuinfoPC(temp);
		newstu = (struct StuinfoC*)malloc(sizeof(struct StuinfoC));
		printf("学号 姓名 学院 专业 班级 现住址 性别 电话 家庭地址\n");
		scanf("%d%s%s%s%s%s%s%s%s", &temp->xh, &temp->xm, &temp->xy, &temp->zy, &temp->bj, &temp->add, &temp->xb, &temp->phno, &temp->jt);
		ShowStuinfoPC(temp);

		system("pause");

	}
	WriteStuinfolistC(listhead);

}
void DelStuinfoC()
{
	int xh;
	//FILE* fpstuinfo;
	struct StuinfoC* listhead, * temp;
	listhead = creatstuinfolistC();
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
	struct StuinfoC* tm = temp->next;
	temp->next = tm->next;
	free(tm);
	WriteStuinfolistC(listhead);

}
void stuinfomenuC()
{
	gotoxy(20, 3);

	printf("------学生籍贯信息管理----------\n");
	gotoxy(20, 5);
	printf("-----1.添加学生籍贯信息 ----------\n");
	gotoxy(20, 7);
	printf("-----2.修改学生籍贯信息 ----------\n");
	gotoxy(20, 9);
	printf("-----3.删除学生籍贯信息 ----------\n");
	gotoxy(20, 11);
	printf("-----4.查询学生籍贯信息 ----------\n");
	gotoxy(20, 13);
	printf("-----0.返回         ----------\n");
}
void JGInfo()
{
	int choice;
	stuinfomenuC();
	choice = 5;
	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
			addnewyxinfoC();
			break;
		case 2:
			editstuinfoC();
			break;
		case 3:
			DelStuinfoC();
			break;
		case 4:
			ShowFileStuinfoC();
			break;
		default:
			break;
		}
		system("cls");
		stuinfomenuC();
		printf("请输入（1-4）：");
		scanf("%d", &choice);
	}

}