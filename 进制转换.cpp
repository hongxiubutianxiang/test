#include<stdio.h>
int tranToDecimal(unsigned number,unsigned base){

    int sum = 0;

    int k = 1;

    while (number) {

        //求子项值

        int remainder = number % 10;

        //不能大于进制

        if (remainder >= base) {

            return -1;

        }

        remainder *= k;

        sum += remainder;

        

        //处理子项值需要的参数

        number /= 10;

        k *= base;

    }

    

    return sum;

}
int main(int argc, const char * argv[]) {

    // insert code here...

    int n;

scanf("%d",&n);

    

    for (int i = 0; i < n; i++) {

        unsigned p;

        unsigned q;

        unsigned r;

        bool hasBase = false;

        

        scanf("%d %d %d",&p,&q,&r);

        for (int i = 2; i <= 16; i++) {

            unsigned p10 = tranToDecimal(p, i);

            unsigned q10 = tranToDecimal(q, i);

            unsigned r10 = tranToDecimal(r, i);

            

            if (p10 != -1 && q10 != -1 && r10 != -1 && p10 * q10 == r10){

                hasBase = true;

                printf("%d\n",i);

                break;

            };

        }

        

        if (!hasBase) {

            printf("0\n");

        }

    }

    

    return 0;

}
