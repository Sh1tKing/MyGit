#include<stdio.h>
#include<string.h>
#include"location.h"
#include<Windows.h>
struct StuinfoE
{
	int bh;
	char mc[40], ps[20], qm[10], xq[20];
	double jd, zp, xf;
	struct StuinfoE* next;
};
char* geturl() {
	char xh[20];
	scanf("%s", &xh);
	char url[50];
	char url1[30] = "data\\score\\";
	char url2[5] = ".txt";
	char* p = url;
	p = strcat(url1, xh);
	p = strcat(p, url2);
	return p;
}
void ShowStuinfoPE(struct StuinfoE* pstu)
{
	printf("课程编号:\t%d\n", pstu->bh);
	printf("课程名称:\t%s\n", pstu->mc);
	printf("学分:\t%.1f\n", pstu->xf);
	printf("平时成绩:\t%s\n", pstu->ps);
	printf("期末成绩:\t%s\n", pstu->qm);
	printf("总评:\t%.1f\n", pstu->zp);
	printf("学期:\t%s\n", pstu->xq);
	pstu->jd = (pstu->zp) / 10.0 - 5;
	printf("绩点:\t %.1f\n", pstu->jd);
	printf("-------------------------\n");
}
struct StuinfoE* creatstuinfolistE(char *p)
{
	FILE* fpdec;
	char c = ' ';
	typedef struct StuinfoE stuinfo;
	stuinfo* stup, * head, * P;
	fpdec = fopen(p, "r+");
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
		fscanf(fpdec, "%d%s%lf%s%s%lf%s%lf", &stup->bh, &stup->mc, &stup->xf, &stup->ps, &stup->qm, &stup->zp, &stup->xq, &stup->jd);
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

void WriteStuinfolistE(struct StuinfoE* listhead,char* p)
{
	FILE* fpstuinfo;
	struct StuinfoE* temp, stu;
	fpstuinfo = fopen(p, "w+");
	if (fpstuinfo == NULL)
	{
		perror("file open error:failed");
		system("pause");
		return;
	}

	temp = listhead;
	while (temp != NULL)
	{
		if (temp->bh > 0) {
			
			fprintf(fpstuinfo, "%d %s %.1f %s %s %.1f %s %.1f\n", temp->bh, temp->mc, temp->xf, temp->ps, temp->qm, temp->zp, temp->xq, temp->jd);

		}
		temp = temp->next;
	}
	fflush(fpstuinfo);
	rewind(fpstuinfo);
	while (fscanf(fpstuinfo, "%d%s%lf%s%s%lf%s%f", &stu.bh, &stu.mc, &stu.xf, &stu.ps, &stu.qm, &stu.zp, &stu.xq))
	{
		stu.jd = (stu.zp) / 10.0 - 5;
		if (feof(fpstuinfo))break;
		printf("%d %s %.1f %s %s %.1f %s %.1f\n", stu.bh, stu.mc, stu.xf, stu.ps, stu.qm, stu.zp, stu.xq, stu.jd);

	}
	fclose(fpstuinfo);
}
void addnewyxinfoE()
{
	char xh[20];
	printf("请输入要添加成绩的学生学号：\n");
	scanf("%s", &xh);
	FILE* fpstuinfo;
	char url[40];
	char url1[30] = "data\\score\\";
	char url2[5] = ".txt";
	char* p = url;
	p = strcat(url1,xh);
	p = strcat(p, url2);
	fpstuinfo = fopen(p, "a + ");
	if (fpstuinfo == NULL)
	{
		fpstuinfo = fopen(p, "w+");
		if (fpstuinfo == NULL)
		{
			perror("file open error:failed");
			system("pause");
			return;
		}
	}
	struct StuinfoE stu;
	char yes = 'y';
	while (yes == 'y')
	{
		printf("课程编号 课程名称 学分 平时成绩 期末成绩 总评 学期 绩点\n");
		scanf("%d%s%lf%s%s%lf%s%s", &stu.bh, &stu.mc, &stu.xf, &stu.ps, &stu.qm, &stu.zp, &stu.xq, &stu.jd);
		if (stu.bh > 0)
		{
			if (fprintf(fpstuinfo, "%d %s %.1f %s %s %s %s %.1f\n",  stu.bh,  stu.mc,  stu.xf,  stu.ps,  stu.qm,  stu.zp,  stu.xq,  stu.jd))
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
	while (fscanf(fpstuinfo, "%d%s%lf%s%s%lf%s%lf", &stu.bh, &stu.mc, &stu.xf, &stu.ps, &stu.qm, &stu.zp, &stu.xq, &stu.jd))
	{
		if (feof(fpstuinfo))break;
		printf("%d %s %.1f %s %s %.1f %s %.1f\n", stu.bh, stu.mc, stu.xf, stu.ps, stu.qm, stu.zp, stu.xq, stu.jd);

	}
	fclose(fpstuinfo);
	//ShowFileStuinfoB();
	system("pause");
}
void editstuinfoE() {
	char xh[20];
	printf("请输入要修改成绩的学生学号：\n");
	char url[50];
	char* p=url;
	strcpy(p, geturl());
	FILE* fpstuinfo;
	fpstuinfo = fopen(p, "a+");
	if (fpstuinfo == NULL)
	{ 
		printf("file doesn't exist\n");
		system("pause");
		return;
	}
	struct StuinfoE * listhead, *temp,*newstu;
	listhead = creatstuinfolistE(p);
	temp = listhead; 
	char yes = 'y';
	int bh;
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
		ShowStuinfoPE(temp);
		newstu = (struct StuinfoE*)malloc(sizeof(struct StuinfoE));
		printf("课程编号 课程名称 学分 平时成绩 期末成绩 总评 学期\n");
		scanf("%d%s%lf%s%s%lf%s", &temp->bh, &temp->mc, &temp->xf, &temp->ps, &temp->qm, &temp->zp, &temp->xq);
		temp->jd = temp->zp / 10.0 - 5;
		ShowStuinfoPE(temp);

		system("pause");

	}
	WriteStuinfolistE(listhead,p);
}
void DelStuinfoE()
{
	char xh[20];
	printf("请输入要删除成绩的学生学号：\n");
	char url[50];
	char* p = url;
	strcpy(p, geturl());
	struct StuinfoE* listhead, * temp;
	listhead = creatstuinfolistE(p);
	temp = listhead;
	int bh;
		printf("输入你要删除的课程编号：");
		scanf("%d", &bh);
		while (temp != NULL)
		{
			if (bh == temp->next->bh)
			{
				break;
			}
			temp = temp->next;
		}
		struct StuinfoE* tm = temp->next;
		temp->next = tm->next;
		free(tm);
		WriteStuinfolistE(listhead,p);
}
void ShowstuinfolistE(struct StuinfoE* stuinfo)
{
	struct StuinfoE* stup = stuinfo;
	while (stup != NULL)
	{
		printf("%d %s %.1f %s %s %.1f %s %.1f\n", stup->bh, stup->mc, stup->xf, stup->ps, stup->qm, stup->zp, stup->xq, stup->jd);
		stup = stup->next;
	}
}
void ShowFileStuinfoE()
{
	FILE* fpstuinfo=NULL;
	char xh[20];
	printf("请输入要查看的学生学号：\n");
	char url[50];
	char* p = url;
	strcpy(p, geturl());
	fpstuinfo = fopen(p, "r+");
	if (fpstuinfo == NULL)
	{
		perror("file open error:failed");
		system("pause");
		return;
	}
	struct StuinfoE t;
	while (fscanf(fpstuinfo, "%d%s%lf%s%s%lf%s%lf", &t.bh, &t.mc, &t.xf, &t.ps, &t.qm, &t.zp, &t.xq, &t.jd) != EOF)
	{
		printf("课程编号:\t%d\n", t.bh);
		printf("课程名称:\t%s\n", t.mc);
		printf("学分:\t%.1f\n", t.xf);
		printf("平时成绩:\t%s\n", t.ps);
		printf("期末成绩:\t%s\n", t.qm);
		printf("总评:\t%.1f\n", t.zp);
		printf("学期:\t%s\n", t.xq);
		t.jd = (t.zp) / 10.0 - 5;
		printf("绩点:\t %.1f\n", t.jd);
		printf("-------------------------\n");
	}
	fclose(fpstuinfo);
	system("pause");
}
struct StuinfoEpx {
		char u[50], name[20], mc[20];
		double zp;
		struct StuinfoEpx* next;
};
void ShowFileStuinfoKME()
{
	FILE* stunum,* fpstuinfo=NULL;
	int bh;
	printf("请输入要查看的课程编号：\n");
	scanf("%d", &bh);
	char u[50],name[20];
	stunum = fopen("data\\studentnum.txt", "r");
	
	struct StuinfoEpx* listhead = (struct StuinfoEpx*)malloc(sizeof(struct StuinfoEpx));
	struct StuinfoEpx* point= listhead;
	while (fscanf(stunum, "%s%s", &u,&name)!=EOF) {
		char* o = u;
		char url1[30] = "data\\score\\";
		char url2[5] = ".txt";
		o = strcat(url1, o);
		o = strcat(o, url2);
		fpstuinfo = fopen(o, "r+");
		struct StuinfoE t;
		struct StuinfoEpx* temp = (struct StuinfoEpx*)malloc(sizeof(struct StuinfoEpx));
		while (fscanf(fpstuinfo, "%d%s%lf%s%s%lf%s%lf", &t.bh, &t.mc, &t.xf, &t.ps, &t.qm, &t.zp, &t.xq, &t.jd)!=EOF) {
			
			if (bh == t.bh) {
				strcpy(temp->u, u);
				strcpy(temp->name, name);
				strcpy(temp->mc, t.mc);
				temp->zp = t.zp;
				point->next = temp;
				point = point->next;
				break;
			}
		}
	}
	point->next = NULL;
	struct StuinfoEpx* pre=NULL, * p, * r;
	p = listhead->next;
	r = p->next;
	p->next = NULL;
	p = r;
	while (p)
	{
		pre = listhead;
		r = p->next;
		while (pre->next != NULL && pre->next->zp > p->zp)
		{
			pre = pre->next;
		}
		p->next = pre->next;
		pre->next = p;
		p = r;
	}
	struct StuinfoEpx* l=listhead->next;
	printf("学号      姓名    科目    分数\n");
	while (l != NULL) {
		printf("%s %s %s %.1f\n", l->u, l->name, l->mc, l->zp);
		l = l->next;
	}
	free(pre);
	free(p);
	free(r);
	free(l);
	fclose(stunum);
	fclose(fpstuinfo);
	system("pause");
}
void calXF() {
	struct xfd {
		char xh[20];
		double cj;
		char name[20];
		struct xfd* next;
	};
	FILE* stunum,*xflabel=NULL, * fpstuinfo = NULL;
	char u[50], name[20];
	stunum = fopen("data\\studentnum.txt", "r");
	xflabel = fopen("data\\xflabel.txt", "w");
	struct xfd* list = (struct xfd*)malloc(sizeof(struct xfd));
	struct xfd* p = list;
	while (fscanf(stunum, "%s%s", u, name) != EOF) {
		char* o = u;
		char url1[30] = "data\\score\\";
		char url2[5] = ".txt";
		o = strcat(url1, o);
		o = strcat(o, url2);
		fpstuinfo = fopen(o, "r+");
		struct StuinfoE t;
		double sum = 0,sum1=0;

		while (fscanf(fpstuinfo, "%d%s%lf%s%s%lf%s%lf", &t.bh, &t.mc, &t.xf, &t.ps, &t.qm, &t.zp, &t.xq, &t.jd) != EOF) {
			sum += (t.xf) * (t.zp);
			sum1 += t.xf;
		}
		struct xfd* temp = (struct xfd*)malloc(sizeof(struct xfd));
		strcpy(temp->xh, u);
		strcpy(temp->name, name);
		temp->cj = sum / sum1;
		p ->next= temp;
		p = p->next;
		printf("%s %s %.1f\n", u, name, sum / sum1);
		fprintf(xflabel, "%s %s %.1f\n", u, name, sum / sum1);
		
	}
	p->next= NULL;
	fclose(xflabel);
	fclose(stunum);
	fclose(fpstuinfo);
	printf("是否统计低于指定值的学生？（y/n）");
	char ch=' ';
	getchar();
	ch = getchar();
	if (ch == 'y') {
		printf("请输入指定学分值：");
		double cj;
		scanf("%lf", &cj);
		struct xfd* pp = list->next;
		while (pp!= NULL) {
			if (pp->cj < cj) printf("%s %s %.1f\n", pp->xh, pp->name, pp->cj);
			pp = pp->next;
		}
		free(pp);
	}
	system("pause");
}
void stuinfomenuE()
{
	gotoxy(20, 3);
	printf("------学生成绩管理----------\n");
	gotoxy(20, 5);
	printf("-----1.添加学生成绩 ----------\n");
	gotoxy(20, 7);
	printf("-----2.修改学生成绩 ----------\n");
	gotoxy(20, 9);
	printf("-----3.删除学生成绩 ----------\n");
	gotoxy(20, 11);
	printf("-----4.查询学生成绩 ----------\n");
	gotoxy(20, 13);
	printf("-----5.统计学生学分 ----------\n");
	gotoxy(20, 15);
	printf("-----0.返回         ----------\n");
}
ShowFileStuinfomenuE() {
	gotoxy(20, 3);
	printf("------学生成绩管理----------\n");
	gotoxy(20, 5);
	printf("-----1.查看学生成绩 ----------\n");
	gotoxy(20, 7);
	printf("-----2.查看科目学生成绩 ----------\n");
	gotoxy(20, 9);
	printf("-----0.返回         ----------\n");
}
void ScoreInfo()
{
	int choice;
	stuinfomenuE();
	choice = -1;
	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
			addnewyxinfoE();
			break;
		case 2:
			editstuinfoE();
			break;
		case 3:
			DelStuinfoE();
			break;
		case 4: {
			system("cls");
			ShowFileStuinfomenuE();
			printf("请输入（0-2）：");
			int c;
			scanf("%d", &c);
			while (c != 0) {
				switch (c) {
					case 1:
						ShowFileStuinfoE();
						break;
					case 2:
						ShowFileStuinfoKME();
						break;
					default:break;
				}
				system("cls");
				ShowFileStuinfomenuE();
				printf("请输入（0-2）：");
				scanf("%d", &c);
			}
			break;
		}
		case 5: 
			calXF();
			break;
		default:
			break;
		}
		system("cls");
		stuinfomenuE();
		printf("请输入（0-5）：");
		scanf_s("%d", &choice);
	}

}