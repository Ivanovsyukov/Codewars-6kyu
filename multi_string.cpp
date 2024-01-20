#include <iostream>
#include <string>



std::string multiply(std::string a, std::string b) {
    int schet=0;
    int len_a=a.size();
    int len_b=b.size();
    std::string dop="";
    if (a[0]=='0'){
        for(int i=0; a[i]=='0' && i<len_a; ++i){
            schet++;
        }
        if (schet!=len_a){
            for(int i=schet; i<len_a; ++i){
                dop=dop+a[i];
            }
        } else {
            return "0";
        }
        a=dop;
    }
    schet=0;
    dop="";
    if (b[0]=='0'){
        for(int i=0; b[i]=='0' && i<len_b; ++i){
            schet++;
        }
        if (schet!=len_b){
            for(int i=schet; i<len_b; ++i){
                dop=dop+b[i];
            }
        } else {
            return "0";
        }
        b=dop;
    }
    len_a=a.size();
    len_b=b.size();
    std::string result="";
    int res;
    int perenos=0;
    if (len_a==len_b){
        for(int i=len_a-1; i>=0; --i){
            res=(int(a[i])-int('0'))*(int(b[i])-int('0'))+perenos;
            perenos=res/10;
            result=char(res%10+'0')+result;
        }
        if (perenos!=0){
            result=std::to_string(perenos)+result;
        }
    } else if (len_a>len_b){
        int raz=len_a-len_b;
        for(int i=len_b-1; i>=0; --i){
            res=(int(a[i+raz])-int('0'))*(int(b[i])-int('0'))+perenos;
            perenos=res/10;
            result=char(res%10+'0')+result;
        }
        int ret=0;
        for (int i=1; perenos!=0; ++i){
            if (len_a-len_b-i<0){
                result=std::to_string(perenos)+result;
                return result;
            }
            res=int(a[len_a-len_b-i])-int('0')+perenos;
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
            res=(int(a[i])-int('0'))*(int(b[i+raz])-int('0'))+perenos;
            perenos=res/10;
            result=char(res%10+'0')+result;
        }
        int ret=0;
        for (int i=1; perenos!=0; ++i){
            if (len_b-len_a-i<0){
                result=std::to_string(perenos)+result;
                return result;
            }
            res=int(b[len_b-len_a-i])-int('0')+perenos;
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
    std::cout << multiply("30", "69") << std::endl;
    return 0;
}