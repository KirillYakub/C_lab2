#include <iostream>
#include <iomanip>

using namespace std;

struct Adress
{
	int index;
	char country[32];
	char region[32];
	char city[32];
	char street[32];
	int home;
	int apartment;
};

struct Birthday
{
	int date;
	int month;
	int year;
};

struct University
{
	int course;
	char group[16];
	float point;
	char specialty[32];
};

struct FIO
{
	char surname[56];
	char name[32];
	char patronomyc[56];
};

struct Student
{
	char sex[10];
	char nationality[56];
	float height;
	float weight;
	long long int phone_number;
	FIO NAME;
	Birthday DATE;
	University COURSE;
	Adress COPY;
	int count;
	int surname_number;
};

void memory(Student*& arr, int& size)
{
	Student* new_array = new Student[size + 1];
	
	for (int i = 0; i < size; i++)
	{
		new_array[i] = arr[i];
	}

	size++;

	delete[] arr;

	arr = new_array;
}

void sort(Student *arr, int size)
{
	int k;

	cout << "������ ������������� ������? �������� ���������� �� ������ ����� ��� ������� ������\n" << endl;
	cout << "�� ������ ����� ������� 1, �� ������ - 2, �� ����������� - ����� ������ �����:";
	cin >> k;

	if (k == 1)
	{
		for (int i = 0; i < size; i++)
		{
			for (int i = 0; i < size - 1; i++)
			{
				if (arr[i].COURSE.course > arr[i + 1].COURSE.course)
				{
					Student temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
                }
			}
		}

		cout << "���������� �� ������ ����� ������ �������!" << endl;
	}

	else if(k == 2)
	{
		for (int i = 0; i < size; i++)
		{
			for (int i = 0; i < size - 1; i++)
			{
				if (arr[i].COURSE.point > arr[i + 1].COURSE.point)
				{
					Student temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
				}
			}
		}

		cout << "���������� �� �������� ����� ������ �������!" << endl;
	}

	else
	{
		cout << "�� ������ �� �����������." << endl;
	}
}

void search(Student* arr, int size)
{
	int s, m, number, count = 0;
	string surname;

	cout << "�� ������ ����� ������� ��� �������� �� ��� �������(1) ��� ������ ��������(2)\n";
	cout << "������� ��������������� ����� ��� ������ ���� ������ ����� ��� ��������: ";
	cin >> s;
	cout << endl;

	if (s == 1)
	{
		cout << "������� �������: ";
		cin >> surname;
		cout << endl;

        for (int i = 0; i < size; i++)
		{
			if (surname == arr[i].NAME.surname)
			{
				cout << "���: " << arr[i].NAME.surname << " " << arr[i].NAME.name << " " << arr[i].NAME.patronomyc << "\n";
				cout << "���: " << arr[i].sex << ", ��������������: " << arr[i].nationality << ", ����: " << arr[i].height << ", ���: " << arr[i].weight << ", ����� ��������: " << arr[i].phone_number << "\n";
				cout << "�������� ������: " << arr[i].COPY.index << ", ������: " << arr[i].COPY.country << ", ������:" << arr[i].COPY.region << ", �����: " << arr[i].COPY.city << "\n";
				cout << "�����: " << arr[i].COPY.street << ", ���: " << arr[i].COPY.home << ", ��������: " << arr[i].COPY.apartment << "\n";
				cout << "���� ��������: " << arr[i].DATE.date << " " << arr[i].DATE.month << " " << arr[i].DATE.year << "\n";
				cout << "����: " << arr[i].COURSE.course << ", ������: " << arr[i].COURSE.group << ", ������: " << arr[i].COURSE.point << ", ��������������: " << arr[i].COURSE.specialty << endl;
				count++;
			}
        }

		if (count == 0)
		{
			cout << "���� � ������ �������� �� �������" << endl;
		}

		cout << endl;
		cout << "���������� �����? �� - 1, ��� - ������ �����: ";
		cin >> m;
		cout << endl;

		if (m == 1)
		{
			search(arr, size);
			count = 0;
		}

		else
		{
			count = 0;
		}

		cout << endl;
	}

	if (s == 2)
	{
		cout << "������� ����� ��������: ";
		cin >> number;
		cout << endl;

		for (int i = 0; i < size; i++)
		{
			if (number == arr[i].phone_number)
			{
				cout << "���: " << arr[i].NAME.surname << " " << arr[i].NAME.name << " " << arr[i].NAME.patronomyc << "\n";
				cout << "���: " << arr[i].sex << ", ��������������: " << arr[i].nationality << ", ����: " << arr[i].height << ", ���: " << arr[i].weight << ", ����� ��������: " << arr[i].phone_number << "\n";
				cout << "�������� ������: " << arr[i].COPY.index << ", ������: " << arr[i].COPY.country << ", ������:" << arr[i].COPY.region << ", �����: " << arr[i].COPY.city << "\n";
				cout << "�����: " << arr[i].COPY.street << ", ���: " << arr[i].COPY.home << ", ��������: " << arr[i].COPY.apartment << "\n";
				cout << "���� ��������: " << arr[i].DATE.date << " " << arr[i].DATE.month << " " << arr[i].DATE.year << "\n";
				cout << "����: " << arr[i].COURSE.course << ", ������: " << arr[i].COURSE.group << ", ������: " << arr[i].COURSE.point << ", ��������������: " << arr[i].COURSE.specialty << endl;
				count++;
			}
		}

		if (count == 0)
		{
			cout << "�������� � ������ ������� �� �������" << endl;
		}

		cout << endl;
		cout << "���������� �����? �� - 1, ��� - ������ �����: ";
		cin >> m;
		cout << endl;

		if (m == 1)
		{
			search(arr, size);
			count = 0;
		}

		else
		{
			count = 0;
		}

		cout << endl;
	}
}

