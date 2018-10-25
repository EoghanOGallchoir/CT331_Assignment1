#include <stdio.h>

int main(int arg, char* argc[]){
	
	private int a;
	private int* b;
	private long c;
	private double* d;
	private char** e;
	
	printf("int size: %d\n", sizeof(a));
	printf("int* size: %d\n", sizeof(b));
	printf("long size: %d\n", sizeof(c));
	printf("double* size: %d\n", sizeof(d));
	printf("char** size: %d\n", sizeof(e));
}
