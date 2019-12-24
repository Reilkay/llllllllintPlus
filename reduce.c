//reduce.c : 此文件包含减法相关的函数的具体实现。
#include"def.h"
#include<stdio.h>
#include<stdlib.h>

//长整数减法
LongNum *longReduce(LongNum *a, LongNum *b)
{
	LongNum *c;
	c = (LongNum *)malloc(sizeof(LongNum));
	longInit(c);
	//若a小于b，则c=a-b为负，将c的符号置负
	if (longJudge(a, b))
	{
		c->sign = 1;
	}
	else
	{
		c->sign = 0;
		longSwap(a, b);
	}
	int tmp = 0, tmpp = 0;
	int sza = size(a), szb = size(b);
	for (int i = sza - 1, j = szb - 1;(i >= 0 || j >= 0);i--, j--)
	{
		if (i >= 0 && j >= 0)
		{
			tmp = get(a, i) - get(b, j) + tmpp;
			tmpp = 0;
			if (tmp < 0)
			{
				tmpp = -1;
				tmp += 10000;
			}
		}
		else if (j < 0)
		{
			tmp = get(a, i) + tmpp;
			tmpp = 0;
			if (tmp < 0)
			{
				tmpp = -1;
				tmp += 10000;
			}
		}
		append_first(c, tmp);
	}
	//判断长整数头部是否有无效零，并将其删除
	if(get(c, 0) == 0)
	{
		int szc = size(c);
		for (int i = 1;i < szc;i++)
		{
			if (get(c, 1) == 0)
			{
				delThis(c, 1);
			}
			else
			{
				delThis(c, 0);
				break;
			}
		}
	}
	return c;
}