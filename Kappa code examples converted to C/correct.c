#include "kappalib.h"


#define SELF struct Triangle *self
typedef struct Triangle{
int base; 
int height;
void (*setHeight)(SELF, int h); 
void (*setBase)(SELF, int b); 
void (*printSurface)(SELF);
}Triangle;

void setHeight(SELF, int h){
self->height = h;
}
void setBase(SELF, int b){
self->base = b;
}
void printSurface(SELF){
double sur;
sur = (self->base * self->height) / 2; 
writeScalar(sur);
}


const Triangle ctor_Triangle = {.setHeight=setHeight, .setBase=setBase, .printSurface=printSurface};
#undef SELF

int num, counter, limit;
int prime(int n){
int i; 
int result, isPrime;
if(n < 0){
result = prime(- n);
}
else{
if(n < 2){
result = 0;
}
else{
if(n == 2){
result = 1;
}
else{
if(n % 2 == 0){
result = 0;
}
else{
i = 3; 
isPrime = 1; 
while(isPrime && (i < n / 2)){
isPrime = n % i != 0; 
i = i + 2;
} 
result = isPrime;
}
}
}
}
return result;
}
int main(){
Triangle tr = ctor_Triangle;
limit = readInteger(); 
writeInteger(2); 
writeStr(" "); 
counter = 1; 
for (int num=3; num<limit + 1; num+=2){
if(prime(num)){
counter = counter + 1; 
writeInteger(num); 
writeStr(" ");
}
} 
writeStr("\nThe total number of primes found is:"); 
writeInteger(counter); 
writeStr("\n"); 
tr.setBase(&tr, 4); 
tr.setHeight(&tr, 5); 
writeStr("\nThe total surface of our triangle is: "); 
tr.printSurface(&tr);
}