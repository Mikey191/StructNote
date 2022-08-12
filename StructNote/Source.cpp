#include <iostream>
#include <fstream>
#include <io.h>
#include <stdio.h>
using namespace std;


struct date
{
	int day;
	int month;
	int year;
};

struct note
{
	char name[255];
	char lastname[255];
	char number[255];
	date birthday;
};
//Alim
note add(note* arr, int& size) {
	note temp;
	
	cout << " Enter Name: " << endl;
	cin>>temp.name;
	cout << " Lastname: " << endl;
	cin >> temp.lastname;
	cout << " Number: " << endl;
	cin>>temp.number;
	cout << " Birthday day: " << endl;
	cin >> temp.birthday.day;
	cout << " Birthday month: " << endl;
	cin >> temp.birthday.month;
	cout << " Birthday year: " << endl;
	cin >> temp.birthday.year;
	return temp;
}
//Alim
void addnote(note* arr, int& size) {
	if (size < 1000)
	{
		arr[size] = add(arr, size);
		size++;
	}
	else
	{
		cout << "note out of memory!" << endl;
		system("pause");
	}
		
	
}

//Radima
void deleteNoteName(note* arr, int& size)
{
	note temp;
	int k = -1;
	cout << "Enter Name for delete: ";
	cin >> temp.name;
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(arr[i].name, temp.name) == 0)
		{
			k = i;
		}
	}
	if (k >= 0)
	{
		for (size_t i = k; i < size - 1; i++)
		{
			arr[i] = arr[i + 1];
		}size--;
	}

}
//Radima
void print(note b) {
	cout << b.name << " " << "\t";
	cout << b.lastname << " " << "\t";
	cout << b.number << " " << "\t";
	cout << b.birthday.day << " " << "\t";
	cout << b.birthday.month << " " << "\t";
	cout << b.birthday.year << " " << "\t";
	cout << endl;
}

//Radima
void showAllNote(note* arr, int& size) {
	cout << "\tList note" << endl;
	for (size_t i = 0; i < size; i++) {
		cout << "Name: " << arr[i].name << "\t";
		cout << "Lastname: " << arr[i].lastname << "\t";
		cout << "Number: " << arr[i].number << "\t";
		cout << "Day: " << arr[i].birthday.day << "\t";
		cout << "Month: " << arr[i].birthday.month << "\t";
		cout << "Year: " << arr[i].birthday.year << "\t";
		cout << endl;
	}
	system("pause");

}
//Igor
void loaddata_bin(note* arr, int& size)
{
	FILE* f;
	const char* filename = "FirstFile.txt";
	struct _finddata_t myfileinfo;
	intptr_t done = _findfirst(filename, &myfileinfo);
	if (done == -1)
	{
		fopen_s(&f, filename, "wb");
		fclose(f);
	}
	fopen_s(&f, filename, "rb");
	while (!feof(f))
	{
		fread(&arr[size], sizeof(note), 1, f);
		size++;
	}
	fclose(f);
	size--;
}
//Igor
void savedata_bin(note* arr, int& size)
{
	FILE* f;
	const char* filename = "FirstFile.txt";
	fopen_s(&f, filename, "wb");
	fwrite(&arr[0], sizeof(note), size, f);
	fclose(f);
}
//Alim
void sortbyyear(note*a, int n) {
	for (size_t i = 0; i < n - 1; i++)
		for (size_t j = i + 1; j < n; j++)
			if (a[i].birthday.year > a[j].birthday.year)
			{
				note tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
}
//Igor
void searchByName(note* arr, int& size)
{
	note temp;
	cout << "Enter Name: ";
	cin >> temp.name;
	int k = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(arr[i].name, temp.name) == 0)
		{
			print(arr[i]);
			k++;
		}
	}
	if (k == 0)
	{
		cout << "Not found" << endl;
	}
	system("pause");
}
//Alim
void searchByLastname(note* arr, int& size)
{
	note temp;
	cout << "Enter Lastname: ";
	cin >> temp.lastname;
	int k = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(arr[i].lastname, temp.lastname) == 0)
		{
			print(arr[i]);
			k++;
		}
	}
	if (k == 0)
	{
		cout << "Not found!" << endl;
	}
	system("pause");
}
//Radima
void searchByNumber(note* arr, int& size)
{
	note temp;
	cout << "Enter Number: ";
	cin >> temp.number;
	int k = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(arr[i].number, temp.number) == 0)
		{
			print(arr[i]);
			k++;
		}
	}
	if (k == 0)
	{
		cout << "Not found!" << endl;
	}
	system("pause");
}
//Alim Radima Igor
int main()
{
	const int size = 1000;
	note arr[size];
	int n = 0;
	int k;

	loaddata_bin(arr, n);

	do
	{
		system("CLS");
		cout << "\tMenu: " << endl;
		cout << " 1 - add note;" << endl;
		cout << " 2 - delete note;" << endl;
		cout << " 3 - show note;" << endl;
		cout << " 4 - search by name;" << endl;
		cout << " 5 - search by lastname;" << endl;
		cout << " 6 - search by number;" << endl;
		cout << " 7 - sort by year;" << endl;
		cout << " 0 - exit;" << endl;
		cout << "\n Enter number: ";
		cin >> k;
		switch (k) {
		case 1:
			addnote(arr, n);
			break;
		case 2:
			deleteNoteName(arr, n);
			break;
		case 3:
			showAllNote(arr, n);
			break;
		case 4:
			searchByName(arr, n);
			break;
		case 5:
			searchByLastname(arr, n);
			break;
		case 6:
			searchByNumber(arr, n);
			break;
		case 7:
			sortbyyear(arr, n);
			break;
		}

	} while (k != 0);

	savedata_bin(arr, n);

	return 0;
}