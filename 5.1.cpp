#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50
typedef int Typedata;
typedef struct HashNode
{
	Typedata* HT;//������յĹؼ��� 
	Typedata* num;//�������Ĺؼ���
	Typedata* broke;//��ͻ���� 
	Typedata key;
}HashNode;

Typedata i, k;//�ؼ��ֵĸ��� 

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
	printf("\n");
}

double EverageHash(HashNode T, Typedata m)//���ҳɹ� 
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

		printf("���ҳɹ���ƽ�����ҳ���ASL=%.2lf\n", EverageHash(T, m));
		printf("\n\n");
	}
	return 0;
}