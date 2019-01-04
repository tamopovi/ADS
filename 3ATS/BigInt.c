#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "BigInt.h"

#define STARTING_SIZE 8

typedef struct Int
{
	int isDefined;
	unsigned int size;
	unsigned char* bytes;
} Int;

//Constructors
Int* Int_create(int a);

//Destructors
void Int_delete(Int* a);

//Converters
void Int_copy(Int* dest, Int* src);
void Int_fromInt(Int* result, int a);
int Int_fromString(Int* result, char* str);
int Int_toInt(Int* a);
void Int_toString(Int* a, char* str, int strLength);
void Int_toHexString(Int* a, char* str, int strLength);

//Basic operations
void Int_negate(Int* acc);
void Int_add(Int* acc, Int* op);
void Int_subtract(Int* acc, Int* op);
void Int_multiply(Int* acc, Int* op);
int Int_divide(Int* acc, Int* op);
int Int_remainder(Int* acc, Int* op);

//Advanced operations
void Int_abs(Int* acc);
int Int_mod(Int* acc, Int* modulo);
int Int_pow(Int* acc, Int* power);
int Int_integerRoot(Int* acc, Int* root);

//Comparisons
int Int_isEqual(Int* a, Int* b);
int Int_isGreater(Int* a, Int* b);
int Int_isGreaterOrEqual(Int* a, Int* b);
int Int_isLess(Int* a, Int* b);
int Int_isLessOrEqual(Int* a, Int* b);

//State queries
int Int_isPositive(Int* a);
int Int_isNegative(Int* a);
int Int_isZero(Int* a);
int Int_isDefined(Int* a);

//Internal
unsigned char Int_internal_getByte(Int* a, unsigned int index);
void Int_internal_setByte(Int* a, unsigned int index, unsigned char byte);
void Int_internal_shiftLeft(Int* a);
void Int_internal_shiftArithmeticRight(Int* a);
int Int_internal_isGreaterUnsigned(Int* a, Int* b);
Int* Int_internal_allocate(unsigned int size);
void Int_internal_allocateBytes(Int* a, unsigned int size);
void Int_internal_deallocateBytes(Int* a);
void Int_internal_deallocate(Int* a);
void Int_internal_resize(Int* a, unsigned int size);
void Int_internal_resizeToFit(Int* a);

////////////////////////////////////////////////////////

unsigned char bytes_MINUS_TEN[] = {0xF6, 0xFF};
unsigned char bytes_MINUS_NINE[] = {0xF7, 0xFF};
unsigned char bytes_MINUS_EIGHT[] = {0xF8, 0xFF};
unsigned char bytes_MINUS_SEVEN[] = {0xF9, 0xFF};
unsigned char bytes_MINUS_SIX[] = {0xFA, 0xFF};
unsigned char bytes_MINUS_FIVE[] = {0xFB, 0xFF};
unsigned char bytes_MINUS_FOUR[] = {0xFC, 0xFF};
unsigned char bytes_MINUS_THREE[] = {0xFD, 0xFF};
unsigned char bytes_MINUS_TWO[] = {0xFE, 0xFF};
unsigned char bytes_MINUS_ONE[] = {0xFF, 0xFF};
unsigned char bytes_ZERO[] = {0x00, 0x00};
unsigned char bytes_ONE[] = {0x01, 0x00};
unsigned char bytes_TWO[] = {0x02, 0x00};
unsigned char bytes_THREE[] = {0x03, 0x00};
unsigned char bytes_FOUR[] = {0x04, 0x00};
unsigned char bytes_FIVE[] = {0x05, 0x00};
unsigned char bytes_SIX[] = {0x06, 0x00};
unsigned char bytes_SEVEN[] = {0x07, 0x00};
unsigned char bytes_EIGHT[] = {0x08, 0x00};
unsigned char bytes_NINE[] = {0x09, 0x00};
unsigned char bytes_TEN[] = {0x0A, 0x00};

