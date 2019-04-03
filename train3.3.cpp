#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FORMAT  "|�г���:%s|�յ�վ:%-3s|����ʱ��:%04d.%02d.%02d|��Ʊ��:%d|��Ʊ��%d|Ʊ��:%.2f\n\n"
#define DATA p->data.num,p->data.reachcity,p->data.StartTime.year, p->data.StartTime.month, p->data.StartTime.day,p->data.ticketnum,p->data.ticketsum,p->data.price
/*����洢����Ϣ�Ľṹ��*/
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
	char num[10];/*�г���*/
	char reachcity[10];/*Ŀ�ĳ���*/
	struct Dtime StartTime;
	double  price;/*Ʊ��*/
	int  ticketnum;/*Ʊ��*/
	int ticketsum;
};
/*��Ʊ�˵���Ϣ*/
struct man
{
	char num[10];/*ID*/
	char name[10];/*����*/
	int  bookNum;/*����Ʊ��*/
	double faresum;
	char lieche[10];
	struct Dtime StartTime;
};
/*�������Ϣ����Ľ��ṹ*/
typedef struct node
{
	struct train data;
	struct node * next;
}Node, *Link;
/*���嶩Ʊ������Ľ��ṹ*/
typedef struct Man
{
	struct man data;
	struct Man *next;
}book, *bookLink;

void SaveTrainInfo(Link l);
/* ��ʼ����*/
int Menu()
{
	int sel;
	printf("\n");
	printf("\t--------------------------------------------\n");
	printf("\t*                                          *\n");
	printf("\t*        ��ӭ����𳵶�Ʊ����ϵͳ          *\n");
	printf("\t*                                          *\n");
	printf("\t--------------------------------------------\n");
	printf("\n");
	printf("\t 1.����Ա���\n");
	printf("\t 2.�˿����\n");
	printf("\t 0.�˳�ϵͳ\n\n");
	printf("\t ��ѡ�񰴼�0~2\n");
	scanf("%d", &sel);
	return(sel);
}

int menu2()
{
	int sel;
	printf("\n");
	printf("\t--------------------------------------------\n");
	printf("\t*                                          *\n");
	printf("\t*        ��ӭ����𳵶�Ʊ����ϵͳ          *\n");
	printf("\t*                                          *\n");
	printf("\t--------------------------------------------\n");
	printf("\n");
	printf("\t��ѡ����Ҫʹ�õĹ��ܣ�\n\n");
	printf("\t 1.��ʾȫ��·��\n");
	printf("\t 2.��·�߲�ѯ\n");
	printf("\t 3.��Ʊ\n");
	printf("\t 4.��Ʊ\n");
	printf("\t 5.������ѯ\n");
	printf("\t 0.�˳�ϵͳ\n\n");
	printf("\t ��ѡ�񰴼�0~4\n");
	scanf("%d", &sel);
	return(sel);
}

int menu3()
{
	int sel;
	printf("\n");
	printf("\t--------------------------------------------\n");
	printf("\t*                                          *\n");
	printf("\t*        ��ӭ����𳵶�Ʊ����ϵͳ          *\n");
	printf("\t*                                          *\n");
	printf("\t--------------------------------------------\n");
	printf("\n");
	printf("\t��ѡ����Ҫʹ�õĹ��ܣ�\n\n");
	printf("\t 1.���복�Σ���ѯ�ó��ε�ȫ����Ʊ��Ϣ\n");
	printf("\t 2.���복�Σ���ѯ�ó��εĶ�Ʊ������Ʊ��\n");
	printf("\t 3.�����յ�վ���ƣ���ѯ��ػ���·����Ϣ\n");
	printf("\t 4.�������ڣ���~��~�գ�����ѯ����ʱ��Ϊ����Ļ���·����Ϣ\n");
	printf("\t 5.��ѯ��Ʊ��Ϊ0�Ļ���·��Ϣ\n");
	printf("\t 6.������һ����\n");
	printf("\t 0.�˳�ϵͳ\n\n");
	printf("\t ��ѡ�񰴼�0~6\n");
	scanf("%d", &sel);
	return(sel);
}

/*���һ������Ϣ*/



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
		printf("�������г���(0Ϊ�˳�)"); 
		scanf("%s", num);
		if (strcmp(num, "0") == 0)
			break;
		printf("�����뷢��ʱ�䣨��ʽΪ�� �� �� ʱ �֣���");
		scanf("%d%d%d%d%d", &year, &month, &day, &hour, &minute);
		/*�ж��Ƿ��Ѿ�����*/
		while (s)                     //                              zy   &ָ�������ڴ�orfile
		{
			if (strcmp(s->data.num, num) == 0)
			{
				if (year == s->data.StartTime.year&&month == s->data.StartTime.month&&day == s->data.StartTime.day)
				{
					printf("����Ϊ '%s'�Ѿ�����!\n", num);
					return;
				}
			}
			s = s->next;
		}
		p = (struct node*)malloc(sizeof(struct node));
		strcpy(p->data.num, num);/*���복��*/
		printf("�������յ�վ:");
		scanf("%s", p->data.reachcity);/*���뵽վ����*/
		p->data.StartTime.year = year;
		p->data.StartTime.month = month;
		p->data.StartTime.day = day;
		p->data.StartTime.hour = hour;
		p->data.StartTime.minute=minute;/*�������ʱ��*/
