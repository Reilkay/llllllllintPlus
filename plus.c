//plus.c : 此文件包含加法相关的函数的具体实现。
#include"def.h"
#include<stdio.h>
#include<stdlib.h>

//长整数加法
LongNum *longPlus(LongNum *a, LongNum *b)
{
	LongNum *c;
	c = (LongNum *)malloc(sizeof(LongNum));
	longInit(c);
	int sza = size(a), szb = size(b);
	int tmp = 0, tmpp = 0;
	for (int i = sza - 1, j = szb - 1;(i >= 0 || j >= 0);i--, j--)
	{
		if (i >= 0 && j >= 0)
		{
			tmp = get(a, i) + get(b, j) + tmpp;
			tmpp = 0;
			if (tmp >= 10000)
			{
				tmpp = 1;
				tmp -= 10000;
			}
		}
		else if (i < 0)
		{
			tmp = get(b, j) + tmpp;
			tmpp = 0;
			if (tmp >= 10000)
			{
				tmpp = 1;
				tmp -= 10000;
			}
		}
		else if (j < 0)
		{
			tmp = get(a, i) + tmpp;
			tmpp = 0;
			if (tmp >= 10000)
			{
				tmpp = 1;
				tmp -= 10000;
			}
		}
		append_first(c, tmp);
	}
	if (tmpp)
	{
		append_first(c, tmpp);
		tmpp = 0;
	}
	return c;
}