#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = numsSize - k + 1; //k<numsSize
    int* result = (int*)malloc((*returnSize) * sizeof(int));
    int* deque = (int*)malloc(numsSize * sizeof(int)); // ˫�˶��У��洢�±�
    int front = 0, rear = -1; // ����ͷβָ��

    for (int i = 0; i < numsSize; i++) {
        // ά�����е����ݼ����Ӷ�β�Ƴ��ȵ�ǰԪ��С��Ԫ��
        while (front <= rear && nums[deque[rear]] <= nums[i]) {
            rear--;
        }

        // ��ǰԪ���±����β
        rear++;
        deque[rear] = i;

        // ������Ԫ���Ƿ��Ѿ���������
        int windowStart = i - k + 1; // ��ǰ������ʼλ��
        if (deque[front] < windowStart) {
            front++; // ����Ԫ���Ѳ��ڴ����ڣ�����
        }

        // ���γ���������ʱ����¼��ǰ�������ֵ
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