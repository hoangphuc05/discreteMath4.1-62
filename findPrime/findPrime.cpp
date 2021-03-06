// findPrime.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cmath>
using namespace std;

long int allPrime[100] = { 2 };
int primeCount = 1;

int nextPrime(long int & prime) {
	
	allPrime[primeCount] = prime;
	primeCount++;
	bool isNotPrime = true;
	//++prime;
	//int i = 0;
	while (isNotPrime) {
		++prime;
		for (int i = 0; i < primeCount; i++) {
			
			if (prime%allPrime[i] == 0)
			{
				isNotPrime = true;
				i = primeCount + 1;
			}
			else isNotPrime = false;

			if (allPrime[i] > (prime / 2)) i = primeCount + 1;
		}
	}
	return prime;
}

bool checkPrime(int number) {
	bool isNotPrime = true;
	//++prime;
	//int i = 0;
	
		
		for (int i = 0; i < primeCount; i++) {

			if (number%allPrime[i] == 0)
			{
				return false;
				i = primeCount + 1;
			}
			else return true;

			if (allPrime[i] > (number / 2)) i = primeCount + 1;
		}
		
}

int main()
{
	
	long int currentPrime = 3;
	

	while (checkPrime(pow(2, currentPrime) - 1)) {
		nextPrime(currentPrime);
	}
	cout << currentPrime << endl;
	
}

