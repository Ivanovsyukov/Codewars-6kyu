#include <iostream>
#include <vector>

std::vector <int> josephus(std::vector < int > items, int k) {
    int len=items.size();
    std::vector <int> res;
    if (len==0){
        return {};
    }
    int chet=-1;
    while(len!=0){
        chet+=k;
        chet=chet%len;
        res.push_back(items[chet]);
        items.erase(items.begin()+chet);
        --len;
        --chet;
    }
    return res;
}

int main(){
    std::vector <int> rt;
    rt=josephus({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 1);
    for (int i=0; i<10; ++i){
        std::cout << rt[i] << " ";
    }
    std::cout << std::endl;
    rt=josephus({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 2);
    for (int i=0; i<10; ++i){
        std::cout << rt[i] << " ";
    }
    std::cout << std::endl;
    rt=josephus({1, 2, 3, 4, 5, 6, 7}, 3);
    for (int i=0; i<7; ++i){
        std::cout << rt[i] << " ";
    }
    std::cout << std::endl;
    rt=josephus({}, 3);
    for (int i=0; i<0; ++i){
        std::cout << rt[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}