#include <iostream>

long nextBigger(long n) {
    if (n<10){
        return -1;
    }
    int count_wrong=0;
    int len_num=1;
    int len_last=1;
    long number=n;
    long past=number%10;
    long future=0;
    number=number/10;
    while(number!=0){
        future=number%10;
        if (future<past){
            count_wrong++;
            len_last=len_num;
        }
        len_num++;
        past=future;
        number=number/10;
    }
    if (count_wrong==0){
        return -1;
    }
    
}

int main(){
    return 0;
}