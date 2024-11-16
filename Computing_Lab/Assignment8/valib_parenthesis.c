#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

void push(Stack *s, char c) {
    s->data[++(s->top)] = c;
}

char pop(Stack *s) {
    return s->data[(s->top)--];
}

bool is_empty(Stack *s) {
    return s->top == -1;
}

bool is_valid_parenthesis(const char *str) {
    Stack s;
    s.top = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        
        if (c == '(' || c == '[' || c == '{') {
            push(&s, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (is_empty(&s)) return false;
            char top = pop(&s);
            if ((c == ')' && top != '(') || 
                (c == ']' && top != '[') || 
                (c == '}' && top != '{')) {
                return false;
            }
        }
    }

    return is_empty(&s);
}

int main() {
    char input[MAX];
    printf("Enter the string: ");
    scanf("%s", input);

    if (is_valid_parenthesis(input)) {
        printf("The given string is valid\n");
    } else {
        printf("The given string is invalid\n");
    }
    
    return 0;
}
