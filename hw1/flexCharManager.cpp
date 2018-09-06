#include "flexCharManager.h"
#include <iostream>
using namespace std;

flexCharManager::flexCharManager(){
	for(int i=0; i<BUF_SIZE; i++)
	{
		buffer[i] = '\0';
	}
	used_mem_size = 2;
 	used_memory = new Mem_Block*[used_mem_size];
 	active_requests = 0;
}

flexCharManager::~flexCharManager(){
	for(int i=0; i<active_requests; i++)
	{
		delete used_memory[i];
	}
	for(int i=0; i<BUF_SIZE; i++)
	{
		buffer[i] = '\0';
	}

	delete[] used_memory;
}
             
char* flexCharManager::alloc_chars(int n){

	char* temp;
	bool open = true;

	//oob checker
	if(n<=0 || n >= 10000) 
	{
		return NULL;
	}


	for(int i=0; i < n; i++)
	{
		//more oob checking
		if(free_place[i] == buffer[10000] && (n-i) > 1)
		{
			return NULL;
		}

		if(free_place[i] != '\0')
		{
			open = false;
		}
	}

	if(open)
	{
		temp = free_place;
		free_place = (free_place + n);
		Mem_Block** used_memory2;

		//mem_block resizing
		if(used_mem_size <= active_requests)
		{
			used_memory2 = new Mem_Block*[used_mem_size*2];
			for(int i=0; i<used_mem_size; i++)
			{
				used_memory2[i] = used_memory[i];
			}
				used_memory = used_memory2;
				
				delete used_memory2;
				used_mem_size *= 2;

		}
		if(used_mem_size != 2 && used_mem_size >= active_requests*4)
		{
			used_memory2 = new Mem_Block*[used_mem_size/4];
			for(int i=0; i<used_mem_size; i++)
			{
				used_memory2[i] = used_memory[i];				
			}
			used_memory = used_memory2;
				
			delete used_memory2;
			used_mem_size /= 4;

		}

		//update used_memory
		used_memory[active_requests] = new Mem_Block(n, temp);
		active_requests++;

		return temp;
	}

	return NULL;

	
}

void flexCharManager::free_chars(char* p){
	int arrIndex = 0, size=0;
	char* blah;
	int pInd, freeInd;

	//find the indexes of p and free_place
	for(int i=0; i<BUF_SIZE; i++)
	{
		if(&buffer[i] == p)
		{
			pInd = i;
		}
		if(&buffer[i] == free_place)
		{
			freeInd = i;
		}
	}

	//clearing of buffer
	for(int i=0; i<active_requests; i++)
	{
		blah = used_memory[i]->physical_location;

		if(blah == p)
		{
			arrIndex = i;
			size = used_memory[i]->size;
			delete used_memory[i];
			active_requests--;
			for(int k=i; k<size; k++)
			{
				blah[k] = '\0';
			}
		}
	}


	//update free_place if necessary
	if(pInd < freeInd)
	{
		free_place = p;
	}

}         


