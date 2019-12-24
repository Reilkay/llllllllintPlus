//func.c : 此文件包含操作链表的基础函数的具体实现。
#include"def.h"
#include<stdio.h>
#include<stdlib.h>

//初始化长整数
void longInit(LongNum *N)
{
	N->count = 0;
	N->sign = 1;
	N->dighead = (longNumDig *)malloc(sizeof(longNumDig));
	N->dighead->next = N->dighead;
	N->dighead->prev = N->dighead;
}

//返回长整数节点数目
int size(LongNum *N)
{
	return N->count;
}

//从链表尾部插入t
void append_last(LongNum *N, int t)
{
	longNumDig *pnode = (longNumDig *)malloc(sizeof(longNumDig));
	pnode->num = t;
	pnode->prev = N->dighead->prev;
	pnode->next = N->dighead;
	N->dighead->prev->next = pnode;
	N->dighead->prev = pnode;
	N->count++;
}

//从链表头部插入t
void append_first(LongNum *N, int t)
{
	longNumDig *pnode = (longNumDig *)malloc(sizeof(longNumDig));
	pnode->num = t;
	pnode->prev = N->dighead;
	pnode->next = N->dighead->next;
	N->dighead->next->prev = pnode;
	N->dighead->next = pnode;
	N->count++;
}

//获取节点
longNumDig *getNode(LongNum *N, int index)
{
	int count = N->count;
	// 判断参数有效性
	if (index < 0 || index >= count)
	{
		printf("get node failed! the index in out of bound!\n");
		return NULL;
	}
	// 正向查找
	if (index <= count / 2)
	{
		int i = 0;
		longNumDig *pindex = N->dighead->next;
		while (i++ < index)
		{
			pindex = pindex->next;
		}
		return pindex;
	}
	// 反向查找
	int j = 0;
	int rindex = count - index - 1;
	longNumDig *prindex = N->dighead->prev;
	while (j++ < rindex)
	{
		prindex = prindex->prev;
	}

	return prindex;
}

//获取index位置的节点的值
int get(LongNum *N, int index)
{
	return getNode(N, index)->num;
}

//删除所有节点
void delAll(LongNum *N)
{
	longNumDig *ptmp;
	longNumDig *pnode = N->dighead->next;
	while (pnode != N->dighead)
	{
		ptmp = pnode;
		pnode = pnode->next;
		free(ptmp);
	}
	N->dighead->prev = N->dighead;
	N->dighead->next = N->dighead;
	N->count = 0;
}

//删除index位置节点
void delThis(LongNum *N, int th)
{
	longNumDig *pindex = getNode(N, th);
	pindex->next->prev = pindex->prev;
	pindex->prev->next = pindex->next;
	free(pindex);
	N->count--;
}

//长整数大小判断
int longJudge(LongNum *a, LongNum *b)
{
	int sza = size(a), szb = size(b);
	int flag = 1;
	if (sza < szb)
	{
		flag = 0;
	}
	else if (sza == szb)
	{
		for (int i = 0;i < sza;i++)
		{
			int tmpa = get(a,i), tmpb = get(b,i);
			if (tmpa > tmpb)
			{
				break;
			}
			else if (tmpa < tmpb)
			{
				flag = 0;
				break;
			}
		}
	}
	return flag;
}

//长整数交换
void longSwap(LongNum *a, LongNum *b)
{
	int sza = size(a), szb = size(b);
	LongNum tmp;
	longInit(&tmp);
	for (int i = szb-1;i >= 0;i--)
	{
		append_first(&tmp, get(b, i));
	}
	delAll(b);
	for (int i = sza-1;i >= 0;i--)
	{
		append_first(b, get(a, i));
	}
	delAll(a);
	for (int i = szb-1;i >= 0;i--)
	{
		append_first(a, get(&tmp, i));
	}
}

//根据长整数符号及加减号分别进行操作
LongNum *oper(LongNum *a, LongNum *b, int sign)
{
	LongNum *c;
	c = (LongNum *)malloc(sizeof(LongNum));
	longInit(c);
	int signa = a->sign, signb = b->sign;
	if (sign==1)
	{
		if (signa&&signb)
			c=longPlus(a, b);
		else if ((!signa) && signb)
			c=longReduce(b, a);
		else if (signa && !(signb))
			c=longReduce(a, b);
		else
		{
			c=longPlus(a, b);
			c->sign = 0;
		}
	}
	else
	{
		if (signa&&signb)
			c=longReduce(a, b);
		else if ((!signa) && signb)
		{
			c=longPlus(a, b);
			c->sign=0;
		}
		else if (signa && !(signb))
			c=longPlus(a, b);
		else
			c=longReduce(b, a);
	}
	return c;
}