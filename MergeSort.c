//병합정렬 알고리즘 함수
#include <stdio.h>
#include <stdlib.h>

void mergeSort(int data[], int left, int right) {		//분할과정 재귀적 알고리즘을 통해 가장 작은 배열(인덱스만)로 분할하는 과정
	int mid = left + (right - left) / 2;

	if (left >= right)
		return;

	mergeSort(data, left, mid);
	mergeSort(data, mid + 1, right);

	merge(data, left, mid, right);
}

void merge(int* data, int left, int mid, int right) {		//병합과 정렬 과정
	int* L = (int*)malloc(sizeof(int) * (mid - left + 1));			//왼쪽배열
	int* R = (int*)malloc(sizeof(int) * (right - mid));				//오른쪽배열
	int l = 0, r = 0, k = left;
	for(int i = left; i<=mid; i++){									//왼쪽배열 복사
		L[i - left] = data[i];
	}
	for (int i = mid+1;i <= right;i++) {							//오른쪽배열 복사
		R[i - mid - 1] = data[i];
	}

	while(l < mid - left + 1 && r < right - mid){					//왼쪽배열과 오른쪽배열을 비교하여 정렬하고자 하는 data를 오름차순으로 정렬
		if (L[l] < R[r]) {
			data[k] = L[l];
			l++;
		}
		else {
			data[k] = R[r];
			r++;
		}
		k++;
	}
		
	while (l < mid - left + 1) {		//왼쪽배열에서 남은 값들 처리
		data[k] = L[l];
		l++;
		k++;
	}	
	while (r < right - mid) {			//오른쪽배열에서 남은 값들 처리
		data[k] = R[r];
		r++;
		k++;
	}

	free(L);
	free(R);
}
