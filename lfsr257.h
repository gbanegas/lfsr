#ifndef LFSR_257_H
#define LFSR_257_H
#include "lfsr.h"

#include <cmath>
#include <gmp.h>
#include <gmpxx.h>
#include <iostream>

class LFSR_257 : public LFSR {

static const int M = 257;

public:
	LFSR_257(unsigned int seed);
	~LFSR_257();
	virtual int nextInt();
	virtual mpz_class getPeriod();
	void printBytes();
private:
	bool compare(bool bits[],bool bitsOriginal[]);
	int TAPS[3];
	bool bits[M+1];
	bool bitsOriginal[M+1];

};
#endif
