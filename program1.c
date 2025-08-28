#include <stdio.h>
#include <stdlib.h>

//I fully admit to just copying and pasting this function from w3's page on qsort
int compare(const void *a, const void *b) {
    int *valA = a;
    int *valB = b;
    return *valA - *valB;
}

int main(void) {
    //get numbers
    int numbers[5];
    printf("Hello, please enter 5 numbers!\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &numbers[i]);
    }
    //compute sum
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += numbers[i];
    }
    printf("The sum is %d\n", sum);
    //compute average
    int count = sizeof(numbers) / sizeof(numbers[0]);
    printf("The average is %.1f\n", (float) sum / count );

    //find median
    qsort(numbers, count, sizeof(numbers[0]), compare);
    int median = numbers[count / 2];
    printf("The median is %d\n", median);
    return 0;
}