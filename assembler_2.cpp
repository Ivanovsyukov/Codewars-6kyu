#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

/*static int& getReg(std::unordered_map<std::string, int>& regs, std::string name)
{
  
}
*/

std::unordered_map<std::string, int> assembler(const std::vector<std::string>& program)
{
    std::unordered_map<std::string, int> data;
    unsigned int len_program=program.size();
    unsigned int i;
    std::string instruction;
    std::string ukaz;
    std::string number;
    std::string text;
    for (i=0; i<len_program; ++i){
        instruction="";
        ukaz="";
        number="";
        text=program[i];
        int space=0;
        bool num_or_ukaz=true;
        char s;
        int len_comand=text.size();
        bool tire=false;
        int count_tire=0;
        for(int j=0; j<len_comand; ++j){
            s=text[j];
            if (space==0){
                if (s!=' '){
                    instruction=instruction+s;
                } else {
                    space++;
                }
            } else if (space==1){
                if (s!=' '){
                    ukaz=ukaz+s;
                } else {
                    space++;
                }
            } else {
                if (num_or_ukaz && !((s>='0' &&  s<='9') || s=='-')){
                    num_or_ukaz=false;
                }
                if (num_or_ukaz && s=='-'){
                    tire=true;
                    count_tire++;
                }
                number=number+s;
            }
        }
        if (num_or_ukaz && tire && !(count_tire==1 && number[0]=='-')){
            num_or_ukaz=false;
        }
        int znach;
        switch (instruction[0])
        {
        case 'm':
            if (num_or_ukaz){
                znach=std::stoi(number);
            } else {
                znach=data[number];
            }
            data[ukaz]=znach;
            break;
        case 'j':
            if (num_or_ukaz){
                znach=std::stoi(number);
            } else {
                znach=data[number];
            }
            if (data[ukaz]!=0){
                i=i-1+znach;
            }
        case 'd':
            data[ukaz]=data[ukaz]-1;
            break;
        case 'i':
            data[ukaz]=data[ukaz]+1;
            break;
        default:
            break;
        }
    }
    return data;
}

int main(){
    std::vector<std::string> program{ "mov a 0", "inc a", "dec a", "jnz a -1", "inc a" };
    std::cout << assembler(program)["0"];
    return 0;
}