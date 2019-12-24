//head.h : 此文件包含链表及相关声明。
#ifndef LONGNUM
#define LONGNUM

//长整数数字部分
typedef struct longNumDig
{
	int num;
	struct longNumDig *prev;
	struct longNumDig *next;
} longNumDig;

//长整数
typedef struct LongNum
{
	longNumDig *dighead;
	int sign;
	int count;
}LongNum;

//初始化长整数
void longInit(LongNum *N);
//返回长整数节点数目
int size(LongNum *N);
//从链表尾部插入t
void append_last(LongNum *N, int t);
//从链表头部插入t
void append_first(LongNum *N, int t);
//获取节点
longNumDig *getNode(LongNum *N, int index);
//获取index位置的节点的值
int get(LongNum *N, int index);
//删除所有节点
void delAll(LongNum *N);
//删除index位置节点
void delThis(LongNum *N, int th);
//长整数大小判断
int longJudge(LongNum *a, LongNum *b);
//长整数交换
void longSwap(LongNum *a, LongNum *b);
//长整数切割
void longCut(LongNum *N, char *number);
//输入
void input(LongNum *N);
//输出
void output(LongNum *N);

//长整数加法
LongNum *longPlus(LongNum *a, LongNum *b);
//长整数减法
LongNum *longReduce(LongNum *a, LongNum *b);
//根据长整数符号及加减号分别进行操作
LongNum *oper(LongNum *a, LongNum *b, int sign);



#endif
