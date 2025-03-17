
/***************************************************************************************
 *	File Name				:	duLinkedList.h
 *	CopyRight				:	2020 QG Studio
 *	SYSTEM					:   win10 
 *	Create Data				:	2020.3.28
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

 /**************************************************************
*	Multi-Include-Prevent Section���ذ�����������
**************************************************************/

#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED//�����ظ���������

/**************************************************************
*	Macro Define Section�궨�岿��
**************************************************************/

#define OVERFLOW -1//��ʾ��������״̬

/**************************************************************
*	Struct Define Section�ṹ�嶨�岿��
**************************************************************/

// define element type�������ͱ���,�����ڵ�����ݲ��ֽ�������
typedef int data;

// define struct of linked list��������ṹ��
typedef struct DuLNode {
	data data;
  	struct DuLNode *prior,  *next;//ָ��ǰһ�ڵ��ָ��ͺ�һ�ڵ��ָ��
} DuLNode, *DuLinkedList;

// define statusö������,��ʾ�����Ľ��״̬
typedef enum Status {
	ERROR,
	SUCCESS,
} Status;


/**************************************************************
*	Prototype Declare Section����ԭ����������
**************************************************************/

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList* L);//��ʼ��һ���յ�˫������,������һ��ͷ�ڵ�

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L);//ɾ�������ͷ��ڴ�

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q);//�ڸ����ڵ�pǰ�����½ڵ�q

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q);

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p,data *e);

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(data e));



 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
