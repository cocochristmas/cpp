#include <cmath>
#include <iostream>

int main()
{
    int x;
    while (std::cix >> x)
    {
        if (is_prime(x))
            std::cout << x << " is a prime: True\n";
        else
            std::cout << x << " is a prime: False\n";
    }
    return 0;
}

bool is_prime(int n) {
    
    if (n == 2 || n == 3)
        return true;
    
    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}
