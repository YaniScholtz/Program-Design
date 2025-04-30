#include "IsDivisible.h"   //
#include "IsEvenOdd.h"     //
#include "IsGreater.h"     //
#include "IsPrimeNumber.h" //
#include "IsSmaller.h"     //
#include "TesterInterface.h"
#include "NumberTester.h"           //
#include "ValueDependantTester.h"   //
#include "ValueIndependantTester.h" //

#include <iostream>
using namespace std;

// int main()
// {
//   TesterInterface tester1(5);
//   // TesterInterface tester2(5) ;

//   IsDivisible *Myvar1 = new IsDivisible(2); // is passed in value divisible by 1
//   IsEvenOdd *Myvar2 = new IsEvenOdd;
//   IsGreater *Myvar3 = new IsGreater(1); // passed in value greater than value 5
//   IsPrimeNumber *Myvar4 = new IsPrimeNumber;

//   tester1.addTester(Myvar1);
//   tester1.addTester(Myvar2);
//   tester1.addTester(Myvar3);
//   tester1.addTester(Myvar4);
//   tester1.addTester(NULL);

//   cout << tester1.evaluate(2) << endl; //

//   int num = tester1.numberOfFailedTests(3); //
//   cout << num << endl;

//   int *array = tester1.failedTests(3) ;
//    for(int x=0 ; x<num ;x++)
//    {
//      cout << array[x] ;
//    }
//    cout << endl ;

//   cout << tester1.getCurrNumTesters() << endl;
//   cout << tester1.getMaxNumTesters() << endl;

//   bool my = tester1.removeTester(3);
//   cout << my << endl;

//   cout << tester1.getCurrNumTesters() << endl;

//   cout << endl
//        << "tester2" << endl;

//   //   // tester reference

//   TesterInterface tester2(tester1);

//   tester2.addTester(Myvar3);
//   cout << tester2.evaluate(2) << endl; //

//   int num1 = tester2.numberOfFailedTests(3); //
//   cout << num1 << endl;

//   int *array1 = tester2.failedTests(3) ;
//   for(int x=0 ; x<num ;x++)
//   {
//     cout << array1[x] ;
//   }
//   cout << endl ;

//   cout << tester2.getCurrNumTesters() << endl;
//   cout << tester2.getMaxNumTesters() << endl;

//   bool my1 = tester2.removeTester(3);
//   cout << my1 << endl;

//   cout << tester2.getCurrNumTesters() << endl;
//   // //lekker

//   TesterInterface *tester3 = new TesterInterface(tester2);
//   TesterInterface tester4(tester3);
//   cout << "lekker" << endl;

//   cout << endl
//        << "tester3" << endl;

//   cout << tester3->evaluate(2) << endl; //

//   int num2 = tester3->numberOfFailedTests(3); //
//   cout << num2 << endl;

//   int *array2 = tester3->failedTests(3) ;
//     for(int x=0 ; x<num ;x++)
//     {
//       cout << array2[x] ;
//     }
//     cout << endl ;

//   cout << tester3->getCurrNumTesters() << endl;
//   cout << tester3->getMaxNumTesters() << endl;

//   bool my2 = tester3->removeTester(3);
//   cout << my2 << endl;

//   cout << tester3->getCurrNumTesters() << endl;

//   cout << endl;

//   cout << "tester4" << endl;
//   //TesterInterface tester4(tester3) ;

//   tester4.addTester(Myvar3);
//   cout << tester4.evaluate(2) << endl; //

//   int num3 = tester4.numberOfFailedTests(3); //
//   cout << num3 << endl;

//    int *array3 = tester4.failedTests(3) ;
//    for(int x=0 ; x<num ;x++)
//    {
//      cout << array3[x] ;
//    }
//    cout << endl ;

//   cout << tester4.getCurrNumTesters() << endl;
//   cout << tester4.getMaxNumTesters() << endl;

//   bool my3 = tester4.removeTester(3);
//   cout << my3 << endl;

//   cout << tester4.getCurrNumTesters() << endl;

//   return 0;
// }

// // TesterInterface tester1(tester2) ;
// // TesterInterface tester2(tester1) ;

int main()
{


TesterInterface interface(6);
    cout<<"max: "<<interface.getMaxNumTesters()<<endl;
    interface.addTester(new IsEvenOdd());
    interface.addTester(new IsPrimeNumber());
    interface.addTester(new IsDivisible(3));
    interface.addTester(new IsGreater(10));
    interface.addTester(new IsSmaller(3));
    interface.addTester(new IsEvenOdd());
    //interface.removeTester(1);
    //interface.removeTester(2);
    cout<<"curr: "<<interface.getCurrNumTesters()<<endl;
    int *arr;
    arr = interface.failedTests(9);
    cout<<"nft: "<< interface.numberOfFailedTests(9)<<endl;
    for(int i = 0; i<interface.numberOfFailedTests(9); i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}