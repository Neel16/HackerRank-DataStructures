#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long stack[100000];

    int number_of_queries =0;
    int querytype = 0;
    long number_to_insert = 0;
    long top_of_stack = -1;
    long max_stack = 0;
    long iterator = 0;

    scanf("%d",&number_of_queries);
    //cin<<number_of_queries;

    while(number_of_queries > 0)
    {
        scanf("%d", &querytype);

        switch(querytype)
        {
            case 1: 
                    scanf("%ld", &number_to_insert);
                    if(number_to_insert > max_stack)
                        max_stack=number_to_insert;
                    stack[++top_of_stack]=number_to_insert;
                    break;
            case 2: 
                    if(stack[top_of_stack] == max_stack)
                    {
                        top_of_stack--;

                        max_stack = 0;
                        iterator = top_of_stack;
                        while(iterator > -1)
                        {
                            max_stack = stack[iterator] > max_stack ? stack[iterator]: max_stack;
                            iterator--;
                        }
                    }
                    else
                     top_of_stack--;
                    break;
            case 3: 
                    printf("%ld\n", max_stack);
                    break;
        }
        number_of_queries--;
    }

    return 0;
}
