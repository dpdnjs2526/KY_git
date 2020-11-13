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
		for (j = 0; j <
    
    }}
