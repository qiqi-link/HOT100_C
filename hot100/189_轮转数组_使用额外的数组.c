#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void rotate(int* nums, int numsSize, int k) {
	int* temp = (int*)malloc(sizeof(int) * numsSize);
	for (int i = 0; i < numsSize; i++) {
		temp[(k + i) % numsSize] = nums[i];
	}
	for (int i = 0; i < numsSize; i++) {
		nums[i] = temp[i];
	}
	free(temp);
}
int main() {
	int numsSize;
	scanf_s("%d", &numsSize, sizeof(int));
	int* nums = (int*)malloc(sizeof(int) * numsSize);
	for (int i = 0; i < numsSize; i++) {
		scanf_s("%d", &nums[i], sizeof(int));
	}
	int k;
	scanf_s("%d", &k, sizeof(int));
	rotate(nums, numsSize, k);
	for (int i = 0; i < numsSize; i++) {
		printf("%d ", nums[i]);
	}
	free(nums);
	return 0;
}