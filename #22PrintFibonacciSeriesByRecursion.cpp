//Write a program to print Fibonacci Series of 10 by Recursion.
#include <iostream>
#include <iomanip>
using namespace std ;
void printFibonacciSeriesOf (const unsigned short number){

        if (number>0){
        static unsigned int prev2=0 , prev1=1;
        cout<<prev1<<" ";
        unsigned int oldPrev2=prev2;
        prev2=prev1;
        prev1+=oldPrev2;
        printFibonacciSeriesOf(number-1);

        }
        

}
void printFibonacciSeriesOf (const unsigned short number,int startPrev2, int startPrev1){

        if (number>0){
        cout<<startPrev1<<" ";
        printFibonacciSeriesOf(number-1,startPrev1,(startPrev1+startPrev2));
        }
        
}
int main(){
    printFibonacciSeriesOf(10);
    cout<<endl;
    printFibonacciSeriesOf(10,0,1);
    return 0;
}
