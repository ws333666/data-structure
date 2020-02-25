/*************************************************************************
    > File Name: 13.binary_search.c
    > Author: ws
    > Mail: ws1519704327@126.com 
    > Created Time: 2020年02月20日 星期四 20时33分25秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define P(func, args...) {\
	printf("%s = %d\n", #func, func(args));\
}

int binary_search1(int *num, int n, int x) {
	int head = 0, tail = n - 1, mid;
	while (head <= tail) {
		mid  = (head + tail) >> 1;
		if (num[mid] == x) return mid;
		if (num[mid] < x) head = mid + 1;
		else tail = mid - 1;
	}
	return -1;
}

int binary_search2(int *num, int n) {
	int head = -1, tail =n, mid;
	while (head < tail) {
		mid = (head + tail + 1) >> 1;
		if (num[mid] == 1) head = mid;
		else tail = mid - 1;
	}
	return head;
}

int binary_search3(int *num, int n) {
	int head = 0, tail = n, mid;
	while (head < tail) {
		mid = (head + tail) >> 1;
		if (num[mid] == 1) tail = mid;
		else head = mid + 1;
	}
	return head == n ? -1 : head;
}

int main() {
	int arr1[10] = {1, 3, 5, 7, 11, 13, 17, 19, 23, 29};
	int arr2[10] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
	int arr3[10] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
	P(binary_search1, arr1, 10, 7);
	P(binary_search2, arr2, 10);
	P(binary_search3, arr3, 10);
	return 0;
}
