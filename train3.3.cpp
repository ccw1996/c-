#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FORMAT  "|列车号:%s|终点站:%-3s|发车时间:%04d.%02d.%02d|余票数:%d|总票数%d|票价:%.2f\n\n"
#define DATA p->data.num,p->data.reachcity,p->data.StartTime.year, p->data.StartTime.month, p->data.StartTime.day,p->data.ticketnum,p->data.ticketsum,p->data.price
/*定义存储火车信息的结构体*/
typedef struct Dtime
{
	int year;
	int month;
	int day;
	int hour;
	int minute;
}SD;
struct train
{
	char num[10];/*列车号*/
	char reachcity[10];/*目的城市*/
	struct Dtime StartTime;
	double  price;/*票价*/
	int  ticketnum;/*票数*/
	int ticketsum;
};
/*订票人的信息*/
struct man
{
	char num[10];/*ID*/
	char name[10];/*姓名*/
	int  bookNum;/*订的票数*/
	double faresum;
	char lieche[10];
	struct Dtime StartTime;
};
/*定义火车信息链表的结点结构*/
typedef struct node
{
	struct train data;
	struct node * next;
}Node, *Link;
/*定义订票人链表的结点结构*/
typedef struct Man
{
	struct man data;
	struct Man *next;
}book, *bookLink;

void SaveTrainInfo(Link l);
/* 初始界面*/
int Menu()
{
	int sel;
	printf("\n");
	printf("\t--------------------------------------------\n");
	printf("\t*                                          *\n");
	printf("\t*        欢迎进入火车订票管理系统          *\n");
	printf("\t*                                          *\n");
	printf("\t--------------------------------------------\n");
	printf("\n");
	printf("\t 1.管理员入口\n");
	printf("\t 2.乘客入口\n");
	printf("\t 0.退出系统\n\n");
	printf("\t 请选择按键0~2\n");
	scanf("%d", &sel);
	return(sel);
}

int menu2()
{
	int sel;
	printf("\n");
	printf("\t--------------------------------------------\n");
	printf("\t*                                          *\n");
	printf("\t*        欢迎进入火车订票管理系统          *\n");
	printf("\t*                                          *\n");
	printf("\t--------------------------------------------\n");
	printf("\n");
	printf("\t请选择您要使用的功能：\n\n");
	printf("\t 1.显示全部路线\n");
	printf("\t 2.火车路线查询\n");
	printf("\t 3.订票\n");
	printf("\t 4.退票\n");
	printf("\t 5.其他查询\n");
	printf("\t 0.退出系统\n\n");
	printf("\t 请选择按键0~4\n");
	scanf("%d", &sel);
	return(sel);
}

int menu3()
{
	int sel;
	printf("\n");
	printf("\t--------------------------------------------\n");
	printf("\t*                                          *\n");
	printf("\t*        欢迎进入火车订票管理系统          *\n");
	printf("\t*                                          *\n");
	printf("\t--------------------------------------------\n");
	printf("\n");
	printf("\t请选择您要使用的功能：\n\n");
	printf("\t 1.输入车次，查询该车次的全部订票信息\n");
	printf("\t 2.输入车次，查询该车次的订票数和余票数\n");
	printf("\t 3.输入终点站名称，查询相关火车线路的信息\n");
	printf("\t 4.输入日期（年~月~日），查询发车时间为该天的火车线路的信息\n");
	printf("\t 5.查询余票数为0的火车线路信息\n");
	printf("\t 6.返回上一界面\n");
	printf("\t 0.退出系统\n\n");
	printf("\t 请选择按键0~6\n");
	scanf("%d", &sel);
	return(sel);
}

/*添加一个火车信息*/



