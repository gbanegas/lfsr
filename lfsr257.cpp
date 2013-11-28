#include "lfsr257.h"

LFSR_257::LFSR_257(unsigned int seed){
	TAPS[0] = 0;
	TAPS[1] = 192;
	TAPS[2] = 257;
	for (int i = 0; i < M; i++) {
		bits[i] = (((1 << i) & seed) >> i) == 1;
	}
	for (int i = 0; i < M; i++) {
		bitsOriginal[i] = (((1 << i) & seed) >> i) == 1;
	}
}

LFSR_257::~LFSR_257()
{

}

int LFSR_257::nextInt() {

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

mpz_class LFSR_257::getPeriod(){
	mpz_class n("0",10);
	mpz_class one("1",10);
	do{
		this->nextInt();
		this->printBytes();
		n = n + one;
	} while (!compare(this->bits, this->bitsOriginal));
	return n;
}

bool LFSR_257::compare(bool bits[], bool bitsOriginal[])
{
	for(int i =0; i < this->M; i++){
		if(bits[i] != bitsOriginal[i]){
			return false;
		}
	}
	return true;
}

void LFSR_257::printBytes()
{
	std::cout << (this->bits[M] ? 1  : 0) << " -> " << std::endl;
	for(int i = this->M - 1;  i >=0; i--){
		std::cout << (this->bits[i] ? 1 : 0);
	}
	std::cout <<  std::endl;

}