piaoj:
		printf("������Ʊ��:");
		scanf("%lf", &p->data.price);/*�����Ʊ��*/
		if(p->data.price < 1.0)
		{
			printf("Ʊ����������!����������!\n");
			goto piaoj;
		}
piaos:
		printf("��������Ʊ��:");
		scanf("%d", &p->data.ticketnum);/*����Ԥ��Ʊ��*/
		if (p->data.ticketnum<1)
		{
			printf("Ʊ����������!����������!\n");
			goto piaos;
		}
		p->data.ticketsum = p->data.ticketnum;
		p->next = NULL;
		r->next = p;/*���뵽������*/
		r = p;
		SaveTrainInfo(linkhead);
	}
}
/*��ӡ��Ʊ��Ϣ*/
void printdata(Node *q) /*��ʽ�������������*/
{
	Node* p;
	p = q;
	printf(FORMAT, DATA);
}


void  printdata2(book *q)
{
	book *p;
	p = q;
	printf("\n���֤�ţ�%s  ������%s  ��Ʊ����%d  ��Ʊ�ۣ�%.2lf  �����γ���ʱ�䣺%d��%d��%d��%dʱ%d��\n\n"
		, q->data.num, q->data.name,q->data.bookNum, q->data.faresum, q->data.StartTime.year, q->data.StartTime.month,
		q->data.StartTime.day, q->data.StartTime.hour, q->data.StartTime.minute);
	
}



/*��ѯ����Ϣ*/
void searchtrain(Link l)

{
	Node *s[10], *r;
	int sel, k, i = 0;
	char str1[5], str2[10];
	if (!l->next)
	{
		printf("���޻����� !");
		return;
	}
	printf("��ѡ��:\n1:�����ѯ���г���;\n2:�����ѯ���յ�վ:\n");
	scanf("%d", &sel);/*����ѡ������*/
	if (sel == 1)
	{
		printf("�������ѯ���г���:");
		scanf("%s", str1);
		r = l->next;
		while (r != NULL)
			if (strcmp(r->data.num, str1) == 0)/*�����Ƿ���������ĳ�����ƥ���*/
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
		printf("��������Ҫ������յ�վ:");
		scanf("%s", str2);
		r = l->next;
		while (r != NULL)
			if (strcmp(r->data.reachcity, str2) == 0)/*�����Ƿ���������ĳ�����ƥ��Ļ�*/
			{
				s[i] = r;
				i++;
				r = r->next;
			}
			else
				r = r->next;
	}
	if (i == 0)
		printf("�Ҳ�����Ҫ��ѯ����Ϣ");
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
		printf("��δ���˶�Ʊ!\n");
		return;
	}
	printf("��������Ҫ��ѯ���г���:");
	scanf("%s", str1);
	t = ki->next;
	while (t != NULL)
	{
		if (strcmp(t->data.lieche, str1) == 0)/*�����˵ĳ���������ĳ�����ƥ���*/
		{
			h[i] = t;
			i++;
			t = t->next;
		}
		else
			t = t->next;
	}
	if (i == 0)
		printf("�Ҳ�����Ҫ��ѯ����Ϣ!");
	for (k = 0; k<i; k++)
		printdata2(h[k]);
	
}

