#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*
Ϊ��������˼·������������±��Ǵ� 1 ��ʼ�ġ�

���� nums=[2,3,1]��

�� nums[1] ��ʼ�������λ�ϵ�ѧ����ѧ���� 2����Ӧ������ nums[2] �ϣ��������� nums[2] ������������ nums=[3,2,1]��
��Ȼ�� nums[1]�������λ�ϵ�ѧ����ѧ���� 3����Ӧ������ nums[3] �ϣ��������� nums[3] ������������ nums=[1,2,3]��
��Ȼ�� nums[1]�������λ�ϵ�ѧ����ѧ���� 1����������ȷ����λ�ϡ�
��������nums[2]=2����������ȷ����λ�ϡ�
��������nums[3]=3����������ȷ����λ�ϡ�
����λ���̽�����
�ٴα��� nums������ nums[i]=i �����㣬˵�������� 1,2,3 ���У�����ȱʧ�ĵ�һ�������� 4
һ��أ�Ϊ�˼��ݡ���ǰѧ��������������ȷ����λ�ϡ��͡���ǰѧ����Ӱ������������������ȷ����λ�ϡ�������������ǿ��԰� i=nums[i] ��һ�� nums���� nums[i]=nums[nums[i]] �ж�
*/
int firstMissingPositive(int* nums, int numsSize) {
	for (int i = 0; i < numsSize; i++) {
		while (1 <= nums[i] && nums[i] <= numsSize && nums[i] != nums[nums[i] - 1]) {
			// ��ô�ͽ��� nums[i] �� nums[j]������ j �� i ��ѧ��
			int j = nums[i] - 1; // ��һ����Ϊ�����±�� 0 ��ʼ
			int tmp = nums[i];
			nums[i] = nums[j];
			nums[j] = tmp;
		}
	}
	// �ҵ�һ��ѧ������λ��Ų�ƥ���ѧ��
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] != i + 1) {
			return i + 1;
		}
	}

	// ����ѧ����������ȷ����λ��
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