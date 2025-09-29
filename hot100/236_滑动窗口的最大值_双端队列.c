#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = numsSize - k + 1; //k<numsSize
    int* result = (int*)malloc((*returnSize) * sizeof(int));
    int* deque = (int*)malloc(numsSize * sizeof(int)); // 双端队列，存储下标
    int front = 0, rear = -1; // 队列头尾指针

    for (int i = 0; i < numsSize; i++) {
        // 维护队列单调递减：从队尾移除比当前元素小的元素
        while (front <= rear && nums[deque[rear]] <= nums[i]) {
            rear--;
        }

        // 当前元素下标入队尾
        rear++;
        deque[rear] = i;

        // 检查队首元素是否已经滑出窗口
        int windowStart = i - k + 1; // 当前窗口起始位置
        if (deque[front] < windowStart) {
            front++; // 队首元素已不在窗口内，出队
        }

        // 当形成完整窗口时，记录当前窗口最大值
        if (windowStart >= 0) {
            result[windowStart] = nums[deque[front]];
        }
    }

    free(deque);
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