#include <stdio.h>
#include <stdlib.h>
typedef struct Node *treepointer;
typedef struct Node {
    char data;
    treepointer leftchild;
    treepointer rightchild;
} Node;

Node* initNode(char data, Node *leftchild, Node* rightchild){ //node에 data와 leftchild, rightchild를 init해주는 함수
    Node* node = (Node*)malloc(sizeof(Node));
    node -> data = data;
    node -> leftchild = leftchild;
    node -> rightchild = rightchild;
    return node;
}


void postorder(Node* root){  // Recursive Postorder(후위) 함수가 단계적으로 어떻게 실행되는지 확인하기 위해 단계별로 출력해주는 함수
    if(root){ // 입력된 노드가 NULL이 아니라면 if문이 실행
        printf("Node %c 에 대한 Recursive Postorder 함수가 실행됩니다.\n\n", root->data);
        
       postorder(root->leftchild); // 입력된 노드의 leftchild가 NULL이 아니라면 실행됨
        postorder(root-> rightchild);// 입력된 노드의 rightchild가 NULL이 아니라면 실행됨
        printf("Node %c 를 출력 하고", root->data);
        printf("Node %c 에 대한 Recurisve Postorder 함수가 종료됩니다.\n\n", root->data);
    }

}

void postorder1(Node* root){  // Recursive Postorder(후위 순회)의 결과만을 출력해주는 함수
    if(root){
       postorder1(root->leftchild);// 입력된 노드의 leftchild가 NULL이 아니라면 실행
        postorder1(root-> rightchild);// 입력된 노드의 rightchild가 NULL이 아니라면 실행
        printf("%c ", root ->data);

    }

}

int main(){
    // tree를 생성
    Node* node11 = initNode('J',NULL,NULL);
    Node* node10 = initNode('I', NULL, node11);
    Node* node9 = initNode('H',NULL,node10);
    Node* node8 = initNode('E', node9,NULL);
    Node* node7 = initNode('D',NULL, node8);
    Node* node6 = initNode('C',NULL,node7);
    Node* node5 = initNode('K',NULL,NULL);
    Node* node4 = initNode('G',NULL,NULL);
    Node* node3 = initNode('F',node5,node4);
    Node* node2 = initNode('B',node3,node6);
    Node* node1 = initNode('A',node2,NULL);


    
    
    postorder(node1); //단계적 Recursive PostOrder 과정을 확인하는 함수를 호출
    printf("Recursive Postorder 최종결과: ");
    postorder1(node1); // Recursive Postorder의 결과를 보여주는 함수를 선언
    printf("\n\n");
    

    return 0;
    }
