int modulo( unsigned int m, unsigned int n )
{
    int result = 0;
    if (m == 0)
        result = 0;
    else if (m == n)
        result = 0;
    else if (m < n)
        result = m;
    else
        result = modulo( m-n, n );
    return( result );  
}


int occurrences( int num, int d )
{
    int result = 0;
    if (num == 0)
        result = 0;
    else if (num % 10 == d)
        result = 1 + occurrences( num / 10, d );
    else
        result = occurrences( num / 10, d );
    return( result );
}


string lucky7s(string n)
{
    string result;
    if (n.size() < 2)
        result = n;
    // checks if first two characters equal
    else if (n.substr(0,1) == n.substr(1,1))
        result = n.substr(0,1) + "77" + lucky7s( n.substr(1) );
    else
        result = n.substr(0,1) + lucky7s( n.substr(1) );
    return( result );  
} 


bool combinations(const int arr[], int size, int target)
{
    bool result = false;
    if (size == 0 && target == 0)
        result = true;
    else if (size == 0)
        result = false;
    // if the rest of the array returns true then
    // return true, no need to consider the first element
    else if (combinations(arr+1, size - 1, target))
        result = true;
    // otherwise, consider the rest of the array and
    // make sure it equals target - first element
    else 
        result =  combinations(arr+1, size - 1, target - arr[0]);
    return( result );
}

