//
//  main.c
//  assignment2
//
//  Created by 곽금주 on 2022/10/09.
//

#include <stdio.h>
#include <stdlib.h>
int main() {
    int machine[5]={101,102,103,104,105};//진동벨 번호
    int queue[5]={0,0,0,0,0}; // 큐 모든 성분을 0으로 초기화
    
    int tmp=0; // 입력한 수를 담을 변수
    
    int front=-1; // front
    int rear=-1; // rear
    
    int first_inst; // 첫번째 명령에 입력된 숫자를 받을 변수
    int second_inst; // 첫번째에 1을 입력후 두번째 명령을 입력할 때 입력된 숫자를 받는 변수
    
    int wait_guest=0; // 대기인원을 카운팅해줄 변수
    int ordering=0; // 큐에서 front의 다음 인덱스를 담을 변수
    
    while(1){
    
    printf("Ajou 푸드코트에 오신 것을 환영합니다. 원하는 기능을 선택해주세요\n");
    printf("1. 주문  2. 서빙 완료 3. 종료\n");
    scanf("%d",&first_inst); // 첫번째 입력을 입력받음
    
    if(first_inst==1){ // 1이 입력됐다면
        printf("현재 대기자 수는 %d 명입니다. 계속 주문하시겠습니까?\n", wait_guest);
        printf("1.계속   2.취소\n");
        
        scanf("%d",&second_inst); // 두번째 명령을 입력받음
       
        if(second_inst==1){// 두번째 명령에서 주문을 선택했다면 enqueue과정임
            if(wait_guest==5){ // 대기자가 최대 5명이므로 5명이 되면 주문이 불가능함
                printf("주문이 불가능합니다.\n감사합니다.\n*_*_*_*_*_*_*_*_*\n");
            }else{
                if (rear==4){ // rear가 queue의 맨 마지막 인덱스에 있으면
                    rear=-1;//-1 즉 처음부터 다시시작
                }
               // printf("rear:%d\n",rear);
            printf("진동벨의 번호를 입력해주세요\n");
            scanf("%d",&tmp);
                if(tmp<101){ // tmp가 101~105말고 다른 수가 입력되었을때 안내 메시지 출력
                    printf("잘못 입력하셨습니다.\n");
                }else if(tmp>105){
                    printf("잘못 입력하셨습니다.\n");
                }
                
                for(int i=0; i<5; i++){ // for문을 통해 입력한 진동벨이 큐에 존재하는지 확인
                    if(tmp==queue[i]){// tmp에 입력한 진동벨 번호가 queue에 존재한다면 사용중인 진동벨이라고 안내문 출력
                        printf("사용중인 진동벨입니다. 다시 입력해주세요\n");
                    }else{// tmp에 입력한 진동벨 번호가 queue에 존재 하지 않는다면
                        if(machine[i]==tmp){ // tmp에 입력한 진동벨 번호가 101~105중 숫자인지 확인해서 맞다면
                        rear++; //rear을 1증가
                        wait_guest++;// 대기중인 손님을 카운팅하기위해 wait_guest를 1증가시킴
                        queue[rear]=machine[i];
                            printf("주문이 완료되었습니다.\n*_*_*_*_*_*_*_*_*_*\n");// machine[i]에 있는 수를 queue[rear]에다가 저장함
                       // printf("front: %d, rear: %d\n", front,rear);
                    }
                        
                    }
            }
            }
            
        }else if(second_inst==2){ // 두번쨰 명령에서 취소했을 때
            printf("취소하셨습니다.\n 감사합니다.\n*_*_*_*_*_*_*_*\n");
        }else{ // 1또는 2 말고 다른 수를 입력했을때
            printf("잘못 입력하셨습니다.\n 처음부터 다시 입력해주세요\n*_*_*_*__*_*_*_*\n");
}
        
    }else if(first_inst==2){ // deqeue를 하기위해서 첫번쨰 명령어 입력에서 2를 눌렀을때
    
        if(front+1 ==rear){ // front+1과 rear가 같다면
        front++;
        queue[front]=0; // dequeue를 위해서 0으로 초기화 즉 큐를 비운다
       //  printf("front: %d, rear: %d\n",front,rear);
        printf("주문내역이 없습니다\n*_*_*_*_*_*_*_*_*\n"); // 주문내역이 없음을 안내
        if(wait_guest>0){ // 대기중인 손님이 0 이상일때만 실행
            wait_guest--; // queue에서 하나가 비어지는것이므로 대기인원도 1줄어듬
            if(rear==4){ // rear가 4일때
            queue[front]=0; // dequeue 즉 queue를 비우기위해서 queue[front]를 0으로 초기화
        front =-1;// 처음의 상태로 초기화
        rear =-1;// 처음의 상태로 초기화
        }}
        
    }else if(front<3){// front가 3보다 작을때
        if(queue[rear]!=0){ // queue[rear]가 0이 아니라면 즉 큐가 비어있지 않다면
        front++;
        queue[front]=0;// queue[front]를 비우기
        ordering=front+1; // queue[front] 다음 인덱스를 가리킴
            //printf("front: %d, rear: %d\n", front,rear);
            wait_guest--;
            printf("%d번님 의 주문을 처리중입니다.\n",queue[ordering]);

        }else if(queue[rear]== 0){// queue[rear]가 비어있다면
           // printf("front: %d, rear: %d\n", front,rear);
            printf("주문내역이 없습니다\n*_*_*_*_*_*_*_*_*\n");
            }

        
    }else if(front==3){// front가 3이라면
        front++;
        queue[front]=0; // dequeue queue[4]를 0으로 초기화 즉 queue를 비움
        if(rear<0){front=-1; //rear가 -1로 초기상태면 front도 -1로 초기화 시킴
        }else if(rear>=0){//rear가 -1이아니고 다른 수라면 즉 큐에 들어가 있다면
            front=-1;
            ordering = front+1;
            wait_guest--; // dequeue를 하므로 대기중인 손님의 수를 줄이기위해 -1
            // printf("front: %d, rear: %d\n", front,rear);
            printf("%d번님 의 주문을 처리중입니다.\n",queue[ordering]);
        }else if(front ==(-1)){// front와 rear둘다 초기상태라면
            if(rear==(-1)){ printf("주문내역이 없습니다\n*_*_*_*_*_*_*_*_*\n");}
                
                }
    }
    
}else if(first_inst==3){
    printf("서비스를 종료합니다.\n");
    exit(0);
}else{
    printf("잘못 누르셨습니다.\n");
    printf("*_*_*_*_*_*_*_*");
}
    
    }
    return 0;
}
