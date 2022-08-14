#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50
typedef int Typedata;
typedef struct HashNode
{
	Typedata* HT;
	Typedata* num;
	Typedata* broke;
	Typedata* NUfod;//���Ҳ��ɹ��Ĵ��� 
	Typedata key;
}HashNode;

Typedata i, k;

void InitHash(HashNode& T)//��ʼ�� 
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
	for (i = 0; i < k; i++)//��ͻ�Ĵ���
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
	for (i = 0; i < m; i++)//���Ҳ��ɹ��Ĵ��� 
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
	printf("\n��ϣ��ĵ�ַ��");
	for (i = 0; i < m; i++)
		printf("%-4d", i);
	printf("\n���еĹؼ��֣�");
	for (i = 0; i < m; i++)
		printf("%-4d", T.HT[i]);
	printf("\n������ͻ������");
	for (i = 0; i < m; i++)
		printf("%-4d", T.broke[i]);
	printf("\n����ʧ�ܴ�����");
	for (i = 0; i < m; i++)
		printf("%-4d", T.NUfod[i]);
	printf("\n");
}

double NUEverageHash(HashNode T, Typedata m)//���Ҳ��ɹ� 
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
	InitHash(T);//��ʼ�� 
	Typedata m;
	printf("����ؼ��ֵĸ�����");
	scanf("%d", &k);
	printf("����ؼ���\n");
	for (i = 0; i < k; i++)
		scanf("%d", &T.num[i]);
	printf("����m=");
	scanf("%d", &m);//С�ڱ���ܳ���������� 
	CreateHash(T, k, m);//���� 
	DisplayHash(T, m);//��� 
	printf("���Ҳ��ɹ���ƽ�����ҳ���NUASL=%.2lf\n", NUEverageHash(T, m));
	printf("\n\n");
	return 0;
}