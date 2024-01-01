# Your Task

Your assignment is to complete this C++ program skeleton (XCodeLinks to an external site. VS2022Links to an external site. VS2019Links to an external site.) to produce a program that implements the described behavior. (We've indicated where you have work to do by comments containing the text TODO.  Please remove those comments as you finish each thing you have to do.)  The program skeleton you are to flesh out provides alot of code but you will be focusing your attention on the classes: Card and Hand.  You will need to complete code for the Card and Hand classes.  Details of the interface to all of these classes are in the program skeleton, but here are the essential responsibilities of each enumeration and class:  

The Suit enumeration is defined in the file Enums.h and is shown below:
![image](https://github.com/VictorAcuna04/Computer-Science-32/assets/112352978/6de19667-570e-4f3a-a7db-b6ef342ff126)

This enumeration defines a value for every suit in a standard deck of playing cards.  This enumeration is fully defined and needs no changes to be made by CS32 students.

The Face enumeration is defined in the file Enums.h and is shown below:

![image](https://github.com/VictorAcuna04/Computer-Science-32/assets/112352978/4646acbe-2ab9-4a6e-92ba-07d953ab4284)

This enumeration defines a value for every face value in a standard deck of playing cards.  Ace represents a one, Deuce represents a two, Three represents a three and so on.  This enumeration is fully defined and needs no changes to be made by CS32 students.

The Choice enumeration is defined in the file Enums.h and is shown below:

![image](https://github.com/VictorAcuna04/Computer-Science-32/assets/112352978/236a6812-252e-40ab-8270-c0f58e68c2a4)

This enumeration defines a value for every possible move in the strategy card shown earlier.  This enumeration is fully defined and needs no changes to be made by CS32 students.

The Card class represents a single playing card from a standard deck of fifty-two playing cards used to play BlackJack.  It is defined in Card.h and Card.cpp and is shown below:

![image](https://github.com/VictorAcuna04/Computer-Science-32/assets/112352978/e41864fb-906b-45f0-a503-1d9721ee64d1)

Each Card holds a Suit and Face value.  The bolded pieces are operations that CS 32 students need to complete.  The getter operations are fully implemented in the skeleton code and need no changes to be made by CS32 students.  The two setter operations along with the getValue operation need to be implemented by CS 32 students.  // TO DO comments further clarify these operations.

The Hand class represents an opening BlackJack hand of two cards.  It is defined in Hand.h and Hand.cpp and is shown below:

![image](https://github.com/VictorAcuna04/Computer-Science-32/assets/112352978/f619c3e2-5a1d-40db-a879-95b0a6c66f17)

Each Hand holds two Cards with member variables named mCard1 and mCard2.  The bolded pieces are operations that CS 32 students need to complete.  The getter operations are fully implemented in the skeleton code and need no changes to be made by CS32 students.  The three bolded operations shown above need to be implemented by CS 32 students.  // TO DO comments further clarify these operations.  The isPair operation should return true when both of the Hand's cards are matching values, say, two Aces or two Threes or two Jacks.  The isSoft operation should return true when one or both of the Hand's cards are Aces.  The evaluateHand operation should implement the strategy table shown above based on the Hand's two Cards and the supplied dealerCard.

You are free to create additional public and private methods and data members as you see fit.  However, the test cases will only be driving the public methods of the classes provided in the skeleton code originally.

The source files you turn in will be these classes and a main routine. You can have the main routine do whatever you want, because we will rename it to something harmless, never call it, and append our own main routine to your file. Our main routine will thoroughly test your functions. You'll probably want your main routine to do the same. If you wish, you may write functions in addition to those required here. We will not directly call any such additional functions. If you wish, your implementation of a function required here may call other functions required here.

The program you turn in must build successfully, and during execution, no method may read anything from cin. If you want to print things out for debugging purposes, write to cerr instead of cout. When we test your program, we will cause everything written to cerr to be discarded instead — we will never see that output, so you may leave those debugging output statements in your program if you wish.

# Programming Guidelines
Your program must not use any function templates from the algorithms portion of the Standard C++ library. If you don't know what the previous sentence is talking about, you have nothing to worry about. 

Your implementations must not use any global variables declared outside main( ).

Your program must build successfully under two of the following: Visual Studio, XCode or g32.

The correctness of your program must not depend on undefined program behavior. 

As an example, here's a very incomplete set of tests for this project.  Please use it to ensure you are spelling everything correctly and understand the rough contours of the assignment.  I hope this gives you some ideas....  

    #include <iostream>
    #include <string>
    #include <cassert>
    #include "Hand.h"
    #include "Card.h"

    int main()
    {
           using namespace std;
           using namespace cs32;

           // test code for Card
           
           Card c( Suit::CLUBS, Face::DEUCE );
           assert( c.getSuit() == Suit::CLUBS );
           assert( c.getFace() == Face::DEUCE );
           assert( c.getValue( ) == 2 );

           Card d( Suit::SPADES, Face::QUEEN );
           assert( d.getSuit() == Suit::SPADES );
           assert( d.getFace() == Face::QUEEN );
           assert( d.getValue( ) == 10 );

           // test code for Hand

           Card ace( Suit::CLUBS, Face::ACE );
           Card two( Suit::HEARTS, Face::DEUCE );
           Card three( Suit::DIAMONDS, Face::THREE );
           Card four( Suit::SPADES, Face::FOUR );
           Card five( Suit::CLUBS, Face::FIVE );
           Card six( Suit::HEARTS, Face::SIX );
           Card seven( Suit::DIAMONDS, Face::SEVEN );
           Card eight( Suit::SPADES, Face::EIGHT );
           Card nine( Suit::CLUBS, Face::NINE );
           Card ten( Suit::HEARTS, Face::TEN );
           Card jack( Suit::DIAMONDS, Face::JACK );
           Card queen( Suit::CLUBS, Face::QUEEN );
           Card king( Suit::SPADES, Face::KING );

           Hand h( c, d );
           assert( h.evaluateHand(two) == Choice::HIT );
           assert( h.evaluateHand(three) == Choice::HIT );
           assert( h.evaluateHand(four) == Choice::STAND );
           assert( h.evaluateHand(five) == Choice::STAND );
           assert( h.isPair( ) == false );
           assert( h.isSoft( ) == false );

           h = Hand( ace, seven );
           assert( h.evaluateHand(five) == Choice::DOUBLESTAND );
           assert( h.evaluateHand(six) == Choice::DOUBLESTAND );
           assert( h.evaluateHand(seven) == Choice::STAND );
           assert( h.evaluateHand(eight) == Choice::STAND );
           assert( h.evaluateHand(nine) == Choice::HIT );   
           assert( h.isPair( ) == false );
           assert( h.isSoft( ) == true );                

           h = Hand( five, five );
           assert( h.evaluateHand(two) == Choice::DOUBLEHIT );
           assert( h.evaluateHand(three) == Choice::DOUBLEHIT );
           assert( h.evaluateHand(four) == Choice::DOUBLEHIT );
           assert( h.isPair( ) == true );
           assert( h.isSoft( ) == false ); 

           cout << "all tests passed!" << endl;
           return( 0 );
       }  

# What To Submit
What you will turn in for this assignment is a zip file containing the following 7 files and nothing more:

The file named Enums.h which is part of the supplied skeleton and does not need to be changed at all as well as the files named  Card.h  and Card.cpp  that implement the Card class diagrammed above, the files named  Hand.h  and  Hand.cpp  that implement the Hand class diagrammed above and the file named main.cpp which will hold your main program. Your source code should have helpful comments that explain any non-obvious code.

A file named report.doc or report.docx (in Microsoft Word format) or report.txt (an ordinary text file) that contains in addition your name and your UCLA Id Number:

A brief description of notable obstacles you overcame.

A list of the test data that could be used to thoroughly test your functions, along with the reason for each test. You must note which test cases your program does not handle correctly. (This could happen if you didn't have time to write a complete solution, or if you ran out of time while still debugging a supposedly complete solution.) Notice that most of this portion of your report can be written just after you read the requirements in this specification, before you even start designing your program.

How nice! Your report this time doesn't have to contain any design documentation.

To create this zip file, begin by creating a folder.  The folder must be named with your UCLA Id number.  Inside this folder, deposit the three desired files.  Then zip this folder to create a single file.  For example, if my UCLA Id number was 800012345, I would create a folder named 800012345 and then have a zip file to upload named 800012345.zip

