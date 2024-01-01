# Overview Of This Assignment
Recursion involves taking a problem and solving it in terms of itself - be it in smaller versions of itself.  Based on certain base cases, the recursive calls break a problem down into smaller pieces and then accumulate an answer as the smaller problems each get solved.  Recursive programming skills are very important in later data structures we will learn in CS 32.

# Your Task
Your assignment is to implement the following four functions which are described below.  Please also see the sample main( ) provided below that offers some ideas on how to test each of these function.  

int modulo( unsigned int m, unsigned int n );

- Returns the remainder of two positive integers, m and n.  The scorer will never send your code an n value of zero but you maybe sent an m value of zero.

int occurrences( int number, int d );

- Returns the number of occurrences of the value d found in the parameter number.  You can safely assume that the value of d will be single digit number.  For occurrences, either parameter may be 0.  Be careful not to / or % by zero as that won't work.  Instead, a zero value should be one of your base cases that stops the recursive function calls.  You can assume both parameters will be zero or more.  As for occurrences(0, 0), the scorer will accept the value either zero or one as the answer.

string lucky7s( string s );

- Returns a string where repeated matching characters in the value s get separated by the string "77".  You can assume that the input string s will not have any 7's in it.

bool combinations( int array[ ], int size, int target ); 

- Returns true if the total of any combination of elements in the array parameter equals the target value.  In determining combinations, each element value should only be used once.  For array of {2, 3, 4}, you could build target values of only 2, 3, 4, 5 (2+3), 6 (2+4), 7 (3+4) or 9 (2+3+4) only and not 12 (3+3+3+3) or 16 (4+4+4+4).


The source file you turn in should declare and implement these four function and also include a buildable main routine. You can have your main routine do whatever you want, because we will rename it to something harmless, never call it, and append our own main routine to your file. Our testing main routine will thoroughly test your functions. You'll probably want your main routine to do the same. If you wish, you may write functions in addition to those required here. We will not directly call any such additional functions. If you wish, your implementation of a function required here may call other functions required here.

The program you turn in must build successfully, and during execution, no function may read anything from cin. If you want to print things out for debugging purposes, write to cerr instead of cout. When we test your program, we will cause everything written to cerr to be discarded instead — we will never see that output, so you may leave those debugging output statements in your program if you wish.

# Programming Guidelines
Your program must not use any function templates from the algorithms portion of the Standard C++ library. If you don't know what the previous sentence is talking about, you have nothing to worry about. 

Your implementations must not use any global variables declared outside main( ).

Your solution must not use the keywords while, for, or goto. You must not use global variables or variables declared with the keyword static, and you must not modify the function parameter lists. You must not use any references or pointers as parameters except for the parameters representing arrays. For the string functions, you may only use the substr(), size() and length() functions, as I want you to become familiar with utilizing recursion on parts of the overall string provided to your function.  I would like to discourage you using helper functions for this assignment, as it can be solved without it.

Your program must build successfully under two of the following: Visual Studio, XCode or g32.

The correctness of your program must not depend on undefined program behavior. 

As an example, here's a very incomplete set of tests for this project.  Please use it to ensure you are spelling everything correctly and understand the rough contours of the assignment.  I hope this gives you some ideas....  

    #include <iostream>
    #include <string>
    #include <cassert>

    int main()
    {
           using namespace std;

           // test code
           assert( modulo( 100, 10 ) == 0 );
           assert( modulo( 1, 13 ) == 1 );
           assert( modulo( 12, 5 ) == 2 );
           assert( modulo( 33, 6 ) == 3 );

           assert( occurrences( 567, 2 ) ==  0 );
           assert( occurrences( 128874, 2 ) == 1 );
           assert( occurrences( 212121, 2 ) == 3 );

           assert( lucky7s( "cs32" ) == "cs32" );
           assert( lucky7s( "Apple Baseball" ) == "Ap77ple Basebal77l" );
           assert( lucky7s( "abbba" ) == "ab77b77ba" );

           int array[ 5 ] = { 2, 4, 6, 8, 10 };
           assert( combinations( array, 5, 10 ) == true );
           assert( combinations( array, 5, 18 ) == true );
           assert( combinations( array, 5, 15 ) == false );

           int other[ 5 ] = { 10, 8, 2, 6, 4 };
           assert( combinations( other, 5, 10 ) == true );
           assert( combinations( other, 5, 18 ) == true );
           assert( combinations( ohter, 5, 15 ) == false );

           cout << "all tests passed!" << endl;
           return( 0 );
       }  

# What To Submit
What you will turn in for this assignment is a zip file containing the following 2 files and nothing more:

The file named project2.cpp declares and implements each of the assigned functions and also holds a buildable main( ) program. Your source code should have helpful comments that explain any non-obvious code.

A file named report.doc or report.docx (in Microsoft Word format) or report.txt (an ordinary text file) that contains in addition your name and your UCLA Id Number:

A brief description of notable obstacles you overcame.

A list of the test data that could be used to thoroughly test your functions, along with the reason for each test. You must note which test cases your program does not handle correctly. (This could happen if you didn't have time to write a complete solution, or if you ran out of time while still debugging a supposedly complete solution.) Notice that most of this portion of your report can be written just after you read the requirements in this specification, before you even start designing your program.


How nice! Your report this time doesn't have to contain any design documentation.

To create this zip file, begin by creating a folder.  The folder must be named with your UCLA Id number.  Inside this folder, deposit the three desired files.  Then zip this folder to create a single file.  For example, if my UCLA Id number was 800012345, I would create a folder named 800012345 and then have a zip file to upload named 800012345.zip
