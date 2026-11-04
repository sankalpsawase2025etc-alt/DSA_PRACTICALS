#include <stdio.h>
#include <string.h>
#include <math.h>

#define size 100

struct stack
{
    double s[size];
    int top;
} st;

void push(double val);
double pop();
double post(char exp[]);

int main()
{
    char exp[size];
    double result;

    printf("\nEnter any postfix expression: ");
    scanf("%s", exp);

    result = post(exp);

    printf("\nThe evaluated expression is %f\n", result);

    return 0;
}

double post(char exp[])
{
    char ch;
    double result, val, op1, op2;
    int i = 0;

    st.top = -1;

    while (exp[i] != '\0')
    {
        ch = exp[i];

        if (ch >= '0' && ch <= '9')
        {
            val = ch - '0';
            push(val);
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            if (st.top < 1)
            {
                printf("\nInvalid postfix expression!\n");
                return 0;
            }

            op2 = pop();
            op1 = pop();

            switch (ch)
            {
                case '+':
                    result = op1 + op2;
                    break;

                case '-':
                    result = op1 - op2;
                    break;

                case '*':
                    result = op1 * op2;
                    break;

                case '/':
                    if (op2 == 0)
                    {
                        printf("\nDivision by zero is not allowed!\n");
                        return 0;
                    }
                    result = op1 / op2;
                    break;

                case '^':
                    result = pow(op1, op2);
                    break;
            }

            push(result);
        }
        else
        {
            printf("\nInvalid character in expression!\n");
            return 0;
        }

        i++;
    }

    if (st.top != 0)
    {
        printf("\nInvalid postfix expression!\n");
        return 0;
    }

    return pop();
}

void push(double val)
{
    if (st.top >= size - 1)
    {
        printf("\nStack Full\n");
        return;
    }

    st.top++;
    st.s[st.top] = val;
}

double pop()
{
    double val;

    if (st.top == -1)
    {
        printf("\nStack is empty\n");
        return 0;
    }

    val = st.s[st.top];
    st.top--;

    return val;
}
