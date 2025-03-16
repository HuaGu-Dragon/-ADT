#pragma once
#include<stdio.h>
#include<malloc.h>
#include<string.h>
//ADT������������
typedef int Data;
//����ڵ�ṹ
typedef struct Node {
	Data data;//������ �洢����
	//struct Node* next;//ָ���� �洢��һ���ڵ�ĵ�ַ
	Node* next;
}Node;
// ��������ĺ�������
Node* createList();
//��ͷ����(����ͷ�ڵ��)
void push_front(Node* list, Data val);//value
//��β����
void push_back(Node* list, Data val);
//ָ��λ�õĺ������(�±�)
void insert_pos(Node* list, int pos, Data val);
//ָ��λ�ò���(ָ��Ԫ��֮�����)
void insert_item(Node* list, Node* item, Data val);
//���� �����
void show_list(Node* list);
//����Ԫ��
Node* find(Node* list, Data val);
//ͷ�ڵ�ɾ
void pop_front(Node* list);
//β�ڵ�ɾ
void pop_back(Node* list);
//ɾ��ָ��Ԫ��
void removeOne(Node* list, Data val);//ɾ��һ�� 
void removeAll(Node* list, Data val);//ɾ��ȫ��ָ����ͬ����
