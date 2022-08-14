#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50
typedef int Typedata;
typedef struct HashNode
{
	Typedata* HT;
	Typedata* num;
	Typedata* broke;
	Typedata* NUfod;//查找不成功的次数 
	Typedata key;
}HashNode;

Typedata i, k;

void InitHash(HashNode& T)//初始化 
{
	T.HT = (Typedata*)malloc(MAXSIZE * sizeof(Typedata));
	T.num = (Typedata*)malloc(MAXSIZE * sizeof(Typedata));
	T.broke = (Typedata*)malloc(MAXSIZE * sizeof(Typedata));
	T.NUfod = (Typedata*)malloc(MAXSIZE * sizeof(Typedata));
	for (i = 0; i < MAXSIZE; i++)
	{
		T.HT[i] = 0; T.num[i] = 0; T.broke[i] = 0;
	}
}

void CreateHash(HashNode T, Typedata k, Typedata m)
{
	Typedata d, t;
	for (i = 0; i < k; i++)//冲突的次数
	{
		d = T.num[i] % m; t = 1;
		while (T.HT[d])
		{
			d = (d + 1) % m;
			t++;
		}
		T.HT[d] = T.num[i];
		T.broke[d] = t;
	}

	Typedata j, count;
	for (i = 0; i < m; i++)//查找不成功的次数 
	{
		count = 1;
		for (j = i; j < m; j++)
		{
			if (T.HT[j] != 0)
				count++;
			else
				break;
			if (T.HT[j] != 0 && j == m - 1)
				j = -1;
		}
		T.NUfod[i] = count;
	}
}

void DisplayHash(HashNode T, Typedata m)
{
	printf("\n哈希表的地址：");
	for (i = 0; i < m; i++)
		printf("%-4d", i);
	printf("\n表中的关键字：");
	for (i = 0; i < m; i++)
		printf("%-4d", T.HT[i]);
	printf("\n发生冲突次数：");
	for (i = 0; i < m; i++)
		printf("%-4d", T.broke[i]);
	printf("\n查找失败次数：");
	for (i = 0; i < m; i++)
		printf("%-4d", T.NUfod[i]);
	printf("\n");
}

double NUEverageHash(HashNode T, Typedata m)//查找不成功 
{

	Typedata sum2 = 0;
	double ave2;
	for (i = 0; i < m; i++)
		sum2 += T.NUfod[i];
	ave2 = (double)sum2 / m;
	return ave2;
}

int main()
{
	HashNode T;
	InitHash(T);//初始化 
	Typedata m;
	printf("输入关键字的个数：");
	scanf("%d", &k);
	printf("输入关键字\n");
	for (i = 0; i < k; i++)
		scanf("%d", &T.num[i]);
	printf("输入m=");
	scanf("%d", &m);//小于表的总长的最大素数 
	CreateHash(T, k, m);//创建 
	DisplayHash(T, m);//输出 
	printf("查找不成功的平均查找长度NUASL=%.2lf\n", NUEverageHash(T, m));
	printf("\n\n");
	return 0;
}