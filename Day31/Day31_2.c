/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type. 
Example 1:
Input: s = "()"
Output: true
Example 2:
Input: s = "()[]{}"
Output: true
Example 3:
Input: s = "(]"
Output: false
Example 4:
Input: s = "([])"
Output: true
Example 5:
Input: s = "([)]"
Output: false
*/

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
bool isValid(char * s) {
    int n = strlen(s);
    char *stack = (char*)malloc(n * sizeof(char));
    int top = -1;
    for(int i = 0; i < n; i++) {
        char c = s[i];
        if(c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        }
        else {
            if(top == -1) {
                free(stack);
                return false;
            }
            char open = stack[top--];       
            if((c == ')' && open != '(') ||
               (c == '}' && open != '{') ||
               (c == ']' && open != '[')) {
                free(stack);
                return false;
            }
        }
    }    
    bool valid = (top == -1);
    free(stack);
    return valid;
}