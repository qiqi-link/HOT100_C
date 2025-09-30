#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*
为方便描述思路，假设数组的下标是从 1 开始的。

假设 nums=[2,3,1]。

从 nums[1] 开始。这个座位上的学生，学号是 2，他应当坐在 nums[2] 上，所以他和 nums[2] 交换。交换后 nums=[3,2,1]。
仍然看 nums[1]，这个座位上的学生，学号是 3，他应当坐在 nums[3] 上，所以他和 nums[3] 交换。交换后 nums=[1,2,3]。
仍然看 nums[1]，这个座位上的学生，学号是 1，他坐在正确的座位上。
向后遍历，nums[2]=2，他坐在正确的座位上。
向后遍历，nums[3]=3，他坐在正确的座位上。
换座位过程结束。
再次遍历 nums，发现 nums[i]=i 都满足，说明数组中 1,2,3 都有，所以缺失的第一个正数是 4
一般地，为了兼容「当前学生是真身，坐在正确的座位上」和「当前学生是影分身，且其真身坐在正确的座位上」两种情况，我们可以把 i=nums[i] 套一层 nums，用 nums[i]=nums[nums[i]] 判断
*/
int firstMissingPositive(int* nums, int numsSize) {
	for (int i = 0; i < numsSize; i++) {
		while (1 <= nums[i] && nums[i] <= numsSize && nums[i] != nums[nums[i] - 1]) {
			// 那么就交换 nums[i] 和 nums[j]，其中 j 是 i 的学号
			int j = nums[i] - 1; // 减一是因为数组下标从 0 开始
			int tmp = nums[i];
			nums[i] = nums[j];
			nums[j] = tmp;
		}
	}
	// 找第一个学号与座位编号不匹配的学生
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] != i + 1) {
			return i + 1;
		}
	}

	// 所有学生都坐在正确的座位上
	return numsSize + 1;
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