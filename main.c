#include <stdio.h>
#include "mymalloc.h"
#define MEMORY_SIZE 25000
#define true 1
	
int main(){	
	
    char* add1 = MyMalloc(1000);
    char* add2 = MyMalloc(5000);
    char* add3 = MyMalloc(2000);
    char* add4 = MyMalloc(3000);
    char* add5 = MyMalloc(6000);

    printf(" 1000 %p \n", add1);
    printf(" 5000 %p \n", add2);
    printf(" 2000 %p \n", add3);
    printf(" 3000 %p \n", add4);
	printf(" 6000 %p \n", add5);

    MyFree(add2);
    MyFree(add4);

    char* add6 = MyMalloc(2700);
    printf(" 2700 %p \n", add6);
	
//    char* OS = MyMalloc(5000);
//    char* ProcessA = MyMalloc(2000);
//    char* ProcessB = MyMalloc(8000);
//    printf(" OS %p \n", OS);
//    printf(" Process A %p \n", ProcessA);
//    printf(" Process B %p \n", ProcessB);
//    
//    MyFree(ProcessA);
//    printf("--");
//    char* ProcessC = MyMalloc(8000);
//    char* ProcessD = MyMalloc(1000);
//    
//    printf(" OS %p \n", OS);
//    printf(" Process B %p \n", ProcessB);
//    printf(" Process C %p \n", ProcessC);
//    printf(" Process D %p \n", ProcessD);

    return 0;
}
