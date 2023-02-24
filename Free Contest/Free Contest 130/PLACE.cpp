#include <iostream>

using namespace std;

bool check(int b, int a)
{
    for (int d = 2; d <= b && d * d <= a; ++d)
        if (a % d == 0)
            return false;

    return true;
}

int main()
{
    int b, a;
    cin >> b >> a;
    while (b < a && !check(b, a)) --a;

    cout << (a <= b ? -1 : a);
    return 0;
}