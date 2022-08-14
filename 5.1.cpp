#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50
typedef int Typedata;
typedef struct HashNode
{
	Typedata* HT;//存放最终的关键字 
	Typedata* num;//存放输入的关键字
	Typedata* broke;//冲突次数 
	Typedata key;
}HashNode;

Typedata i, k;//关键字的个数 

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
	printf("\n");
}

double EverageHash(HashNode T, Typedata m)//查找成功 
{
	Typedata sum = 0;
	double ave;
	for (i = 0; i < m; i++)
		sum += T.broke[i];
	ave = (double)sum / k;
	return ave;
}
int main()
{
	HashNode T;
	char c = 'Y';
	while (c == 'Y')
	{
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

		printf("查找成功的平均查找长度ASL=%.2lf\n", EverageHash(T, m));
		printf("\n\n");
	}
	return 0;
}