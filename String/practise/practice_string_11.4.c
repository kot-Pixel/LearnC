/*
设计并测试一个函数，搜索第1个函数形参指定的字符串，在其中查找第2个函数形参指定的字符首次出现的位置。
如果成功，该函数返指向该字符的指针，如果在字符串中未找到指定字符，则返回空指针（该函数的功能与strchr()函数相同）
在一个完整的程序中测试该函数，使用一个循环给函数提供输入值
 */

char *removeTargetStr(const char *target, char *source);

char *removeTargetStr(const char *target, char *source) {
    const int targetLength = strlen(target);
    const int sourceLength = strlen(source);
    if (targetLength > sourceLength) return NULL;
    char *result = NULL;
    int matched = 0;
    for (int index = 0; index < sourceLength; ++index) {
        if (index + targetLength > sourceLength) {
        } else {
            int start = index;
            for (int j = 0; j < targetLength; ++j) {
                if (target[j] == source[start++]) {
                    matched++;
                } else {
                    matched = 0;
                }
                if (matched == targetLength) {
                    result = source + index;
                    break;
                }
            }
        }
    }
    return result;
}

int main() {
    while(1) {
        char str[1000] = {};
        char str2[1000] = {};
        printf("Please input taget string \n");
        gets(str);
        if (removeTargetStr("quit", str) != NULL) {
            break;
        }
        printf("Please input source string \n");
        gets(str2);
        if (removeTargetStr("quit", str2) != NULL) {
            break;
        }
        char * po = removeTargetStr(str, str2);
        if (po != NULL) {
            puts(po);
        } else {
            printf("three is no target str in source string\n");
        }
    }
}