Int Int_STR_MINUS_TEN = {1, 2, bytes_MINUS_TEN};
Int Int_STR_MINUS_NINE = {1, 2, bytes_MINUS_NINE};
Int Int_STR_MINUS_EIGHT = {1, 2, bytes_MINUS_EIGHT};
Int Int_STR_MINUS_SEVEN = {1, 2, bytes_MINUS_SEVEN};
Int Int_STR_MINUS_SIX = {1, 2, bytes_MINUS_SIX};
Int Int_STR_MINUS_FIVE = {1, 2, bytes_MINUS_FIVE};
Int Int_STR_MINUS_FOUR = {1, 2, bytes_MINUS_FOUR};
Int Int_STR_MINUS_THREE = {1, 2, bytes_MINUS_THREE};
Int Int_STR_MINUS_TWO = {1, 2, bytes_MINUS_TWO};
Int Int_STR_MINUS_ONE = {1, 2, bytes_MINUS_ONE};
Int Int_STR_ZERO = {1, 2, bytes_ZERO};
Int Int_STR_ONE = {1, 2, bytes_ONE};
Int Int_STR_TWO = {1, 2, bytes_TWO};
Int Int_STR_THREE = {1, 2, bytes_THREE};
Int Int_STR_FOUR = {1, 2, bytes_FOUR};
Int Int_STR_FIVE = {1, 2, bytes_FIVE};
Int Int_STR_SIX = {1, 2, bytes_SIX};
Int Int_STR_SEVEN = {1, 2, bytes_SEVEN};
Int Int_STR_EIGHT = {1, 2, bytes_EIGHT};
Int Int_STR_NINE = {1, 2, bytes_NINE};
Int Int_STR_TEN = {1, 2, bytes_TEN};

Int* Int_MINUS_TEN = &Int_STR_MINUS_TEN;
Int* Int_MINUS_NINE = &Int_STR_MINUS_NINE;
Int* Int_MINUS_EIGHT = &Int_STR_MINUS_EIGHT;
Int* Int_MINUS_SEVEN = &Int_STR_MINUS_SEVEN;
Int* Int_MINUS_SIX = &Int_STR_MINUS_SIX;
Int* Int_MINUS_FIVE = &Int_STR_MINUS_FIVE;
Int* Int_MINUS_FOUR = &Int_STR_MINUS_FOUR;
Int* Int_MINUS_THREE = &Int_STR_MINUS_THREE;
Int* Int_MINUS_TWO = &Int_STR_MINUS_TWO;
Int* Int_MINUS_ONE = &Int_STR_MINUS_ONE;
Int* Int_ZERO = &Int_STR_ZERO;
Int* Int_ONE = &Int_STR_ONE;
Int* Int_TWO = &Int_STR_TWO;
Int* Int_THREE = &Int_STR_THREE;
Int* Int_FOUR = &Int_STR_FOUR;
Int* Int_FIVE = &Int_STR_FIVE;
Int* Int_SIX = &Int_STR_SIX;
Int* Int_SEVEN = &Int_STR_SEVEN;
Int* Int_EIGHT = &Int_STR_EIGHT;
Int* Int_NINE = &Int_STR_NINE;
Int* Int_TEN = &Int_STR_TEN;

//Constructors
Int* Int_create(int a)
{
	unsigned int bits;
	unsigned int i;
	Int* integer = Int_internal_allocate(STARTING_SIZE);
	if(a >= 0)
	{
		bits = (unsigned int)a;
	}
	else
	{
		bits = (unsigned int)(-a);
	}
	for(i = 0;i < integer->size;i++)
	{
		if(bits != 0)
		{
			Int_internal_setByte(integer, i, (unsigned char)bits);
			bits = bits >> 8;
		}
		else
		{
			break;
		}
	}
	if(a < 0)
	{
		Int_negate(integer);
	}
	return integer;
}

//Destructors
void Int_delete(Int* a)
{
	Int_internal_deallocate(a);
}

