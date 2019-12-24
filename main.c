//mian.c : 此文件包含入口函数(main)。
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "def.h"
#include "func.c"
#include "io.c"
#include "plus.c"
#include "reduce.c"

int main()
{
	LongNum a, b;
	LongNum *c;
	while(1)
	{
		longInit(&a);
		longInit(&b);
		printf("input number1: ");
		input(&a);
		printf("input number2: ");
		input(&b);
		printf("select the sign: \n1.\"+\"  2.\"-\"\n");
		int sign;
		scanf("%d", &sign);
		c = oper(&a, &b, sign);
		output(c);
	}
	
	return 0;
}
