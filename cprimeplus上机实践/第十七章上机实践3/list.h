#pragma once
#ifndef LIST_H_
#define LIST_H_
#include<stdbool.h>

/*�ض����������*/

#define TSIZE 45 /*�����Ӱ�������ݴ�С*/
struct film
{
	char title[TSIZE];
	int rating;
};
/*һ�����Ͷ���*/

typedef struct film Item;

typedef struct node
{
	Item item;
	struct node* next;
}Node;

typedef Node* List;
/*����ԭ��*/

/*����:        ��ʼ��һ������               */
/*ǰ������:    plistָ��һ������            */
/*��������:    �����ʼ��                   */
void InitializeList(List* plist);

/*����:        ȷ�������Ƿ�Ϊ�ն��壬plistָ��һ���ѳ�ʼ��������*/
/*����:        �������Ϊ�գ��ú�������ture�����򷵻�false      */
bool ListIsEmpty(const List* plist);

/*����:        ȷ�������Ƿ�������plistָ��һ���ѳ�ʼ��������    */
/*��������:    ��������������ú��������棻���򷵻ؼ�           */
bool ListIsFull(const List* plist);

/*����:        ȷ�������е�������plistָ��һ���ѳ�ʼ��������    */
/*��������:    �ú������������е�����                           */
unsigned int ListItemCount(const List* plist);

/*����:        �����ӵ�ĩβ�����                               */
/*ǰ������:    item��һ���������������plistָ��һ���ѳ�ʼ��������*/
/*��������:    ������ԣ��ú���������ĩβ���һ����ҷ���ture�����򷵻�false*/
bool AddItem(Item item, List* plist);

/*����:        �Ѻ��������������е�ÿһ��                        */
/*             plistָ��һ���ѳ�ʼ��������                       */
/*             pfunָ��һ�������У��ú�������һ��Item���͵Ĳ�������Ϊ����ֵ*/
/*��������:    pfunָ��ĺ��������������е�ÿһ��һ��            */
void Traverse(const List* plist, void(*pfun)(Item item));

/*����:        �ͷ��ѷ�����ڴ棨����еĻ���                    */
/*             plistָ��һ���ѳ�ʼ��������                       */
/*��������:    �ͷ���Ϊ�������������ڴ棬��������Ϊ��          */
void EmptyTheList(List* plist);

#endif