//Converters
void Int_copy(Int* dest, Int* src)
{
	unsigned int i;
	Int_internal_deallocateBytes(dest);
	Int_internal_allocateBytes(dest, src->size);
	for(i = 0;i < src->size;i++)
	{
		unsigned char a = Int_internal_getByte(src, i);
		Int_internal_setByte(dest, i, a);
	}
	dest->isDefined = src->isDefined;
}

void Int_fromInt(Int* result, int a)
{
	Int* integer = Int_create(a);
	Int_copy(result, integer);
	Int_delete(integer);
}

int Int_fromString(Int* result, char* str)
{
	int strLength = strlen(str);
	unsigned char stack[strLength];
	int stackIndex = -1;
	int negative;
	int i;
	Int* integer;
	Int* power;
	if(strLength == 0)
	{
		result->isDefined = 0;
		return 0;
	}
	if(str[0] == '-')
	{
		negative = 1;
		if(strLength <= 1)
		{
			result->isDefined = 0;
			return 0;
		}
	}
	else if(str[0] == '+')
	{
		negative = 0;
		if(strLength <= 1)
		{
			result->isDefined = 0;
			return 0;
		}
	}
	else if(str[0] >= '0' && str[0] <= '9')
	{
		negative = 0;
		stackIndex++;
		stack[stackIndex] = str[0] - '0';
	}
	else
	{
		result->isDefined = 0;
		return 0;
	}
	for(i = 1;i < strLength;i++)
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			stackIndex++;
			stack[stackIndex] = str[i] - '0';
		}
		else
		{
			result->isDefined = 0;
			return 0;
		}
	}
	integer = Int_create(0);
	power = Int_create(1);
	for(;stackIndex >= 0;stackIndex--)
	{
		Int* temp = Int_create((int)stack[stackIndex]);
		Int_multiply(temp, power);
		Int_add(integer, temp);
		Int_delete(temp);
		Int_multiply(power, Int_TEN);
	}
	if(negative)
	{
		Int_negate(integer);
	}
	Int_copy(result, integer);
	Int_delete(integer);
	Int_delete(power);
	return 1;
}

int Int_toInt(Int* a)
{
	unsigned int result = 0;
	int i;
	for(i = 0;i < a->size;i++)
	{
		result = result | (((unsigned int)Int_internal_getByte(a, i)) << (8 * i));
	}
	return (int)result;
}

void Int_toString(Int* a, char* str, int length)
{
	unsigned char stack[length];
	int stackIndex = -1;
	int i;
	Int* integer;
	if(length < 4)
	{
		return;
	}
	if(!Int_isDefined(a))
	{
		strcpy(str, "NaN");
		return;
	}
	integer = Int_create(0);
	Int_copy(integer, a);
	if(Int_isNegative(a))
	{
		Int_negate(integer);
	}

	do
	{
		int tmp;
		Int* remainder = Int_create(0);
		Int_copy(remainder, integer);
		Int_remainder(remainder, Int_TEN);

		tmp = Int_toInt(remainder);
		
		stackIndex++;
		stack[stackIndex] = ((unsigned char)tmp) + '0';

		Int_divide(integer, Int_TEN);
		Int_delete(remainder);
	}while(!Int_isZero(integer));

	Int_delete(integer);

	i = 0;
	if(Int_isNegative(a))
	{
		str[0] = '-';
		i = 1;
	}
	for(;stackIndex >= 0 && i < length - 1;stackIndex--, i++)
	{
		str[i] = stack[stackIndex];
	}
	str[i] = '\0';
}

void Int_toHexString(Int* a, char* str, int length)
{
	int i;
	int index = 0;
	char* dictionary = "0123456789ABCDEF";
	Int* integer;
	if(length < 4)
	{
		return;
	}
	if(!Int_isDefined(a))
	{
		strcpy(str, "NaN");
		return;
	}
	integer = Int_create(-10);
	Int_copy(integer, a);
	Int_internal_resizeToFit(integer);
	for(i = integer->size - 1;i >= 0 && index < length - 2;i--, index += 2)
	{
		str[index] = dictionary[(Int_internal_getByte(integer, i) >> 4) & 0x0F];
		str[index + 1] = dictionary[Int_internal_getByte(integer, i) & 0x0F];
	}
	str[index] = '\0';
	Int_delete(integer);
}

