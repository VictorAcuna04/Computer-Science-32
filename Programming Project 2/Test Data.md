# Programming Project 2 Test Data
There were 20 test cases.  Each case is worth 5 points for a total correctness score of 100.  Each test case is represented by an assertion that must be true for you to pass that test.  To run the test cases:

- Remove the main routine from your main.cpp file.
- Append the following text to the end of your main.cpp file, and build the resulting program.
- For any test case you wish to try, run the program, providing as input the test number.
 
Test Data:

    #include <iostream>
    #include <string>
    #include <cassert>
    using namespace std;
    
    
    
    void testone(int n)
    {
     
        int array[ 5 ] = { 2, 4, 8, 10, 12 };
     
        
        switch (n)
        {
             case  1:
                    assert( modulo(101, 10) == 1 );
                    break;
                
             case  2:
                    assert( modulo(100, 10) == 0 );
                    break;
                
             case  3:
                    assert( modulo(99, 8)  == 3 );
                    break;
                 
                 
             case  4:
                    assert( modulo( 0, 12 ) == 0 );
                    break;
                
             case  5:
                    assert( modulo( 10, 10) == 0 );
                    break;
              
             case  6:
                    assert( occurrences(18838, 8) == 3 );
                    break;
    
             case  7:
                    assert( occurrences(18838, 3) == 1 );
                    break;
            
             case  8:
                    assert( occurrences(18838, 1) == 1 );
                    break;
                            
             case  9:
                    assert( occurrences(18838, 5) == 0 );
                    break;
                            
             case  10:
                    assert( occurrences(0, 0)  == 0 || occurrences(0,0) == 1 );
                    break;
                
             case 11:          
                    assert( lucky7s("goodbye") == "go77odbye" );
                    break;
                                
             case 12:
                    assert( lucky7s("yyuu")    == "y77yu77u" );
                    break;
    
             case 13:
                    assert( lucky7s("aaaa")    == "a77a77a77a" );
                    break;
                            
             case 14:
                    assert( lucky7s("")        == "" );
                    break;
                           
             case 15:
                    assert( lucky7s("abcdefg")        == "abcdefg" );
                    break;
                
             case 16:
                    assert( combinations(array, 5, 10) );
                    break;
                 
             case 17:
                    assert( combinations(array, 5, 6) );
                    break;
     
             case 18:
                    assert( combinations(array, 5, 11) == false );
                    break;
                        
             case 19:
                    assert( combinations(array, 5, 21) == false  );
                    break;
        
             case 20:
                    assert( combinations(array, 0, 0)  );
                    break;
    
    
             default:
                    cout << "Bad argument" ;
                    break;
        } 
    } 
    
    int main() 
    {
        cout << "Enter test number: ";
        int n;
        cin >> n;
        testone(n);
        cout << "Passed!" << endl; 
        return( 0 ); 
    }
