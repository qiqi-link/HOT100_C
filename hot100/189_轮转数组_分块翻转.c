#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void reverse(int* nums, int start, int end) {
	while (start < end) {
		swap(&nums[start], &nums[end]);
		start++;
		end--;
	}
}
void rotate(int* nums, int numsSize, int k) {
	k %= numsSize;
	reverse(nums, 0, numsSize-1);
	reverse(nums, 0, k - 1);
	reverse(nums, k, numsSize-1);
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