//Basic operations
void Int_negate(Int* acc)
{
	unsigned int i;
	for(i = 0;i < acc->size;i++)
	{
		unsigned char result = Int_internal_getByte(acc, i);
		result = ~result;
		Int_internal_setByte(acc, i, result);
	}
	Int_add(acc, Int_ONE);
}

void Int_add(Int* acc, Int* op)
{
	unsigned char carry = 0;
	unsigned int i;
	Int* operand = Int_create(0);
	Int_copy(operand, op);
	if(acc->size < operand->size)
	{
		Int_internal_resize(acc, operand->size + 1);
	}
	for(i = 0;i < acc->size;i++)
	{
		unsigned int sum = (unsigned int)Int_internal_getByte(acc, i) + (unsigned int)Int_internal_getByte(operand, i) + (unsigned int)carry;
		carry = (unsigned char)(sum >> 8);
		Int_internal_setByte(acc, i, (unsigned char)sum);
	}
	Int_internal_resizeToFit(acc);
	Int_delete(operand);
}

void Int_subtract(Int* acc, Int* op)
{
	Int* operand = Int_create(0);
	Int_copy(operand, op);
	Int_negate(operand);
	Int_add(acc, operand);
	Int_delete(operand);
}

void Int_multiply(Int* acc, Int* op)
{
	unsigned int i;
	unsigned int j;
	int sign = Int_isNegative(acc) ^ Int_isNegative(op);
	Int* operand = Int_create(0);
	Int* result = Int_create(0);
	Int_copy(operand, op);
	Int_abs(acc);
	Int_abs(operand);
	for(i = 0;i < acc->size;i++)
	{
		unsigned char byte = Int_internal_getByte(acc, i);
		for(j = 0;j < 8;j++)
		{
			if((byte >> j) & 0x01)
			{
				Int_add(result, operand);
			}
			Int_internal_shiftLeft(operand);
		}
	}
	if(sign)
	{
		Int_negate(result);
	}
	Int_copy(acc, result);
	Int_delete(operand);
	Int_delete(result);
}

int Int_divide(Int* acc, Int* op)
{
	if(Int_isZero(op))
	{
		acc->isDefined = 0;
		return 0;
	}
	Int* dividend = Int_create(0);
	Int* divisor = Int_create(0);
	Int* quotient = Int_create(0);
	int signDividend = 0;
	int signDivisor = 0;
	int i = 0;
	Int_copy(dividend, acc);
	Int_copy(divisor, op);
	if(Int_isNegative(dividend))
	{
		signDividend = 1;
		Int_negate(dividend);
	}
	if(Int_isNegative(divisor))
	{
		signDivisor = 1;
		Int_negate(divisor);
	}

	if(Int_isGreaterOrEqual(dividend, divisor))
	{
		while(Int_isLessOrEqual(divisor, dividend))
		{
			Int_internal_shiftLeft(divisor);
			i++;
		}
		Int_internal_shiftArithmeticRight(divisor);
		i--;

		for(;i >= 0;i--)
		{
			Int_internal_shiftLeft(quotient);
			if(Int_isGreaterOrEqual(dividend, divisor))
			{
				Int_subtract(dividend, divisor);
				Int_add(quotient, Int_ONE);
			}
			Int_internal_shiftArithmeticRight(divisor);
		}
	}
	if(signDividend)
	{
		Int_negate(dividend);
	}
	if(signDividend ^ signDivisor)
	{
		Int_negate(quotient);
	}
	Int_copy(acc, quotient);

	Int_delete(dividend);
	Int_delete(divisor);
	Int_delete(quotient);
	return 1;
}

