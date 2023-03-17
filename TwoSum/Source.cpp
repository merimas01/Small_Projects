#include <iostream>
using namespace std;

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they 
add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

*/

void twoSum(int nums[], int vel, int target) {
	int suma = 0;
	int brojac = 0;
	int indeks1 = 0, indeks2 = 0;

	//probamo sve kombinacije
	for (int i = 0; i < vel; i++)
	{
		for (int j = 0; j < vel; j++)
		{
			if (nums[i] + nums[j] == target && i != j) {
				indeks1 = i;
				indeks2 = j;
				cout << "Indeksi su: " << indeks1 << " i " << indeks2 << endl;
				return;
			}
		}
	}
}

int main() {
	int vel = 4;
	int nums[] = { 2, 7, 11, 15 };
	
	twoSum(nums, vel, 18);

	//unaprijedjenje: funckija da vraca pokazivac na niz koji ce sadrzavati indekse. Dozvoliti korisniku da
	//unosi niz i target. Obavezna alokacija i dealokacija.

	return 0;
}