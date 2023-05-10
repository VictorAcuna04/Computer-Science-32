bool allTrue(const string a[], int n)
{
    if (n <= 0)
        return true;
    return (somePredicate(a[n-1]) && allTrue(a, n-1));
}

int countTrue(const string a[], int n)
{
    if (n <= 0)
        return 0;
    int count = countTrue(a, n-1);
    if (somePredicate(a[n-1]))
        count++;
    return count;
}

int firstTrue(const string a[], int n)
{
    if (n <= 0)
        return -1;
    int position = firstTrue(a, n-1);
    if (position == -1 && somePredicate(a[n-1]))
        position = n-1;
    return position;
}

int positionOfMax(const string a[], int n)
{
    if (n <= 0)
        return -1;
    int position = positionOfMax(a, n-1);
    if (position == -1 || a[n-1] >= a[position])
        position = n-1;
    return position;
}

bool contains(const string a1[], int n1, const string a2[], int n2)
{
    if (n2 <= 0)
        return true;
    if (n1 <= 0)
        return false;
    if (a1[0] == a2[0])
        return contains(a1+1, n1-1, a2+1, n2-1);
    else
        return contains(a1+1, n1-1, a2, n2);
}
