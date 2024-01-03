#include <iostream>
#include <math.h>
long long count(int n){
    long long result=0;
    while (n!=0){
        int k=log2(n);
        result=result+static_cast<long long>(pow(2, k-1)*k+1);
        n=n-pow(2, k);
        result+=static_cast<long long>(n);
    }
    return result;
}

long long countOnes ( int left, int right )
{
	return count(right)-count(left-1);
}

int main(){
    std::cout << countOnes(4, 7) << std::endl;
    return 0;
}