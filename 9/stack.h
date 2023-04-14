#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 128

typedef struct Stack {
  int data[MAX_SIZE];
  int top;
} Stack;

bool is_full(Stack *stack) { return stack->top == MAX_SIZE; }

bool is_empty(Stack *stack) { return stack->top == 0; }

void push(Stack *stack, int value) {
  if (is_full(stack)) {
    printf("Stack is full!\n");
    return;
  }
  stack->data[stack->top++] = value;
}

int pop(Stack *stack) {
  if (is_empty(stack)) {
    printf("Stack is empty!\n");
    return -1;
  }
  return stack->data[--stack->top];
}

int compare_stacks(Stack *stack1, Stack *stack2) {
  if (stack1->top != stack2->top) {
    return 0;
  }

  for (int i = 0; i < stack1->top; i++) {
    if (stack1->data[i] != stack2->data[i]) {
      return 0;
    }
  }

  return 1;
}

int contain(Stack *stack1, Stack *stack2) {
  if (stack1->top < stack2->top) {
    return 0;
  }

  for (int i = 0; i < stack2->top; i++) {
    if (stack1->data[i] != stack2->data[i]) {
      return 0;
    }
  }

  return 1;
}

void print_stack(Stack *stack) {
  if (is_empty(stack)) {
    printf("Stack is empty!\n");
    return;
  }

  printf("Stack elements:\n");
  for (int i = stack->top - 1; i >= 0; i--) {
    printf("%d\n", stack->data[i]);
  }
}

void print_stack_with_message(Stack *stack, const char *message) {
  if (is_empty(stack)) {
    printf("Stack is empty!\n");
    return;
  }

  printf("%s\n", message);
  for (int i = stack->top - 1; i >= 0; i--) {
    printf("%d\n", stack->data[i]);
  }
}

#endif
