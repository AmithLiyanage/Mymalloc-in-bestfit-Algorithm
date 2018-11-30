#include <stdio.h>
#include "mymalloc.h"
#define MEMORY_SIZE 25000
#define true 1

char mallocArr[MEMORY_SIZE] = {'\0'};

char *base = mallocArr;

char* search_bestFitBlock(size_t size) {

    char* movePoint = base;
    int curBlockSize = 0;
    int min = 0;
    char* bestBlock;

    while(movePoint + curBlockSize + size + 5 <= mallocArr + (MEMORY_SIZE-1)) {

        curBlockSize = *(int*)(movePoint+1);

        if(*movePoint == 'f' && curBlockSize>=size+5) {
            if(curBlockSize == size+5) {
                bestBlock = movePoint;
                break;
            }
            else {
                if(min == 0) {
                    min = curBlockSize;
                    bestBlock = movePoint;
                }
                else {
                    if(min > curBlockSize) {
                        min = curBlockSize;
                        bestBlock = movePoint;
                    }
                }
            }
        }

        movePoint = movePoint + curBlockSize;

    }

    if(bestBlock == NULL) {
        printf("Memory is Full!\n");
        return NULL;
    }
    else {
        return bestBlock;
    }

}

void split_block(char* block, size_t size){
    char* temp;
    int blockSize = *(int *)(block+1);

    blockSize = blockSize - size - 5;
    
    temp = block + size + 5;
    *temp = 'f';
    *(int *)(temp + 1) = blockSize + 5;
    *(int *)(block + 1) = size + 5;
    *block = 'a';
}

char *MyMalloc(size_t memblock_size){
    if(memblock_size <=0){
        return NULL;
    }

    if(!*base){
        *base = 'f';
        *(int *)(base+1) = (MEMORY_SIZE-1) - 5;
    }

    size_t size = memblock_size;
    char* block = search_bestFitBlock(size);

    if(block){
        if(*(int *)(block+1) >= memblock_size){
            split_block(block, size);
        }
    }else{
    	printf("Can not allocate this block\n");
        return NULL;
    }

	printf("n");
    return (block);
    
}

void MyFree(char *address){
    char *point, *prev, *next;
    point = base;

    int num = *(int *)(point+1);

    while(true){
        num = *(int *)(point+1);
        if(point == address){
            break;
        }else if(!*point){
            break;
        }else{
            prev = point;
            point = point + num;
            next = point + *(int *)(point+1);
        }
    }

    if(*next == 'f'){
        *point = 'f';
        *(int *)(point+1) = *(int *)(point+1) + *(int *)(next+1);
    }

    if(*prev == 'f'){
        *point = 'f';
        *(int *)(prev+1) = *(int *)(point+1) + *(int *)(prev+1);
    }else{
        *address = 'f';
    }
    
    printf("\n address %p Memory block is free\n\n",address);
}