void Traininfo(Link linkhead)
{
	int year, month, day,hour,minute;
	struct node *p, *r, *s;
	char num[10];
	while (1)
	{
		r = linkhead;
		s = linkhead->next;
		while (r->next != NULL)
			r = r->next;
		printf("请输入列车号(0为退出)"); 
		scanf("%s", num);
		if (strcmp(num, "0") == 0)
			break;
		printf("请输入发车时间（格式为年 月 日 时 分）：");
		scanf("%d%d%d%d%d", &year, &month, &day, &hour, &minute);
		/*判断是否已经存在*/
		while (s)                     //                              zy   &指针走向内存orfile
		{
			if (strcmp(s->data.num, num) == 0)
			{
				if (year == s->data.StartTime.year&&month == s->data.StartTime.month&&day == s->data.StartTime.day)
				{
					printf("火车名为 '%s'已经存在!\n", num);
					return;
				}
			}
			s = s->next;
		}
		p = (struct node*)malloc(sizeof(struct node));
		strcpy(p->data.num, num);/*输入车号*/
		printf("请输入终点站:");
		scanf("%s", p->data.reachcity);/*输入到站城市*/
		p->data.StartTime.year = year;
		p->data.StartTime.month = month;
		p->data.StartTime.day = day;
		p->data.StartTime.hour = hour;
		p->data.StartTime.minute=minute;/*输入出发时间*/
piaoj:
		printf("请输入票价:");
		scanf("%lf", &p->data.price);/*输入火车票价*/
		if(p->data.price < 1.0)
		{
			printf("票价输入有误!请重新输入!\n");
			goto piaoj;
		}
piaos:
		printf("请输入总票数:");
		scanf("%d", &p->data.ticketnum);/*输入预定票数*/
		if (p->data.ticketnum<1)
		{
			printf("票数输入有误!请重新输入!\n");
			goto piaos;
		}
		p->data.ticketsum = p->data.ticketnum;
		p->next = NULL;
		r->next = p;/*插入到链表中*/
		r = p;
		SaveTrainInfo(linkhead);
	}
}
/*打印火车票信息*/
void printdata(Node *q) /*格式化输出表中数据*/
{
	Node* p;
	p = q;
	printf(FORMAT, DATA);
}


void  printdata2(book *q)
{
	book *p;
	p = q;
	printf("\n身份证号：%s  姓名：%s  订票数：%d  总票价：%.2lf  订购次车次时间：%d年%d月%d日%d时%d分\n\n"
		, q->data.num, q->data.name,q->data.bookNum, q->data.faresum, q->data.StartTime.year, q->data.StartTime.month,
		q->data.StartTime.day, q->data.StartTime.hour, q->data.StartTime.minute);
	
}



/*查询火车信息*/
void searchtrain(Link l)

{
	Node *s[10], *r;
	int sel, k, i = 0;
	char str1[5], str2[10];
	if (!l->next)
	{
		printf("暂无火车数据 !");
		return;
	}
	printf("请选择:\n1:输入查询的列车号;\n2:输入查询的终点站:\n");
	scanf("%d", &sel);/*输入选择的序号*/
	if (sel == 1)
	{
		printf("请输入查询的列车号:");
		scanf("%s", str1);
		r = l->next;
		while (r != NULL)
			if (strcmp(r->data.num, str1) == 0)/*检索是否有与输入的车号相匹配的*/
			{
				s[i] = r;
				i++;
				break;
			}
			else
				r = r->next;
	}
	else if (sel == 2)
	{
		printf("请输入你要到达的终点站:");
		scanf("%s", str2);
		r = l->next;
		while (r != NULL)
			if (strcmp(r->data.reachcity, str2) == 0)/*检索是否有与输入的城市相匹配的火车*/
			{
				s[i] = r;
				i++;
				r = r->next;
			}
			else
				r = r->next;
	}
	if (i == 0)
		printf("找不到您要查询的信息");
	else
	{
		for (k = 0; k<i; k++)
			printdata(s[k]);
	}
}

void find0(bookLink ki)
{
	book *h[10], *t;
	int k, i = 0;
	char str1[5];
	if (!(ki->next))
	{
		printf("尚未有人订票!\n");
		return;
	}
	printf("请输入您要查询的列车号:");
	scanf("%s", str1);
	t = ki->next;
	while (t != NULL)
	{
		if (strcmp(t->data.lieche, str1) == 0)/*检索人的车号与输入的车号相匹配的*/
		{
			h[i] = t;
			i++;
			t = t->next;
		}
		else
			t = t->next;
	}
	if (i == 0)
		printf("找不到您要查询的信息!");
	for (k = 0; k<i; k++)
		printdata2(h[k]);
	
}

