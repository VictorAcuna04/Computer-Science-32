#include "Hand.h"

namespace cs32
{

Hand::Hand( Card card1, Card card2 ) : mCard1( card1 ), mCard2( card2 )
{

}

Card Hand::getCard1() const
{
    return( mCard1 );
}

Card Hand::getCard2() const
{
    return( mCard2 );
}

Choice Hand::evaluateHand( Card dealerCard ) const
{
    // by default HIT
    Choice c = Choice::HIT;

    int handvalue = mCard1.getValue() + mCard2.getValue();
    bool pair = isPair();
    bool soft = isSoft();

    if (pair)
    {
        // by default SPLIT
        c = Choice::SPLIT;

        if (dealerCard.getValue() == 7 ||
            dealerCard.getValue() == 8 ||
            dealerCard.getValue() == 9 ||
            dealerCard.getValue() == 10 ||
            dealerCard.getValue() == 1)
        {
            c = Choice::HIT;
            // double 2s 3s 7s when dealerCard is seven
            if ((handvalue == 4 || handvalue == 6 || handvalue == 14) && dealerCard.getValue() == 7)
            {
                c = Choice::SPLIT;
            }
            else if (handvalue == 16)
            {
                c = Choice::SPLIT;
            }
        }
        // double 5s
        if (handvalue == 10)
        {
            // by default, DOUBLEHIT
            c = Choice::DOUBLEHIT;
            if (dealerCard.getValue() == 10 || dealerCard.getValue() == 1)
            {
                c = Choice::HIT;
            }
        }

        if (handvalue == 2)
        {
            c = Choice::SPLIT;
        }

        // double 10s
        if (handvalue == 20)
        {
            c = Choice::SPLIT;
        }

        // double 9s
        if (handvalue == 18)
        {
            c = Choice::SPLIT;
            if (dealerCard.getValue() == 7 || dealerCard.getValue() == 10 || dealerCard.getValue() == 1)
            {
                c = Choice::STAND;
            }
        }

        // double 2s 3s
        if (handvalue == 4 || handvalue == 6)
        {
            if (dealerCard.getValue() == 2 || dealerCard.getValue() == 3)
            {
                c = Choice::SPLITHIT;
            }
        }

        // double 6s
        if (handvalue == 12)
        {
            if (dealerCard.getValue() == 2)
            {
                c = Choice::SPLITHIT;
            }
        }

        // double 4s
        if (handvalue == 8)
        {
            if (dealerCard.getValue() == 5 || dealerCard.getValue() == 6)
            {
                c = Choice::SPLITHIT;
            }
            else if (dealerCard.getValue() == 2 || dealerCard.getValue() == 3 || dealerCard.getValue() == 4)
            {
                c = Choice::HIT;
            }
        }
    }
    else if (soft)
    {
        // by default, HIT
        c = Choice::HIT;

        if (handvalue == 9 || handvalue == 10 || handvalue == 11)
        {
            c = Choice::STAND;
        }
        // A+7
        else if (handvalue == 8)
        {
            c = Choice::STAND;
            if (dealerCard.getValue() == 3 || dealerCard.getValue() == 4 || dealerCard.getValue() == 5 || dealerCard.getValue() == 6)
            {
                c = Choice::DOUBLESTAND;
            }
            else if (dealerCard.getValue() == 9 ||
                     dealerCard.getValue() == 10 ||
                     dealerCard.getValue() == 1)
            {
                c = Choice::HIT;
            }
        }
        else if (dealerCard.getValue() == 5 || dealerCard.getValue() == 6)
        {
            c = Choice::DOUBLEHIT;
        }
        else if (dealerCard.getValue() == 4 && (handvalue == 5 || handvalue == 6 || handvalue == 7))
        {
            c = Choice::DOUBLEHIT;
        }
        else if (dealerCard.getValue() == 3 && handvalue == 7)
        {
            c = Choice::DOUBLEHIT;
        }
    }
    else if (handvalue == 17 || handvalue == 18 || handvalue == 19 || handvalue == 20)
    {
        c = Choice::STAND;
    }
    else if (handvalue == 11)
    {
        c = Choice::DOUBLEHIT;
    }
    else if (handvalue == 10)
    {
        if (dealerCard.getValue() == 10 || dealerCard.getValue() == 1)
        {
            c = Choice::HIT;
        }
        else
        {
            c = Choice::DOUBLEHIT;
        }
    }
    else if (handvalue == 9)
    {
        if (dealerCard.getValue() == 2 || dealerCard.getValue() == 7 || dealerCard.getValue() == 8 || dealerCard.getValue() == 9 ||dealerCard.getValue() == 10 || dealerCard.getValue() == 1)
        {
            c = Choice::HIT;
        }
        else
        {
            c = Choice::DOUBLEHIT;
        }
    }
    else if (handvalue == 16)
    {
        if (dealerCard.getValue() == 7 || dealerCard.getValue() == 8)
        {
            c = Choice::HIT;
        }
        else if (dealerCard.getValue() == 9 ||dealerCard.getValue() == 10 || dealerCard.getValue() == 1)
        {
            c = Choice::SURRENDERHIT;
        }
        else
        {
            c = Choice::STAND;
        }
    }
    else if (handvalue == 13 || handvalue == 14 || handvalue == 15)
    {
        c = Choice::HIT;

        if (dealerCard.getValue() == 2 || dealerCard.getValue() == 3 || dealerCard.getValue() == 4 || dealerCard.getValue() == 5 || dealerCard.getValue() == 6)
        {
            c = Choice::STAND;
        }
        else if (dealerCard.getValue() == 10 && handvalue == 15)
        {
            c = Choice::SURRENDERHIT;
        }
    }
    else if (handvalue == 12)
    {
        c = Choice::HIT;
        if (dealerCard.getValue() == 4 || dealerCard.getValue() == 5 || dealerCard.getValue() == 6)
        {
            c = Choice::STAND;
        }
    }
    
    return( c );

}

bool Hand::isPair() const
{
    return( mCard1.getFace() == mCard2.getFace() );
}

bool Hand::isSoft() const
{
    return( mCard1.getFace() == Face::ACE || mCard2.getFace() == Face::ACE );
}


}
