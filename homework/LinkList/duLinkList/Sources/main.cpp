#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "duLinkedList.h"  // �������������ͷ�ļ�



// ���ʺ��������ڴ�ӡ�����е�����
void printElem(int e) {
    printf("%d ", e);  // ��ӡÿ���ڵ������
}

int main() {
    DuLinkedList L = NULL;  // ��������ͷָ��
    int choice, value;
    int deletedData;
    DuLNode* newNode;

    // ��ʾ�˵���ֱ���û�ѡ���˳�
    while (1) {
        printf("\n===========================\n");
        printf("˫����������˵���\n");
        printf("1. ��ʼ������\n");
        printf("2. ����ڵ㣨β����\n");
        printf("3. ɾ���ڵ�\n");
        printf("4. ����������ʾ\n");
        printf("5. ��������\n");
        printf("6. �˳�����\n");
        printf("���������ѡ�� (1-6): ");
        scanf("%d", &choice);

        DuLNode* tempNode = NULL;  // ȷ���ڴ˴���ʼ�� tempNode

        switch (choice) {
        case 1:
            // ��ʼ������
            if (InitList_DuL(&L) == SUCCESS) {
                printf("�����ʼ���ɹ�\n");
            }
            else {
                printf("�����ʼ��ʧ��\n");
            }
            break;

        case 2:
            // ����ڵ㵽����β��
            if (L == NULL) {
                printf("����δ��ʼ�������ȳ�ʼ������\n");
                break;
            }
            newNode = (DuLNode*)malloc(sizeof(DuLNode));
            if (newNode == NULL) {
                printf("�ڴ����ʧ��\n");
                break;
            }
            printf("������Ҫ��������ݣ�");
            scanf("%d", &value);
            newNode->data = value;
            newNode->next = NULL;

            if (L->next == NULL) {
                L->next = newNode;  // �������Ϊ�գ�ֱ�Ӳ���
                newNode->prior = L;
            }
            else {
                // ������뵽����β��
                DuLNode* tail = L;
                while (tail->next != NULL) {
                    tail = tail->next;
                }
                InsertAfterList_DuL(tail, newNode);
            }
            printf("���� %d ����ɹ�\n", value);
            break;

        case 3:
            // ɾ�������еĽڵ�
            if (L == NULL || L->next == NULL) {
                printf("����Ϊ�գ��޷�ɾ���ڵ�\n");
                break;
            }
            printf("������Ҫɾ���ڵ�����ݣ�");
            scanf("%d", &value);

            // ��ɾ������֮ǰ��ʼ�� tempNode
            tempNode = L->next;
            while (tempNode != NULL && tempNode->data != value) {
                tempNode = tempNode->next;
            }

            if (tempNode == NULL) {
                printf("δ�ҵ����� %d �Ľڵ㣡\n", value);
            }
            else {
                if (DeleteList_DuL(tempNode, &deletedData) == SUCCESS) {
                    printf("���� %d ��ɾ���ɹ���\n", deletedData);
                }
                else {
                    printf("ɾ��ʧ��\n");
                }
            }
            break;

        case 4:
            // ����������ʾ
            if (L == NULL || L->next == NULL) {
                printf("����Ϊ��\n");
            }
            else {
                printf("�������ݣ�");
                TraverseList_DuL(L, printElem);
                printf("\n");
            }
            break;

        case 5:
            // ��������
            if (L == NULL) {
                printf("����δ��ʼ�����޷��������ٲ���\n");
            }
            else {
                DestroyList_DuL(&L);
                printf("�������ٳɹ�\n");
            }
            break;

        case 6:
            // �˳�����
            DestroyList_DuL(&L);
            printf("�����˳�������������\n");
            return 0;

        default:
            // ������Чʱ����ʾ
            printf("��Чѡ������������\n");
        }
    }

    return 0;
}
