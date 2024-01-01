#include "Card.h"
#include "Enums.h"

namespace cs32
{

class Hand
{

public:
    Hand( Card card1, Card card2 );
    
    Card getCard1() const;
    Card getCard2() const;
    
    Choice evaluateHand( Card dealerCard ) const;

    bool isPair() const;
    bool isSoft() const;

private:
    Card mCard1, mCard2;
};

}
