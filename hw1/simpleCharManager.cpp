#include <cstddef>
#include "simpleCharManager.h"
#include <iostream>

using namespace std;



simpleCharManager::simpleCharManager(){
	for(int i=0; i<BUF_SIZE; i++)
	{
		buffer[i] = '\0';
	}
	free_place = &buffer[0];
}


simpleCharManager::~simpleCharManager(){}
             
char* simpleCharManager::alloc_chars(int n){
	char* temp;
	bool open = true;
	bool bounds = false;
	int holder = 0;

	//oob checking
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

	//if space available return pointer
	if(open)
	{
		temp = free_place;
		free_place = (free_place + n);
		return temp;
	}

	return NULL;

	
}

void simpleCharManager::free_chars(char* p){
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

	for(int i=0; i<BUF_SIZE; i++)
	{
		if(&buffer[9999] == &p[i])
		{
			break;
		}
		p[i] = '\0';

	}

	//update free_place if necessary
	if(pInd < freeInd)
	{
		free_place = p;
	}

}         




