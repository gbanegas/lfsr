#ifndef LFSR_H
#define LFSR_H

#include <cmath>
#include <gmp.h>
#include <gmpxx.h>
class LFSR;

class LFSR
{
public:
	virtual ~LFSR() {};
	virtual mpz_class getPeriod() = 0;
	virtual int nextInt() = 0;

};
#endif
