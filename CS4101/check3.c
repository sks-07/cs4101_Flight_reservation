#include<stdio.h>
int main(){
 char array[5] = "Knot", *ptr, i, *ptr1;
 ptr = &array[1];
 ptr1 = ptr + 3;
 *ptr1 = 101;
 for(i = 0; i < 4;i++)
 printf("%c", *ptr++);
 return 0;
}
