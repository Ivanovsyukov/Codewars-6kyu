#include <iostream>
#include <string>

unsigned char tape[5000]={};
unsigned char* ukaz=tape;

std::string brainLuck(const std::string &code, const std::string &input) {
    char now;
    unsigned int i, loop;
    unsigned int len=code.size();
    unsigned int ind_input=0;
    std::string output;
    for (i=0; i<len;++i){
        now=code[i];
        switch (now)
        {
        case '>':++ukaz;break;
        case '<':--ukaz;break;
        case '+':++*ukaz;break;
        case '-':--*ukaz;break;
        case ',':*ukaz=input[ind_input];ind_input++;break;
        case '.':output=output+char(*ukaz);break;
        case '[':
            if(*ukaz==0){
                loop=1;
                while(loop>0){
                    now=code[++i];
                    if (now=='['){
                        loop++;
                    } else if (now==']'){
                        loop--;
                    }
                }
            };
            break;
        case ']':
            if(*ukaz){
                loop=1;
                while(loop>0){
                    now=code[--i];
                    if (now=='['){
                        loop--;
                    } else if (now==']'){
                        loop++;
                    }
                }
            };
            break;
        default: break;
        }
    }
    return output;
}
int main(){
    std::string tw = "codewars";
    tw.append(1,(char)255);
    std::cout << brainLuck(",+[-.,+]",tw);
    return 0;
}