// https://leetcode.com/problems/reducing-dishes

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
       int n= satisfaction.size();
       sort(satisfaction.begin(),satisfaction.end());
        int suf[n];
        suf[n-1]=satisfaction[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i]=suf[i+1]+satisfaction[i];
        }
        // find the index 
      

        int idx=-1;
        for(int i=0;i<n;i++){
            if(suf[i]>=0){
                idx=i;
                break;
            }
        }
          if (idx==-1) return 0;
        //max sum of like time 
        int time=1;
        int sum=0;
        for(int i=idx;i<n;i++){
            sum+=(satisfaction[i]*time);
            time++;
        }
        return sum;
    }
};