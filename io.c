//io.c : 此文件包含输入输出函数的具体实现。
#include"def.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//初始化字符串
void initchar(char *str,int k)
{
	for (int i = 0; i < k;i++)
		str[i] = '\0';
}
//长整数切割
void longCut(LongNum *N, char *number)
{
	int len = strlen(number);
	if (number[0] == '-')
	{
		N->sign = 0;
		len--;
		for (int i = 0; i < len;i++)
		{
			number[i] = number[i + 1];
		}
	}
	else
	{
		N->sign = 1;
	}
	char tmp[5];
	int tmpnum;
	if (len > 4)
	{
		int lenc = len / 4;
		int lens = len % 4;
		if (lens == 0)
		{
			for (int i = 0;i < lenc;i++)
			{
				initchar(tmp, 5);
				for (int j = 4 * i, c = 0; c < 4;j++,c++)
				{
					tmp[c] = number[j];
				}
				tmpnum = atoi(tmp);
				append_last(N, tmpnum);
			}
		}
		else
		{
			for (int i = lenc;i > 0;i--)
			{
				initchar(tmp, 5);
				for (int j = lens + (i - 1) * 4, c = 0; c < 4;j++,c++)
				{
					tmp[c] = number[j];
				}
				tmpnum = atoi(tmp);
				append_first(N,tmpnum);
			}
			initchar(tmp, 5);
			for (int j = 0; j < lens; j++)
			{
				tmp[j] = number[j];
			}
			tmpnum = atoi(tmp);
			append_first(N,tmpnum);
		}
	}
	else
	{
		initchar(tmp, 5);
		for (int j = 0; j < len; j++)
		{
			tmp[j] = number[j];
		}
		tmpnum = atoi(tmp);
		append_first(N,tmpnum);
	}
}

//输入
void input(LongNum *N)
{
	char numm[30000];
	scanf("%s",numm);
	longCut(N, numm);
}

//输出
void output(LongNum *N)
{
	if (!N->sign)
	{
		printf("-");
	}
	int sz = size(N);
	printf("%d",get(N,0));
	for (int i = 1; i < sz; i++)
		printf("%04d", get(N, i));
	printf("\n");
}