#include <stdio.h>

int find_all_in_array(int* aarr, int* barr, int key) {

	int count = 0;

	for (int i = 0; i < 10; i++) {
		if (key == aarr[i]) {

			barr[count] = i;
			count++;

		}
	}
	return count;
}

int main(void) {

	int a[10] = { 12,45,62,12,99,83,23,12,72,37 };
	int b[10];
	int* p = a;
	int* pp = b;
	int i, k;

	for (i = 0; i < 10; i++) {

		printf("%d ", a[i]);
		}

	printf("찾을 값? ");
	scanf_s("%d", &k);

	int c = find_all_in_array(p, pp, k);


	printf("찾은 항목은 모두 %d개입니다.\n", c);
	printf("찾은 항목의 인덱스 : ");

	for (i = 0; i < c; i++) {

		printf("%d ", pp[i]);
		}
	printf("\n");

	return 0;

}
