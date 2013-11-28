/*
 * =====================================================================================
 *
 *       Filename:  lfsr_4.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/28/2013 08:35:36 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gustavo Banegas (), gustavosouzabanegas@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "lfsr4.h"

LFSR_4::LFSR_4(unsigned int seed){
	TAPS[0] = 0;
	TAPS[1] = 1;
	TAPS[2] = 4;
	for (int i = 0; i < M; i++) {
		bits[i] = (((1 << i) & seed) >> i) == 1;
	}
	for (int i = 0; i < M; i++) {
		bitsOriginal[i] = (((1 << i) & seed) >> i) == 1;
	}
}

LFSR_4::~LFSR_4()
{

}

int LFSR_4::nextInt() {

	int next = 0;
	for (int i = 0; i < M; i++) {
		next |= (bits[i] ? 1 : 0) << i;
	}
	if (next < 0)
		next++;

	bits[M] = false;
	for (int i = 0; i < 3; i++) {
		bits[M] ^= bits[M - TAPS[i]];
	}

	for (int i = 0; i < M; i++) {
		bits[i] = bits[i + 1];
	}
	return next;

}

mpz_class LFSR_4::getPeriod(){
	mpz_class n("0",10);
	mpz_class one("1",10);
	do{
		this->nextInt();
		this->printBits();
		n = n + one;
	} while (!compare(this->bits, this->bitsOriginal));
	return n;
}

bool LFSR_4::compare(bool bits[], bool bitsOriginal[])
{
	for(int i =0; i < this->M; i++){
		if(bits[i] != bitsOriginal[i]){
			return false;
		}
	}
	return true;
}

void LFSR_4::printBits()
{
	std::cout << (this->bits[M] ? 1  : 0) << " -> ";
	for(int i = this->M - 1;  i >=0; i--){
		std::cout << (this->bits[i] ? 1 : 0);
	}
	std::cout <<  std::endl;

}

