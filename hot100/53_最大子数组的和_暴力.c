#include <stdio.h>
#include <stdlib.h>
int maxSubArray(int* nums, int numsSize) {
    int* precal = (int*)malloc(sizeof(int) * (numsSize + 1));
    precal[0] = 0;
    for (int i = 1; i <= numsSize; i++) {
        precal[i] = precal[i - 1] + nums[i - 1];
    }
    int max = nums[0];
    for (int i = 0; i <= numsSize; i++) {
        for (int j = i+1; j <= numsSize; j++) {
            int temp = precal[j] - precal[i];
            if (temp > max) max = temp;
        }
    }
    return max;
}
int main() {
	int numsSize;
	scanf_s("%d", &numsSize);
	int* nums = (int*)malloc(sizeof(numsSize));
	for (int i = 0; i < numsSize; i++) {
		scanf_s("%d", &nums[i]);
	}
    int result = maxSubArray(nums, numsSize);
    printf("%d", result);
    return 0;
	free(nums);
}