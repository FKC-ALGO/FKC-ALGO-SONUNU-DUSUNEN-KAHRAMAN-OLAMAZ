#include <iostream>
using namespace std;

void swap(int* a1, int* a2){
	int a3=*a2;
	*a1=*a2;
	*a2=a3;
	delete a1;
	delete a2;
}
int partition(int arr[],int low,int high)
{

int pivot=arr[high];

int i=(low-1);

for(int j=low;j<=high;j++)
{
	if(arr[j]<pivot)
	{

	i++;
	swap(arr[i],arr[j]);
	}
}
swap(arr[i+1],arr[high]);
return (i+1);
}


			
void quickSort(int arr[],int low,int high)
{
if(low<high)
{
	
	int pi=partition(arr,low,high);
	quickSort(arr,low,pi-1);
	quickSort(arr,pi+1,high);
}
}
		

int main() {
int arr[]={10,7,8,9,1,5};
int n=sizeof(arr)/sizeof(arr[0]);
// Function call
quickSort(arr,0,n-1);
//Print the sorted array
cout<<"Sorted Array\n";
for(int i=0;i<n;i++)
{
	cout<<arr[i]<<" ";
}
return 0;
}
