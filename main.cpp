/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/27/2013 10:17:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gustavo Banegas (), gustavosouzabanegas@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "lfsr257.h"
#include "lfsr4.h"

#include <iostream>

using namespace std;
int main (int argc, char **argv) {
	
	LFSR_4 lfsr(1);
	
	cout << lfsr.getPeriod() << endl;

	cout << lfsr.nextInt() << endl;
	cout << lfsr.nextInt() << endl;
	lfsr.printBits();
	
	//mpz_class n("48112959837082048697", 10);
	//mpz_class z("1",10);
	//n = z+n;
	//cout << n.get_str() << "\n" << endl;
	return 0;
}
