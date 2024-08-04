/*
给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。

*/
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** resut = (int**)malloc(numRows * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));
    for (int i = 1; i <= numRows; i++) {
        int* coResult = (int*)malloc(i * sizeof(int));
        (*returnColumnSizes)[i - 1] = i;
        coResult[0] = 1;
        coResult[i - 1] = 1;
        for (int j = 1; j < i - 1; j++) {
            coResult[j] = resut[i - 2][j - 1] + resut[i - 2][j];
        }
        resut[i - 1] = coResult;
    }
    *returnSize = numRows;
    //free(resut);
    return resut;
}