#include<stdio.h>
#include<stdlib.h>

struct record
{
	char author[12];
	char title[32];
	char publisher[16];
	short int year;
	short int num_of_page;
	
}rec;

struct List
{
	record* Data;
	List* Next;
};

void Copy_Address(struct record Records[], struct record* Index_Records[])
{
	for(int i=1;i<=4000;i++)
	{
		Index_Records[i]=&Records[i];
	}
}
/*
int less(struct record *X, struct record *Y)
{
	if(X->year<Y->year) return 1;
	if(X->year>Y->year) return 0;
	for(int i=0;i<12;i++)
	{
		if(X->author[i]<Y->author[i]) return 1;
		if(X->author[i]>Y->author[i]) return 0;
	}
	return 0;
}

int less_equal(struct record *X, struct record *Y)
{
	if(X->year<Y->year) return 1;
	if(X->year>Y->year) return 0;
	for(int i=0;i<12;i++)
	{
		if(X->author[i]<Y->author[i]) return 1;
		if(X->author[i]>Y->author[i]) return 0;
	}
	return 1;
}*/

/*void Heap(struct record* Z[], int L, int R)
{
	struct record* X=Z[L];
	int i=L, j=0;
	while(1)
	{
		j=2*i;
		if(j>R)
		{
			break;
		}
		if(j<R)
		{
			if(less_equal(Z[j+1],Z[j])) j++;
		}
		if(less(X,Z[j]))
		{
			break;
		}
		Z[i]=Z[j];
		i=j;
	}
	Z[i]=X;
}

void HeapSort(struct record* Z[], int N)
{
	int L=N/2, R=N;
	struct record* t;
	while(L>0)
	{
		Heap(Z,L,R);
		L--;
	}
	while(R>1)
	{
		t=Z[1];
		Z[1]=Z[R];
		Z[R]=t;
		R--;
		Heap(Z,1,R);
	}
}*/

int more(struct record *X, struct record *Y)
{
	if(X->year>Y->year) return 1;
	if(X->year<Y->year) return 0;
	for(int i=0;i<12;i++)
	{
		if(X->author[i]>Y->author[i]) return 1;
		if(X->author[i]<Y->author[i]) return 0;
	}
	return 0;
}

int more_equal(struct record *X, struct record *Y)
{
	if(X->year>Y->year) return 1;
	if(X->year<Y->year) return 0;
	for(int i=0;i<12;i++)
	{
		if(X->author[i]>Y->author[i]) return 1;
		if(X->author[i]<Y->author[i]) return 0;
	}
	return 1;
}

void Heap(struct record* Z[], int L, int R)
{
	struct record* X=Z[L];
	int i=L, j=0;
	while(1)
	{
		j=2*i;
		if(j>R)
		{
			break;
		}
		if(j<R)
		{
			if(more_equal(Z[j+1],Z[j])) j++;
		}
		if(more(X,Z[j]))
		{
			break;
		}
		Z[i]=Z[j];
		i=j;
	}
	Z[i]=X;
}

void HeapSort(struct record* Z[], int N)
{
	int L=N/2, R=N;
	struct record* t;
	while(L>0)
	{
		Heap(Z,L,R);
		L--;
	}
	while(R>1)
	{
		t=Z[1];
		Z[1]=Z[R];
		Z[R]=t;
		R--;
		Heap(Z,1,R);
	}
}

void ReadDataBase(struct record Records[], FILE *file)
{
	for(int i=1;i<=4000;i++)
	{
		fread(&rec,sizeof(rec),1,file);
		Records[i]=rec;
	}
}

void WriteDataBase(struct record Records[])
{
	int i=1, switcher=1;
	struct record* show;
	printf("Жизнь замечательных людей!\n\n");
	system("chcp 866>nul");
	while(1)
	{
		for(int k=0;k<20;k++)
		{
			show=&Records[i];
			printf("%-6i %s  %s  %s  %i  %i\n",i,show->author,show->title, show->publisher, show->year, show->num_of_page);
			i++;
		}
		if(i<=4000 && switcher==1)
		{
			system("chcp 1251>nul");
			printf("\nВы хотите продолжить?\n");
			printf("0 -- Нет\n");
			printf("1 -- Да, ещё 20 записей\n");
			printf("2 -- Да, все оставшиеся записи\n");
			scanf("%i",&switcher);
			printf("\n");
			system("chcp 866>nul");
			if(switcher==0)
			{
				break;
			}
		}
		if(i>4000) break;
	}
	printf("\n");
	system("pause");
}

void SortDataBase(struct record* Index_Records[])
{
	HeapSort(Index_Records,4000);
}

