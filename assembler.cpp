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
        for(int j=0; j<int(text.size()); ++j){
            if (space==0){
                if (text[j]!=' '){
                    instruction=instruction+text[j];
                } else {
                    space++;
                }
            } else if (space==1){
                if (text[j]!=' '){
                    ukaz=ukaz+text[j];
                } else {
                    space++;
                }
            } else {
                number=number+text[j];
            }
        }
        bool num_or_ukaz=true;
        int znach;
        int work;
        if (instruction=="mov"){
            for(int j=0; j<int(number.size()) && num_or_ukaz; ++j){
                if (!(j==0 && (number[j]=='-' || (number[j]>='0' && number[j]<='9')))){
                    if (!(j==0 && number[j]=='-')){
                        num_or_ukaz=false;
                    }
                }
            }
            if (num_or_ukaz){
                znach=std::stoi(number);
            } else {
                znach=data[number];
            }
            data[ukaz]=znach;
        } else if (instruction=="inc"){
            work=data[ukaz];
            data[ukaz]=work+1;
        } else if (instruction=="dec"){
            work=data[ukaz];
            data[ukaz]=work-1;
        } else if (instruction=="jnz"){
            for(int j=0; j<int(number.size()) && num_or_ukaz; ++j){
                if (!(number[j]>='0' && number[j]<='9')){
                    if (!(j==0 && (number[j]=='-' || (number[j]>='0' && number[j]<='9')))){
                        num_or_ukaz=false;
                    }
                }
            }
            if (num_or_ukaz){
                znach=std::stoi(number);
            } else {
                znach=data[number];
            }
            work=data[ukaz];
            if (work!=0){
                i=i+znach-1;
            }
        }
    }
    return data;
}

int main(){
    std::vector<std::string> program{ "mov a 0", "inc a", "dec a", "jnz a -1", "inc a" };
    std::cout << assembler(program)["0"];
    return 0;
}