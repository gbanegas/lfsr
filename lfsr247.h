#ifndef LFSR_247_H
#define LFSR_247_H
#include "lfsr.h"

#include <cmath>
#include <gmp.h>
#include <gmpxx.h>
#include <iostream>

class LFSR_247 : public LFSR {

static const int M = 247;

public:
	LFSR_247(unsigned int seed);
	~LFSR_247();
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
