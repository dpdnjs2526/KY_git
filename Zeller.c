#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 함수 선언 
int get_week_day(int, int, int);
void set_feb(int);
void get_dday(int*, int*, int*, int);
int input(int*, int*, int*, int*);

// 프로그램 종료시 까지 필요하므로 외부변수로 선언 
int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };    // 각 달의 일수
char week[7][4] = { "일", "월", "화", "수", "목", "금", "토" };        // 요일명

void main(void)
{
    int yy, mm, dd;    // 기준년월일 
    int after;        // 구해야 할 날수 
    int wd;            // 최종 요일 

    input(&yy, &mm, &dd, &after);    // 기준일자, 더해야 할 날 수 입력 
    get_dday(&yy, &mm, &dd, after);    // 최종 날짜 얻기 
    wd = get_week_day(yy, mm, dd);    // 요일 얻기 

    printf(" %d년 %d월 %d일 (%s)입니다.\n", yy, mm, dd, week[wd]);
}

int get_week_day(int yy, int mm, int dd)
{
    int i;
    int total = 0, y;


    yy--;                // 이전해 말일까지
    total = 365 * yy;    // 작년 말일까지 평일 수 
    total += yy / 4;
    total += yy / 400;
    total -= yy / 100;    // 윤년 만큼 더함 

    set_feb(yy);        // 올해 2월의 날수 설정

    for (i = 0; i < mm - 1; i++) total += month[i];    // 이전달 말일 까지 날짜 누산 

    total += dd;    // 금일의 날수 더함 

    // 1년 1월 1일을 월요일로 가정 

    return (total % 7);    // 요일을 반환 (0 이면 일요일) 
}

void set_feb(int yy)
{
    // 외부변수 이므로 별다른 조치를 하지 않고 변경

    if (yy % 4 == 0 && yy % 100 != 0 || yy % 400 == 0)
        month[1] = 29;    // 윤년 
    else    month[1] = 28;        // 평년 
}

void get_dday(int* yy, int* mm, int* dd, int after)
{
    int i, j;

    after += *dd;    // 받은 날짜를 더함 

    for (i = *yy; after > 0; i++, *mm = 1) {    // 기준년부터  
        for (j = *mm; j <= 12; j++) {            // 월단위로 
            if (j == 2) set_feb(*yy);            // 2월이면 윤년확인 
            if (after > month[j - 1]) {            // 당월보다 크면 
                after -= month[j - 1];             // 당월 날수를 뺌 
            }
            else break;                            // 당월 말일보다 작으면 
        }
        if (j < 13 && after < month[j - 1]) {        // 당월 말일 보다 작으면 
            *yy = i;                            // 년도를 확정 
            *mm = j;                            // 월 확정 
            *dd = after;                        // 날짜 확정 
            break;                                // 날짜 찾기 종료 
        }
    }
}

int input(int* yy, int* mm, int* dd, int* after)
{
    printf(" 기준 날짜를 입력하세요(yyyy mm dd) : ");
    scanf("%d %d %d", yy, mm, dd);                 // 기준 날짜값 입력 

    printf(" 며칠 후를 계산할까요? : ");
    scanf("%d", after);                            // 며칠 후인지 입력받기
}


요일 구하는 공식

wd = ((21 * (yy / 100) / 4) + (5 * (yy - yy / 100 * 100) / 4) + (26 * (mm + 1) / 10) + dd - 1) % 7;
//a=년도 앞 두 자리, b=년도 뒤 두자리, c=월, d=일 : Zeller의 공식 
cs
