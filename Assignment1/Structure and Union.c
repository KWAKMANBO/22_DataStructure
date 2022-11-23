//
//  main.c
//  DatsStructure_assignment1
//
//  Created by 곽금주 on 2022/09/24.
//

// DS_assignment.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.


#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Person { //구조체 선언
    char name[20];
    char phone[13];
    char Lec_code;
    union {
        float Swim_record;
        int Best_score;
        char Presence[10];
    }add_info;
};
int main() {

    struct Person p[100]; // 구조체배열 100개 선언


    // 각 과목 수영, 골프, 요가를 수강하는 학생수를 카운팅 해줄 변수 선언 부분
    int snum = 0;
    int gnum = 0;
    int ynum = 0;

    // 수영과목
    char s_name[100][20]; // 수영과목 수강 학생들의 이름을 저장할 변수 최대 100개까지 저장가능
    double s_record[100]; // 수영을 수강하는 학생들의 기록을 저장할 변수를 선언 최대 100개 까지 가능
    char best_swimmer[20] = { "NULL" }; // 수영을 수강하는 학생들 중 가장 좋은 기록을 가진 학생의 이름을 저정할 변수
    double best_s_record = 0; // 수영을 수강하는 학생중 가장 좋은 기록을 저장할 변수
    double sum_swim = 0; // 수영을 수강하는 학생들의 기록을 모두 더한 수를 저장할 변수
    double avg_swim = 0; // 수영을 수강하는 학생들의 평균 기록을 저장할 변수

    //골프과목
    char g_name[100][20]; //골프를 수강하는 학생들의 이름을 저장할 변수 최대 100개까지 가능
    char best_golfer[20] = { "NULL" }; // 타수가 제일 적은 학생의 이름을 저장할 변수
    int golf_record[100]; // 골프를 수강하는 학생들의 타수를 저장할 변수
    int best_g_score = 0; // 가장 적은 타수를 저장할 변수
    int sum_golf = 0; // 학생들의 타수의 합계를 저장할 변수
    int avg_golf = 0; // 골프를 수강하는 학생들 타수 평균을 저장할 변수

    // 요가
    int disease = 0; // 척추 질환이 있는 학생들의 수를 저장할 변수


    int i = 0; // while문에서 사용할 변수

    printf("고객 정보를 입력해주세요요: [이름] [전화번호] [강습 코드] [추가 정보]\n");

    while (i < 100) { // i가 100이 될때까지 반복 시행

        scanf("%s", &p[i].name); // 구조체 p[i]의 name을 입력
        if (strcmp(p[i].name, "end") == 0)break; // 이름을 입력
        scanf("%s", &p[i].phone); // 전화번호 입력
        if (strcmp(p[i].phone, "end") == 0)break; // p[i].phone가 end 이면 입력 종료
        scanf(" %c", &p[i].Lec_code); // 과목코드 입력

        switch (p[i].Lec_code) {
        case 'S': // 과목코드가 S이면
            scanf("%f", &p[i].add_info.Swim_record); // 학생의 수영 기록을 입력
            strcpy(s_name[snum], p[i].name); // 수영과목을 수강하는 학생들의 이름을 배열에 저장
            s_record[snum] = p[i].add_info.Swim_record; // 수영과목을 수강하는 학생들의 기록을 배열에 저장
            sum_swim = sum_swim + s_record[snum]; // 학생들의 기록 합계를 저장
            snum++; // 수영과목을 수강하는 학생을 카운팅
            break;
        case 'G': // 과목코드 G이면
            scanf("%d", &p[i].add_info.Best_score); // 학생의 골프 타수를 입력
            strcpy(g_name[gnum], p[i].name); // 골프 과목을 수강하는 학생들의 이름을 배열에 저장
            golf_record[gnum] = p[i].add_info.Best_score; // 학생들의 골프 베스트 스코어 기록을 배열에 저장
            sum_golf = sum_golf + golf_record[gnum];  // 학생들의 골프 타수의 합계를 저장
            gnum++; // 골프를 수강하는 학생을 카운팅
            break;
        case 'Y': // 과목코드가 Y이면
            scanf("%s", &p[i].add_info.Presence); // 척추 질환 유무를 입력
            while (1) {// 척추질환 유무를 제대로 입력할때 까지 while문을 반복
                if (strcmp(p[i].add_info.Presence, "TRUE") == 0) { // 척추질환이 있으면
                    ynum++;  // 요가를 수강하는 학생수를 카운팅
                    disease++; // 척추질환을 갖는 학생수를 카운팅
                    break;
                }
                else if (strcmp(p[i].add_info.Presence, "FALSE") == 0) { // 척추질환이 없으면
                    ynum++; // 요가를 수강하는 학생을 카운팅
                    break;
                }
                else {
                    printf("잘못 입력하셨습니다. 다시 입력해주세요: ");// TRUE,FALSE말고 다른 문자열을 입력했을 시
                    scanf("%s", &p[i].add_info.Presence);// 다시 입력
                }

            }
        }
        i++; // 모든 과정이 끝나면 전체 학생수를 카운팅

    }
    if (snum == 1) { // 수영을 수강하는 학생이 1명일 경우
        strcpy(best_swimmer, s_name[0]);
        best_s_record = s_record[0];
    }
    if (gnum == 1) { // 골프를 수강하는 학생이 1명일 경우 
        strcpy(best_golfer, g_name[0]);
        best_g_score = golf_record[0];
    }
    for (int a = 0; a < snum - 1; a++) { // 수영 기록이 제일 좋은 학생을 찾기위해 for문을 사용
        if (s_record[a] < s_record[a + 1]) { // s_record[a]가 s_record[a+1]보다 작으면
            strcpy(best_swimmer, s_name[a]); // s_name[a]을 수영 기록이 제일 좋은 학생의 이름으로 입력
            best_s_record = s_record[a];// s_record[a]를 가장 빠른 수영 기록으로 입력
        }
        else { // s_record[a]가 s_record[a+1]보다 크거나 같으면
            strcpy(best_swimmer, s_name[a + 1]); //s_name[a+1]을 수영 기록이 제일 좋은 학생의 이름으로 입력
            best_s_record = s_record[a + 1];// s_record[a+1]을 가장 빠른 수영기록으로 입력
        }
    }
    for (int a = 0; a < gnum - 1; a++) {// 골프 타수가 제일 적은 학생을 찾기 위해 for문을 사용
        if (golf_record[a] < golf_record[a + 1]) {// golf_record[a]가 golf_record[a + 1] 보다 적을 경우
            strcpy(best_golfer, g_name[a]); // g_name[a]을 타수가 가장 적은 학생의 이름 입력
            best_g_score = golf_record[a]; // golf_record[a]의 타수를 저장 
        }
        else { // golf_record[a]가 golf_record[a + 1] 보다 작거나 같을 경우
            strcpy(best_golfer, g_name[a + 1]); //g_name[a + 1] 을 타수가 가장 적은 학생의 이름으로 입력
            best_g_score = golf_record[a + 1];// golf_record[a + 1]의 타수를 가장 적은 타수로 입력
        }
    }
    if (snum > 0) { // snum이 0보다 크면 if문 실행 snum이 0이면 오류가 발생하기 때문에 if문 사용
        avg_swim = (sum_swim / snum); // 수영기록 평균을 계산
    }
    if (gnum > 0) { // gnum이 0보다 크면 if문 실행 gnum이 0이면 오류가 발생하기 문에 if문 사용
        avg_golf = (sum_golf / gnum); // 골프 타수 평균 계산
    }
    printf("\n\n");
    printf("수강생 인원: 골프 %d 명, 수영 %d 명, 요가 %d 명\n", gnum, snum, ynum);
    printf("최고 수영 실력자: %s  %0.1lf초\n", best_swimmer, best_s_record);
    printf("수영 평균 기록: %0.1lf초\n", avg_swim);
    printf("골프 최저타 기록 보유자: %s %d타\n", best_golfer, best_g_score);
    printf("골프 평균 타수: %d타 \n", avg_golf);
    printf("요가 척추질환 보유자: %d명\n", disease);
    return 0;
}
