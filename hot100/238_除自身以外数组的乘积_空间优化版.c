#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//主要摒弃了pre数组，实现一边遍历，一边算前几项的乘积
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
	
	int* suf = (int*)malloc(sizeof(int) * numsSize);
	int* result = (int*)malloc(sizeof(int) * numsSize);
	int cur = 1;
	*returnSize = numsSize;
	suf[numsSize - 1] = 1;
	for (int i = numsSize - 2; i >= 0; i--) {
		suf[i] = suf[i + 1] * nums[i + 1];
	}
	result[0] = suf[0];
	for (int i = 1; i < numsSize; i++) {
		cur = cur * nums[i - 1];
		result[i] = cur * suf[i];
	}
	return result;
	
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