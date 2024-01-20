 #include <cmath>

long long rectangle_rotation(int a, int b)
{
    a = a / std::sqrt(2)+1;
    b = b / std::sqrt(2)+1;
    long long sum=0;
    sum = sum + a * b + (b - 1) * (a - 1);
    if (sum % 2 == 0) sum--;
    return sum;
}