#include "linklist.h"
//�����ڵ�
Node* createNode(Data val) {//�����ڵ�ֵ
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (!newNode) {
		printf("newNode malloc failed");//�ж�
		return NULL;
	}
	newNode->data = val;
	newNode->next = NULL;

	return newNode;
}
//��������

//����
Node* createList()
{
	Node* head = (Node*)malloc(sizeof(Node));//headͷ�ڵ� 
	if (!head)//�ж������Ƿ�ʧ��
	{
		printf("head malloc failed");
		return NULL;

	}
	//��ʼ��ΪNULL
	//head->data = 0;//��ʼ��
	//head->next = NULL;
	memset(head, 0, sizeof(Node));  //��ʼ��
	return head;
}
void push_front(Node* list, Data val)
{//���õڶ����ڵ�(��Ԫ�ڵ�)�����½ڵ�,�����½ڵ����ͷ�ڵ�
	Node* newNode = createNode(val);
	newNode->next = list->next;
	list->next = newNode;
}
void push_back(Node* list, Data val)
{//�����ҵ����һ���ڵ�,��β�ڵ����½ڵ�����,������½ڵ��nextָ��null
	Node* curNode = list;
	while (curNode->next){
		curNode = curNode->next;
	}
	Node* newNode = createNode(val);
	newNode->next = NULL;


}
void insert_pos(Node* list, int pos, Data val)
{//����,���ҵ�posλ��ǰһ��Ԫ��,ԭ���Ǳ�����֪��ǰһԪ�ص�next
	Node* curNode = list;
	for (int i = 0; i < pos&&curNode->next; i++) {//�ų��������,��pos>>i;ͬʱ�ų�curNodeΪ�յ��������

		curNode = curNode->next;
	}
	//�����½ڵ����Ϻ�һ���ڵ�
	Node* newNode = createNode(val);
	newNode->next = curNode->next;
	//��ǰһ���ڵ������½ڵ�
	curNode->next = newNode;
	
}
void insert_item(Node* list, Node* item, Data val)
{
	Node* newNode = createNode(val);
	//�½ڵ����Ϻ���Ľڵ�
	newNode->next = item->next;
	//item(��ָ֪���Ľڵ�)�����½ڵ�
	item->next = newNode;
}

void show_list(Node* list)
{
	Node* curNode = list->next;
	while (curNode){
		printf("%d ", curNode->data);
		curNode = curNode->next;
	}
	putchar('\n');
}

Node* find(Node* list, Data val)
{
	Node* curNode = list->next;
	while (curNode) {
		if (curNode->data == val) {
			return curNode;
		}
		curNode = curNode->next;
	}
	return NULL;
}

void pop_front(Node* list)
{
	Node* delNode = list->next;//��Ҫ��ɾ���Ľڵ���ͷ�ڵ�
	list->next = delNode->next;
	free(delNode);//�ͷ�,ɾ���ڵ�
}

void pop_back(Node* list)
{
	//������Ϊ��ֱ���˳�
	if (list->next == NULL)
		return;
	Node* curNode = list;
	while (/*curNode->next && */curNode->next->next)//ע���ų�����Ϊ�յ����
	{
		//�ж�curNode�Ƿ�Ϊ�����ڶ����ڵ�,��Ҫɾ���ڵ��ǰһ���ڵ�
		curNode = curNode->next;//�ƶ�Ŀǰ�ڵ�
	}
	free(curNode->next);//�ͷ����һ���ڵ�,ɾ��
	curNode->next = NULL;
	
}

void removeOne(Node* list, Data val)
{
	//������Ϊ��ֱ���˳�
	if (list->next == NULL)
		return;
	Node* prevNode = list;//ǰһλ�ڵ�
	Node* curNode = list->next;
	while(curNode)
	{
		if (curNode->data == val)
		{
			break;
		}
		curNode = curNode->next;
	}
	if (curNode) {


		prevNode->next = curNode->next;
		free(curNode);
	}//ɾ��
}

void removeAll(Node* list, Data val)
{//������Ϊ��ֱ���˳�
	if (list->next == NULL)
		return;
	Node* prevNode = list;
	Node* curNode = list->next;
	Node* delNode = NULL;
	while (curNode) {
		if (curNode->data == val) {
			prevNode->next = curNode->next;//��Ҫɾ���Ľڵ��ǰһ���ڵ�ָ��Ҫɾ���ڵ�ĺ�һ���ڵ�
			delNode = curNode;
		}
		else {//����Ҫɾ����Ԫ��,���ƶ�pre
			prevNode = curNode;
		}
		prevNode = curNode;
		curNode = curNode->next;
		//��������ͷ�
		if (delNode) {
			free(delNode);
			delNode = NULL;
		}
	}
}