/*订票子模块*/
void Bookticket(Link l, bookLink k)
{
	Node *r[10], *p;
	char ch[2], tnum[10], str[10], str1[10], str2[10];
	book *q, *h,*m[10],*w;
	int i = 0, t = 0,v=0, flag = 0, dnum;
	int year, month, day;
	q = k;
	w=k->next;
	while (q->next != NULL)
		q = q->next;
	printf("请输入你要到达的终点站: ");
	scanf("%s", &str);/*输入要到达的城市*/
	p = l->next;
	while (p != NULL)
	{
		if (strcmp(p->data.reachcity, str) == 0)
		{
			r[i] = p;/*将满足条件的记录存到数组r中*/
			i++;
		}
		p = p->next;
	}
	for (t = 0; t<i; t++)
		printdata(r[t]);
	if (i == 0)
		printf("\n抱歉!\n找不到你要查询的火车!\n\n");
	else
	{
		printf("\n要订票吗?<y/n>\n");
		scanf("%s", ch);
		if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)/*判断是否订票*/           
		{
			h = (book*)malloc(sizeof(book));
			printf("请输入您的姓名: ");
			scanf("%s", &str1);
			printf("请输入您的身份证: ");
			scanf("%s", &str2);
			strcpy(h->data.name, str1);
			strcpy(h->data.num, str2);
			while (w != NULL)
			{
			
				if (strcmp(w->data.num, str2) == 0)
					{
						m[v] = w;
						v=1;
						break;
					}
				w = w->next;
			}
			if(v==1)
			{
				if(strcmp(str1,m[v-1]->data.name)!=0)
				{
					printf("姓名与身份证不匹配!\n");
					return;
				}
			}
			printf("请输入您要预定的列车号:");
			scanf("%s", tnum);
			printf("请输入您要出发的时间：");
			scanf("%d%d%d", &year, &month, &day);
			for (t = 0; t<i; t++)
				if(year==r[t]->data.StartTime.year&&month == r[t]->data.StartTime.month&&day == r[t]->data.StartTime.day)
					if (strcmp(r[t]->data.num, tnum) == 0)
					{
						if (r[t]->data.ticketnum<1)/*判断剩余的供订票的票数是否为0*/
						{
							printf("余票数不足，订票失败!");
							_getch();
							return;
						}
						printf("剩余 %d 票\n", r[t]->data.ticketnum);
						flag = 1;
						break;
					}
			if (v == 1)
			{
				if (year == m[v-1]->data.StartTime.year&&month == m[v-1]->data.StartTime.month&&day == m[v-1]->data.StartTime.day)
				{
					printf("你已经买过票了，不得继续买票!\n");
					return;
				}
			}
					if (flag == 0)
					{
						printf("抱歉，找不到你要预定的列车\n");
						_getch();
						return;
					}
					printf("请输入你要预定的票数: ");
					scanf("%d", &dnum);
					if (dnum > r[t]->data.ticketnum)
					{
						printf("余票数不足，订票失败!");
						return;
					}
					else
					{
						r[t]->data.ticketnum = r[t]->data.ticketnum - dnum;/*定票成功则可供订的票数相应减少*/
						h->data.bookNum = dnum;
						h->data.faresum = r[t]->data.price*dnum;
						strcpy(h->data.lieche, tnum);
						h->data.StartTime = r[t]->data.StartTime;
						h->next = NULL;
						q->next = h;
						q = h;
						printf("\n你已经成功预订到票了!");
						printf("%.2f", h->data.faresum);
					}
		}
	}
}
void showtrain(Link l)/*自定义函数显示列车信息*/
{
	Node *p;
	p = l->next;   
	if (l->next == NULL)
		printf("暂无火车信息!");
	else
		while (p != NULL)
		{
			printdata(p);
			p = p->next;
		}
}
/*保存火车信息*/
void SaveTrainInfo(Link l)
{
	FILE*fp;
	Node*p;
	fp = fopen("train.txt", "wb");
	if (fp == NULL)
	{
		printf("文件无法打开!");
		return;
	}
	p = l->next;
	while (p)
	{
		if (fwrite(p, sizeof(Node), 1, fp) == 1)
		{
			p = p->next;
		}
		else
		{
			break;
		}
	}
	fclose(fp);
}
/*保存订票人的信息*/
void SaveBookInfo(bookLink k)
{
	FILE*fp;
	book *p;
	fp = fopen("man.txt", "wb");
	if (fp == NULL)
	{
		printf("文件无法打开!");
		return;
	}
	p = k->next;
	while (p)                                
	{
		if (fwrite(p, sizeof(book), 1, fp) == 1)
		{
			p = p->next;
		}
		else
		{
			break;
		}
	}
	fclose(fp);
}

