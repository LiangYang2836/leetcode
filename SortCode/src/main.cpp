/*
 * main.cpp
 *
 *  Created on: Apr 9, 2017
 *      Author: yl
 */

#include <iostream>
using namespace std;

void Swap(int &a, int &b) {
	if (a != b) {
		a ^= b;
		b ^= a;
		a ^= b;
	}
}

void HeapAdjust(int arr[], int start, int len) {

	if (arr == NULL) {
		return;
	}

	for (int i = 2 * start + 1; i < len; i = i * 2 + 1) {
		if ((i + 1) < len && arr[i] < arr[i + 1]) {
			i++;
		}

		if (arr[start] > arr[i]) {
			break;
		}

		Swap(arr[start], arr[i]);
		start = i;
	}
}

void HeapSort(int arr[], int len) {

	if (arr == NULL) {
		return;
	}

	for (int i = len / 2 - 1; i >= 0; i--) {
		HeapAdjust(arr, i, len);
	}

	for (int i = len - 1; i >= 0; i--) {
		Swap(arr[0], arr[i]);
		HeapAdjust(arr, 0, i);
	}

}

int Partition(int arr[], int low, int high) {
	if (arr == NULL) {
		return low;
	}

	int tmp = arr[low];
	while (low < high) {
		while (low < high && arr[high] > tmp) {
			high--;
		}

		if (low < high) {
			Swap(arr[low], arr[high]);
			low++;
		}

		while (low < high && arr[low] < tmp) {
			low++;
		}

		if (low < high) {
			Swap(arr[low], arr[high]);
			high--;
		}
	}

	return low;
}

void QuickSort(int arr[], int low, int high) {
	if (arr == NULL) {
		return;
	}

	if (low < high) {
		int position = Partition(arr, low, high);
		QuickSort(arr, low, position - 1);
		QuickSort(arr, position + 1, high);
	}
}

void QuickSort2(int arr[], int low, int high) {
	if (arr == NULL) {
		return;
	}

	if (low < high) {
		int i = low;
		int j = high;
		int tmp = arr[i];
		while (i < j) {
			while (i < j && arr[j] > tmp) {
				j--;
			}
			if (i < j) {
				Swap(arr[i], arr[j]);
				i++;
			}
			while (i < j && arr[i] < tmp) {
				i++;
			}
			if (i < j) {
				Swap(arr[i], arr[j]);
				j--;
			}
		}
		QuickSort(arr, low, i - 1);
		QuickSort(arr, i + 1, high);
	}
}

void MergeArray(int arr[], int start, int mid, int end, int tmp_arr[]) {
	if (arr == NULL || tmp_arr == NULL) {
		return;
	}

//	cout << start << "-" << mid << "-" << end << endl;
//	cout << arr[start] << "==" << arr[mid] << "==" << arr[end] << endl;

	int i_start = start;
	int j_start = mid + 1;
	int i_end = mid;
	int j_end = end;
	int tmp_index = 0;
	while (i_start <= i_end && j_start <= j_end) {
		if (arr[i_start] < arr[j_start]) {
			tmp_arr[tmp_index++] = arr[i_start++];
		} else {
			tmp_arr[tmp_index++] = arr[j_start++];
		}
	}

	while (i_start <= i_end) {
		tmp_arr[tmp_index++] = arr[i_start++];
	}

	while (j_start <= j_end) {
		tmp_arr[tmp_index++] = arr[j_start++];
	}

	for (int i = 0; i < tmp_index; i++) {
		arr[start + i] = tmp_arr[i];
	}

}

void Merge(int arr[], int start, int end, int tmp_arr[]) {
	if (arr == NULL || tmp_arr == NULL) {
		return;
	}

	if (start < end) {
		int mid = (start + end) / 2;
		Merge(arr, start, mid, tmp_arr);
		Merge(arr, mid + 1, end, tmp_arr);
		MergeArray(arr, start, mid, end, tmp_arr);
	}
}

void MergeSort(int arr[], int len) {

	if (arr == NULL) {
		return;
	}

	int *tmp_arr = new int[len];
	Merge(arr, 0, len - 1, tmp_arr);
	delete []tmp_arr;
}

void InsertSort(int arr[], int len) {

	if (arr == NULL) {
		return;
	}

	for (int i = 1; i < len; i++) {
		for (int j = i - 1; j >=0 && arr[j] > arr[j + 1]; j--) {
			Swap(arr[j], arr[j + 1]);
		}
	}
}

void ShellSort(int arr[], int len) {

	if (arr == NULL) {
		return;
	}

	for (int gap = len / 2; gap > 0; gap = gap >> 1) {
		for (int i = gap; i < len; i++) {
			for (int j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap) {
				Swap(arr[j], arr[j + gap]);
			}
		}
	}
}

void SelectSort(int arr[], int len) {

	if (arr == NULL) {
		return;
	}

	int min_index = 0;
	for (int i = 0; i < len - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < len; j++) {
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}

		Swap(arr[i], arr[min_index]);
	}
}

void BubbleSort(int arr[], int len) {

	if (arr == NULL) {
		return;
	}

	int k = 0;
	int flag = len;
	while (flag > 0) {
		k = flag;
		flag = 0;
		for (int i = 1; i < k; i++) {
			if (arr[i - 1] > arr[i]) {
				Swap(arr[i - 1], arr[i]);
				flag = i;
			}
		}
	}
}

int main() {

	int arr[] = {49, 48, 65, 97, 76, 13, 27, 49};
	int len = sizeof(arr) / sizeof(int);
//	HeapSort(arr, len);
//	QuickSort(arr, 0, len - 1);
//	MergeSort(arr, len);
//	InsertSort(arr, len);
//	ShellSort(arr, len);
//	SelectSort(arr, len);
	BubbleSort(arr, len);
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}


