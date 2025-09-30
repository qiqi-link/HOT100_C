#include <stdio.h>
#include <stdlib.h>
int maxnums(int a, int b) {
    if (a > b) return a;
    else return b;
}

int maxSubArray(int* nums, int numsSize) {
    int pre = 0, maxAns = nums[0];
    for (int i = 0; i < numsSize; i++) {
        pre = maxnums(pre + nums[i], nums[i]);
        maxAns = maxnums(maxAns, pre);
    }
    return maxAns;
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