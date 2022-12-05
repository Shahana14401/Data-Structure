//Merge two sorted array and store result in third array

#include<stdio.h>
#include<conio.h>
void main()
{
  int first[50],second[50],third[50],n1,n2,i,j,k;
  clrscr();


  //first sorted array
  printf("Enter size of first array:");
  scanf("%d",&n1);
  printf("Enter the sorted elements in first array:");
  for(i=0;i<n1;i++)
    scanf("%d",&first[i]);
  printf("Elements in first array:");
  for(i=0;i<n1;i++)
    printf("%d \t",first[i]);


  //second sorted array
  printf("\n\nEnter size of second array:");
  scanf("%d",&n2);
  printf("Enter the sorted elements in second array:");
  for(j=0;j<n2;j++)
    scanf("%d",&second[j]);
  printf("Elements in second array:");
  for(j=0;j<n2;j++)
    printf("%d \t",second[j]);


  //merge and sort
  i=0,j=0,k=0;
  while(i<n1 && j<n2)
  {
   if(first[i]<second[j])
   {
     third[k]=first[i];
     i++;
   }
   else
   {
     third[k]=second[j];
     j++;
   }
   k++;
  }

  while(i<n1)
  {
    third[k]=first[i];
    i++;
    k++;
  }

  while(j<n2)
  {
    third[k]=second[j];
    j++;
    k++;
  }


  //merged array
  printf("\n\n Array after merging sorted arrays:");
  for(k=0;k<n1+n2;k++)
    printf("%d \t",third[k]);
  getch();
}
