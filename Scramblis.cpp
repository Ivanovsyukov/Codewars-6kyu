#include <string>
#include <iostream>

bool scramble(const std::string& s1, const std::string& s2){
    int a[26]={};
    int b[26]={};
    int len1=s1.size();
    int len2=s2.size();
    for(int i=0; i<len1; ++i){
        a[s1[i]-'a']++;
    }
    for(int i=0; i<len2; ++i){
        b[s2[i]-'a']++;
    }
    bool res=true;
    for(int i=0; i<26; ++i){
        if (a[i]<b[i]){
            res=false;
            break;
        }
    }
    return res;
}

int main(){
    return 0;
}