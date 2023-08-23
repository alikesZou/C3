#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1
typedef int SElemType;
typedef int Status;


//结点(用结构体表示)
typedef struct SNode{
	SElemType data;//定义数据域 
	struct SNode* next;//定义指针域 
}SNode,*LinkStack;//StackNode用来定义普通的结点，是一个结构体；LinkStack用来定义一个指向该结点的指针，是一个指针 

//链栈的初始化
Status InitStack(LinkStack &S){
	S = NULL;//S作为头指针，指向栈顶元素 
	return OK;
}

//判断链表是否为空
Status StackEmpty(LinkStack S){
	if(S == NULL)
		return true;
	else
		return false;
} 

//链栈的入栈
Status Push(LinkStack &S,SElemType e){
	LinkStack p;
	p = new SNode;//创造一个结点，但p是零时的指针 
	p->data = e;//新结点的数据域存放元素 
	p->next = S;//将新结点的指针域指向上一个结点，及指向上个栈顶结点 
	S = p;//将头指针重新指向新的栈顶元素，同时销毁了p指针 
} 

//链栈的出栈,并将出栈的值赋给e 
Status Pop(LinkStack &S,SElemType &e){
	if(S == NULL)
		return ERROR;
	e = S -> data;
	S = S -> next;
	return OK;
}

//取栈顶元素
Status GetTop(LinkStack S){
	if(S != NULL)
		return S -> data;
}

int main(){
	SNode Stack;//定义一个名为Stack的栈
	LinkStack S;//定义一个头指针 
	Stack ={NULL,S}; //头指针指向Stack栈 
//	printf("%p\n",Stack.next);
//	printf("%p\n",S);
	//入栈1，2，3，4，5
	for(int i = 1;i <= 5;i++){
		Push(S,i);
	} 
	//出栈两次并输出出栈的值
	for(int i = 0;i < 2;i++){
		int n = 0;
		Pop(S,n);
		printf("%d\n",n);
	} 
	//查看栈顶元素
	printf("%d\n",GetTop(S)); 
	 
	 
	return 0;
}

 

