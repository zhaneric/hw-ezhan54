#include <iostream>
#include <stdlib.h>
#include "flexCharManager.h"
using namespace std;

int main(int argc, char *argv[])
{
  flexCharManager simplest_mem_manager;

  /*write driver code as described in the assignment to replace this */
  char* hello = simplest_mem_manager.alloc_chars(13);
  hello[0] = 'H';
  hello[1] = 'e';
  hello[2] = 'l';
  hello[3] = 'l';
  hello[4] = 'o';
  hello[5] = ' ';
  hello[6] = 'W';
  hello[7] = 'o';
  hello[8] = 'r';
  hello[9] = 'l';
  hello[10] = 'd';
  hello[11] = '!';
  hello[12] = '\n';

  cout << hello;
  simplest_mem_manager.free_chars(hello);
  cout << hello;
  
  char* moon = simplest_mem_manager.alloc_chars(11);
  moon[0] = 'm';
  moon[1] = 'o';
  moon[2] = 'o';
  moon[3] = 'n';
  moon[4] = '!';
  moon[5] = ' ';
  moon[6] = 'B';
  moon[7] = 'y';
  moon[8] = 'e';
  moon[9] = '.';
  moon[10] = '\n';
  cout << moon;

  simplest_mem_manager.free_chars(&hello[0]);
  

  return 0;

	// simplest_mem_manager.free_chars(&hello[6]);
	// cout << hello << endl << endl;
	// cout << moon << endl;
	// simplest_mem_manager.free_chars(&hello[0]);
	// 		simplest_mem_manager.free_chars(&moon[0]);


  // simplest_mem_manager.free_chars(&hello[0]);

}

