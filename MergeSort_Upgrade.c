#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//백준 안정정렬문제

typedef struct {
	int age;
	char name[102];
}Guest;

void mergeSort(Guest* data, int left, int right);
void merge(Guest* data, int left, int mid, int right);



void mergeSort(Guest* data, int left, int right) {		//분할과정 재귀적 알고리즘을 통해 가장 작은 배열(인덱스만)로 분할하는 과정
	int mid = left + (right - left) / 2;

	if (left >= right)
		return;

	mergeSort(data, left, mid);
	mergeSort(data, mid + 1, right);

	merge(data, left, mid, right);
}

void merge(Guest* data, int left, int mid, int right) {
	Guest* tmp = (Guest*)malloc(sizeof(Guest) * (right - left + 1));
	int i = left, j = mid + 1, k = 0;

	while (i <= mid && j <= right) {
		if (data[i].age <= data[j].age) {
			tmp[k++] = data[i++];
		}
		else {
			tmp[k++] = data[j++];
		}
	}

	while (i <= mid) {
		tmp[k++] = data[i++];
	}

	while (j <= right) {
		tmp[k++] = data[j++];
	}

	for (int x = 0; x < k; x++) {
		data[left + x] = tmp[x];
	}

	free(tmp);
}
