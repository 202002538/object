#include <iostream>

int arr[] = { 6,5,4,3,2,1 };

void sort() {
	//직접 구현
	int tmp;
	for (int i = 0; i < sizeof(arr)/4; i++){
		for (int j = i; j < sizeof(arr)/4; j++)
		{
			if (arr[i] > arr[j]) {
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}
}

int main() {
	//구현: 정렬 전의 배열 출력
	for (int i = 0; i < sizeof(arr)/4; i++){
		std::cout << arr[i] << " ";
	}

	sort();

	//구현: 정렬 후의 배열 출력
	std::cout << "" << std::endl;
	for (int i = 0; i < sizeof(arr) / 4; i++) {
		std::cout << arr[i] << " ";
	}

	return 0;
}