#include "stdio.h"
#include <stdlib.h>
#include <iostream> 
#include <iterator> 
#include <map>
using namespace std;
union Example
{
	char firstAttr;
	long secondAttr;
};
typedef enum {
	NOT_DEFINED= 0, MONDAY=1,TUESDAY, WENDSDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY 
} DayEnum;
struct Days
{
	static std::map<int, DayEnum> days;
	static DayEnum getEnumDayById(int id)
	{
		DayEnum day = days[id];
		return day;
	}
	static void staticInitializer()
	{
		Days::days.insert(make_pair(1, DayEnum::MONDAY));
		days.insert(pair<int, DayEnum>(2, DayEnum::TUESDAY));
		days.insert(pair<int, DayEnum>(3, DayEnum::WENDSDAY));
		days.insert(pair<int, DayEnum>(4, DayEnum::THURSDAY));
		days.insert(pair<int, DayEnum>(5, DayEnum::FRIDAY));
		days.insert(pair<int, DayEnum>(6, DayEnum::SATURDAY));
		days.insert(pair<int, DayEnum>(7, DayEnum::SUNDAY));

	}
};
std::map<int, DayEnum> Days::days;


void main()
{
	Days::staticInitializer();
	Example unionEx;
	unionEx.firstAttr = 'A';
	unionEx.secondAttr = 2;
	printf("Union char: %c \n", unionEx.firstAttr);
	printf("Union long: %d \n", unionEx.secondAttr);

	DayEnum day; int value;
	printf("Give day: ");
	scanf("%d", &value);
	day = Days::getEnumDayById(value);
	printf("Day is: %d \n", day);

	char buffer[] = {"Initializer"};

	char* ptrBuf = new char[strlen(buffer) + 1];
	char* ptrBuf1 = (char*)malloc(strlen(buffer) + 1);
	// *buffer
	//sizeof(ptrBuf1);
	//ptrBuf+i
	int** matrix;
	//matrix[i][j]
	//(matrix+i)[j]
	//*(*(matrix+i)+j)
	printf("%s\n", buffer);

	int vect[4] = { 1,2,3,4 };
	printf("%d\n", vect[8]);
}