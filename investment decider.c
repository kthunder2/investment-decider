#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 3

double coin_interest(double, int, int);
void investment_decider(double, double);

int main()
{
    int i, j; //numbers used in for loops
    double a;
    int years, interest_rate;
    char yes_no;
    int x; //for random number generator
    double arr[N], invested[N];
    srand(time(NULL));

    do
    {
        for (i=1; i<=N; i++)
        {
            do
            {
                printf("\nEnter the coins for account[%d]:", i);
                scanf("%lf", &a);
                fflush(stdin);
                arr[i-1]=a;
                if(a>100 || a<10)
                {
                    printf("\nError! Enter a valu between 10-100!\n");
                }
            }
            while(a>100 || a<10);

        }
        years= 1 + (int) rand() % 6;
        printf("\nNumber of years = %d", years);

        interest_rate=2 + (int) rand() % 6;

        printf("\nInterest rate is %d percent", interest_rate);

        for(j=1; j<=N; j++)
        {
            invested[j-1]=coin_interest(arr[j-1], interest_rate, years); //used array to save values of invested amount at the end, to use it in the next function
            investment_decider(arr[j-1], invested[j-1]);
        }


        printf("\nDo you want to try again?");
        scanf("%c", &yes_no);
        fflush(stdin);

        if(yes_no=='N' || yes_no=='n')
        {
            printf("\nByee!");
        }


    }
    while(yes_no!='n' && yes_no!='N');

    return 0;

}

double coin_interest(double arr, int interest_rate, int years)
{
    double investment_return;
    if(years=1)
    {
        investment_return=arr;
    }
    else if(years>1)
    {
        investment_return= coin_interest(arr, interest_rate, years-1)+(interest_rate*coin_interest(arr, interest_rate, years-1));
    }

    return investment_return;
}

void investment_decider(double arr, double invested)
{
    int counter=1;
    if((invested-arr)<=(2.0/10.0*arr))
    {
        printf("\nAccount [%d]: Don't invest", counter);
    }
    else if((invested-arr)>(0.2*arr) && (invested-arr)<=(0.5*arr))
    {
        printf("\nAccount [%d]: Invest", counter);
    }
    else
    {
        printf("\nAccount [%d]: Definitely Invest", counter);
    }
    counter++;
}
