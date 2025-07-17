#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100
typedef struct Stack
{
    int top;
    int capacity;
    int *arr;
} Stack;

Stack *createStack(int capacity)
{
    Stack *s = (Stack *)malloc(sizeof(int));
    s->top = -1;
    s->capacity = capacity;
    s->arr = (int *)malloc(capacity * sizeof(int));
    return s;
}
bool isFull(Stack *s)
{
}
void freeStack(Stack *s)
{
    if (s)
    {
        free(s->arr);
        free(s);
    }
    else
    {
        printf("%s", "s is null");
    }
}
void pushStack(Stack *s, int a)
{
}

int main()
{
    Stack *s = createStack(MAX);
}

/*
네, 수정하신 코드를 다시 살펴보겠습니다. return s;를 추가하신 것은 좋지만, 여전히 메모리 할당 부분에 중요한 오류가 남아있습니다.

수정된 코드의 문제점 🧐
Stack 구조체 메모리 할당 오류:

Stack *s = (Stack *)malloc(sizeof(int));

이 코드는 Stack 구조체를 위해 int 하나 크기(4바이트)의 메모리만 할당합니다. Stack 구조체는 int 변수 2개와 포인터 1개로 이루어져 4바이트보다 훨씬 큽니다. 따라서 **sizeof(Stack)**으로 올바르게 할당해야 합니다.

배열 메모리 할당 오류:

s->arr = (int *)malloc(sizeof(capacity));

이 부분도 이전과 동일한 문제입니다. capacity개의 int를 저장할 공간이 아니라, int 변수 capacity 자체의 크기(4바이트)만 할당합니다. **capacity * sizeof(int)**로 수정해야 합니다.

pushStack 함수 미구현:

push 함수의 내용이 여전히 비어있습니다. 데이터를 실제로 배열에 넣는 로직이 필요합니다.

올바르게 수정된 최종 코드 ✅
아래는 위 오류들을 모두 수정하고, push 기능까지 완전하게 구현한 코드입니다.

C

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef struct Stack
{
    int top;
    int capacity;
    int *arr;
} Stack;

// --- 함수 선언 ---
Stack* createStack(int capacity);
void freeStack(Stack* s);
void push(Stack* s, int data);
int pop(Stack* s); // 다른 필수 함수들도 추가
int peek(Stack* s);
int isEmpty(Stack* s);
int isFull(Stack* s);


// --- main 함수 ---
int main()
{
    Stack *s = createStack(MAX);
    if (!s) {
        printf("스택 생성 실패\n");
        return 1;
    }

    printf("Push: 50\n");
    push(s, 50);
    printf("Push: 100\n");
    push(s, 100);

    printf("Top element is %d\n", peek(s)); // 100 출력
    printf("Popped element is %d\n", pop(s)); // 100 꺼냄
    printf("Now top element is %d\n", peek(s)); // 50 출력

    freeStack(s); // 메모리 해제
    return 0;
}


// --- 함수 정의 ---

Stack *createStack(int capacity)
{
    // 1. Stack 구조체 자체의 메모리를 올바르게 할당
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if (!s) return NULL;

    s->top = -1;
    s->capacity = capacity;

    // 2. 스택 배열의 메모리를 올바르게 할당
    s->arr = (int *)malloc(s->capacity * sizeof(int));
    if (!s->arr) {
        free(s); // 배열 할당 실패 시, 구조체도 해제
        return NULL;
    }
    return s;
}

void freeStack(Stack *s)
{
    if (s) {
        free(s->arr);
        free(s);
    }
}

// 스택이 가득 찼는지 확인
int isFull(Stack* s) {
    return s->top == s->capacity - 1;
}

// 스택이 비었는지 확인
int isEmpty(Stack* s) {
    return s->top == -1;
}

// 스택에 데이터 추가 (push)
void push(Stack *s, int data)
{
    if (isFull(s)) {
        printf("Stack is full!\n");
        return;
    }
    // top을 1 증가시키고 해당 위치에 데이터 저장
    s->arr[++s->top] = data;
}

// 스택에서 데이터 꺼내기 (pop)
int pop(Stack* s)
{
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1; // 오류
    }
    return s->arr[s->top--];
}

// 스택의 top 데이터 확인 (peek)
int peek(Stack* s)
{
    if (isEmpty(s)) {
        return -1; // 오류
    }
    return s->arr[s->top];
}
*/