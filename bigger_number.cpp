#include <iostream>

long nextBigger(long n) {
   int a = n%10, b;
   long pivot = 1;
   do {
      pivot *= 10;
      b = a;
      a = (n/pivot)%10;
   } while(a >= b);
   
   if(n/pivot == 0)
      return -1;
   
   long l = n/pivot, r = n%pivot, rev_r = 0;

   while(r != 0){
      int digit = r%10;
      if(digit > a && digit <= b){
         l=(l/10)*10 + digit;
         b = 0;
         digit = a;
      }
      rev_r = rev_r*10 + digit;
      r/=10;
   }

   return l*pivot + rev_r;
}

int main(){
    std::cout << nextBigger(11991) << std::endl;
    return 0;
}