void massiv(Student* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "���: " << arr[i].NAME.surname << " " << arr[i].NAME.name << " " << arr[i].NAME.patronomyc << "\n";
		cout << "���: " << arr[i].sex << ", ��������������: " << arr[i].nationality << ", ����: " << arr[i].height << ", ���: " << arr[i].weight << ", ����� ��������: " << arr[i].phone_number << "\n";
		cout << "�������� ������: " << arr[i].COPY.index << ", ������: " << arr[i].COPY.country << ", ������:" << arr[i].COPY.region << ", �����: " << arr[i].COPY.city << "\n";
		cout << "�����: " << arr[i].COPY.street << ", ���: " << arr[i].COPY.home << ", ��������: " << arr[i].COPY.apartment << "\n";
		cout << "���� ��������: " << arr[i].DATE.date << " " << arr[i].DATE.month << " " << arr[i].DATE.year << "\n";
		cout << "����: " << arr[i].COURSE.course << ", ������: " << arr[i].COURSE.group << ", ������: " << arr[i].COURSE.point << ", ��������������: " << arr[i].COURSE.specialty << endl << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "RU");

	Student* arr;
	int size;

	cout << "������� ���������� �������, ������ ������� �� ������ �������: ";

	cin >> size;

	arr = new Student[size];

	for (int i = 0; i < size; i++)
	{
		cout << "������� ������� �������� ��� ������� " << i + 1 << ": ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].NAME.surname, 56);
		cout << endl;

		cout << "������� ���: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].NAME.name, 56);
		cout << endl;

		cout << "������� ��������: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].NAME.patronomyc, 56);
		cout << endl;

		cout << "������� ���: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].sex, 10);
		cout << endl;

		cout << "������� ��������������: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].nationality, 56);
		cout << endl;

		do
		{
			do
			{
				cout << "������� ���� � ������: ";
				cin >> arr[i].height;
				cout << endl;
			} while (arr[i].height > 2.5);
		} while (arr[i].height < 0.3);

		cout << "������� ���: ";
		cin >> arr[i].weight;
		cout << endl;

		cout << "������� ����� ��������: ";
		cin >> arr[i].phone_number;
		cout << endl;

		cout << "������� ���� ��������: ";
		cin >> arr[i].DATE.date;
		cout << endl;
		cout << "�����: ";
		cin >> arr[i].DATE.month;
		cout << endl;
		cout << "���: ";
		cin >> arr[i].DATE.year;
		cout << endl;

		cout << "������� �������� ������: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> arr[i].COPY.index;
		cout << endl;

		cout << "������� ������: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].COPY.country, 32);
		cout << endl;

		cout << "������� ������: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].COPY.region, 32);
		cout << endl;

		cout << "������� �����: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].COPY.city, 32);
		cout << endl;

		cout << "������� �����: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].COPY.street, 32);
		cout << endl;

		cout << "������� ����� ����: ";
		cin >> arr[i].COPY.home;
		cout << endl;

		cout << "������� ����� ��������: ";
		cin >> arr[i].COPY.apartment;
		cout << endl;

		cout << "������� ����� ����� � ������������: ";
		cin >> arr[i].COURSE.course;
		cout << endl;

		cout << "������� �������� ������: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].COURSE.group, 16);
		cout << endl;

		cout << "������� ������� ������: ";
		cin >> arr[i].COURSE.point;
		cout << endl;

		cout << "������� �������������: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].COURSE.specialty, 32);
		cout << endl << endl;

		if (i == size - 1)
		{
			arr[i].count = 0;

			cout << "������ �������� ������ ��������?(���� �� - ������� 1, ��� - ����� ������ �����)" << endl;
			cin >> arr[i].count;
			cout << endl;

			if (arr[i].count == 1)
			{
				//������� ��� ��������� ������ ���� ������������ ��������� ����;
				memory(arr, size);
			}
		}

	}
	
	if (size > 0)
	{
		//������� ���������� �������;
		sort(arr, size);

		//������� ������ ������ ��������� �� ��������� ��������;
		search(arr, size);
	}

	else
	{
		cout << "��� ��� �� ����� ���������� ������ �� 1 �������� ������� ���������� � ������ ����������" << endl;
	}

	cout << "����� ���������� � ��������� �����: " << endl;
	//������� ������ �������;
	massiv(arr, size);
}

