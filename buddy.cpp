#include <math.h>

using namespace std;

namespace Bud
{
    string buddy(long long start, long long limit)
    {
      for (long long i=start; i<=limit; ++i){
        long long sum=0;
        bool p=true;
        for (long long j=2; j<((long long)(sqrt(i))+1); ++j){
          if(i%j==0){
            if (j*j==i){
              sum+=j;
            } else {
              sum=sum+j+(long long)(i/j);
            }
          }
        }
        if (sum>i){
          long long sum_2=0;
          for (long long j=2; j<((long long)(sqrt(sum))+1); ++j){
            if(sum%j==0){
              if (j*j==sum){
                sum_2+=j;
              } else {
                sum_2=sum_2+j+(long long)(sum/j);
              }
              if (sum_2>i){
                p=false;
                break;
              }
            }
          }
          if (p && sum_2==i){
            return '('+std::to_string(i)+' '+std::to_string(sum)+')';
          }
        }
      }
      return "Nothing";
    }
}