void WriteSortDataBase(struct record* Index_Records[])
{
	int i=1, switcher=1;
	struct record* show;
	printf("Жизнь замечательных людей!\n\n");
	system("chcp 866>nul");
	while(1)
	{
		for(int k=0;k<20;k++)
		{
			show=Index_Records[i];
			printf("%-6i %s  %s  %s  %i  %i\n",i,show->author,show->title, show->publisher, show->year, show->num_of_page);
			i++;
		}
		if(i<=4000 && switcher==1)
		{
			system("chcp 1251>nul");
			printf("\nВы хотите продолжить?\n");
			printf("0 -- Нет\n");
			printf("1 -- Да, ещё 20 записей\n");
			printf("2 -- Да, все оставшиеся записи\n");
			scanf("%i",&switcher);
			printf("\n");
			system("chcp 866>nul");
			if(switcher==0)
			{
				break;
			}
		}
		if(i>4000) break;
	}
	printf("\n");
	system("pause");
}

int BSearchDataBase(struct record* Index_Records[], int year)
{
	int L=1, R=4000, m;
	while(L<R)
	{
		m=(L+R)/2;
		if(Index_Records[m]->year<year)
		{
			L=m+1;
		}
		else
		{
			R=m;
		}
	}
	if(Index_Records[R]->year==year)
	{
		return R;
	}
	return 0;
}

void BSearchAllDataBase(struct record* Index_Records[], List* &Head, List* &Tail)
{
	int year, switcher=1;
	printf("Пожалуйста, введите год, по которому необходимо провести поиск данных\n");
	scanf("%i",&year);
	printf("\n");
	int j=BSearchDataBase(Index_Records, year);
	if(j==0)
	{
		printf("Простите, но элементов с вышеуказанным годом не существует в базе данных\n");
		system("pause");
		return;
	}
	struct List* p;
	p = new List;
	p->Data=Index_Records[j];
	Head=p;
	Tail=p;
	j++;
	printf("Жизнь замечательных людей!\n\n");
	system("chcp 866>nul");
	printf("%-6i %s  %s  %s  %i  %i\n",1,p->Data->author,p->Data->title, p->Data->publisher, p->Data->year, p->Data->num_of_page);
	for(int i=2; j<=4000 && Index_Records[j]->year==year;i++,j++)
	{
		p = new List;
		p->Data=Index_Records[j];
		Tail->Next=p;
		Tail=p;
		if(switcher) printf("%-6i %s  %s  %s  %i  %i\n",i,p->Data->author,p->Data->title, p->Data->publisher, p->Data->year, p->Data->num_of_page);
		if((i%20==0)&&switcher==1)
		{
			system("chcp 1251>nul");
			printf("\nВы хотите продолжить?\n");
			printf("0 -- Нет\n");
			printf("1 -- Да, ещё 20 записей\n");
			printf("2 -- Да, все оставшиеся записи\n");
			scanf("%i",&switcher);
			printf("\n");
			system("chcp 866>nul");
		}
	}
	Tail->Next=NULL;
	printf("\n");
	system("pause");
}

int Menu(char path[])
{
	int switcher;
	system("CLS");
	system("chcp 1251>nul");
	system("color 02");
	printf("Пожалуйста выбирете что вы хотите сделать:\n\n");
	printf("1) Просмотреть файл базы данных %s!\n",path);
	printf("2) Просмотреть отсортированный файл базы данных %s по году и автору!\n",path);
	printf("3) Произвести поиск всех данных в файле %s с указанным годом!\n",path);
	printf("4) Выйти из приложения!\n");
	scanf("%i",&switcher);
	system("color 07");
	system("CLS");
	return switcher;
}

void PrintList(List* Head)
{
	List* p=Head;
	system("chcp 866>nul");
	system("pause");
	while(p!=NULL)
	{
		printf("%s  %s  %s  %i  %i\n",p->Data->author,p->Data->title, p->Data->publisher, p->Data->year, p->Data->num_of_page);
		p=p->Next;
	}
	system("pause");
}

int main()
{
	FILE *file;
	char path[]="testBase1.dat";
	file=fopen(path,"rb");
	struct record *Records = new record[4001];
	ReadDataBase(Records, file);
	fclose(file);
	struct record* Index_Records[4001];
	Copy_Address(Records,Index_Records);
	SortDataBase(Index_Records);
	List *Head=NULL,*Tail=NULL;
	int menu_switcher;
	do
	{
		menu_switcher=Menu(path)%4;
		switch(menu_switcher)
		{
			case 1:
				WriteDataBase(Records);
				break;
			case 2:
				WriteSortDataBase(Index_Records);
				break;
			case 3:
				BSearchAllDataBase(Index_Records,Head,Tail);
				PrintList(Head);
				break;
				
		}
	}while(menu_switcher);
	delete []Records;
	return 0;
}
