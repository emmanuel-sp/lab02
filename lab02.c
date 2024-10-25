#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Converts integer into bits
void convert(int bits[] , int n);
//Calculates hamming distance given two integer array represent binary string
int hDistance(int bits1[], int bits2[]);
// Prints out bits
void printBits(int bits[], int n);

int g = 33; // Used to calculate the last index of larger bit

/**
 * Calculate Hamming Distance
 */
int main(int argc, char * argv[]) {
	int str1[33] = {};
	int str2[33] = {};
	int first = atoi(argv[1]);
	int second = atoi(argv[2]);
	convert(str1, first);
	convert(str2, second);
	printBits(str1, first);
	printBits(str2, second);
	printf("%d is the Hamming distance between the bit strings\n", hDistance(str1, str2));
	return 0;
}

void convert(int bits[], int n) {
	int i = 32;
	while (n != 0) {
		bits[i--] = n % 2;
		n = n / 2;
	}
	i++;
	g = g < i ? g : i;
}
void printBits(int bits[], int n) {
	int i = g;
	while (i < 33) {
		printf("%d", bits[i++]);
	}
	printf(" is the bit string for %d\n", n);
}

int hDistance(int bits1[], int bits2[]) {
	int i = g;
	int j = g;
	int count = 0;
	while (i < 33) {
		if (bits1[i++] != bits2[j++]) {
			count++;
		}
	}
	return count;
}
