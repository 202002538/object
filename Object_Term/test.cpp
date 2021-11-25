#include <stdio.h>
#include "Stack.h"
#include <stdlib.h>
#include <ctype.h>


int GetOpPrec(char op)
{

	switch(op)
	{
		case '*':
		case '/':
			return 2;
		case '+':
		case '-':
			return 1;
		case '(':
			return 0;
		case ')':
			return -1;
		default:
			return -2;
	}
}

int WhoPreOp(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec >= op2Prec)
	{
		return 1;
	}
	else if (op1Prec < op2Prec)
	{
		return 0;
	}
}


void Convert(char* test)
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	StackInit(stack);

	int expLen = strlen(test);
	char* changed = (char*)malloc(expLen + 1);
	char word;
	int code;
	int j = 0;
	Data tmp;
	memset(changed, 0, sizeof(char) * expLen + 1);



	for (int i = 0; i < expLen; i++)
	{
		word = test[i];
		code = GetOpPrec(word);
		
		switch (code)
		{
		case -2: //숫자
			changed[j] = word;
			j++;
			break;
		case 2: //곱하기나누기
		case 1:
			while (stack->num > 0)
			{
				Peek(stack, &tmp);
				//Stack이 비어있지 않다면
			
				if (WhoPreOp(tmp, word))
				{	//스택에 있는 연산자 우선순위가 높다면
					Pop(stack, &tmp);

					changed[j] = tmp;
					j++;
				}
				else {
					break;
				}
			}
			Push(stack, word);
			//pop
			break;
		case 0: //(
			Push(stack, word);
			break;
		case -1:
			while (1)
			{
				Pop(stack, &tmp);
				if (tmp == '(')
				{
					break;
				}
				changed[j] = tmp;
				j++;
			}

		default:
			break;
		}

	}
	//남아있으면 pop
	while (Pop(stack, &tmp))
	{
		changed[j] = tmp;
		j++;
	}

	strcpy(test, changed);
	free(changed);
	free(stack);
	/*
	for (int v = 0; v < j; v++)
	{
		printf("%c", changed[v]);
	}
	*/
}


int Calc(int first, int second, char word)
{
	switch (word)
	{
	case '+':
		return first + second;
	case '-':
		return first - second;
	case '*':
		return first * second;
	case '/':
		return first / second;

	}
}

int Result(char* test)
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	StackInit(stack); //이부분이 멀위한건지...?
	int j = 0;
	int expLen = strlen(test);
	char word;
	char first;
	char second;
	int result;
	char tmp;
	while (j<expLen)
	{
		word = test[j];
		j++;
		if (isdigit(word))
		{

			Push(stack,word);
		}
		else{
			Pop(stack, &tmp);
			second = tmp;
			Pop(stack, &tmp);
			first = tmp;
			result = Calc(first-'0', second-'0', word);
;
			Push(stack, result+'0');
		}
	}
	Pop(stack, &tmp);
	free(stack);
	return tmp-'0';

}

void main()
{
	char Firstorder[2] = {'*','/'};
	char Secondorder[2] = { '+','-' };

	char test1[] = "1+2*3";
	char test2[] = "(1+2)*3";
	char test3[] = "((1-2)+3)*(5-2)";


	Convert(test1);
	printf("%s\n", test1);
	Convert(test2);
	printf("%s\n", test2);
	Convert(test3);
	printf("%s\n", test3);


	int result1 = Result(test1);
	int result2 = Result(test2);
	int result3 = Result(test3);

	printf("%d\n",result1);
	printf("%d\n",result2);
	printf("%d\n",result3);

}