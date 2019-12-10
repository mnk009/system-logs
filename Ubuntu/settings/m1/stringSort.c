#include<stdio.h>
#include<string.h>
int main(){
   int i,j,k,count;
   char str[25][25],temp[25];
   puts("How many strings u are going to enter?: ");
   scanf("%d",&count);

   puts("Enter Strings one by one: ");
   for(i=0;i<=count;i++)
      gets(str[i]);
   for(i=0;i<=count;i++)
      for(j=i+1;j<=count;j++){
         if(strcmp(str[i],str[j])>0){
            strcpy(temp,str[i]);
            strcpy(str[i],str[j]);
            strcpy(str[j],temp);
         }
      }
   printf("Order of Sorted Strings:");
   for(i=0;i<=count;i++){
      for(j=0;j<=str[i][j]!='\0';j++){
      	if(str[i][j]==' '){
      		break;
		  }
		  else {
		  	printf("%c",str[i][j]);
		  }
	  }
	  printf("\n");
}
   return 0;
}
