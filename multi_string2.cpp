#include <iostream>
#include <string>
#include <vector>

std::string multiply(const std::string &t, const std::string &b)
{
    int tsize = static_cast<int>(t.size());
    int bsize = static_cast<int>(b.size());
  
    std::vector<size_t> pos(static_cast<size_t>(tsize + bsize), 0);
    for (int i = tsize - 1; i >= 0; i--){
        for (int j = bsize - 1; j >= 0; j--){
            int mul = (t[i] - '0') * (b[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            int sum = mul + pos[p2];
            pos[p1] += sum / 10;
            pos[p2] = sum % 10;
        }
    }
    std::string res;
    for (const auto& p : pos) if (!(res.size() == 0 && p == 0)) res.push_back('0'+p);
    
    return (res.size() == 0)? "0" : res;
}