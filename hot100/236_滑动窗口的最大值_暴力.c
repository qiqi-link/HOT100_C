#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int findMax(int* arr, int size) {
	int max = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] > max) max = arr[i];
	}
	return max;
}
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
	int* result;
	if (numsSize < k) {
		*returnSize = 1;
		result = (int*)malloc(sizeof(int) * 1);
		result[0] = findMax(nums, numsSize);
	}
	else {
		*returnSize = numsSize - k + 1;
		result = (int*)malloc(sizeof(int) * (*returnSize));
		int* temp = malloc(sizeof(int) * k);
		for (int i = 0; i < k; i++) {
			temp[i] = nums[i]; //设temp用来记录滑动窗口中的数
		}
		result[0] = findMax(temp, k);
		for (int i = k; i < numsSize; i++) {
			temp[i%k] = nums[i]; //每次取缔掉原本滑动窗口中的left
			result[i-k+1] = findMax(temp, k); //result 在循环中从1开始
		}
	}
	return result;
}
int main() {
	int numsSize;
	scanf_s("%d", &numsSize);
	int* nums = (int*)malloc(sizeof(int) * numsSize);
	for (int i = 0; i < numsSize; i++) {
		scanf_s("%d", &nums[i]);
	}
	int k;
	scanf_s("%d", &k);
	int* result;
	int returnSize;
	result = maxSlidingWindow(nums, numsSize, k, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		printf("%d", result[i]);
	}
	return 0;
}