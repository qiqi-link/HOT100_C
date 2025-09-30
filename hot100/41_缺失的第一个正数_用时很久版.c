#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a, const void* b) {
	int x = *(const int*)a;
	int y = *(const int*)b;

	// 使用三目运算符避免溢出
	return (x > y) - (x < y);
}
int firstMissingPositive(int* nums, int numsSize) {
	if (numsSize == 0) return 1;
	qsort(nums, numsSize, sizeof(int), cmp);
	if (nums[numsSize - 1] < 1) return 1;
	int firstPositiveIndex = 0;
	for (int i = 0; i < numsSize; i++) {
		if (nums[firstPositiveIndex] <= 0)
			firstPositiveIndex++;
	}
	if (nums[firstPositiveIndex] != 1) return 1;
	for (int i = firstPositiveIndex + 1; i < numsSize; i++) {
		if (nums[i] == nums[i - 1]) {
			continue;
		}
		if ((nums[i] - nums[i - 1] != 1)) return nums[i - 1] + 1;
	}

	return nums[numsSize - 1] + 1;
}
int main() {
	int numsSize;
	scanf_s("%d", &numsSize, sizeof(int));
	int* nums = (int*)malloc(sizeof(int) * numsSize);
	for (int i = 0; i < numsSize; i++) {
		scanf_s("%d", &nums[i], sizeof(int));
	}
	int result = firstMissingPositive(nums, numsSize);
	printf("%d ", result);
	free(nums);
	return 0;
}