/*��Ʊ��ģ��*/
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
	printf("��������Ҫ������յ�վ: ");
	scanf("%s", &str);/*����Ҫ����ĳ���*/
	p = l->next;
	while (p != NULL)
	{
		if (strcmp(p->data.reachcity, str) == 0)
		{
			r[i] = p;/*�����������ļ�¼�浽����r��*/
			i++;
		}
		p = p->next;
	}
	for (t = 0; t<i; t++)
		printdata(r[t]);
	if (i == 0)
		printf("\n��Ǹ!\n�Ҳ�����Ҫ��ѯ�Ļ�!\n\n");
	else
	{
		printf("\nҪ��Ʊ��?<y/n>\n");
		scanf("%s", ch);
		if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)/*�ж��Ƿ�Ʊ*/           
		{
			h = (book*)malloc(sizeof(book));
			printf("��������������: ");
			scanf("%s", &str1);
			printf("�������������֤: ");
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
					printf("���������֤��ƥ��!\n");
					return;
				}
			}
			printf("��������ҪԤ�����г���:");
			scanf("%s", tnum);
			printf("��������Ҫ������ʱ�䣺");
			scanf("%d%d%d", &year, &month, &day);
			for (t = 0; t<i; t++)
				if(year==r[t]->data.StartTime.year&&month == r[t]->data.StartTime.month&&day == r[t]->data.StartTime.day)
					if (strcmp(r[t]->data.num, tnum) == 0)
					{
						if (r[t]->data.ticketnum<1)/*�ж�ʣ��Ĺ���Ʊ��Ʊ���Ƿ�Ϊ0*/
						{
							printf("��Ʊ�����㣬��Ʊʧ��!");
							_getch();
							return;
						}
						printf("ʣ�� %d Ʊ\n", r[t]->data.ticketnum);
						flag = 1;
						break;
					}
			if (v == 1)
			{
				if (year == m[v-1]->data.StartTime.year&&month == m[v-1]->data.StartTime.month&&day == m[v-1]->data.StartTime.day)
				{
					printf("���Ѿ����Ʊ�ˣ����ü�����Ʊ!\n");
					return;
				}
			}
					if (flag == 0)
					{
						printf("��Ǹ���Ҳ�����ҪԤ�����г�\n");
						_getch();
						return;
					}
					printf("��������ҪԤ����Ʊ��: ");
					scanf("%d", &dnum);
					if (dnum > r[t]->data.ticketnum)
					{
						printf("��Ʊ�����㣬��Ʊʧ��!");
						return;
					}
					else
					{
						r[t]->data.ticketnum = r[t]->data.ticketnum - dnum;/*��Ʊ�ɹ���ɹ�����Ʊ����Ӧ����*/
						h->data.bookNum = dnum;
						h->data.faresum = r[t]->data.price*dnum;
						strcpy(h->data.lieche, tnum);
						h->data.StartTime = r[t]->data.StartTime;
						h->next = NULL;
						q->next = h;
						q = h;
						printf("\n���Ѿ��ɹ�Ԥ����Ʊ��!");
						printf("%.2f", h->data.faresum);
					}
		}
	}
}
void showtrain(Link l)/*�Զ��庯����ʾ�г���Ϣ*/
{
	Node *p;
	p = l->next;   
	if (l->next == NULL)
		printf("���޻���Ϣ!");
	else
		while (p != NULL)
		{
			printdata(p);
			p = p->next;
		}
}
/*�������Ϣ*/
void SaveTrainInfo(Link l)
{
	FILE*fp;
	Node*p;
	fp = fopen("train.txt", "wb");
	if (fp == NULL)
	{
		printf("�ļ��޷���!");
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
/*���涩Ʊ�˵���Ϣ*/
void SaveBookInfo(bookLink k)
{
	FILE*fp;
	book *p;
	fp = fopen("man.txt", "wb");
	if (fp == NULL)
	{
		printf("�ļ��޷���!");
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
		printf("��������Ҫ��Ʊ�ĳ��Σ� ");
		scanf("%s", &str);
		printf("�������������֤: ");
		scanf("%s", &str1);
		printf("��������Ҫ��Ʊ��ʱ�䣺�� �� �� �գ�");
		scanf("%d%d%d", &year, &month, &day);
		
		p = l->next;
		q = k->next;
		while (p != NULL)
		{
			if (strcmp(p->data.num, str) == 0 && year == p->data.StartTime.year && month == p->data.StartTime.month
				&& day == p->data.StartTime.day )
			{
				r[i] = p;/*�����������ļ�¼�浽����r��*/
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
				printf("\nδ�ҵ���Ӧ��Ϣ\n");
			}
			else if (u == 1)
			{
				printf("\n������Ϣ������Ʊʧ��\n");
				goto end;
			}
		}
	}
	i--;
	j--;
	printf("\n��Ҫ��Ʊ��?<y/n>\n");
	scanf("%s", ch);
	if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0)/*�ж��Ƿ���Ʊ*/
	{
	/*printf("Input your day:");
		scanf("%d%d%d", &year, &month, &day);*/
		if (year == h[j]->data.StartTime.year&&month == h[j]->data.StartTime.month&&day == h[j]->data.StartTime.day)
		{
			flag = 1;
		}
		if (flag == 0)
		{
			printf("δ�ҵ�����Ҫ��ļ�¼");
			_getch();
			return;
		}
		printf("���� %d ��Ʊ\n", (h[j]->data.bookNum));
		printf("������������Ʊ��: ");
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
			printf("��Ʊ���������");
			_getch();
			return;
		}
		
		printf("\n��ϲ!\n��Ʊ�ɹ�!\n");
end:
		_getch();
	}
	
}
void find1(Link l)
{
	int i=0;
		if (!l->next)
	{
		printf("���޻����� !");
		return;
	}
	node *p;
	char ch[20];
	p = l->next;
	printf("��������Ҫ��ѯ�ĳ���");
	scanf("%s", ch);
	while (p != NULL)
	{
		if (strcmp(p->data.num,ch)==0)
		{
			i++;
			printf("����ʱ�䣺%04d.%02d.%02d", p->data.StartTime.year, p->data.StartTime.month, p->data.StartTime.day);
			printf("\t��Ʊ����%d    ��Ʊ����%d\n", p->data.ticketsum, p->data.ticketnum);
		}
		p = p->next;
	}
		if(i==0)
		printf("��Ǹ��û����Ӧ������\n");
}

