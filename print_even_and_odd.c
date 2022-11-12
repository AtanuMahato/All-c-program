#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
void gotoxy(int x,int y){
  COORD c;
  c.X = x;
  c.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
print_even_num(int range){
   int X = 15,Y = 2,num,X1 = 28;
   for( num = 0;num<=10;num++){
	 if(num%2 == 0){
	   gotoxy(X,Y);
	   printf("%d",num);
	 }else{
	   gotoxy(X1,Y++);
	   printf("%d",num);
	 }
	 
   }
   if(num%2 == 0){

   }
}
int main(){

  gotoxy(10,1);
  printf("Even Numbers");
  gotoxy(25,1);
  printf("Odd Numbers");
  print_even_num(10);
  return 0;
}
