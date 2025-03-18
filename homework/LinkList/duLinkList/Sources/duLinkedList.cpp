#include "duLinkedList.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//������������
typedef int data;

//��������Ľڵ�ṹ
/*typedef struct DuLNode {
    data data;            // �ڵ�������
    struct DuLNode* prior;    // ǰ��ָ��
    struct DuLNode* next;     // ���ָ��
} DuLNode, * DuLinkedList;*/

Status InitList_DuL(DuLinkedList* L)
{
    *L = (DuLinkedList)malloc(sizeof(DuLNode));//Ϊͷ�ڵ�����ڴ�
    if (*L==NULL) {//�ж�ͷ�ڵ�ָ��ֵ�Ƿ�Ϊ��
        return ERROR; // ���ڴ����ʧ�ܣ����� ERROR
    }
    //��ʼ��ͷ�ڵ��prior��nextָ��
    (*L)->prior= NULL;
    (*L)->next = NULL;
    //��ʼ��ͷ�ڵ�����Ϊ0
    (*L)->data = 0;
    return SUCCESS;
}

void DestroyList_DuL(DuLinkedList* L)//���������ͷ����нڵ���ڴ�(ɾ��)
{
    DuLNode* curNode = *L;
    DuLNode* temp;

    //�������������һ�ͷ�ÿ���ڵ�
    while (curNode != NULL) {
        temp = curNode;
        curNode = curNode->next;
        free(temp);
    }
    *L = NULL;  // ���ͷָ����ΪNULL
}

Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q)//�ڸ����ڵ�pǰ�����½ڵ�q
{
    if (p == NULL || q == NULL) return ERROR;
    
    {
        q->next = p;
        q->prior = p->prior;
    }

    if (p->prior != NULL) {
        p->prior->next = q; //��ǰ���ڵ��nextָ���޸���q����
    }
    p->prior = q;  // �޸�p�ڵ��priorָ��

    return SUCCESS;
}

Status InsertAfterList_DuL(DuLNode* p, DuLNode* q)//�ڸ����ڵ�p������½ڵ�q
{
    if (p == NULL || q == NULL) return ERROR;
    {
        q->prior = p;
        q->next = p->next;
    }
    if (p->next != NULL) {
        p->next->prior = q;  //�޸ĺ�̽ڵ��priorָ��
    }
    p->next = q;  //�޸�p�ڵ��nextָ��

    return SUCCESS;
}

Status DeleteList_DuL(DuLNode* p, data* e)//ɾ���ڵ�p
{
    if (!p) 
        return ERROR;
    if (p->prior != NULL) {
        p->prior->next = p->next;  //�޸�ǰ���ڵ��nextָ��
    }
    if (p->next != NULL) {
        p->next->prior = p->prior;  //�޸ĺ�̽ڵ��priorָ��
    }
    free(p);  // ɾ��
    return SUCCESS;
}

void TraverseList_DuL(DuLinkedList L, void(*visit)(data e))//�����������
{
    if (L == NULL || L->next == NULL) {
        printf("����Ϊ��\n");
        return;  //�������Ϊ�գ���ֱ�ӽ�������
    }
    DuLNode* curNode = L->next;  //��ͷ�ڵ�ĺ�̽ڵ㿪ʼ����
    while (curNode != NULL) {
        visit(curNode->data);  //ִ��visit�����ݴ�ӡ���
        curNode = curNode->next;
    } // �ƶ�����һ���ڵ�
}

