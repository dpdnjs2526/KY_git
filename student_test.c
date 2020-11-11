#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int answers[100]; //정답배열
	int points[100]; //배점 배열
	int st_answers[100]; //학생 답 배열
	int size; 
	int stn;
	int comp[100] = { 0, }; //점수 비교
	int max;

	scanf("%d", &size);

	for (int i = 0; i < size; i++){
		scanf("%d", &answers[i]);
	}
	
	for (int i = 0; i < size; i++) {
		scanf("%d", &points[i]);
	}

	scanf("%d", &stn);


	for (int i = 0; i < stn; i++)
		for (int j = 0; j < size; j++)
			scanf("%d", &st_answers[j]);

	for(int i = 0; i < stn; i++)
		for (int j = 0; j < size; j++) {
			int k = j*(i+1) + size*i; //k는 st_answers때문
			if (answers[j] == st_answers[k])
				comp[i] += points[j];    //comp i 는 학생별 점수를 저장해주는 코드 
		}

	max = comp[0];

	for (int i = 0; i < 100; i++) {
		if (comp[i] > max) {
			max = comp[i];
		}
	}
	printf("%d", max);

	return 0;
}
