//
//  main.c
//  DatsStructure_assignment1
//
//  Created by ������ on 2022/09/24.
//

// DS_assignment.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.


#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Person { //����ü ����
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

    struct Person p[100]; // ����ü�迭 100�� ����


    // �� ���� ����, ����, �䰡�� �����ϴ� �л����� ī���� ���� ���� ���� �κ�
    int snum = 0;
    int gnum = 0;
    int ynum = 0;

    // ��������
    char s_name[100][20]; // �������� ���� �л����� �̸��� ������ ���� �ִ� 100������ ���尡��
    double s_record[100]; // ������ �����ϴ� �л����� ����� ������ ������ ���� �ִ� 100�� ���� ����
    char best_swimmer[20] = { "NULL" }; // ������ �����ϴ� �л��� �� ���� ���� ����� ���� �л��� �̸��� ������ ����
    double best_s_record = 0; // ������ �����ϴ� �л��� ���� ���� ����� ������ ����
    double sum_swim = 0; // ������ �����ϴ� �л����� ����� ��� ���� ���� ������ ����
    double avg_swim = 0; // ������ �����ϴ� �л����� ��� ����� ������ ����

    //��������
    char g_name[100][20]; //������ �����ϴ� �л����� �̸��� ������ ���� �ִ� 100������ ����
    char best_golfer[20] = { "NULL" }; // Ÿ���� ���� ���� �л��� �̸��� ������ ����
    int golf_record[100]; // ������ �����ϴ� �л����� Ÿ���� ������ ����
    int best_g_score = 0; // ���� ���� Ÿ���� ������ ����
    int sum_golf = 0; // �л����� Ÿ���� �հ踦 ������ ����
    int avg_golf = 0; // ������ �����ϴ� �л��� Ÿ�� ����� ������ ����

    // �䰡
    int disease = 0; // ô�� ��ȯ�� �ִ� �л����� ���� ������ ����


    int i = 0; // while������ ����� ����

    printf("�� ������ �Է����ּ����: [�̸�] [��ȭ��ȣ] [���� �ڵ�] [�߰� ����]\n");

    while (i < 100) { // i�� 100�� �ɶ����� �ݺ� ����

        scanf("%s", &p[i].name); // ����ü p[i]�� name�� �Է�
        if (strcmp(p[i].name, "end") == 0)break; // �̸��� �Է�
        scanf("%s", &p[i].phone); // ��ȭ��ȣ �Է�
        if (strcmp(p[i].phone, "end") == 0)break; // p[i].phone�� end �̸� �Է� ����
        scanf(" %c", &p[i].Lec_code); // �����ڵ� �Է�

        switch (p[i].Lec_code) {
        case 'S': // �����ڵ尡 S�̸�
            scanf("%f", &p[i].add_info.Swim_record); // �л��� ���� ����� �Է�
            strcpy(s_name[snum], p[i].name); // ���������� �����ϴ� �л����� �̸��� �迭�� ����
            s_record[snum] = p[i].add_info.Swim_record; // ���������� �����ϴ� �л����� ����� �迭�� ����
            sum_swim = sum_swim + s_record[snum]; // �л����� ��� �հ踦 ����
            snum++; // ���������� �����ϴ� �л��� ī����
            break;
        case 'G': // �����ڵ� G�̸�
            scanf("%d", &p[i].add_info.Best_score); // �л��� ���� Ÿ���� �Է�
            strcpy(g_name[gnum], p[i].name); // ���� ������ �����ϴ� �л����� �̸��� �迭�� ����
            golf_record[gnum] = p[i].add_info.Best_score; // �л����� ���� ����Ʈ ���ھ� ����� �迭�� ����
            sum_golf = sum_golf + golf_record[gnum];  // �л����� ���� Ÿ���� �հ踦 ����
            gnum++; // ������ �����ϴ� �л��� ī����
            break;
        case 'Y': // �����ڵ尡 Y�̸�
            scanf("%s", &p[i].add_info.Presence); // ô�� ��ȯ ������ �Է�
            while (1) {// ô����ȯ ������ ����� �Է��Ҷ� ���� while���� �ݺ�
                if (strcmp(p[i].add_info.Presence, "TRUE") == 0) { // ô����ȯ�� ������
                    ynum++;  // �䰡�� �����ϴ� �л����� ī����
                    disease++; // ô����ȯ�� ���� �л����� ī����
                    break;
                }
                else if (strcmp(p[i].add_info.Presence, "FALSE") == 0) { // ô����ȯ�� ������
                    ynum++; // �䰡�� �����ϴ� �л��� ī����
                    break;
                }
                else {
                    printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���: ");// TRUE,FALSE���� �ٸ� ���ڿ��� �Է����� ��
                    scanf("%s", &p[i].add_info.Presence);// �ٽ� �Է�
                }

            }
        }
        i++; // ��� ������ ������ ��ü �л����� ī����

    }
    if (snum == 1) { // ������ �����ϴ� �л��� 1���� ���
        strcpy(best_swimmer, s_name[0]);
        best_s_record = s_record[0];
    }
    if (gnum == 1) { // ������ �����ϴ� �л��� 1���� ��� 
        strcpy(best_golfer, g_name[0]);
        best_g_score = golf_record[0];
    }
    for (int a = 0; a < snum - 1; a++) { // ���� ����� ���� ���� �л��� ã������ for���� ���
        if (s_record[a] < s_record[a + 1]) { // s_record[a]�� s_record[a+1]���� ������
            strcpy(best_swimmer, s_name[a]); // s_name[a]�� ���� ����� ���� ���� �л��� �̸����� �Է�
            best_s_record = s_record[a];// s_record[a]�� ���� ���� ���� ������� �Է�
        }
        else { // s_record[a]�� s_record[a+1]���� ũ�ų� ������
            strcpy(best_swimmer, s_name[a + 1]); //s_name[a+1]�� ���� ����� ���� ���� �л��� �̸����� �Է�
            best_s_record = s_record[a + 1];// s_record[a+1]�� ���� ���� ����������� �Է�
        }
    }
    for (int a = 0; a < gnum - 1; a++) {// ���� Ÿ���� ���� ���� �л��� ã�� ���� for���� ���
        if (golf_record[a] < golf_record[a + 1]) {// golf_record[a]�� golf_record[a + 1] ���� ���� ���
            strcpy(best_golfer, g_name[a]); // g_name[a]�� Ÿ���� ���� ���� �л��� �̸� �Է�
            best_g_score = golf_record[a]; // golf_record[a]�� Ÿ���� ���� 
        }
        else { // golf_record[a]�� golf_record[a + 1] ���� �۰ų� ���� ���
            strcpy(best_golfer, g_name[a + 1]); //g_name[a + 1] �� Ÿ���� ���� ���� �л��� �̸����� �Է�
            best_g_score = golf_record[a + 1];// golf_record[a + 1]�� Ÿ���� ���� ���� Ÿ���� �Է�
        }
    }
    if (snum > 0) { // snum�� 0���� ũ�� if�� ���� snum�� 0�̸� ������ �߻��ϱ� ������ if�� ���
        avg_swim = (sum_swim / snum); // ������� ����� ���
    }
    if (gnum > 0) { // gnum�� 0���� ũ�� if�� ���� gnum�� 0�̸� ������ �߻��ϱ� ������ if�� ���
        avg_golf = (sum_golf / gnum); // ���� Ÿ�� ��� ���
    }
    printf("\n\n");
    printf("������ �ο�: ���� %d ��, ���� %d ��, �䰡 %d ��\n", gnum, snum, ynum);
    printf("�ְ� ���� �Ƿ���: %s  %0.1lf��\n", best_swimmer, best_s_record);
    printf("���� ��� ���: %0.1lf��\n", avg_swim);
    printf("���� ����Ÿ ��� ������: %s %dŸ\n", best_golfer, best_g_score);
    printf("���� ��� Ÿ��: %dŸ \n", avg_golf);
    printf("�䰡 ô����ȯ ������: %d��\n", disease);
    return 0;
}