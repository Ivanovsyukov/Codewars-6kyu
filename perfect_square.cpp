#include <iostream>
#include <math.h>

int is_square(int n){
    int half=sqrt(n);
    return (half*half==n);
}

//Теорема Лагранжа о четырех квадратах
int sum_of_squares(int n){
    if (is_square(n)){
        return 1;//полный
    }
    for (int i=0; i<int(sqrt(n))+1; ++i){
        if (is_square(n-(i*i))){//сумма из двух квадратов
            return 2;
        }
    }
    while(n%4==0){ //имеет вид 4а*(8о+7)
        n=n>>2;
    }
    if (n%8==7){
        return 4;
    }
    return 3;//не имеет вид 4а*(8о+7)
}

int main(){
    std::cout << sum_of_squares(18) << std::endl;
    return 0;
}