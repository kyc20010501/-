//
//  main.c
//  单链表
//
//  Created by 亢一晨 on 2021/1/17.
//

#include <stdio.h>
#include <stdlib.h> //malloc函数头文件
#include <string.h> //字符串函数头文件

typedef struct ListNode {
    int Data;
    struct ListNode* Next;
} LinkList;

LinkList* Creat();          //初始化链表
void Add(LinkList* Head);   //添加节点
void HeadAdd(LinkList* Head);
void BodyAdd(LinkList* Head);
void TailAdd(LinkList* Head);
void Delet(LinkList* Head); //删除节点
void Edit(LinkList* Head);  //修改节点
void Serch(LinkList* Head); //查找节点
void Print(LinkList* Head); //打印链表


int main() {
    LinkList* Head = (LinkList*)malloc(sizeof(LinkList));
    Head = Creat();
    int x;
    while (1) {
        printf("\n\n1、添加节点\n2、打印数据\n3、删除节点\n4、修改节点\n5、查找数据\n\n0、退出系统\n\n选择功能：");
        scanf("%d",&x);
        if (x==0) {
            printf("\n\n退出程序\n\n");
            printf("\n _   __    _____\n| | / /   / ___ \\ \n| |/ /   | /   \\_\\ \n| |\\ \\   | |    _  Thanks For Using~~~\n| | \\ \\  | \\___/ /\n|_|  \\_\\  \\_____/\n\n\n");
            break;
        }
        switch (x) {
            case 1:
                Add(Head);
                break;
            case 2:
                Print(Head);
                break;
            case 3:
                Delet(Head);
                break;
            case 4:
                Edit(Head);
                break;
            case 5:
                Serch(Head);
                break;
            default:
                printf("\n\n!!!输入错误!!!\n\n");
                break;
        }
    }
}

LinkList* Creat() {
    LinkList *Head;
    Head = (LinkList*)malloc(sizeof(LinkList));
    Head->Next = NULL;
    return Head;
}

void Add(LinkList* Head) {
    printf("\n插入位置：\n1、头部\n2、中间\n3、尾部\n");
    int i;
    printf("\n选择位置：");
    scanf("%d",&i);
    switch (i) {
        case 1:
            HeadAdd(Head);
            break;
        case 2:
            BodyAdd(Head);
            break;
        case 3:
            TailAdd(Head);
            break;
        default:
            printf("\n\n！！！该位置不存在！！！\n\n");
            break;
    }
}

void HeadAdd(LinkList* Head) {
    LinkList* Node = (LinkList*)malloc(sizeof(LinkList));
    printf("输入节点数据：");
    scanf("%d",&Node->Data);
    if (Head->Next!=NULL)
        Node->Next = Head->Next;
    else
        Node->Next = NULL;
    Head->Next = Node;
}

void BodyAdd(LinkList* Head) {
    if (Head->Next==NULL) {
        printf("该链表为空,转换为头插\n");
        HeadAdd(Head);
        return;
    }
    LinkList* NodeReader = (LinkList*)malloc(sizeof(LinkList));
    int i = 0,j;
    printf("在哪个节点后插入新节点？");
    scanf("%d",&j);
    NodeReader = Head;
    while (NodeReader!=NULL) {
        if (i==j) {
            LinkList* Node = (LinkList*)malloc(sizeof(LinkList));
            printf("输入节点数据：");
            scanf("%d",&Node->Data);
            Node->Next = NodeReader->Next;
            NodeReader->Next = Node;
            return;
        }
        i++;
        NodeReader = NodeReader->Next;
    }
}

void TailAdd(LinkList* Head) {
    
}

void Delet(LinkList* Head) {
    if (Head->Next==NULL) {
        printf("该链表为空\n");
        return;
    }
    int i,j=1;
    printf("输入待删除节点序号：");
    scanf("%d",&i);
    LinkList* NodeReader = (LinkList*)malloc(sizeof(LinkList));
    NodeReader = Head;
    while (NodeReader->Next!=NULL) {
        if (i==j) {
            NodeReader->Next = NodeReader->Next->Next;
            return;
        }
        j++;
        NodeReader = NodeReader->Next;
    }
    printf("无该节点");
}

void Edit(LinkList* Head) {
    if (Head->Next==NULL) {
        printf("该链表为空\n");
        return;
    }
    int i,j=0,x;
    printf("输入待修改节点序号：");
    scanf("%d",&i);
    printf("输入修改数据：");
    scanf("%d",&x);
    LinkList* NodeReader = (LinkList*)malloc(sizeof(LinkList));
    NodeReader = Head;
    while (NodeReader!=NULL) {
        if (j==i) {
            NodeReader->Data = x;
            return;
        }
        NodeReader = NodeReader->Next;
        j++;
    }
    printf("\n无该节点\n");
}

void Serch(LinkList* Head) {
    if (Head->Next==NULL) {
        printf("该链表为空\n");
        return;
    }
    LinkList* NodeReader = (LinkList*)malloc(sizeof(LinkList));
    NodeReader = Head;
    int i=0,x;
    printf("输入待查找数据：");
    scanf("%d",&x);
    while (NodeReader!=NULL) {
        if (NodeReader->Data==x) {
            printf("第%d个节点的数据为%d",i,x);
            return;
        }
        NodeReader = NodeReader->Next;
        i++;
    }
}

void Print(LinkList* Head) {
    LinkList* NodeReader = (LinkList*)malloc(sizeof(LinkList));
    if (Head->Next==NULL) {
        printf("该链表为空\n");
        return;
    }
    NodeReader = Head;
    printf("HEAD ");
    while (NodeReader->Next!=NULL) {
        NodeReader = NodeReader->Next;
        printf("---> %d ",NodeReader->Data);
    }
}
