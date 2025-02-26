#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct
{
	char data[MAX_STACK_SIZE];
	int top;
} StackType;

//스택 초기화 함수
void init_stack(StackType* s)
{
	s->top = -1;
}

//공백 상태 검출 함수
int is_empty(StackType* s)
{
	return (s->top == -1);
}

//포화 상태 검출 함수
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

//삽입 함수
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

//삭제 함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

//peek함수
element peek(StackType* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}

//스택출력함수
void stackPrint(StackType* s)
{
	for (int i = s->top; i >= 0; i--) {
		printf("%c", s->data[i]);
	}
}

//연산자 우선순위 검사 함수
int priority(char op)
{
	switch (op) {
	case '(':
	case ')':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	}
	return -1;
}

//중위식을 후위식으로 변환하는 함수
void inf_to_posf(char inf[])
{
	int i = 0;
	char ch, top_op;
	int len = strlen(inf);
	StackType s;

	init_stack(&s);
	for (i = 0; i < len; i++) {
		ch = inf[i];
		switch (ch) {
		case '+':
		case '-':
		case '*':
		case '/':
			while (!is_empty(&s) && (priority(ch) <= priority(peek(&s))))
				printf("%c", pop(&s));
			push(&s, ch);
			break;
		case'(':
			push(&s, ch);
			break;
		case ')':
			top_op = pop(&s);
			while (top_op != '(') {
				printf("%c", top_op);
				top_op = pop(&s);
			}
			break;
		default :
			printf("%c", ch);
			break;
		}
	}
	while (!is_empty(&s))
		printf("%c", pop(&s));
}


int main(void)
{

	char inf[50];
	//printf("중위식을 입력하세요 : ");
	gets(inf, sizeof(inf), stdin);
	StackType s;
	init_stack(&s);
	char posf[50];
	inf_to_posf(inf);
	return 0;
}