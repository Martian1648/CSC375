#include <stdio.h>
#include <string.h>

int main(int argc, const char* argv[]) {
    int n = 0;
    for (int i = 1; i < argc; i++) {
        printf("%d\t%s\n", i, argv[i]);
        n += (int) strlen(argv[i]);
    }
    char str[n];
    for (int i = 1; i < argc; i++) {
        strcat(str, argv[i]);
    }
    printf("%s\n%d\n", str, n);
    return 0;
}