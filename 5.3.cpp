代码3：
#include<stdio.h>
#include<stdlib.h>

typedef struct {
	float coef;//系数
	int expn;//指数
}term, ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;//线性表定义

typedef LinkList polynomial;

polynomial CreatPolyn() {
	polynomial h;
	h = (polynomial)malloc(sizeof(LNode));
	h->next = NULL;
	return h;
}//创建多项式

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
}//多项式的赋值

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
}//多项式A与B相加

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
		temp = CreatPolyn();//表示第i个多项式 
		LNode* pt = temp;//pt为temp的头指针 
		while (pb != NULL) {
			LNode* set;//保存当前pa与pb所指数据元素相乘所得结果 
			set = (polynomial)malloc(sizeof(LNode));
			set->data.coef = pa->data.coef * pb->data.coef;
			set->data.expn = pa->data.expn + pb->data.expn;
			set->next = NULL;
			pt->next = set;
			pt = pt->next;
			pb = pb->next;
		}
		//每次计算出第i个多项式后，都将其与C进行相加 
		C = AddPolyn(C, temp);
		pa = pa->next;
	}
	return C;
}//多项式A与B相乘

int main() {
	//A，B为输入的多项式，C为相乘所得结果 
	polynomial A, B, C;
	int n;
	A = CreatPolyn();
	printf("建立多项式A：\n");
	A = inputPolyn(A);
	B = CreatPolyn();
	printf("建立多项式B：\n");
	B = inputPolyn(B);
	//将A与B相乘的结果存入C中 
	C = MultiplyPolyn(A, B);
	return 0;
}