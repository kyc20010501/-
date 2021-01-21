//
//  main.c
//  栈
//
//  Created by 亢一晨 on 2021/1/19.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX 5//栈最大元素数

typedef struct {
    int TOP;//栈顶指针
    int Data[MAX];//数据
} TypeStack;

TypeStack *InitStack();//初始化栈
int IfFull(TypeStack *Stack);//判满 满返回1
int IfEmpty(TypeStack *Stack);//判空 空返回1
void Push(TypeStack *Stack);//入栈
int Pop(TypeStack * Stack);//出栈
void Print(TypeStack *Stack);//打印栈

int main(int argc, const char * argv[]) {
    TypeStack* Stack = (TypeStack*)malloc(sizeof(TypeStack));
    Stack = InitStack();
    int x;
    while (1) {
        printf("1、判空\n2、判满\n3、入栈\n4、出栈\n\n0、退出\n\n\n选择功能：");
        scanf("%d",&x);
        switch (x) {
            case 0:
                printf(">>>>>>退出程序>>>>>>\n");
                return 0;
            case 1:
                if (IfEmpty(Stack))
                    printf("\n\n栈为空\n\n");
                else
                    printf("\n\n栈非空\n\n");
                break;
            case 2:
                if (IfFull(Stack))
                    printf("\n\n栈已满\n\n");
                else
                    printf("\n\n栈未满\n\n");
                break;
            case 3:
                Push(Stack);
                break;
            case 4:
                if (IfEmpty(Stack))
                    printf("\n！！！栈为空，无法出栈！！！\n");
                else
                    printf("\n\n出栈元素为：%d\n\n",Pop(Stack));
            case 5:
                Print(Stack);
                break;
            default:
                printf("\n\n！！！输入错误！！！\n\n");
                break;
        }
    }
}

TypeStack* InitStack() {
    TypeStack *Stack = (TypeStack*)malloc(sizeof(TypeStack));
    Stack->TOP = -1;
    return Stack;
}

int IfFull(TypeStack *Stack) {
    if (Stack->TOP == MAX-1)
        return 1;
    return 0;
}

int IfEmpty(TypeStack *Stack) {
    if (Stack->TOP == -1)
        return 1;
    return 0;
}

void Push(TypeStack *Stack) {
    if (IfFull(Stack)) {
        printf("\n！！！栈已满，无法入栈！！！\n");
        return;
    }
    printf("输入待入栈的值；");
    Stack->TOP++;
    scanf("%d",&Stack->Data[Stack->TOP]);
}

int Pop(TypeStack *Stack) {
    int x = Stack->Data[Stack->TOP];
    Stack->TOP--;
    return x;
}

void Print(TypeStack *Stack) {
    if (IfEmpty(Stack))
        printf("\n！！！栈为空,无法打印！！！\n");
    while (!IfEmpty(Stack))
        printf("\n%d",Pop(Stack));
}
