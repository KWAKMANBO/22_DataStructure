#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_STACK_SIZE 10


int size = 0;
typedef struct ListStack {
    int* data; // 입력할 데이터가 담길 변수
    struct ListStack* next; //다음 번을 가리키는 스
} Stack;

bool isEmpty(Stack* Top) {
    bool isEmpty;

    if (Top == NULL) {
        isEmpty = true;
        return isEmpty;
    }
    else {
        isEmpty = false;
        return isEmpty;
    }
   // return (Top == NULL);  // top==NULL을 반환
}



void isFull(int size) {

    if (size == MAX_STACK_SIZE) {
        printf("Stack is Full, cannot add element\n");

    }
}


void push(Stack** Top, int data) {
    Stack* newNode = NULL;

    newNode = malloc(sizeof(Stack));

    int* address = &data;


    if (size == MAX_STACK_SIZE) {
        isFull(size);
    }
    else {

        newNode->data = data;
        address = &newNode->data;
        newNode->next = *Top;

        *Top = newNode;

        printf("%d pushed to stack -->  ", newNode->data);
        printf("address: %p\n", &newNode->data);
        size++;
        //printf("size: %d\n", size);
    }
}


void pop(Stack** top) {
    Stack* temp = NULL;
    int data = 0;
    int* address;
    if (isEmpty(*top)) {

        printf("Stack is empty\n");
        return;

    }
    else {
        size--;
       // printf("size: %d\n", size);
        temp = *top;
        *top = temp->next;
        data = temp->data;
        address = &temp->data;
        
        printf("%d poped from stack -->", temp->data);
        printf("address : %p\n", address);
        free(temp);

        return;
    }


}

void peek(Stack** top) {
    Stack* temp = NULL;
    temp = *top;
    int data = 0;
    if (isEmpty(*top) == true) {
        printf("Stack is empty, Unable to execute peek\n");
        return;
    }
    else {
        temp = *top;
        data = temp->data;
        printf("top is %d and size is %d \n", temp->data, size);
        

    }
}

int main() {
    printf("linked list stack\n\n");
    Stack* s = NULL;
    printf("peek: "); peek(&s);
    printf("-----push-----\n");
    for (int i = 0; i < MAX_STACK_SIZE+1; i++) {
        push(&s, i);
        if (i == 5) {
           printf("peek: ");
           peek(&s);
        }
    }
    printf("-------------\n\n");
    peek(&s);
    printf("\n");
    printf("-----pop-----\n");
   for (int i = 0; i < MAX_STACK_SIZE; i++) {

        pop(&s);
    }

    return 0;
}