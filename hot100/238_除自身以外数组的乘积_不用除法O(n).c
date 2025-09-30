#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
	int* pre = (int*)malloc(sizeof(int) * numsSize);
	int* suf = (int*)malloc(sizeof(int) * numsSize);
	int* result = (int*)malloc(sizeof(int) * numsSize);
	pre[0] = 1;
	*returnSize = numsSize;
	for (int i = 1; i < numsSize; i++) {
		pre[i] = pre[i - 1] * nums[i - 1];
	}
	suf[numsSize - 1] = 1;
	for (int i = numsSize - 2; i >= 0; i--) {
		suf[i] = suf[i + 1] * nums[i + 1];
	}
	for (int i = 0; i < numsSize; i++) {
		result[i] = pre[i] * suf[i];
	}
	return result;
	free(pre);
	free(suf);
	free(result);
}
int main() {
	int numsSize;
	scanf_s("%d", &numsSize, sizeof(int));
	int* nums = (int*)malloc(sizeof(int) * numsSize);
	for (int i = 0; i < numsSize; i++) {
		scanf_s("%d", &nums[i], sizeof(int));
	}
	int returnSize = 0;
	int* result = (int*)malloc(sizeof(int) * numsSize);
	result = productExceptSelf(nums, numsSize, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		printf("%d ", result[i]);
	}
	free(result);
	return 0;
}