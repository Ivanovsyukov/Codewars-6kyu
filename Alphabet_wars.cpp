#include <iostream>
#include <string>
#include <vector>

std::string alphabet_war(const std::vector<std::string>& reinforces,
                         const std::vector<std::string>& airstrikes){
                            const int len_gorizontal_reinforces=reinforces[0].size();
                            int len_gorizontal_airstrikes;
                            const int len_vertical_reinforces=reinforces.size();
                            const int len_vertical_airstrikes=airstrikes.size();
                            int a[len_gorizontal_reinforces];
                            std::string result;
                            for(int i=0; i<len_gorizontal_reinforces; ++i){
                                a[i]=1;
                                result.push_back(reinforces[0][i]);
                            }
                            /*
                            std::cout << "len_gorizontal_reinforces - " << len_gorizontal_reinforces << std::endl;
                            std::cout << "len_vertical_reinforces - " << len_vertical_reinforces << std::endl;
                            std::cout << "len_vertical_airstrikes - " << len_vertical_airstrikes << std::endl;
                            std::cout << "result - " << result << std::endl;
                            */
                            char symbol;
                            int len_prov;
                            for (int i=0; i<len_vertical_airstrikes; ++i){
                                len_gorizontal_airstrikes=airstrikes[i].size();
                                if (len_gorizontal_airstrikes>len_gorizontal_reinforces){
                                    len_prov=len_gorizontal_reinforces;
                                } else {
                                    len_prov=len_gorizontal_airstrikes;
                                }
                                for (int j=0; j<len_prov; ++j){
                                    symbol=airstrikes[i][j];
                                    if ((symbol=='*') || (symbol!='*' && j!=0 && airstrikes[i][j-1]=='*') || (symbol!='*' && j!=len_gorizontal_airstrikes-1 && airstrikes[i][j+1]=='*')){
                                        if (a[j]!=len_vertical_reinforces){
                                            result[j]=reinforces[a[j]][j];
                                            a[j]+=1;
                                        } else {
                                            result[j]='_';
                                        }
                                    }
                                    if (j==len_prov-1){
                                        if ((len_gorizontal_airstrikes<len_gorizontal_reinforces)&&(symbol=='*')){
                                            if (a[j+1]!=len_vertical_reinforces){
                                                result[j+1]=reinforces[a[j+1]][j+1];
                                                a[j+1]+=1;
                                            } else {
                                                result[j+1]='_';
                                            }
                                        }
                                    }
                                }
                                // std::cout << "result - " << result << std::endl;
                                // std::cout << "a[1]- " << a[1] << std::endl;
                            }
                            return result;
                         }

int main(){
    const std::vector<std::string> reinforces = {
      "g964xxxxxxxx",
      "myjinxin2015",
      "steffenvogel",
      "smile67xxxxx",
      "giacomosorbi",
      "freywarxxxxx",
      "bkaesxxxxxxx",
      "vadimbxxxxxx",
      "zozofouchtra",
      "colbydauphxx"
    }; // 10*13
    const std::vector<std::string> airstrikes = {
      "* *** ** ***",
      " ** * * * **",
      " * *** * ***",
      " **  * * ** ",
      "* ** *   ***",
      "***   ",
      "**",
      "*",
      "*"
    }; // 9*13
    std::cout << alphabet_war(reinforces, airstrikes) << std::endl;
    std::cout << alphabet_war({"zzzzz","bbbbb", "ccccc", "ddddd"}, {"*", " *", "   "}) << std::endl;
    return 0;
}