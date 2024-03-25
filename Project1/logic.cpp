#include <iostream>
#include <string>

using namespace std;

void user_init(int** medals, int country_index) {
	for (int i = 0; i < 3; i++)
	{
		cin >> medals[country_index][i];
	}
}

void count_total_point(int** medals, int* total_points, int size) {

	for (int i = 0; i < size; i++)
	{
		total_points[i] = medals[i][0] * 7 + medals[i][1] * 6 + medals[i][2] * 5;
	}
}

void leaderboard_sort(int* total_points, string* country_names, int size)
{
	string keyStr;
	int key, j;
	for (int i = 1; i < size; i++) {
		key = total_points[i];
		keyStr = country_names[i];
		for (j = i - 1; j >= 0 && total_points[j] < key; j--)
		{
			total_points[j + 1] = total_points[j];
			country_names[j + 1] = country_names[j];
		}
		total_points[j + 1] = key;
		country_names[j + 1] = keyStr;
	}
}

string leaderboard_to_string
(string* country_names, int* total_points, int size) {

	string msg = "";
	for (int i = 0; i < size; i++)
	{
		msg += to_string(i + 1) + " " + country_names[i]
			+ "\t" + to_string(total_points[i]) + "\n";
	}
	return msg;
}
