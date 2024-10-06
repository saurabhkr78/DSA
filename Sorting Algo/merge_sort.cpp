#include<bits/stdc++.h>
using namespace std;

vector<int>merge_two_sorted_array(vector<int>v1,vector<int>v2){
    int i=0,j=0,k=0;
    vector<int>ans(v1.size()+v2.size());
    while(i<v1.size()&&j<v2.size()){
        if(v1[i]<v2[j]){
            ans[k++]=v1[i];
            i++;
        }
        else if(v1[i]>v2[j]){
            ans[k++]=v2[j];
            j++;
        }
        else{
            ans[k++]=v1[i];
            ans[k++]=v2[j];
            i++;
            j++;
        }
    }
    if(i<v1.size()){
        while(i<v1.size()){
            ans[k++]=v1[i];
            i++;
        }
    }
    if(j<v2.size()){
        while(j<v2.size()){
            ans[k++]=v2[j];
            j++;
        }
    }
    return ans;

}
vector<int> merge_sort(vector<int>v,int l,int h){
    if(l==h and l>=h) return vector<int>{v[l]};
    int mid=(l+h)/2;
    vector<int>first_half_sorted_array=merge_sort(v,l,mid);
    vector<int>second_half_sorted_array=merge_sort(v,mid+1,h);
    vector<int>finalArray=merge_two_sorted_array(first_half_sorted_array,second_half_sorted_array);
    

    return finalArray;


}

int main()
{
    vector<int>v{1,8,18,2,9,11,0};
    vector<int>finalAnswer=merge_sort(v,0,v.size()-1);
    for(auto x:finalAnswer){
        cout<<x<<" ";
    }

    return 0;
}