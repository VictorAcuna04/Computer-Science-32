std::string List::min() const
{
    // by default, result is the empty string for when no items are on the list
    std::string result;
    if (!isEmpty())
    {
        // force a starting value for result
        result = head->getElement();
    }
    // walk the list
    ListNode * temp = head;
    while( temp != nullptr )
    {
        // found a smaller one
        if (result > temp->getElement())
            result = temp->getElement();
        temp = temp->getNext();
    }
    return( result );
}

void   List::removeAllBiggerThan( const std::string& data )
{
    ListNode * node = head;
    ListNode * priornode = nullptr;
    while( node != nullptr )
    {
            // is it one we want to remove?
            if (node->getElement() > data)
            {
                // skip around it
                if (priornode != nullptr)
                    priornode->setNext( node->getNext( ) );
                else
                {
                    // if the priornode is null, then we have to adjust the head instead
                    head = node->getNext();
                }
                
                delete(node);
                
                // reestablish node value for next iteration
                if (priornode == nullptr)
                    node = head;
                else
                    node = priornode->getNext();
            }
            else
            {
                priornode = node;
                node = node->getNext();
            }
    }
}


size_t List::size() const
{
    // walk down the list seeing how many nodes you have 
    size_t result = 0;
    ListNode * temp = head;
    while( temp != nullptr )
    {
        temp = temp->getNext();
        result++;
    }
    return( result );
}

int List::position( const std::string& data )
{
    // walk down the list looking for the desired data value
    int result = 0;
    ListNode * temp = head;
    while( temp != nullptr && temp->getElement() != data)
    {
        temp = temp->getNext();
        result++;
    }
    // data was not found!
    if (temp == nullptr)
    {
        result = -1;
    }
    return( result );
}


bool   List::before( const std::string& before, const std::string& after )
{
    bool result = false;
    ListNode * temp = head;
    // find the desired before value
    while( temp != nullptr && temp->getElement() != before)
    {
        temp = temp->getNext();
    }
    // then find the desired after value
    while( temp != nullptr && temp->getElement() != after)
    {
        temp = temp->getNext();
    }
    // if we wind up not finding the before or after value, then temp will wind up being nullptr
    result = (temp != nullptr);
    return( result );
}


bool   List::get( int i, std::string& data )
{
    bool result = true;
    ListNode * temp = head;
    // walk down the list a total of i nodes worth
    for( int k=0; k < i && temp != nullptr; k++ )
    {
        temp = temp->getNext();
    }
    
    if (temp == nullptr)
    {
        result = false;
    }
    else
    {
        data = temp->getElement();
    }
    return( result );
}
