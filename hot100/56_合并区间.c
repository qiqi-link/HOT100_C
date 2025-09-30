/*
https://leetcode.cn/problems/merge-intervals/
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a, const void* b) {
    int* A = *(int**)a;
    int* B = *(int**)b;
    return A[0] - B[0];
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    int** ans = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = malloc(intervalsSize * sizeof(int));
    for (int i = 0; i < intervalsSize; i++) {
        ans[i] = (int*)malloc(2 * sizeof(int));//返回的数组的列大小都为2
        (*returnColumnSizes)[i] = 2;
    }
    int count = 0;
    qsort(intervals, intervalsSize, sizeof(int*), cmp);

    for (int i = 0; i < intervalsSize; i++) {
        int l = intervals[i][0] , r = intervals[i][1];
        if (count > 0 || l > ans[count - 1][1]) { //现在的左边界比上一个右边界还大，独立出一个新的区间
            ans[count][0] = l;
            ans[count][1] = r;
            count++;
        }
        else {
            ans[count - 1][1] = fmax(ans[count - 1][1], r);//取上一个右边界和现在右边界的最大值
        }
    }
    *returnSize = count;
    return ans;
}
int main() {
    int intervalsSize;
    printf("请输入区间数量: ");
    scanf_s("%d", &intervalsSize);

    int* intervalsColSize = (int*)malloc(sizeof(int) * intervalsSize);
    int** intervals = (int**)malloc(sizeof(int*) * intervalsSize);

    printf("请输入每个区间的长度（每个区间都是2个元素）:\n");
    for (int i = 0; i < intervalsSize; i++) {
        intervalsColSize[i] = 2; // 区间合并问题中，每个区间通常是2个元素
    }

    printf("请输入%d个区间（每个区间两个数字，用空格分隔）:\n", intervalsSize);
    for (int i = 0; i < intervalsSize; i++) {
        intervals[i] = (int*)malloc(sizeof(int) * 2); // 分配2个int的空间
        printf("区间 %d: ", i + 1);
        scanf_s("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    int returnSize = 0;
    int* returnColumnSizes = NULL;

    int** ans = merge(intervals, intervalsSize, intervalsColSize, &returnSize, &returnColumnSizes);

    printf("合并后的区间: [");
    for (int i = 0; i < returnSize; i++) {
        if (i > 0) printf(", ");
        printf("[%d, %d]", ans[i][0], ans[i][1]);
    }
    printf("]\n");

    // 释放内存
    for (int i = 0; i < intervalsSize; i++) {
        free(intervals[i]);
    }
    free(intervals);
    free(intervalsColSize);

    for (int i = 0; i < returnSize; i++) {
        free(ans[i]);
    }
    free(ans);
    free(returnColumnSizes);

    return 0;
}