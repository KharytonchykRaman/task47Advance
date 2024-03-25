#include <iostream>

using namespace std;

void user_init(int** medals, int country_index);
void count_total_point(int** medals, int* total_points, int size);
void leaderboard_sort(int* total_points, string* country_names, int size);
string leaderboard_to_string(string* country_names, int* total_points, int size);

int main() {

	int size = 8;
	int** medals = new int* [size];
	for (int i = 0; i < size; i++)
	{
		medals[i] = new int[3];
	}
	string* country_names = new string[size];
	int* total_points = new int[size];

	cout << "Enter the number of gold, silver and bronze medals in one line:\n";
	cout << "Austria: "; country_names[0] = "Austria";
	user_init(medals, 0);

	cout << "Germany: "; country_names[1] = "Germany";
	user_init(medals, 1);

	cout << "Norway: "; country_names[2] = "Norway";
	user_init(medals, 2);

	cout << "Russia: "; country_names[3] = "Russia";
	user_init(medals, 3);

	cout << "Finland: "; country_names[4] = "Finland";
	user_init(medals, 4);

	cout << "China: "; country_names[5] = "China";
	user_init(medals, 5);

	cout << "USA: "; country_names[6] = "USA";
	user_init(medals, 6);

	cout << "Belarus: "; country_names[7] = "Belarus";
	user_init(medals, 7);

	count_total_point(medals, total_points, size);

	leaderboard_sort(total_points, country_names, size);

	cout << "Team\tTotal points\n";
	cout << leaderboard_to_string(country_names, total_points, size);

	for (int i = 0; i < size; i++)
	{
		delete[] medals[i];
	}
	delete[] medals;
	delete[] country_names;
	delete[] total_points;

	return 0;
}