void tuiticket(Link l, bookLink k)     //i,,j
{
	Node *r[10], *p;
	char ch[2], str[10], str1[10];
	book *q,*h[10];
	int i = 0,j=0, t = 0, flag = 0, dnum;
	int year, month, day;
	for (int u = 0; u < 2; u++)
	{
		printf("请输入您要退票的车次： ");
		scanf("%s", &str);
		printf("请输入您的身份证: ");
		scanf("%s", &str1);
		printf("请输入您要退票的时间：（ 年 月 日）");
		scanf("%d%d%d", &year, &month, &day);
		
		p = l->next;
		q = k->next;
		while (p != NULL)
		{
			if (strcmp(p->data.num, str) == 0 && year == p->data.StartTime.year && month == p->data.StartTime.month
				&& day == p->data.StartTime.day )
			{
				r[i] = p;/*将满足条件的记录存到数组r中*/
				i++;
			}
			p = p->next;
		}
		while (q != NULL)
		{
			if (strcmp(q->data.num, str1) == 0 && year == q->data.StartTime.year && month == q->data.StartTime.month
				&& day == q->data.StartTime.day  && strcmp(q->data.lieche,str) == 0)
			{
				h[j] = q;
				j++;
			}
			q = q->next;
		}
		if (i!=0 && j!=0)
			break;
		
		else
		{
			if (u == 0)
			{
				printf("\n未找到相应信息\n");
			}
			else if (u == 1)
			{
				printf("\n输入信息错误，退票失败\n");
				goto end;
			}
		}
	}
	i--;
	j--;
	printf("\n您要退票吗?<y/n>\n");
	scanf("%s", ch);
	if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)/*判断是否退票*/
	{
	/*printf("Input your day:");
		scanf("%d%d%d", &year, &month, &day);*/
		if (year == h[j]->data.StartTime.year&&month == h[j]->data.StartTime.month&&day == h[j]->data.StartTime.day)
		{
			flag = 1;
		}
		if (flag == 0)
		{
			printf("未找到符合要求的记录");
			_getch();
			return;
		}
		printf("您有 %d 张票\n", (h[j]->data.bookNum));
		printf("请输入您的退票数: ");
		scanf("%d", &dnum);
		
		if (dnum<(h[j]->data.bookNum))
		{
			r[i]->data.ticketnum = r[i]->data.ticketnum + dnum;
			h[j]->data.bookNum -= dnum;
			h[j]->data.faresum -= r[i]->data.price*dnum;
		}
		else if (dnum == h[j]->data.bookNum)
		{
			r[i]->data.ticketnum = r[i]->data.ticketnum + dnum;
			q = k;
			do
			{
				if (q->next==h[j])
				{
					q->next = h[j]->next;
					break;
				}
				q = q->next;
			} while (q != NULL);
		}
		else
		{
			printf("退票数输入错误");
			_getch();
			return;
		}
		
		printf("\n恭喜!\n退票成功!\n");
end:
		_getch();
	}
	
}
void find1(Link l)
{
	int i=0;
		if (!l->next)
	{
		printf("暂无火车数据 !");
		return;
	}
	node *p;
	char ch[20];
	p = l->next;
	printf("请输入您要查询的车次");
	scanf("%s", ch);
	while (p != NULL)
	{
		if (strcmp(p->data.num,ch)==0)
		{
			i++;
			printf("发车时间：%04d.%02d.%02d", p->data.StartTime.year, p->data.StartTime.month, p->data.StartTime.day);
			printf("\t订票数：%d    余票数：%d\n", p->data.ticketsum, p->data.ticketnum);
		}
		p = p->next;
	}
		if(i==0)
		printf("抱歉！没有相应的数据\n");
}

void find2(Link l)
{
	int i=0;
		if (!l->next)
	{
		printf("暂无火车数据 !");
		return;
	}
	node *p;
	p = l->next;
	char ch[20];
	printf("请输入您要到达的终点站：");
	scanf("%s", ch);
	while (p != NULL)
	{
		if (strcmp(p->data.reachcity,ch)==0)
		{
			i++;
			printf("终点站：%s 车次：%s 发车时间：%d年%d月%d日%d时%d分 火车票价：%.2f 火车余票数：%d\n\n",
				p->data.reachcity, p->data.num, p->data.StartTime.year, p->data.StartTime.month,
				p->data.StartTime.day, p->data.StartTime.hour, p->data.StartTime.minute,
				p->data.price, p->data.ticketnum);
		}
		p = p->next;
	}
		if(i==0)
		printf("抱歉！没有相应的数据\n");
}