int Int_remainder(Int* acc, Int* op)
{
	if(Int_isZero(op))
	{
		acc->isDefined = 0;
		return 0;
	}
	Int* dividend = Int_create(0);
	Int* divisor = Int_create(0);
	Int* quotient = Int_create(0);
	int signDividend = 0;
	int signDivisor = 0;
	int i = 0;
	Int_copy(dividend, acc);
	Int_copy(divisor, op);
	if(Int_isNegative(dividend))
	{
		signDividend = 1;
		Int_negate(dividend);
	}
	if(Int_isNegative(divisor))
	{
		signDivisor = 1;
		Int_negate(divisor);
	}

	if(Int_isGreaterOrEqual(dividend, divisor))
	{
		while(Int_isLessOrEqual(divisor, dividend))
		{
			Int_internal_shiftLeft(divisor);
			i++;
		}
		Int_internal_shiftArithmeticRight(divisor);
		i--;

		for(;i >= 0;i--)
		{
			Int_internal_shiftLeft(quotient);
			if(Int_isGreaterOrEqual(dividend, divisor))
			{
				Int_subtract(dividend, divisor);
				Int_add(quotient, Int_ONE);
			}
			Int_internal_shiftArithmeticRight(divisor);
		}
	}
	if(signDividend)
	{
		Int_negate(dividend);
	}
	if(signDividend ^ signDivisor)
	{
		Int_negate(quotient);
	}
	Int_copy(acc, dividend);

	Int_delete(dividend);
	Int_delete(divisor);
	Int_delete(quotient);
	return 1;
}

//Advanced operations
void Int_abs(Int* acc)
{
	if(Int_isNegative(acc))
	{
		Int_negate(acc);
	}
}

int Int_mod(Int* acc, Int* modulo)
{
	Int* remainder;
	if(!Int_isGreater(modulo, Int_ZERO))
	{
		acc->isDefined = 0;
		return 0;
	}
	remainder = Int_create(0);
	Int_copy(remainder, acc);
	Int_remainder(remainder, modulo);
	if(Int_isNegative(remainder))
	{
		Int_add(remainder, modulo);
	}
	Int_copy(acc, remainder);
	Int_delete(remainder);
	return 1;
}

int Int_pow(Int* acc, Int* power)
{
	if(Int_isNegative(power) || (Int_isZero(acc) && Int_isZero(power)))
	{
		acc->isDefined = 0;
		return 0;
	}
	if(Int_isZero(power))
	{
		Int_copy(acc, Int_ONE);
		return 1;
	}
	
	Int* tempAcc = Int_create(1);
	Int* tempPower = Int_create(0);
	Int_copy(tempPower, power);
	for(;!Int_isZero(tempPower);Int_add(tempPower, Int_MINUS_ONE))
	{
		Int_multiply(tempAcc, acc);
	}
	Int_copy(acc, tempAcc);
	Int_delete(tempAcc);
	Int_delete(tempPower);
	return 1;
}

int Int_integerRoot(Int* acc, Int* root)
{
	Int* integer;
	Int* min;
	Int* max;
	Int* middle;
	Int* test;
	int sign;
	
	if(Int_isNegative(root) || Int_isZero(root))
	{
		acc->isDefined = 0;
		return 0;
	}
	sign = Int_isNegative(acc);
	if(sign && !(Int_internal_getByte(acc, 0) & 0x01))
	{
		acc->isDefined = 0;
		return 0;
	}
	integer = Int_create(0);
	Int_copy(integer, acc);
	if(sign)
	{
		Int_negate(integer);
	}
	min = Int_create(0);
	max = Int_create(0);
	middle = Int_create(0);
	test = Int_create(0);
	Int_copy(max, integer);
	while(1)
	{
		Int_copy(test, max);
		Int_subtract(test, min);
		if(Int_isEqual(test, Int_ONE))
		{
			if(sign)
			{
				Int_negate(min);
			}
			Int_copy(acc, min);
			Int_delete(integer);
			Int_delete(min);
			Int_delete(max);
			Int_delete(middle);
			Int_delete(test);
			return 0;
		}
		Int_copy(middle, min);
		Int_add(middle, max);
		Int_internal_shiftArithmeticRight(middle);
		Int_copy(test, middle);
		Int_pow(test, root);
		if(Int_isEqual(test, integer))
		{
			if(sign)
			{
				Int_negate(middle);
			}
			Int_copy(acc, middle);
			Int_delete(integer);
			Int_delete(min);
			Int_delete(max);
			Int_delete(middle);
			Int_delete(test);
			return 1;
		}
		else if(Int_isGreater(test, integer))
		{
			Int_copy(max, middle);
		}
		else
		{
			Int_copy(min, middle);
		}
	}
}

