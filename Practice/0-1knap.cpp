#include<bits/stdc++.h>
using namespace std;

int maxprofit(vector<int>&wt,vector<int>&profit,vector<int>&items,int n,int capacity){

  vector<vector<int>>table(n+1,vector<int>(capacity+1,0));
  for(int i=1;i<=n;i++){
     for(int j=1;j<=capacity;j++){
         if(wt[i]<=j){
            table[i][j]=max(table[i-1][j],profit[i]+table[i-1][j-wt[i]]);
         }else{
          table[i][j]=table[i-1][j];
         }
     }
  }
  //Backtracks
  int j=capacity;
  int i=n;
  while(i>0&&j>0){
     if(table[i][j]!=table[i-1][j]){
      items.push_back(i);
      j=j-wt[i];
     }
     i--;
  }

  //dp table
  for(int j=0;j<=capacity;j++){
    cout<<"\t"<<j<<" ";

  }
  cout<<endl;
  for(int i=0;i<=n;i++){
     cout<<"i="<<i<<"\t";
     for(int j=0;j<=capacity;j++){
       cout<<table[i][j]<<"\t";
     }
     cout<<endl;
  }
  return table[n][capacity];
  

}
int main(){
    int n;
    cout<<"Enter the number of items:";
    cin>>n;
    int capacity;
    cout<<"Enter the knapsack capacity:";
    cin>>capacity;

    vector<int>wt(n+1,0);
    vector<int>profit(n+1,0);
    vector<int>items;
    
    cout<<"==========Enter the weights of the items==========\n";
    for(int i=1;i<=n;i++){
       cout<<"Enter the weight of item "<<(i)<<":";
       cin>>wt[i];
    }
     cout<<"==========Enter the Profits of the items==========\n";
    for(int i=1;i<=n;i++){
       cout<<"Enter the profit of item "<<(i)<<":";
       cin>>profit[i];
    }
    int maximumprofit=maxprofit(wt,profit,items,n,capacity);
    

    cout<<"Maximum Profit by 0-1 knapsack: "<<maximumprofit<<endl;
    cout<<"==========Selected items list=========\n";
    int k=items.size();
    for(int i=0;i<k;i++){
      cout<<"Item :"<<items[i]<<endl;
       
    }
    cout<<endl;
    return 0;
}