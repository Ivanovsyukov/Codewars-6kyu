#include <iostream>
#include <string>

struct multi{
    int* count;
    int* num;
    int len;
};

int* prime(int n){
  int* a=new int[n+1];
  a[0]=0;
  a[1]=0;
  for(size_t i=2; i<n+1; ++i){
    a[i]=1;
  }
  for(int i=2; i<=n; ++i){
    if (a[i]){
        for (int j=i+1; j*j<=i*i; ++j){
            if (i%j==0){
                a[i]=0;
                break;
            }
        }
        for(int k=i; k*i<=n;++k){
            a[i*k]=0;
        }
    }
  }
  return a;
}

std::string decomp(int n) {
    if (n==0 || n==1){
        return "";
    }
    int* prime_t=prime(n);
    multi work;
    work.len=0;
    work.count=nullptr;
    work.num=nullptr;
    for(int i=2; i<=n; ++i){
        if (prime_t[i]){
            int* tmp1=new int[work.len+1];
            int* tmp2=new int[work.len+1];
            for (size_t j=0; j<work.len; ++j){
                tmp1[j]=work.count[j];
                tmp2[j]=work.num[j];
            }
            tmp1[work.len]=0;
            tmp2[work.len]=i;
            work.len++;
            delete[] work.count;
            work.count=tmp1;
            delete[] work.num;
            work.num=tmp2;
        }
    }
    int s;
    for (int i=2; i<=n; ++i){
        s=i;
        for (int j=0; j<work.len && s!=1;++j){
            while (s%work.num[j]==0){
                work.count[j]++;
                s=s/work.num[j];
            }
        }
    }
    std::string res;
    for(int j=0; j<work.len; ++j){
        res=res+std::to_string(work.num[j]);
        if (work.count[j]!=1){
            res+='^';
            res=res+std::to_string(work.count[j]);
        }
        if (j!=work.len-1){
            res=res+" * ";
        }
    }
    delete[] work.count;
    delete[] work.num;
    return res;
}

int main(){
    std::cout << decomp(12) << std::endl;
    return 0;
}