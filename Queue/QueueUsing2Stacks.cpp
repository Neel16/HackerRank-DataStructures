#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    stack<int> s1;
    stack<int> s2;

    int number_of_queries = 0;
    int query = 0;
    int data;
    cin>> number_of_queries;

    while(number_of_queries != 0)
    {
        
        cin>>query;
        if(query == 1)
        {
            cin>>data;
            s1.push(data);
        }
        else
        {
            if(s2.empty())
            {
                while(!s1.empty())
                {
                s2.push(s1.top());
                s1.pop();
                }
            }
            if(!s2.empty())
            {
                if(query == 2)
                    s2.pop();
                if(query == 3)
                    cout<<s2.top()<<endl;
            }
        }
         number_of_queries--;
    }    
       
    

    return 0;
}
