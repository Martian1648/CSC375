#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

struct stack {
    //create a stack of size 10
    int pos;
    int arr[SIZE];
};

bool empty(struct stack* stack) {
    return stack->pos == 0;
}

bool full(struct stack* stack) {
    return stack->pos == SIZE;
}

int push(struct stack* stack, int value) {
    if (full(stack)) {
        return 1;
    }
    stack->arr[stack->pos] = value;
    stack->pos++;
    return 0;
}

int pop(struct stack* stack) {
    if (empty(stack)) {
        return 1;
    }
    stack->pos--;
    return 0;
}

int top(struct stack* stack, int* value) {
    if (empty(stack)) {
        return 1;
    }
    *value = stack->arr[stack->pos - 1];
    return 0;
}



int display(struct stack* stack) {
    printf("Stack contents: ");
    for (int i = 0; i < stack->pos; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
    return 0;
}


int main(void) {
    struct stack s = {0};
    struct stack* stack = &s;
    int num;
    int* ptr = &num;
    for (int i = 0; i < 7; i++) {
        push(stack, i);
    }
    display(stack);
    top(stack, ptr);
    printf("Top of stack: %d\n", *ptr);
    pop(stack);
    display(stack);
    top(stack, ptr);
    printf("Top of stack: %d\n", *ptr);
    for (int i = stack->pos; i < SIZE; i++) {
        push(stack, i);
    }
    display(stack);
    printf("Full? %d\n", full(stack));
    printf("Empty? %d\n", empty(stack));
    for (int i = 0; i < SIZE; i++) {
        pop(stack);
    }
    display(stack);
    printf("Full? %d\n", full(stack));
    printf("Empty? %d\n", empty(stack));
}