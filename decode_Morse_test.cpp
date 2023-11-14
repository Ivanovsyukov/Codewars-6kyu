#include <iostream>
#include <string>

std::string decodeMorse(const std::string& morseCode) {
  // ToDo: Accept dots, dashes and spaces, return human-readable message
  std::string decoded;
  std::string word;
  char p1, p2;
  for( auto p : morseCode ) {
    if (p==' '){
      if (p1==' ' && p2=='0'){
        p2=' ';
      } else if (p2==' ' && decoded.size()!=0){
        decoded+=' '+'8';
      } else {
        p1=' ';
        decoded+=word;
        word.clear();
      }
    } else {
      p1='0';
      p2='0';
      word+=p;
    }
  }
  decoded+=word;
  word.clear();
  int lend=decoded.size();
  for (int i=lend-1; i>=0; --i){
    if (decoded[i]==' '){
        decoded.resize(i);
    } else {
        break;
    }
  }
  return decoded;
}
int main(){
    std::cout << decodeMorse("     .... . -.--   .--- ..- -.. .    ") << std::endl;
    return 0;
}