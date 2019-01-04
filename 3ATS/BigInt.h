#ifndef BIGINT_H
#define BIGINT_H
//use BigInt.[function or constant name]
typedef struct Int Int;

struct lib_BigInt
{
	//Constants
	Int* MINUS_TEN;
	Int* MINUS_NINE;
	Int* MINUS_EIGHT;
	Int* MINUS_SEVEN;
	Int* MINUS_SIX;
	Int* MINUS_FIVE;
	Int* MINUS_FOUR;
	Int* MINUS_THREE;
	Int* MINUS_TWO;
	Int* MINUS_ONE;
	Int* ZERO;
	Int* ONE;
	Int* TWO;
	Int* THREE;
	Int* FOUR;
	Int* FIVE;
	Int* SIX;
	Int* SEVEN;
	Int* EIGHT;
	Int* NINE;
	Int* TEN;

	//Constructors
	Int* (*create)(int a); // Create new big integer instance with value a.

	//Destructors
	void (*delete)(Int* a); // Delete chosen big integer instance.

	//Converters
	void (*copy)(Int* dest, Int* src); // Copy one big integer to another big integer.
	void (*fromInt)(Int* result, int a); //Convert a value given in int into big integer value.
	int (*fromString)(Int* result, char* str); // convert a value given in string into big integer value, use only decimal digits. return 1 is if everything is good, return 0 if error.
	int (*toInt)(Int* a); // convert given big integer to basic int. return 1 if everything is good, return 0 if error.
	void (*toString)(Int* a, char* str, int strLength); // convert given integer to a string of a maximum characters.
	void (*toHexString)(Int* a, char* str, int strLength); // convert given integer to a hex string of a maximum characters.

	//Basic operations
	void (*negate)(Int* acc); // change big integer value to negative.
	void (*add)(Int* acc, Int* op); // add two big integer values and store the result in acc.
	void (*subtract)(Int* acc, Int* op); // subtract op from acc and store the result in acc.
	void (*multiply)(Int* acc, Int* op); // multiply acc by op and store the result in acc.
	int (*divide)(Int* acc, Int* op);// divide acc by op and store the result in acc. return 0 if given acc is NaN.
	int (*remainder)(Int* acc, Int* op); // divide the acc by op and store the result in acc. return 0 if given acc is NaN.

	//Advanced operations
	void (*abs)(Int* acc); // set the value of acc into absolute value.
	int (*mod)(Int* acc, Int* modulo); // return the remainder acc / modulo in the range of 0; modulo - 1
	int (*pow)(Int* acc, Int* power); // raise the acc to the given power and store the result in acc. return 0 if acc is NaN
	int (*integerRoot)(Int* acc, Int* root); // Find the any root of given acc and store the result in acc. return 0 if acc is NaN or the root is not an exact integer. In the case of the non-integer root, the value of acc is the truncated root.

	//Comparisons
	int (*isEqual)(Int* a, Int* b);// return 1 if a and b are equal
	int (*isGreater)(Int* a, Int* b);//return 1 is a > b
	int (*isGreaterOrEqual)(Int* a, Int* b);//return 1 if a >= b
	int (*isLess)(Int* a, Int* b);//return 1 if a < b
	int (*isLessOrEqual)(Int* a, Int* b); // return 1 if a <= b

	//State queries
	int (*isPositive)(Int* a);// return 1 if a is positive.
	int (*isNegative)(Int* a);// return 1 if a is negative.
	int (*isZero)(Int* a); // return 1 if a is equal to zero.
	int (*isDefined)(Int* a);// return 1 if given a is not a NaN.
};

extern struct lib_BigInt BigInt;

#endif