void find3(Link l)
{
	int i=0;
		if (!l->next)
	{
		printf("暂无火车数据 !");
		return;
	}
	node *p;
	int year, month, day;
	p = l->next;
	printf("请输入您要查询的时间（格式为年 月 日）：");
	scanf("%d%d%d", &year, &month, &day);                 //  int i 输出有多条线路!\n
	while (p != NULL)
	{
		if (p->data.StartTime.year == year  &&  p->data.StartTime.month == month  &&  day == p->data.StartTime.day)
		{
			i++;
			printf("终点站：%s 车次：%s 发车时间：%d年%d月%d日%d时%d分 火车票价：%.2f 火车余票数：%d\n\n",
				p->data.reachcity, p->data.num, p->data.StartTime.year, p->data.StartTime.month,
				p->data.StartTime.day, p->data.StartTime.hour, p->data.StartTime.minute,
				p->data.price, p->data.ticketnum);
		}
		p = p->next;
	}
		if(i==0)
		printf("抱歉！没有相应的数据\n");
}

void find4(Link l)
{
	int i=0;
		if (!l->next)
	{
		printf("暂无火车数据 !");
		return;
	}
	node *p;
	p = l->next;
	while (p != NULL)
	{
		if (p->data.ticketnum == 0)
		{
			i++;
			{printf("终点站：%s 车次：%s 发车时间：%d年%d月%d日%d时%d分 火车票价：%.2f 火车余票数：%d\n\n",
				p->data.reachcity, p->data.num, p->data.StartTime.year, p->data.StartTime.month,
				p->data.StartTime.day, p->data.StartTime.hour, p->data.StartTime.minute,
				p->data.price, p->data.ticketnum); }
		}
		p = p->next;
	}
	if(i==0)
		printf("抱歉！没有相应的数据\n");
}
int main()
{
	int b, c;
	FILE*fp1, *fp2;
	Node *p, *r;
	Link l;
	bookLink k;
	book *t, *h;
	int sel;
	l = (Node*)malloc(sizeof(Node));
	l->next = NULL;
	r = l;
	k = (book*)malloc(sizeof(book));
	k->next = NULL;
	h = k;
	fp1 = fopen("train.txt", "ab+");/*打开存储车票信息的文件*/
	if ((fp1 == NULL))
	{
		printf("文件无法打开!");
		return 0;
	}
	while (!feof(fp1))
	{
		p = (Node*)malloc(sizeof(Node));
		if (fread(p, sizeof(Node), 1, fp1) == 1)/*从指定磁盘文件读取记录*/
		{
			p->next = NULL;
			r->next = p;/*构造链表*/
			r = p;
			
		}
	}
	fclose(fp1);
	fp2 = fopen("man.txt", "ab+");
	if ((fp2 == NULL))
	{
		printf("文件无法打开!");
		return 0;
	}
	
	while (!feof(fp2))
	{
		t = (book*)malloc(sizeof(book));
		if (fread(t, sizeof(book), 1, fp2) == 1)
		{
			t->next = NULL;
			h->next = t;
			h = t;
			
		}
	}
	fclose(fp2);
	while (1)
	{
		system("cls");
		sel=Menu();
		if (sel == 0)
		{
			printf("\n谢谢使用\n");
			break;	
		}
		switch (sel)/*根据输入的sel值不同选择相应操作*/
		{
		case 1:
			Traininfo(l); break;
		case 2:
			while(1)
			{
				system("cls");
				b=menu2();
				switch (b)
				{
				case 1:
					showtrain(l);
					system("pause");
					break;
				case 2:
					searchtrain(l);
					system("pause");
					break;
				case 3:
					Bookticket(l, k);
					SaveBookInfo(k);
					SaveTrainInfo(l);
					system("pause");
					break;
				case 4:
					tuiticket(l, k);
					SaveBookInfo(k);
					SaveTrainInfo(l);
					system("pause");
					break;
				case 5:
start:
					system("cls");
					c = menu3();
					switch (c)
					{
					case 1:
						find0(k);
						system("pause");
						break;
					case 2:
						find1(l);
						system("pause");
						break;
					case 3:
						find2(l);
						system("pause");
						break;
					case 4:
						find3(l);
						system("pause");
						break;
					case 5:
						find4(l);
						system("pause");
						break;
					case 6:
						break;
					case 0:
						exit(0);
					default:printf("您输入的按键有误，请重新输入!\n\n");
						_getch();
						goto start;
					}
					break;
					case 0:
						exit(0);
					default:printf("您输入的按键有误，请重新输入!\n");
						_getch();
						break;
				}
			}
		default:printf("您输入的按键有误，请重新输入!\n");
			break;
		}
		system("pause");
	}
}