//Comparisons
int Int_isEqual(Int* a, Int* b)
{
	int i;
	int maxSize = (a->size > b->size) ? a->size : b->size;
	int result = 1;
	for(i = 0;i < maxSize;i++)
	{
		result = result && (Int_internal_getByte(a, i) == Int_internal_getByte(b, i));
	}
	return result;
}

int Int_isGreater(Int* a, Int* b)
{
	Int* integer = Int_create(0);
	int signA = Int_isNegative(a);
	int signB = Int_isNegative(b);
	Int_copy(integer, a);
	if(signA)
	{
		Int_negate(integer);
	}
	if(signB)
	{
		Int_add(integer, b);
	}
	else
	{
		Int_subtract(integer, b);
	}
	int result = !Int_isNegative(integer) && !Int_isEqual(integer, Int_ZERO);
	if(!signA && signB)
	{
		result = 1;
	}
	else if(signA && !signB)
	{
		result = 0;
	}
	else if(signA == signB)
	{
		if(signA)
		{
			result = !result;
		}
		else
		{
			result = result;
		}
	}
	Int_delete(integer);
	return result;
}

int Int_isGreaterOrEqual(Int* a, Int* b)
{
	return Int_isGreater(a, b) || Int_isEqual(a, b);
}

int Int_isLess(Int* a, Int* b)
{
	return !Int_isGreaterOrEqual(a, b);
}

int Int_isLessOrEqual(Int* a, Int* b)
{
	return Int_isLess(a, b) || Int_isEqual(a, b);
}

//State queries
int Int_isPositive(Int* a)
{
	return !Int_isNegative(a) && !Int_isZero(a);
}

int Int_isNegative(Int* a)
{
	return (int)(Int_internal_getByte(a, a->size) >> 7);
}

int Int_isZero(Int* a)
{
	return Int_isEqual(a, Int_ZERO);
}

int Int_isDefined(Int* a)
{
	return a->isDefined;
}

//Internal
unsigned char Int_internal_getByte(Int* a, unsigned int index)
{
	if(index >= a->size)
	{
		return (a->bytes[a->size - 1] >> 7) * 0xFF;
	}
	else
	{
		return a->bytes[index];
	}
}

void Int_internal_setByte(Int* a, unsigned int index, unsigned char byte)
{
	if(index < a->size)
	{
		a->bytes[index] = byte;
	}
}

void Int_internal_shiftLeft(Int* a)
{
	Int_add(a, a);
}

void Int_internal_shiftArithmeticRight(Int* a)
{
	int i;
	for(i = 0;i < a->size;i++)
	{
		a->bytes[i] = (Int_internal_getByte(a, i + 1) << 7) | (a->bytes[i] >> 1);
	}
}

int Int_internal_isGreaterUnsigned(Int* a, Int* b)
{
	int i;
	int maxSize = (a->size > b->size) ? a->size : b->size;
	for(i = maxSize - 1;i >= 0;i--)
	{
		if(Int_internal_getByte(a, i) > Int_internal_getByte(b, i))
		{
			return 1;
		}
		else if(Int_internal_getByte(a, i) < Int_internal_getByte(b, i))
		{
			return 0;
		}
	}
	return 0;
}

Int* Int_internal_allocate(unsigned int size)
{
	Int* integer = (Int*)malloc(sizeof(Int));
	if(integer != NULL)
	{
		integer->isDefined = 1;
		integer->size = size;
		integer->bytes = (unsigned char*)calloc(sizeof(unsigned char), size);
	}
	return integer;
}

