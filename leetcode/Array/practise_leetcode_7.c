/*
����һ���Ǹ����� numRows�����ɡ�������ǡ���ǰ numRows �С�

�ڡ�������ǡ��У�ÿ�����������Ϸ������Ϸ������ĺ͡�

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