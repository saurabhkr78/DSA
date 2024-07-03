// https://leetcode.com/problems/find-k-closest-elements

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>v(k);
        int n=arr.size();
        if(x<arr[0]){
            for(int i=0;i<k;i++){
                v[i]=arr[i];
            }
            return v;
        }
        if(x>arr[n-1]){
            int i=n-1;
            int j=k-1;
            while(j>=0){
                v[j]=arr[i];
                i--;
                j--;
            }
            return v;
        }

        int l=0;
        int h=n-1;
        bool f=false;
        int idx=0;
        int m=0;
        while(l<=h){
            m=l+(h-l)/2;
            if(arr[m]==x){
                f=true;
                v[idx]=arr[m];
                idx++;
                break;
            }
            else if(arr[m]>x) h=m-1;
            else l=m+1;
        }
        int lb=l;
        int ub=h;
        if(f==true){
           lb=m-1;
           ub=m+1; 
        }
        while(idx<k &&lb>=0&&ub<=n-1){
                int diff1=abs(x-arr[lb]);
                int diff2=abs(x-arr[ub]);
                if(diff1<=diff2){
                    v[idx]=arr[lb];
                    lb--;
                }
                else{
                    v[idx]=arr[ub];
                    ub++;
                }
                if(idx < k) idx++;
        }
        if(lb < 0){
            while(idx < k && ub < n){
                v[idx] = arr[ub++];
                idx++;
            }
        }
        if(ub > n-1){
            while(idx < k && lb >= 0){
                v[idx] = arr[lb--];
                idx++;
            }
        }
        sort(v.begin(),v.end());
        return v;
    }
};