void Int_internal_allocateBytes(Int* a, unsigned int size)
{
	a->isDefined = 1;
	a->size = size;
	a->bytes = (unsigned char*)calloc(sizeof(unsigned char), size);
}

void Int_internal_deallocateBytes(Int* a)
{
	free(a->bytes);
}

void Int_internal_deallocate(Int* a)
{
	free(a->bytes);
	free(a);
}

void Int_internal_resize(Int* a, unsigned int size)
{
	unsigned int minSize = a->size;
	unsigned char leading;
	unsigned int newSize;
	unsigned char* newBytes;
	unsigned int i;
	if(Int_isNegative(a))
	{
		leading = 0xFF;
	}
	else
	{
		leading = 0x00;
	}
	for(i = a->size - 1;i > 0;i--)
	{
		if(Int_internal_getByte(a, i) != leading)
		{
			break;
		}
	}
	minSize = i + 2;

	newSize = (size > minSize) ? size : minSize;
	if(newSize == a->size)
	{
		return;
	}
	newBytes = (unsigned char*)malloc(sizeof(unsigned char) * newSize);
	if(newBytes == NULL)
	{
		a->isDefined = 0;
		return;
	}
	for(i = 0;i < newSize;i++)
	{
		newBytes[i] = Int_internal_getByte(a, i);
	}
	free(a->bytes);
	a->size = newSize;
	a->bytes = newBytes;
}

void Int_internal_resizeToFit(Int* a)
{
	unsigned int minSize = a->size;
	unsigned char leading;
	unsigned int newSize;
	unsigned char* newBytes;
	unsigned int i;
	if(Int_isNegative(a))
	{
		leading = 0xFF;
	}
	else
	{
		leading = 0x00;
	}
	for(i = a->size - 1;i > 0;i--)
	{
		if(Int_internal_getByte(a, i) != leading)
		{
			break;
		}
	}
	minSize = i + 2;

	newSize = minSize;
	if(newSize == a->size)
	{
		return;
	}
	newBytes = (unsigned char*)malloc(sizeof(unsigned char) * newSize);
	if(newBytes == NULL)
	{
		a->isDefined = 0;
		return;
	}
	for(i = 0;i < newSize;i++)
	{
		newBytes[i] = Int_internal_getByte(a, i);
	}
	free(a->bytes);
	a->size = newSize;
	a->bytes = newBytes;
}
struct lib_BigInt BigInt = {
	//Constants
	&Int_STR_MINUS_TEN,
	&Int_STR_MINUS_NINE,
	&Int_STR_MINUS_EIGHT,
	&Int_STR_MINUS_SEVEN,
	&Int_STR_MINUS_SIX,
	&Int_STR_MINUS_FIVE,
	&Int_STR_MINUS_FOUR,
	&Int_STR_MINUS_THREE,
	&Int_STR_MINUS_TWO,
	&Int_STR_MINUS_ONE,
	&Int_STR_ZERO,
	&Int_STR_ONE,
	&Int_STR_TWO,
	&Int_STR_THREE,
	&Int_STR_FOUR,
	&Int_STR_FIVE,
	&Int_STR_SIX,
	&Int_STR_SEVEN,
	&Int_STR_EIGHT,
	&Int_STR_NINE,
	&Int_STR_TEN,

	//Constructors
	&Int_create,

	//Destructors
	&Int_delete,

	//Converters
	&Int_copy,
	&Int_fromInt,
	&Int_fromString,
	&Int_toInt,
	&Int_toString,
	&Int_toHexString,

	//Basic operations
	&Int_negate,
	&Int_add,
	&Int_subtract,
	&Int_multiply,
	&Int_divide,
	&Int_remainder,

	//Advanced operations
	&Int_abs,
	&Int_mod,
	&Int_pow,
	&Int_integerRoot,

	//Comparisons
	&Int_isEqual,
	&Int_isGreater,
	&Int_isGreaterOrEqual,
	&Int_isLess,
	&Int_isLessOrEqual,

	//State queries
	&Int_isPositive,
	&Int_isNegative,
	&Int_isZero,
	&Int_isDefined
};
