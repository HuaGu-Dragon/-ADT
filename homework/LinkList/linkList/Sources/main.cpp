#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"linklist.h"
/*int main() {
	Node* list = createList();
	

	return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

void menu() {
    printf("\n��������˵�:\n");
    printf("1. ��ʼ������\n");
    printf("2. ͷ�巨����Ԫ��\n");
    printf("3. β�巨����Ԫ��\n");
    printf("4. ��λ�ò���Ԫ��\n");
    printf("5. ����Ԫ��\n");
    printf("6. ɾ��ͷ�ڵ�\n");
    printf("7. ɾ��β�ڵ�\n");
    printf("8. ɾ��ָ��Ԫ��(һ��)\n");
    printf("9. ��������\n");
    printf("0. �˳�\n");
    printf("��ѡ�����: ");
}

int main() {
    Node* list = NULL;
    int choice, value, pos;

    while (1) {
        menu();
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            list = createList();
            printf("�����ѳ�ʼ��\n");
            break;
        case 2:
            printf("����Ҫ�����ֵ: ");
            scanf("%d", &value);
            push_front(list, value);
            break;
        case 3:
            printf("����Ҫ�����ֵ: ");
            scanf("%d", &value);
            push_back(list, value);
            break;
        case 4:
            printf("�������λ�ú�ֵ: ");
            scanf("%d %d", &pos, &value);
            insert_pos(list, pos, value);
            break;
        case 5:
            printf("����Ҫ���ҵ�ֵ: ");
            scanf("%d", &value);
            if (find(list, value))
                printf("Ԫ�� %d ������������\n", value);
            else
                printf("Ԫ�� %d ������\n", value);
            break;
        case 6:
            pop_front(list);
            printf("ͷ�ڵ���ɾ��\n");
            break;
        case 7:
            pop_back(list);
            printf("β�ڵ���ɾ��\n");
            break;
        case 8:
            printf("����Ҫɾ����ֵ: ");
            scanf("%d", &value);
            removeOne(list, value);
            break;
        case 9:
            printf("��ǰ����: ");
            show_list(list);
            break;
        case 0:
            printf("�����˳�\n");
            return 0;
        default:
            printf("��Ч���룬������ѡ��\n");
        }
    }
}
