#include <iostream>

int arr[] = { 6,5,4,3,2,1 };

void sort() {
	//���� ����
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
	//����: ���� ���� �迭 ���
	for (int i = 0; i < sizeof(arr)/4; i++){
		std::cout << arr[i] << " ";
	}

	sort();

	//����: ���� ���� �迭 ���
	std::cout << "" << std::endl;
	for (int i = 0; i < sizeof(arr) / 4; i++) {
		std::cout << arr[i] << " ";
	}

	return 0;
}