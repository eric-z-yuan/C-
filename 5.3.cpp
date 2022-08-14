����3��
#include<stdio.h>
#include<stdlib.h>

typedef struct {
	float coef;//ϵ��
	int expn;//ָ��
}term, ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;//���Ա���

typedef LinkList polynomial;

polynomial CreatPolyn() {
	polynomial h;
	h = (polynomial)malloc(sizeof(LNode));
	h->next = NULL;
	return h;
}//��������ʽ

polynomial inputPolyn(polynomial A) {
	int n, i;
	LNode* pa = A;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		LNode* set;
		set = (polynomial)malloc(sizeof(LNode));
		scanf("%f,%d", &(set->data.coef), &(set->data.expn));
		set->next = NULL;
		pa->next = set;
		pa = pa->next;
	}
	return A;
}//����ʽ�ĸ�ֵ

polynomial AddPolyn(polynomial A, polynomial B) {
	if (B->next == NULL)return A;
	if (A->next == NULL)return B;
	LNode* pa = A->next, * pb = B->next, * pc;
	polynomial C;
	C = CreatPolyn();
	pc = C;
	while (pa != NULL && pb != NULL) {
		LNode* temp;
		temp = (polynomial)malloc(sizeof(LNode));
		if (pb->data.expn > pa->data.expn) {
			temp->data.expn = pb->data.expn;
			temp->data.coef = pb->data.coef;
			pc->next = temp;
			pc = pc->next;
			pc->next = NULL;
			pb = pb->next;
		}
		else if (pb->data.expn < pa->data.expn) {
			temp->data.expn = pa->data.expn;
			temp->data.coef = pa->data.coef;
			pc->next = temp;
			pc = pc->next;
			pc->next = NULL;
			pa = pa->next;
		}
		else {
			temp->data.coef = pa->data.coef + pb->data.coef;
			temp->data.expn = pa->data.expn;
			pc->next = temp;
			pc = pc->next;
			pc->next = NULL;
			pa = pa->next;
			pb = pb->next;
		}
	}
	if (pa == NULL && pb != NULL) {
		while (pb) {
			LNode* temp;
			temp = (polynomial)malloc(sizeof(LNode));
			temp->data.expn = pb->data.expn;
			temp->data.coef = pb->data.coef;
			pc->next = temp;
			pc = pc->next;
			pc->next = NULL;
			pb = pb->next;
		}
	}
	else if (pa != NULL && pb == NULL) {
		while (pa) {
			LNode* temp;
			temp = (polynomial)malloc(sizeof(LNode));
			temp->data.expn = pa->data.expn;
			temp->data.coef = pa->data.coef;
			pc->next = temp;
			pc = pc->next;
			pc->next = NULL;
			pa = pa->next;
		}
	}
	return C;
}//����ʽA��B���

polynomial MultiplyPolyn(polynomial A, polynomial B) {
	if (A == NULL || B == NULL) {
		printf("Polynomial A or B is empty.\n");
		exit(0);
	}
	LNode* pa = A->next, * pb, * p;
	polynomial C;
	C = CreatPolyn();
	while (pa != NULL) {
		pb = B->next;
		polynomial temp;
		temp = CreatPolyn();//��ʾ��i������ʽ 
		LNode* pt = temp;//ptΪtemp��ͷָ�� 
		while (pb != NULL) {
			LNode* set;//���浱ǰpa��pb��ָ����Ԫ��������ý�� 
			set = (polynomial)malloc(sizeof(LNode));
			set->data.coef = pa->data.coef * pb->data.coef;
			set->data.expn = pa->data.expn + pb->data.expn;
			set->next = NULL;
			pt->next = set;
			pt = pt->next;
			pb = pb->next;
		}
		//ÿ�μ������i������ʽ�󣬶�������C������� 
		C = AddPolyn(C, temp);
		pa = pa->next;
	}
	return C;
}//����ʽA��B���

int main() {
	//A��BΪ����Ķ���ʽ��CΪ������ý�� 
	polynomial A, B, C;
	int n;
	A = CreatPolyn();
	printf("��������ʽA��\n");
	A = inputPolyn(A);
	B = CreatPolyn();
	printf("��������ʽB��\n");
	B = inputPolyn(B);
	//��A��B��˵Ľ������C�� 
	C = MultiplyPolyn(A, B);
	return 0;
}