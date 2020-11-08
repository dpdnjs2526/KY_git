#include<stdio.h>
#include<stdlib.h>

struct number {
	int num;
	struct number* next;
	struct number* below;
};
int main()
{
	char buffer[256];
	FILE* fp = NULL;
	int arr[9][9] = { 0, };
	int i = 0, j = 0;

	if (0 == fopen_s(&fp, "ggd.txt", "rt")) {
		while (fgets(buffer, 256, fp) != NULL) {

			char* ptr = strtok(buffer, " ");
			int num;
			j = 0;
			while (ptr != NULL) {
				num = atoi(ptr);
				arr[i][j] = num;
				j++;
				ptr = strtok(NULL, " ");
			}
			i++;
		}
		fclose(fp);

	}
	struct number* head = malloc(sizeof(struct number));
	
	struct number* List[9][9];

	for (i = 0; i < 9; i++) 
		for (j = 0; j < 9; j++) 
			List[i][j] = malloc(sizeof(struct number));	
	
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			List[i][j]->num = arr[i][j];
			if (i == 8 || j == 8)
				continue;
			List[i][j]->next = List[i][j+1];
			List[i][j]->below = List[i+1][j];
		}
	}

	head = List[0][0]; //ø¨∞·∏ÆΩ∫∆Æ¿« Ω«¡˙¿˚¿Œ Ω√¿€ ±∏¡∂√º ∆˜¿Œ≈Õ

	printf("√£æ∆ ∞• «‡ ∑ƒ¿ª ¿‘∑¬ : ");
	int row, col;
	scanf_s(" %d %d", &row, &col);

	printf("√£æ∆∞°¥¬ º¯º≠ : ");

	for (int i = 0; i < col-1; i++) { // ¿‘∑¬πﬁ¿∫ col ∏∏≈≠ ø∑¿∏∑Œ ¿¸¡¯
		printf("%d ", head->num);
		if (i == col - 1)
			break;
		head = head->next;
	}
	for (int j = 0; j < row-1; j++) { // ¿‘∑¬πﬁ¿∫ row ∏∏≈≠ ø∑¿∏∑Œ ¿¸¡¯
		printf("%d ", head->num);
		if (i == row - 1)
			break;
		head = head->below;
	}
	printf("%d ", head->num);
	return 0;
}
