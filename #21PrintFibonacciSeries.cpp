//Write a program to print Fibonacci Series of 10.
#include <iostream>
#include <iomanip>
using namespace std ;
void printFibonacciSeriesOf (const unsigned short number){
    unsigned int prev2=0 , prev1=1;
    for(unsigned short i=0;i<number;i++){
        cout<<prev1<<" ";
        unsigned int oldPrev2=prev2;
        prev2=prev1;
        prev1+=oldPrev2;
   }
}
int main(){
    printFibonacciSeriesOf(10);
    return 0;
}
