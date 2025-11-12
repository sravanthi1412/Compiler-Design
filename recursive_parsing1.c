#include<stdio.h>
#include<string.h>
char input[100];
int i=0;
int S();
int L();
int main(){
printf("Enter the input string:\n");
scanf("%s",input);
if(S()&&input[i]=='\0'){
printf("Successfully parsed\n");
}
else{
printf("Invalid parse\n");
}
return 0;
}
int S(){
if(input[i]=='a'){
i++;
return 1;
}
else if(input[i]=='('){
i++;
if(L()){
if(input[i]==')'){
i++;
return 1;
}
}
}
return 0;
}
int L(){
if(S()){
while(input[i]==','){
i++;
if(!S()){
return 0;
}
}
return 1;
}
return 0;
}