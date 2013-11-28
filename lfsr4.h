#ifndef LFSR_4_H
#define LFSR_4_H
#include "lfsr.h"

#include <cmath>
#include <gmp.h>
#include <gmpxx.h>
#include <iostream>

class LFSR_4 : public LFSR {

	static const int M = 4;

	public:
	LFSR_4(unsigned int seed);
	~LFSR_4();
	virtual int nextInt();
	virtual mpz_class getPeriod();
	void printBits();
	private:
	bool compare(bool bits[],bool bitsOriginal[]);
	int TAPS[3];
	bool bits[M+1];
	bool bitsOriginal[M+1];

};
#endif

