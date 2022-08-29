
#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int low,int high,int y)
{
   while(low<=high)
   {
     int mid=(low+high)/2;
     if(arr[mid]<y)
     {
         low=mid+1;
     }
     else if(arr[mid]>y)
     {
         high=mid-1;
     }
     else
     {
         return mid;
     }
   }
   return -1;
 }

int main(void)
{
   int x,y,z,i=0;
   cin>>x>>y;
   z=x;
   int arr[x];
   while(x--)
   {
       cin>>arr[i];
       i++;
   }
   sort(arr,arr+z);

   int result = binarySearch(arr,0,z-1,y);

   if(result==-1)
   {
       cout<<"not found in the array";
   }

   else if(result!=-1)
   {
       cout<<result+1<<" "<<"element";
   }

}
