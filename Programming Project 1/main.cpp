#include <iostream>
#include <cassert>
#include "Enums.h"
#include "Card.h"
#include "Hand.h"

using namespace std;
using namespace cs32;

int main() {
    Card c;

    
    
    Card c1;
    Card c2;
    Hand h( c1, c2);
    Card ace( Suit::CLUBS, Face::ACE );
    Card two( Suit::CLUBS, Face::DEUCE );
    Card three( Suit::CLUBS, Face::THREE );
    Card four( Suit::CLUBS, Face::FOUR );
    Card five( Suit::CLUBS, Face::FIVE );
    Card six( Suit::CLUBS, Face::SIX );
    Card seven( Suit::CLUBS, Face::SEVEN );
    Card eight( Suit::CLUBS, Face::EIGHT );
    Card nine( Suit::CLUBS, Face::NINE );
    Card ten( Suit::CLUBS, Face::TEN );
    Card jack( Suit::CLUBS, Face::JACK );
    Card queen( Suit::CLUBS, Face::QUEEN );
    Card king( Suit::CLUBS, Face::KING );
    // two aces...
    assert( h.evaluateHand(two) == Choice::SPLIT );
    
    Hand h1( two, two );
    assert( h1.evaluateHand(two) == Choice::SPLITHIT );
    assert( h1.evaluateHand(three) == Choice::SPLITHIT );
    assert( h1.evaluateHand(four) == Choice::SPLIT );
    assert( h1.evaluateHand(five) == Choice::SPLIT );
    assert( h1.evaluateHand(six) == Choice::SPLIT );
    assert( h1.evaluateHand(seven) == Choice::SPLIT );
    assert( h1.evaluateHand(eight) == Choice::HIT );
    assert( h1.evaluateHand(nine) == Choice::HIT );
    assert( h1.evaluateHand(ten) == Choice::HIT );
    assert( h1.evaluateHand(jack) == Choice::HIT );
    assert( h1.evaluateHand(queen) == Choice::HIT );
    assert( h1.evaluateHand(king) == Choice::HIT );
    
    return( 0 );
}
