/*
===============================================
    SYNTAX CHECKER USING STACK
===============================================
    Author: Yash
    Branch: Artificial Intelligence and Data Science (AIDS)
    University: Savitribai Phule Pune University (SPPU)
    Subject: Data Structures & Algorithms (DSA)
    Project Type: Mini Project (Unit III)
===============================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack Structure
typedef struct {
    char items[MAX];
    int top;
} Stack;

// Function Prototypes
void initStack(Stack *s);
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, char c);
char pop(Stack *s);
char peek(Stack *s);
void displayStack(Stack *s);
int isOpeningBracket(char c);
int isClosingBracket(char c);
int isMatchingPair(char opening, char closing);
int checkSyntax(char *expression, Stack *s);
void printMenu();

// Initialize Stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Push operation
void push(Stack *s, char c) {
    if (isFull(s)) {
        printf("\n❌ Stack Overflow! Cannot push '%c'\n", c);
        return;
    }
    s->items[++(s->top)] = c;
}

// Pop operation
char pop(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->items[(s->top)--];
}

// Peek operation
char peek(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->items[s->top];
}

// Display stack contents
void displayStack(Stack *s) {
    if (isEmpty(s)) {
        printf("\n📭 Stack is empty\n");
        return;
    }
    
    printf("\n📚 Current Stack (Top -> Bottom): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%c ", s->items[i]);
    }
    printf("\n");
}

// Check if character is an opening bracket
int isOpeningBracket(char c) {
    return (c == '(' || c == '{' || c == '[');
}

// Check if character is a closing bracket
int isClosingBracket(char c) {
    return (c == ')' || c == '}' || c == ']');
}

// Check if opening and closing brackets match
int isMatchingPair(char opening, char closing) {
    return ((opening == '(' && closing == ')') ||
            (opening == '{' && closing == '}') ||
            (opening == '[' && closing == ']'));
}

// Main syntax checking function
int checkSyntax(char *expression, Stack *s) {
    int len = strlen(expression);
    int position = 0;
    
    printf("\n🔍 Analyzing expression: %s\n", expression);
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    
    for (int i = 0; i < len; i++) {
        char current = expression[i];
        position = i + 1;
        
        // If opening bracket, push to stack
        if (isOpeningBracket(current)) {
            push(s, current);
            printf("Position %2d: '%c' → Push to stack\n", position, current);
        }
        // If closing bracket, check matching
        else if (isClosingBracket(current)) {
            if (isEmpty(s)) {
                printf("\n❌ Syntax Error at position %d\n", position);
                printf("   Found closing bracket '%c' without matching opening bracket\n", current);
                return 0;
            }
            
            char top = pop(s);
            if (!isMatchingPair(top, current)) {
                printf("\n❌ Syntax Error at position %d\n", position);
                printf("   Expected closing bracket for '%c', but found '%c'\n", top, current);
                return 0;
            }
            printf("Position %2d: '%c' → Pop '%c' (matched)\n", position, current, top);
        }
    }
    
    // Check if stack is empty (all brackets matched)
    if (!isEmpty(s)) {
        printf("\n❌ Syntax Error: Unmatched opening bracket(s) remain\n");
        printf("   Missing closing bracket(s) for: ");
        while (!isEmpty(s)) {
            printf("'%c' ", pop(s));
        }
        printf("\n");
        return 0;
    }
    
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("✅ Syntax is correct: All brackets are balanced!\n");
    return 1;
}

// Print menu
void printMenu() {
    printf("\n╔═══════════════════════════════════════╗\n");
    printf("║      SYNTAX CHECKER USING STACK       ║\n");
    printf("╚═══════════════════════════════════════╝\n");
    printf("  1. Check Expression Syntax\n");
    printf("  2. View Sample Test Cases\n");
    printf("  3. Display Stack Status\n");
    printf("  4. Exit\n");
    printf("═════════════════════════════════════════\n");
    printf("Enter your choice: ");
}

// Display sample test cases
void displaySamples() {
    printf("\n📝 Sample Test Cases:\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("✅ Valid Expressions:\n");
    printf("   1. {[a+b]*(c+d)}\n");
    printf("   2. ((a+b)*c)\n");
    printf("   3. {[(x+y)*(a-b)]}\n");
    printf("   4. [a+(b*c)]\n\n");
    printf("❌ Invalid Expressions:\n");
    printf("   1. {[(a+b]*c}  → Mismatched brackets\n");
    printf("   2. ((a+b)      → Missing closing bracket\n");
    printf("   3. a+b)        → Extra closing bracket\n");
    printf("   4. {[a+b)}     → Wrong bracket type\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
}

// Main function
int main() {
    Stack stack;
    char expression[MAX];
    int choice;
    
    printf("\n");
    printf("╔═══════════════════════════════════════════════════╗\n");
    printf("║   DATA STRUCTURES & ALGORITHMS - MINI PROJECT     ║\n");
    printf("║           SYNTAX CHECKER USING STACK              ║\n");
    printf("╚═══════════════════════════════════════════════════╝\n");
    printf("  Author: Yash\n");
    printf("  Branch: AIDS (SPPU)\n");
    printf("  Unit III: Stacks and Queues\n");
    printf("═════════════════════════════════════════════════════\n");
    
    while (1) {
        printMenu();
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer
        
        switch (choice) {
            case 1:
                initStack(&stack);
                printf("\nEnter expression to check: ");
                fgets(expression, MAX, stdin);
                expression[strcspn(expression, "\n")] = 0; // Remove newline
                
                if (strlen(expression) == 0) {
                    printf("❌ Empty expression!\n");
                    break;
                }
                
                checkSyntax(expression, &stack);
                
                // Time Complexity Analysis
                printf("\n⏱️  Time Complexity Analysis:\n");
                printf("   • Expression length: %lu characters\n", strlen(expression));
                printf("   • Time Complexity: O(n) where n = %lu\n", strlen(expression));
                printf("   • Space Complexity: O(n) for stack storage\n");
                break;
                
            case 2:
                displaySamples();
                break;
                
            case 3:
                displayStack(&stack);
                break;
                
            case 4:
                printf("\n✨ Thank you for using Syntax Checker!\n");
                printf("🎓 Keep learning Data Structures!\n\n");
                exit(0);
                
            default:
                printf("\n❌ Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}

/*
===============================================
    COMPLEXITY ANALYSIS
===============================================
Operation          | Time Complexity | Space
-------------------|-----------------|--------
Push/Pop           | O(1)            | O(1)
Syntax Check       | O(n)            | O(n)
Total Algorithm    | O(n)            | O(n)

where n = length of input expression
===============================================

    REAL-WORLD APPLICATIONS
===============================================
✓ Compiler Syntax Analysis
✓ Code Editor Auto-Matching
✓ XML/HTML Tag Validation
✓ Mathematical Expression Parsing
===============================================
*/
