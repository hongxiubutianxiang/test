#include <stdio.h>
#define N 10000 + 10
char s[N];

int main()
{
    int n;
    char c, *p;
    while (scanf("%d\n", &n) != EOF)
    {
        while (n--)
        {
            *s = getchar();
            p = s + 1;
            while ((c = getchar()) != '\n')
            {
                if (*(p - 1) == c - 1 || *(p - 1) == c - 2)
                    p--;
                else
                    *p++ = c;
            }
            if (p == s)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
}