#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ST_NUM 10
#define BUFFER_SIZE (32)

int main()
{
    enum rainbow_color { RED, ORG, YEL, GRE, BLU, NAV, PUR };
    typedef enum rainbow_color COLOR;
    struct student {
        int id;
        char name[20];
        char phone[20];
        int age;
        COLOR color;
        struct student* next;
    };
    typedef struct student STUDENT;

    STUDENT* student_list = NULL;
    int num = 10;
    char* color_tbl[7] = { "RED", "ORG", "YEL", "GRE", "BLU", "NAV", "PUR" };

    printf("학생 정보를 입력하시오. 띄어쓰기로 정보는 구분합니다.\n");
    printf("예) 본인학번 본인이름 본인번호 본인나이 본인칼라\n");

    STUDENT* sp = NULL;
    int index = 1;

    for (int i = 0; i < num; ++i)
    {
        STUDENT* cur = malloc(sizeof(STUDENT));
        char color[BUFFER_SIZE];
        scanf("%d %s %s %d %s", &(cur->id), cur->name, cur->phone, &(cur->age), color);
        if (strcmp(color, "RED") == 0) {
            cur->color = RED;
        }
        else if (strcmp(color, "ORG") == 0) {
            cur->color = ORG;
        }
        else if (strcmp(color, "YEL") == 0) {
            cur->color = YEL;
        }
        else if (strcmp(color, "GRE") == 0) {
            cur->color = GRE;
        }
        else if (strcmp(color, "BLU") == 0) {
            cur->color = BLU;
        }
        else if (strcmp(color, "NAV") == 0) {
            cur->color = NAV;
        }
        else if (strcmp(color, "PUR") == 0) {
            cur->color = PUR;
        }
        else {
            printf("입력 오류. 프로그램 종료.");
            return -1;
        }
        if (student_list == NULL) {
            student_list = cur;
            sp = student_list;
            sp->next = NULL;
        }
        else {
            sp->next = cur;
            sp = sp->next;
            sp->next = NULL;
        }
    }

    printf("(1) 학생 정보를 출력합니다 (나이 20이상 22 이하).\n");
    sp = student_list;

    while (sp != NULL)
    {
        if (sp->age >= 20 && sp->age <= 22)
        {
            printf("%d. 학번: %d, 이름: %s, 번호: %s, 나이: %d, 칼라: %s\n", index++, sp->id, sp->name, sp->phone, sp->age, color_tbl[sp->color]);
        }

        sp = sp->next;
    }

    printf("(2) 리스트 맨 처음에 입력할 학생 정보를 입력하시오.\n");
    printf("학생 정보를 입력하시오. 띄어쓰기로 정보를 구분합니다.\n");
    printf("예) 본인학번 본인이름 본인번호 본인나이 본인칼라\n");
    sp = malloc(sizeof(STUDENT));
    char color[BUFFER_SIZE];
    scanf("%d %s %s %d %s", &(sp->id), sp->name, sp->phone, &(sp->age), color);
    if (strcmp(color, "RED") == 0) {
        sp->color = RED;
    }
    else if (strcmp(color, "ORG") == 0) {
        sp->color = ORG;
    }
    else if (strcmp(color, "YEL") == 0) {
        sp->color = YEL;
    }
    else if (strcmp(color, "GRE") == 0) {
        sp->color = GRE;
    }
    else if (strcmp(color, "BLU") == 0) {
        sp->color = BLU;
    }
    else if (strcmp(color, "NAV") == 0) {
        sp->color = NAV;
    }
    else if (strcmp(color, "PUR") == 0) {
        sp->color = PUR;
    }
    else {
        printf("입력 오류. 프로그램 종료.");
        return -1;
    }

    sp->next = student_list;
    student_list = sp;
    sp = student_list;
    index = 1;
    while (sp != NULL)
    {
        printf("%d. 학번: %d, 이름: %s, 번호: %s, 나이: %d, 칼라: %s\n", index++, sp->id, sp->name, sp->phone, sp->age, color_tbl[sp->color]);

        sp = sp->next;
    }

    printf("(3) 2번에서 입력받은 학생을 7번과 8번 사이로 이동\n");

    sp = student_list;
    student_list = sp->next;
    STUDENT* cur = student_list;
    for (int i = 0; i < 6; ++i)
    {
        cur = cur->next;
    }

    STUDENT* next = cur->next;
    cur->next = sp;
    sp->next = next;

    sp = student_list;
    index = 1;
    while (sp != NULL)
    {
        printf("%d. 학번: %d, 이름: %s, 번호: %s, 나이: %d, 칼라: %s\n", index++, sp->id, sp->name, sp->phone, sp->age, color_tbl[sp->color]);

        sp = sp->next;
    }
    printf("(4) 2번에서 입력받은 학생을 마지막 순서로 이동\n");
    cur = student_list;
    for (int i = 0; i < 6; ++i)
    {
        cur = cur->next;
    }

    sp = cur->next;
    cur->next = sp->next;
    while (cur->next != NULL) {
        cur = cur->next;
    }

    cur->next = sp;
    sp->next = NULL;
    sp = student_list;
    index = 1;
    while (sp != NULL)
    {
        printf("%d. 학번: %d, 이름: %s, 번호: %s, 나이: %d, 칼라: %s\n", index++, sp->id, sp->name, sp->phone, sp->age, color_tbl[sp->color]);

        sp = sp->next;
    }
}
