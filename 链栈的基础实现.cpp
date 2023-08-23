#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1
typedef int SElemType;
typedef int Status;


//���(�ýṹ���ʾ)
typedef struct SNode{
	SElemType data;//���������� 
	struct SNode* next;//����ָ���� 
}SNode,*LinkStack;//StackNode����������ͨ�Ľ�㣬��һ���ṹ�壻LinkStack��������һ��ָ��ý���ָ�룬��һ��ָ�� 

//��ջ�ĳ�ʼ��
Status InitStack(LinkStack &S){
	S = NULL;//S��Ϊͷָ�룬ָ��ջ��Ԫ�� 
	return OK;
}

//�ж������Ƿ�Ϊ��
Status StackEmpty(LinkStack S){
	if(S == NULL)
		return true;
	else
		return false;
} 

//��ջ����ջ
Status Push(LinkStack &S,SElemType e){
	LinkStack p;
	p = new SNode;//����һ����㣬��p����ʱ��ָ�� 
	p->data = e;//�½�����������Ԫ�� 
	p->next = S;//���½���ָ����ָ����һ����㣬��ָ���ϸ�ջ����� 
	S = p;//��ͷָ������ָ���µ�ջ��Ԫ�أ�ͬʱ������pָ�� 
} 

//��ջ�ĳ�ջ,������ջ��ֵ����e 
Status Pop(LinkStack &S,SElemType &e){
	if(S == NULL)
		return ERROR;
	e = S -> data;
	S = S -> next;
	return OK;
}

//ȡջ��Ԫ��
Status GetTop(LinkStack S){
	if(S != NULL)
		return S -> data;
}

int main(){
	SNode Stack;//����һ����ΪStack��ջ
	LinkStack S;//����һ��ͷָ�� 
	Stack ={NULL,S}; //ͷָ��ָ��Stackջ 
//	printf("%p\n",Stack.next);
//	printf("%p\n",S);
	//��ջ1��2��3��4��5
	for(int i = 1;i <= 5;i++){
		Push(S,i);
	} 
	//��ջ���β������ջ��ֵ
	for(int i = 0;i < 2;i++){
		int n = 0;
		Pop(S,n);
		printf("%d\n",n);
	} 
	//�鿴ջ��Ԫ��
	printf("%d\n",GetTop(S)); 
	 
	 
	return 0;
}

 

