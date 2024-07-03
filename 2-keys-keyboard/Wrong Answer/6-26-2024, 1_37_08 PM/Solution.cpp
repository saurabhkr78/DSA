// https://leetcode.com/problems/2-keys-keyboard

class Solution {
public:

bool isprime(int n){
    if(n==1) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}

int factor(int n){
    for(int i=2;i<=sqrt(n);i++){
      if(n%i==0) return n/i;
    }
 return 1;
}

    int minSteps(int n) {
        int ct=0;
        while(n>1){
            if(isprime(n)){
                ct+=n;
                break;
            }
            int hf=factor(n);
            ct=n/hf;
            n=hf;
        }
        return ct;
    }
};