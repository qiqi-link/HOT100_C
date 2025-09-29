#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int subarraySum(int* nums, int numsSize, int k) {
	int* precal = (int*)malloc(sizeof(int) * (numsSize + 1));
	precal[0] = 0;
	for (int i = 1; i <= numsSize; i++) {
		precal[i] = precal[i - 1] + nums[i - 1];
	}
	int ans = 0;
	int pos = 1000;
	int hash[2000] = { 0 };
	for (int i = 0; i <= numsSize; i++) hash[precal[i] + pos]++;
	for (int i = 0; i <= numsSize; i++) {
		hash[precal[i] + pos]--;
		ans += hash[k + precal[i] + pos];
	}

	return ans;
	free(precal);
}
int main() {
	int numsSize;
	scanf_s("%d", &numsSize,sizeof(int));
	int* nums = (int*)malloc(sizeof(int) * numsSize);
	for (int i = 0; i < numsSize; i++) {
		scanf_s("%d", &nums[i],sizeof(int));
	}
	int target;
	scanf_s("%d", &target,sizeof(int));
	int result = subarraySum(nums, numsSize, target);
	printf("%d", result);
	free(nums);
	return 0;
}