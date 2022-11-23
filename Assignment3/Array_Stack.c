#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_STACK_SIZE 10

typedef struct ArrayStack { // 배열 스택
    int top;
    int capacity; // 스택의 최대 용량을 저장해줄 변수
    int* array;
} Stack;

Stack* CreateStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));

    //if(!stack)
   // return NULL;
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

bool isEmpty(Stack* stack) { // 스택이 비어져 있는지 확인
    bool isEmpty;

    if (stack->top == -1) { // top이 -1 즉 초기상태면

        isEmpty = true;
        return isEmpty;
    }
    else {
        isEmpty = false;
        return isEmpty;
    }
}

bool isFull(Stack* stack) { // 스택이 꽉 찼는지 확인
    bool isFull;

    if (stack->top == stack->capacity - 1) { // stack->top 과 stack->capacity - 1이 같다면 
        isFull = true;
        return isFull;
    }
    else {

        isFull = false;
        return isFull;
    }
}

void push(Stack* stack, int data) { // stack에 data를 삽입
    if (isFull(stack) == true) {
        printf("Stack is full, cannot add element \n");
    }
    else {

        stack->array[++stack->top] = data; // top을 1증가 시킨후 data를 저장
        // printf("%d pushed to stack\n", data);
        //printf("size : %d\n", stack->top + 1);
        printf("%d pushed to Stack--> address: %p\n", data, &stack->array[stack->top]);
       // printf("stack->array[%d]: %d  ", stack->top, stack->array[stack->top]);
        //printf("address: %p\n", &stack->array[stack->top]);
    }

}

int pop(Stack* stack) { // stack에서 data를 삭제
    if (isEmpty(stack) == true) {
        printf("Stack is Empty\n");
        return stack->top;
    }
    else {
        // printf("before Pop: stack->array[%d]: %d\n", stack->top, stack->array[stack->top]);
          // printf("address: %p\n", &stack->array[stack->top]);

        printf("%d popped from array Stack --> address: %p\n", stack->top, &stack->array[stack->top]);
      //  printf("After Pop: stack->array[%d]: %d ", stack->top, stack->array[stack->top]);
        //printf("address: %p\n", &stack->array[stack->top]);
        stack->top = stack->top - 1;

        return stack->top;
    }

}

void peek(Stack* stack) {
    if (isEmpty(stack) == true) {
        printf("Stack is Empty, Unable to execute peek \n");
        return stack->top;
    }
    else {
        printf("top is %d and size is %d \n", stack->array[stack->top], stack->top+1);
    }
}

int main() {
    
   
    printf("array stack\n\n");
    Stack* stack = CreateStack(MAX_STACK_SIZE); // MAX_STACK_SIZE의 배열 스택을 생성
    printf("peek: ");
    peek(stack);
    printf("-----push-----\n");
    for (int i = 0; i < MAX_STACK_SIZE+1; i++) { // for문을 통해 11번 실행해 isfull까지 실행
        push(stack, i);
        if (i == 5) {
           printf("peek: ");
            peek(stack);
        }
    }
    printf("--------------\n\n");
    printf("peek:");
    peek(stack);;
    printf("\n");
    printf("-----pop-----\n");
    for (int i = 0; i < MAX_STACK_SIZE+1; i++) { // 11번 실행해 isempty를 실행
        pop(stack);
    }

}