#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char data;
    struct Node *leftchild;
    struct Node *rightchild;
}   Node;

int top =-1; // stack의 top을 전역 변수로 선언
Node* stack[11]; // stack을 전역 변수로 선언

void push(Node* root){ // stack push역할

    if(top < 11-1){ // 주언지 트리는 총11개의 노드가 필요하므로 0~10까지 
        top++; // top을 1증가시키고
        stack[top] = root; // stack[top]에 입력된 노들 ㄹ저장
    }
}

Node* pop(){
    Node* node = NULL;
    if(top >= 0){ // top 0 보다 같거나 크면 즉 top이 -1보다 크다면
            node = stack[top]; //stack[top]에 저장된 노드를 node에 저장
            top--;
    }
    return node; //node를 반환
}

void postorder(Node* root){
    int i =0;
    Node* node;
    Node* output[11]; // Postorder 결과를 저장할 배열 output[11]을 선언
    push(root);// root를 stack에 푸시
    while(top >= 0){
        node = pop(); // stack[top]에 있는 node를 pop
        output[i] = node; // output[i]에 pop된 노드르 저장
        i++;
        if(node->leftchild != NULL)// node->left가 NULL이 아니라면 즉 존재 한다면
                push(node->leftchild);// node->leftchild를 push
        if(node->rightchild != NULL)// node->right가 NULL이 아니라면 즉 존재 한다면
                push(node->rightchild);// node->rightchild를 Push
    }
    for(i = 10; i >= 0; i--){// postorderr결과를 출력하기위해 for문을 사용
        printf("%c ", output[i]->data);
    }
}


int main() {

// tree를 생성
Node n0 = {'J',NULL,NULL};
Node n1 = {'I', NULL, &n0};
Node n2 = {'H',NULL, &n1};
Node n3 = {'E', &n2, NULL};
Node n4 = {'D', NULL,&n3};
Node n5 = {'C', NULL,&n4};
Node n6 = {'G', NULL,NULL};
Node n7 = {'K', NULL,NULL};
Node n8 = {'F',&n7,&n6};
Node n9 = {'B',&n8,&n5};
Node n10 = {'A', &n9,NULL};
Node* root = &n10;

printf("Iterative PostOrder가 실행됩니다.\n");
printf("-----Iterative PostOrder------\n");
postorder(root);
printf("\n------------------------------\n");
printf("Iterative PostOrder가 종료되었습니다.\n");
printf("\n");

return 0;

}
