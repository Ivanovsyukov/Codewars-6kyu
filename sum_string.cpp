#include <string>
#include <iostream>

std::string sum_strings(const std::string& a, const std::string& b) {
    int len_a=a.size();
    int len_b=b.size();
    std::string result;
    int res;
    int perenos=0;
    if (len_a==len_b){
        for(int i=len_a-1; i>=0; --i){
            res=int(a[i])+int(b[i])-int('0')-int('0')+perenos;
            perenos=res/10;
            result=char(res%10+'0')+result;
        }
        if (perenos!=0){
            result=char(perenos+'0')+result;
        }
    } else if (len_a>len_b){
        int raz=len_a-len_b;
        for(int i=len_b-1; i>=0; --i){
            res=int(a[i+raz])+int(b[i])-int('0')-int('0')+perenos;
            perenos=res/10;
            result=char(res%10+'0')+result;
        }
        int ret=0;
        if (perenos!=0){
            if (len_a-len_b-1<0){
                result=char(perenos+'0')+result;
                return result;
            }
            res=int(a[len_a-len_b-1])-int('0')+perenos;
            perenos=res/10;
            result=char(res%10+'0')+result;
            ret++;
        }
        if (perenos!=0){
            if (len_a-len_b-2<0){
                result=char(perenos+'0')+result;
                return result;
            }
            res=int(a[len_a-len_b-2])-int('0')+perenos;
            perenos=res/10;
            result=char(res%10+'0')+result;
            ret++;
        }
        for (int i = len_a-len_b-1-ret; i >=0 ; --i)
        {
            result=a[i]+result;
        }
    } else {
        int raz=len_b-len_a;
        for(int i=len_a-1; i>=0; --i){
            res=int(a[i])+int(b[i+raz])-int('0')-int('0')+perenos;
            perenos=res/10;
            result=char(res%10+'0')+result;
        }
        int ret=0;
        if (perenos!=0){
            if (len_b-len_a-1<0){
                result=char(perenos+'0')+result;
                return result;
            }
            res=int(b[len_b-len_a-1])-int('0')+perenos;
            perenos=res/10;
            result=char(res%10+'0')+result;
            ret++;
        }
        if (perenos!=0){
            if (len_b-len_a-2<0){
                result=char(perenos+'0')+result;
                return result;
            }
            res=int(b[len_b-len_a-2])-int('0')+perenos;
            perenos=res/10;
            result=char(res%10+'0')+result;
            ret++;
        }
        for (int i = len_b-len_a-1-ret; i >=0 ; --i)
        {
            result=b[i]+result;
        }
    }
    return result;
}

int main(){
    std::cout << sum_strings("923", "11111195") << std::endl;
    return 0;
}