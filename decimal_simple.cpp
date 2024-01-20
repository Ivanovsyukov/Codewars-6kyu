long properFractions(long n)
{
  if (n==1) return 0;
  long count=n;
  long tmp=n;
  for (long i=2; i*i<=tmp; ++i){
    if (tmp%i==0){
      count-=count/i;
      while(tmp%i==0){
        tmp/=i;
      }
    }
  }
  if (tmp>1) count-=count/tmp;
  return count;
}