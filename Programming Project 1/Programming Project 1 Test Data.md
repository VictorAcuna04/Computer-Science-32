# Programming Project 1 Test Data
There were 34 test cases.  The first eight cases is worth 2 points and all the rest were worth 3 points for a total correctness score of 94.  The remaining six points were awarded by your TA relating to your reporting document and code comments.  Each test case is represented by an assertion that must be true for you to pass that test.  To run the test cases:

- Remove the main routine from your main.cpp file.
-  Append the following text to the end of your main.cpp file, and build the resulting program.
-   For any test case you wish to try, run the program, providing as input the test number.

Test Data:  

    #include "Card.h"
    #include "Hand.h"
    #include "Enums.h"
    #include <iostream>
    #include <string>
    #include <cassert>
    using namespace std;
    
    void testone(int n)
    {
        Card c;
        
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
        
        Hand h( ace, ace );  
    
    
        switch (n)
        {
            case  1:
                    c = Card( Suit::HEARTS, Face::ACE );
                    assert( c.getSuit() == Suit::HEARTS );
                    assert( c.getFace() == Face::ACE );
                    assert( c.getValue( ) == 1 || c.getValue() == 11 );
                    break;
                
            case  2:
                    c = Card( Suit::CLUBS, Face::DEUCE );
                    assert( c.getSuit() == Suit::CLUBS );
                    assert( c.getFace() == Face::DEUCE );
                    assert( c.getValue( ) == 2 );
                    break;
                
            case  3:
                    c = Card( Suit::SPADES, Face::THREE );
                    assert( c.getSuit() == Suit::SPADES );
                    assert( c.getFace() == Face::THREE );
                    assert( c.getValue( ) == 3 );
                    break;
                              
            case  4:
                    c = Card( Suit::DIAMONDS, Face::FOUR );
                    assert( c.getSuit() == Suit::DIAMONDS );
                    assert( c.getFace() == Face::FOUR );
                    assert( c.getValue( ) == 4 );
                    break;
                
            case  5:
                    c = Card( Suit::DIAMONDS, Face::TEN );
                    assert( c.getSuit() == Suit::DIAMONDS );
                    assert( c.getFace() == Face::TEN );
                    assert( c.getValue( ) == 10 );
                    break;
                
            case  6:
                    c = Card( Suit::SPADES, Face::JACK );
                    assert( c.getSuit() == Suit::SPADES );
                    assert( c.getFace() == Face::JACK );
                    assert( c.getValue( ) == 10 );
                    break;
     
            case  7:
                    c = Card( Suit::SPADES, Face::QUEEN );
                    assert( c.getSuit() == Suit::SPADES );
                    assert( c.getFace() == Face::QUEEN );
                    assert( c.getValue( ) == 10 );
                    break;
            
            case  8:
                    h = Hand( two, two );
                    assert( h.getCard1().getValue( ) == 2 );
                    assert( h.getCard2().getValue( ) == 2 );
                    assert( h.getCard1().getSuit( ) == Suit::HEARTS );
                    assert( h.getCard1().getFace( ) == Face::DEUCE );
                    assert( h.getCard2().getFace( ) == Face::DEUCE );
                    assert( h.getCard2().getSuit( ) == Suit::HEARTS );
                    break;
                
            case  9:
                    h = Hand( two, two );
                    assert( h.evaluateHand(two) == Choice::SPLITHIT );
                    assert( h.evaluateHand(three) == Choice::SPLITHIT );
                    assert( h.evaluateHand(four) == Choice::SPLIT );
                    assert( h.evaluateHand(five) == Choice::SPLIT );
                    assert( h.evaluateHand(six) == Choice::SPLIT );
                    assert( h.evaluateHand(seven) == Choice::SPLIT );
                    assert( h.evaluateHand(eight) == Choice::HIT );
                    assert( h.evaluateHand(nine) == Choice::HIT );
                    assert( h.evaluateHand(ten) == Choice::HIT );
                    assert( h.evaluateHand(jack) == Choice::HIT );
                    assert( h.evaluateHand(queen) == Choice::HIT );
                    assert( h.evaluateHand(king) == Choice::HIT );
                    break;
                
             case  10:
                    h = Hand( three, three );
                    assert( h.evaluateHand(two) == Choice::SPLITHIT );
                    assert( h.evaluateHand(three) == Choice::SPLITHIT );
                    assert( h.evaluateHand(four) == Choice::SPLIT );
                    assert( h.evaluateHand(five) == Choice::SPLIT );
                    assert( h.evaluateHand(six) == Choice::SPLIT );
                    assert( h.evaluateHand(seven) == Choice::SPLIT );
                    assert( h.evaluateHand(eight) == Choice::HIT );
                    assert( h.evaluateHand(nine) == Choice::HIT );
                    assert( h.evaluateHand(ten) == Choice::HIT );
                    assert( h.evaluateHand(jack) == Choice::HIT );
                    assert( h.evaluateHand(queen) == Choice::HIT );
                    assert( h.evaluateHand(king) == Choice::HIT );
                    break;
     
              case 11:          
                    h = Hand( four, four );
                    assert( h.evaluateHand(two) == Choice::HIT );
                    assert( h.evaluateHand(three) == Choice::HIT );
                    assert( h.evaluateHand(four) == Choice::HIT );
                    assert( h.evaluateHand(five) == Choice::SPLITHIT );
                    assert( h.evaluateHand(six) == Choice::SPLITHIT );
                    assert( h.evaluateHand(seven) == Choice::HIT );
                    assert( h.evaluateHand(eight) == Choice::HIT );
                    assert( h.evaluateHand(nine) == Choice::HIT );
                    assert( h.evaluateHand(ten) == Choice::HIT );
                    assert( h.evaluateHand(jack) == Choice::HIT );
                    assert( h.evaluateHand(queen) == Choice::HIT );
                    assert( h.evaluateHand(king) == Choice::HIT );
                    break;
                                
              case 12:
                    h = Hand( five, five );
                    assert( h.evaluateHand(two) == Choice::DOUBLEHIT );
                    assert( h.evaluateHand(three) == Choice::DOUBLEHIT );
                    assert( h.evaluateHand(four) == Choice::DOUBLEHIT );
                    assert( h.evaluateHand(five) == Choice::DOUBLEHIT );
                    assert( h.evaluateHand(six) == Choice::DOUBLEHIT );
                    assert( h.evaluateHand(seven) == Choice::DOUBLEHIT );
                    assert( h.evaluateHand(eight) == Choice::DOUBLEHIT );
                    assert( h.evaluateHand(nine) == Choice::DOUBLEHIT );
                    assert( h.evaluateHand(ten) == Choice::HIT );
                    assert( h.evaluateHand(jack) == Choice::HIT );
                    assert( h.evaluateHand(queen) == Choice::HIT );
                    assert( h.evaluateHand(king) == Choice::HIT );
                    break;
     
              case 13:
                    h = Hand( six, six );
                    assert( h.evaluateHand(two) == Choice::SPLITHIT );
                    assert( h.evaluateHand(three) == Choice::SPLIT );
                    assert( h.evaluateHand(four) == Choice::SPLIT );
                    assert( h.evaluateHand(five) == Choice::SPLIT );
                    assert( h.evaluateHand(six) == Choice::SPLIT );
                    assert( h.evaluateHand(seven) == Choice::HIT );
                    assert( h.evaluateHand(eight) == Choice::HIT );
                    assert( h.evaluateHand(nine) == Choice::HIT );
                    assert( h.evaluateHand(ten) == Choice::HIT );
                    assert( h.evaluateHand(jack) == Choice::HIT );
                    assert( h.evaluateHand(queen) == Choice::HIT );
                    assert( h.evaluateHand(king) == Choice::HIT );
                    break;
                            
              case 14:
                    h = Hand( seven, seven );
                    assert( h.evaluateHand(two) == Choice::SPLIT );
                    assert( h.evaluateHand(three) == Choice::SPLIT );
                    assert( h.evaluateHand(four) == Choice::SPLIT );
                    assert( h.evaluateHand(five) == Choice::SPLIT );
                    assert( h.evaluateHand(six) == Choice::SPLIT );
                    assert( h.evaluateHand(seven) == Choice::SPLIT );
                    assert( h.evaluateHand(eight) == Choice::HIT );
                    assert( h.evaluateHand(nine) == Choice::HIT );
                    assert( h.evaluateHand(ten) == Choice::HIT );
                    assert( h.evaluateHand(jack) == Choice::HIT );
                    assert( h.evaluateHand(queen) == Choice::HIT );
                    assert( h.evaluateHand(king) == Choice::HIT );
                    break;
                           
              case 15:
                    h = Hand( eight, eight );
                    assert( h.evaluateHand(two) == Choice::SPLIT );
                    assert( h.evaluateHand(three) == Choice::SPLIT );
                    assert( h.evaluateHand(four) == Choice::SPLIT );
                    assert( h.evaluateHand(five) == Choice::SPLIT );
                    assert( h.evaluateHand(six) == Choice::SPLIT );
                    assert( h.evaluateHand(seven) == Choice::SPLIT );
                    assert( h.evaluateHand(eight) == Choice::SPLIT );
                    assert( h.evaluateHand(nine) == Choice::SPLIT );
                    assert( h.evaluateHand(ten) == Choice::SPLIT );
                    assert( h.evaluateHand(jack) == Choice::SPLIT );
                    assert( h.evaluateHand(queen) == Choice::SPLIT );
                    assert( h.evaluateHand(king) == Choice::SPLIT );
                    break;
    
              case 16:
                    h = Hand( nine, nine );
                    assert( h.evaluateHand(two) == Choice::SPLIT );
                    assert( h.evaluateHand(three) == Choice::SPLIT );
                    assert( h.evaluateHand(four) == Choice::SPLIT );
                    assert( h.evaluateHand(five) == Choice::SPLIT );
                    assert( h.evaluateHand(six) == Choice::SPLIT );
                    assert( h.evaluateHand(seven) == Choice::STAND );
                    assert( h.evaluateHand(eight) == Choice::SPLIT );
                    assert( h.evaluateHand(nine) == Choice::SPLIT );
                    assert( h.evaluateHand(ten) == Choice::STAND );
                    assert( h.evaluateHand(jack) == Choice::STAND );
                    assert( h.evaluateHand(queen) == Choice::STAND );
                    assert( h.evaluateHand(king) == Choice::STAND );
                    break; 
     
              case 17:
                    h = Hand( ace, ace );
                    assert( h.evaluateHand(two) == Choice::SPLIT );
                    assert( h.evaluateHand(three) == Choice::SPLIT );
                    assert( h.evaluateHand(four) == Choice::SPLIT );
                    assert( h.evaluateHand(five) == Choice::SPLIT );
                    assert( h.evaluateHand(six) == Choice::SPLIT );
                    assert( h.evaluateHand(seven) == Choice::SPLIT );
                    assert( h.evaluateHand(eight) == Choice::SPLIT );
                    assert( h.evaluateHand(nine) == Choice::SPLIT );
                    assert( h.evaluateHand(ten) == Choice::SPLIT );
                    assert( h.evaluateHand(jack) == Choice::SPLIT );
                    assert( h.evaluateHand(queen) == Choice::SPLIT );
                    assert( h.evaluateHand(king) == Choice::SPLIT );
                    break;
                        
              case 18:
                    h = Hand( ten, seven 
                    assert( h.evaluateHand(two) == Choice::STAND );
                    assert( h.evaluateHand(three) == Choice::STAND );
                    assert( h.evaluateHand(four) == Choice::STAND );
                    assert( h.evaluateHand(five) == Choice::STAND );
                    assert( h.evaluateHand(six) == Choice::STAND );
                    assert( h.evaluateHand(seven) == Choice::STAND );
                    assert( h.evaluateHand(eight) == Choice::STAND );
                    assert( h.evaluateHand(nine) == Choice::STAND );
                    assert( h.evaluateHand(ten) == Choice::STAND );
                    assert( h.evaluateHand(jack) == Choice::STAND );
                    assert( h.evaluateHand(queen) == Choice::STAND );
                    assert( h.evaluateHand(king) == Choice::STAND );
                    break;
                            
              case 19:
                    h = Hand( three, five );
                    assert( h.evaluateHand(two) == Choice::HIT );
                    assert( h.evaluateHand(three) == Choice::HIT );
                    assert( h.evaluateHand(four) == Choice::HIT );
                    assert( h.evaluateHand(five) == Choice::HIT );
                    assert( h.evaluateHand(six) == Choice::HIT );
                    assert( h.evaluateHand(seven) == Choice::HIT );
                    assert( h.evaluateHand(eight) == Choice::HIT );
                    assert( h.evaluateHand(nine) == Choice::HIT );
                    assert( h.evaluateHand(ten) == Choice::HIT );
                    assert( h.evaluateHand(jack) == Choice::HIT );
                    assert( h.evaluateHand(queen) == Choice::HIT );
                    assert( h.evaluateHand(king) == Choice::HIT );
                    break;
                
              case 20:
                    h = Hand( three, six );
                    assert( h.evaluateHand(two) == Choice::HIT );
                    assert( h.evaluateHand(three) == Choice::DOUBLEHIT );
                    assert( h.evaluateHand(four) == Choice::DOUBLEHIT );
                    assert( h.evaluateHand(five) == Choice::DOUBLEHIT );
                    assert( h.evaluateHand(six) == Choice::DOUBLEHIT );
                    assert( h.evaluateHand(seven) == Choice::HIT );
                    assert( h.evaluateHand(eight) == Choice::HIT );
                    assert( h.evaluateHand(nine) == Choice::HIT );
                    assert( h.evaluateHand(ten) == Choice::HIT );
                    assert( h.evaluateHand(jack) == Choice::HIT );
                    assert( h.evaluateHand(queen) == Choice::HIT );
                    assert( h.evaluateHand(king) == Choice::HIT );
                    break;
                
              case 21:
                    h = Hand( three, seven );
                    assert( h.evaluateHand(two) == Choice::DOUBLEHIT );
                    assert( h.evaluateHand(three) == Choice::DOUBLEHIT );
                    assert( h.evaluateHand(four) == Choice::DOUBLEHIT );
                    assert( h.evaluateHand(five) == Choice::DOUBLEHIT );
                    assert( h.evaluateHand(six) == Choice::DOUBLEHIT );
                    assert( h.evaluateHand(seven) == Choice::DOUBLEHIT );
                    assert( h.evaluateHand(eight) == Choice::DOUBLEHIT );
                    assert( h.evaluateHand(nine) == Choice::DOUBLEHIT );
                    assert( h.evaluateHand(ten) == Choice::HIT );
                    assert( h.evaluateHand(jack) == Choice::HIT );
                    assert( h.evaluateHand(queen) == Choice::HIT );
                    assert( h.evaluateHand(king) == Choice::HIT );
                    break;
     
              case 22:
                    h = Hand( three, eight );
                    assert( h.evaluateHand(two) == Choice::DOUBLEHIT );
                    assert( h.evaluateHand(three) == Choice::DOUBLEHIT );
                    assert( h.evaluateHand(four) == Choice::DOUBLEHIT );
                    assert( h.evaluateHand(five) == Choice::DOUBLEHIT );
                    assert( h.evaluateHand(six) == Choice::DOUBLEHIT );
                    assert( h.evaluateHand(seven) == Choice::DOUBLEHIT );
                    assert( h.evaluateHand(eight) == Choice::DOUBLEHIT );
                    assert( h.evaluateHand(nine) == Choice::DOUBLEHIT );
                    assert( h.evaluateHand(ten) == Choice::DOUBLEHIT );
                    assert( h.evaluateHand(jack) == Choice::DOUBLEHIT );
                    assert( h.evaluateHand(queen) == Choice::DOUBLEHIT );
                    assert( h.evaluateHand(king) == Choice::DOUBLEHIT );
                    break;
                
              case 23:
                    h = Hand( two, ten );
                    assert( h.evaluateHand(two) == Choice::HIT );
                    assert( h.evaluateHand(three) == Choice::HIT );
                    assert( h.evaluateHand(four) == Choice::STAND );
                    assert( h.evaluateHand(five) == Choice::STAND );
                    assert( h.evaluateHand(six) == Choice::STAND );
                    assert( h.evaluateHand(seven) == Choice::HIT );
                    assert( h.evaluateHand(eight) == Choice::HIT );
                    assert( h.evaluateHand(nine) == Choice::HIT );
                    assert( h.evaluateHand(ten) == Choice::HIT );
                    assert( h.evaluateHand(jack) == Choice::HIT );
                    assert( h.evaluateHand(queen) == Choice::HIT );
                    assert( h.evaluateHand(king) == Choice::HIT );
                    break;
                            
              case 24:
                    h = Hand( three, ten );
                    assert( h.evaluateHand(two) == Choice::STAND );
                    assert( h.evaluateHand(three) == Choice::STAND );
                    assert( h.evaluateHand(four) == Choice::STAND );
                    assert( h.evaluateHand(five) == Choice::STAND );
                    assert( h.evaluateHand(six) == Choice::STAND );
                    assert( h.evaluateHand(seven) == Choice::HIT );
                    assert( h.evaluateHand(eight) == Choice::HIT );
                    assert( h.evaluateHand(nine) == Choice::HIT );
                    assert( h.evaluateHand(ten) == Choice::HIT )
                    assert( h.evaluateHand(jack) == Choice::HIT );
                    assert( h.evaluateHand(queen) == Choice::HIT );
                    assert( h.evaluateHand(king) == Choice::HIT );
                    break;
                            
              case 25:
                    h = Hand( four, ten );
                    assert( h.evaluateHand(two) == Choice::STAND );
                    assert( h.evaluateHand(three) == Choice::STAND );
                    assert( h.evaluateHand(four) == Choice::STAND );
                    assert( h.evaluateHand(five) == Choice::STAND );
                    assert( h.evaluateHand(six) == Choice::STAND );
                    assert( h.evaluateHand(seven) == Choice::HIT );
                    assert( h.evaluateHand(eight) == Choice::HIT );
                    assert( h.evaluateHand(nine) == Choice::HIT );
                    assert( h.evaluateHand(ten) == Choice::HIT );
                    assert( h.evaluateHand(jack) == Choice::HIT );
                    assert( h.evaluateHand(queen) == Choice::HIT );
                    assert( h.evaluateHand(king) == Choice::HIT );
                    break;
            
              case 26:
                    h = Hand( five, ten );
                    assert( h.evaluateHand(two) == Choice::STAND );
                    assert( h.evaluateHand(three) == Choice::STAND );
                    assert( h.evaluateHand(four) == Choice::STAND );
                    assert( h.evaluateHand(five) == Choice::STAND );
                    assert( h.evaluateHand(six) == Choice::STAND );
                    assert( h.evaluateHand(seven) == Choice::HIT );
                    assert( h.evaluateHand(eight) == Choice::HIT );
                    assert( h.evaluateHand(nine) == Choice::HIT );
                    assert( h.evaluateHand(ten) == Choice::SURRENDERHIT );
                    assert( h.evaluateHand(jack) == Choice::SURRENDERHIT );
                    assert( h.evaluateHand(queen) == Choice::SURRENDERHIT );
                    assert( h.evaluateHand(king) == Choice::SURRENDERHIT );
                    break;
                
                
              case 27:
                    h = Hand( six, ten );
                    assert( h.evaluateHand(two) == Choice::STAND );
                    assert( h.evaluateHand(three) == Choice::STAND );
                    assert( h.evaluateHand(four) == Choice::STAND );
                    assert( h.evaluateHand(five) == Choice::STAND );
                    assert( h.evaluateHand(six) == Choice::STAND );
                    assert( h.evaluateHand(seven) == Choice::HIT );
                    assert( h.evaluateHand(eight) == Choice::HIT );
                    assert( h.evaluateHand(nine) == Choice::SURRENDERHIT );
                    assert( h.evaluateHand(ten) == Choice::SURRENDERHIT );
                    assert( h.evaluateHand(jack) == Choice::SURRENDERHIT );
                    assert( h.evaluateHand(queen) == Choice::SURRENDERHIT );
                    assert( h.evaluateHand(king) == Choice::SURRENDERHIT );
                    break;
                
               // ACE options
               case 28:
                     h = Hand( ace, two );
                     assert( h.evaluateHand(two) == Choice::HIT );
                     assert( h.evaluateHand(three) == Choice::HIT );
                     assert( h.evaluateHand(four) == Choice::HIT );
                     assert( h.evaluateHand(five) == Choice::DOUBLEHIT );
                     assert( h.evaluateHand(six) == Choice::DOUBLEHIT );
                     assert( h.evaluateHand(seven) == Choice::HIT );
                     assert( h.evaluateHand(eight) == Choice::HIT );
                     assert( h.evaluateHand(nine) == Choice::HIT );
                     assert( h.evaluateHand(ten) == Choice::HIT );
                     assert( h.evaluateHand(jack) == Choice::HIT );
                     assert( h.evaluateHand(queen) == Choice::HIT );
                     assert( h.evaluateHand(king) == Choice::HIT );
                     break;
                
               case 29:
                     h = Hand( ace, three );
                     assert( h.evaluateHand(two) == Choice::HIT );
                     assert( h.evaluateHand(three) == Choice::HIT );
                     assert( h.evaluateHand(four) == Choice::HIT );
                     assert( h.evaluateHand(five) == Choice::DOUBLEHIT );
                     assert( h.evaluateHand(six) == Choice::DOUBLEHIT );
                     assert( h.evaluateHand(seven) == Choice::HIT );
                     assert( h.evaluateHand(eight) == Choice::HIT );
                     assert( h.evaluateHand(nine) == Choice::HIT );
                     assert( h.evaluateHand(ten) == Choice::HIT );
                     assert( h.evaluateHand(jack) == Choice::HIT );
                     assert( h.evaluateHand(queen) == Choice::HIT );
                     assert( h.evaluateHand(king) == Choice::HIT );
                     break;
                
               case 30:
                     h = Hand( ace, four );
                     assert( h.evaluateHand(two) == Choice::HIT );
                     assert( h.evaluateHand(three) == Choice::HIT );
                     assert( h.evaluateHand(four) == Choice::DOUBLEHIT );
                     assert( h.evaluateHand(five) == Choice::DOUBLEHIT );
                     assert( h.evaluateHand(six) == Choice::DOUBLEHIT );
                     assert( h.evaluateHand(seven) == Choice::HIT );
                     assert( h.evaluateHand(eight) == Choice::HIT );
                     assert( h.evaluateHand(nine) == Choice::HIT );
                     assert( h.evaluateHand(ten) == Choice::HIT );
                     assert( h.evaluateHand(jack) == Choice::HIT );
                     assert( h.evaluateHand(queen) == Choice::HIT );
                     assert( h.evaluateHand(king) == Choice::HIT );
                     break;
                
               case 31:
                     h = Hand( ace, five );
                     assert( h.evaluateHand(two) == Choice::HIT );
                     assert( h.evaluateHand(three) == Choice::HIT );
                     assert( h.evaluateHand(four) == Choice::DOUBLEHIT );
                     assert( h.evaluateHand(five) == Choice::DOUBLEHIT );
                     assert( h.evaluateHand(six) == Choice::DOUBLEHIT );
                     assert( h.evaluateHand(seven) == Choice::HIT );
                     assert( h.evaluateHand(eight) == Choice::HIT );
                     assert( h.evaluateHand(nine) == Choice::HIT );
                     assert( h.evaluateHand(ten) == Choice::HIT );
                     assert( h.evaluateHand(jack) == Choice::HIT );
                     assert( h.evaluateHand(queen) == Choice::HIT );
                     assert( h.evaluateHand(king) == Choice::HIT );
                     break;
                
               case 32:
                     h = Hand( ace, six );
                     assert( h.evaluateHand(two) == Choice::HIT );
                     assert( h.evaluateHand(three) == Choice::DOUBLEHIT );
                     assert( h.evaluateHand(four) == Choice::DOUBLEHIT );
                     assert( h.evaluateHand(five) == Choice::DOUBLEHIT );
                     assert( h.evaluateHand(six) == Choice::DOUBLEHIT );
                     assert( h.evaluateHand(seven) == Choice::HIT );
                     assert( h.evaluateHand(eight) == Choice::HIT );
                     assert( h.evaluateHand(nine) == Choice::HIT );
                     assert( h.evaluateHand(ten) == Choice::HIT );
                     assert( h.evaluateHand(jack) == Choice::HIT );
                     assert( h.evaluateHand(queen) == Choice::HIT );
                     assert( h.evaluateHand(king) == Choice::HIT );
                     break;
                
               case 33:
                     h = Hand( ace, seven );
                     assert( h.evaluateHand(two) == Choice::STAND );
                     assert( h.evaluateHand(three) == Choice::DOUBLESTAND );
                     assert( h.evaluateHand(four) == Choice::DOUBLESTAND );
                     assert( h.evaluateHand(five) == Choice::DOUBLESTAND );
                     assert( h.evaluateHand(six) == Choice::DOUBLESTAND );
                     assert( h.evaluateHand(seven) == Choice::STAND );
                     assert( h.evaluateHand(eight) == Choice::STAND );
                     assert( h.evaluateHand(nine) == Choice::HIT );
                     assert( h.evaluateHand(ten) == Choice::HIT );
                     assert( h.evaluateHand(jack) == Choice::HIT );
                     assert( h.evaluateHand(queen) == Choice::HIT );
                     assert( h.evaluateHand(king) == Choice::HIT );
                     break;
                
               case 34:
                     h = Hand( ace, eight );
                     assert( h.evaluateHand(two) == Choice::STAND );
                     assert( h.evaluateHand(three) == Choice::STAND );
                     assert( h.evaluateHand(four) == Choice::STAND );
                     assert( h.evaluateHand(five) == Choice::STAND );
                     assert( h.evaluateHand(six) == Choice::STAND );
                     assert( h.evaluateHand(seven) == Choice::STAND );
                     assert( h.evaluateHand(eight) == Choice::STAND );
                     assert( h.evaluateHand(nine) == Choice::STAND );
                     assert( h.evaluateHand(ten) == Choice::STAND );
                     assert( h.evaluateHand(jack) == Choice::STAND );
                     assert( h.evaluateHand(queen) == Choice::STAND );
                     assert( h.evaluateHand(king) == Choice::STAND );
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