void find2(Link l)
{
	int i=0;
		if (!l->next)
	{
		printf("���޻����� !");
		return;
	}
	node *p;
	p = l->next;
	char ch[20];
	printf("��������Ҫ������յ�վ��");
	scanf("%s", ch);
	while (p != NULL)
	{
		if (strcmp(p->data.reachcity,ch)==0)
		{
			i++;
			printf("�յ�վ��%s ���Σ�%s ����ʱ�䣺%d��%d��%d��%dʱ%d�� ��Ʊ�ۣ�%.2f ����Ʊ����%d\n\n",
				p->data.reachcity, p->data.num, p->data.StartTime.year, p->data.StartTime.month,
				p->data.StartTime.day, p->data.StartTime.hour, p->data.StartTime.minute,
				p->data.price, p->data.ticketnum);
		}
		p = p->next;
	}
		if(i==0)
		printf("��Ǹ��û����Ӧ������\n");
}

void find3(Link l)
{
	int i=0;
		if (!l->next)
	{
		printf("���޻����� !");
		return;
	}
	node *p;
	int year, month, day;
	p = l->next;
	printf("��������Ҫ��ѯ��ʱ�䣨��ʽΪ�� �� �գ���");
	scanf("%d%d%d", &year, &month, &day);                 //  int i ����ж�����·!\n
	while (p != NULL)
	{
		if (p->data.StartTime.year == year  &&  p->data.StartTime.month == month  &&  day == p->data.StartTime.day)
		{
			i++;
			printf("�յ�վ��%s ���Σ�%s ����ʱ�䣺%d��%d��%d��%dʱ%d�� ��Ʊ�ۣ�%.2f ����Ʊ����%d\n\n",
				p->data.reachcity, p->data.num, p->data.StartTime.year, p->data.StartTime.month,
				p->data.StartTime.day, p->data.StartTime.hour, p->data.StartTime.minute,
				p->data.price, p->data.ticketnum);
		}
		p = p->next;
	}
		if(i==0)
		printf("��Ǹ��û����Ӧ������\n");
}

void find4(Link l)
{
	int i=0;
		if (!l->next)
	{
		printf("���޻����� !");
		return;
	}
	node *p;
	p = l->next;
	while (p != NULL)
	{
		if (p->data.ticketnum == 0)
		{
			i++;
			{printf("�յ�վ��%s ���Σ�%s ����ʱ�䣺%d��%d��%d��%dʱ%d�� ��Ʊ�ۣ�%.2f ����Ʊ����%d\n\n",
				p->data.reachcity, p->data.num, p->data.StartTime.year, p->data.StartTime.month,
				p->data.StartTime.day, p->data.StartTime.hour, p->data.StartTime.minute,
				p->data.price, p->data.ticketnum); }
		}
		p = p->next;
	}
	if(i==0)
		printf("��Ǹ��û����Ӧ������\n");
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
	fp1 = fopen("train.txt", "ab+");/*�򿪴洢��Ʊ��Ϣ���ļ�*/
	if ((fp1 == NULL))
	{
		printf("�ļ��޷���!");
		return 0;
	}
	while (!feof(fp1))
	{
		p = (Node*)malloc(sizeof(Node));
		if (fread(p, sizeof(Node), 1, fp1) == 1)/*��ָ�������ļ���ȡ��¼*/
		{
			p->next = NULL;
			r->next = p;/*��������*/
			r = p;
			
		}
	}
	fclose(fp1);
	fp2 = fopen("man.txt", "ab+");
	if ((fp2 == NULL))
	{
		printf("�ļ��޷���!");
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
			printf("\nллʹ��\n");
			break;	
		}
		switch (sel)/*���������selֵ��ͬѡ����Ӧ����*/
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
					default:printf("������İ�����������������!\n\n");
						_getch();
						goto start;
					}
					break;
					case 0:
						exit(0);
					default:printf("������İ�����������������!\n");
						_getch();
						break;
				}
			}
		default:printf("������İ�����������������!\n");
			break;
		}
		system("pause");
	}
}