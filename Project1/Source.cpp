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
	bool isCorrect();
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

	cout << "Хотите отсортировать массив? Возможна сортировка по номеру курса или средней оценке\n" << endl;
	cout << "По номеру курса нажмите 1, по оценке - 2, не сортировать - любое другое число:";
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

		cout << "Сортировка по номеру курса прошла успешно!" << endl;
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

		cout << "Сортировка по среднему баллу прошла успешно!" << endl;
	}

	else
	{
		cout << "Вы решили не сортировать." << endl;
	}
}

void search(Student* arr, int size)
{
	int s, m, number, count = 0;
	string surname;

	cout << "Вы можете найти нужного вам человека по его фамилии(1) или номеру телефона(2)\n";
	cout << "Введите соответствующий номер для поиска либо другое число для пропуска: ";
	cin >> s;
	cout << endl;

	if (s == 1)
	{
		cout << "Введите фамилию: ";
		cin >> surname;
		cout << endl;

        for (int i = 0; i < size; i++)
		{
			if (surname == arr[i].NAME.surname)
			{
				cout << "ФИО: " << arr[i].NAME.surname << " " << arr[i].NAME.name << " " << arr[i].NAME.patronomyc << "\n";
				cout << "Пол: " << arr[i].sex << ", Национальность: " << arr[i].nationality << ", Рост: " << arr[i].height << ", Вес: " << arr[i].weight << ", Номер телефона: " << arr[i].phone_number << "\n";
				cout << "Почтовый инлекс: " << arr[i].COPY.index << ", Страна: " << arr[i].COPY.country << ", Регион:" << arr[i].COPY.region << ", Город: " << arr[i].COPY.city << "\n";
				cout << "Улица: " << arr[i].COPY.street << ", Дом: " << arr[i].COPY.home << ", Квартира: " << arr[i].COPY.apartment << "\n";
				cout << "Дата рождения: " << arr[i].DATE.date << " " << arr[i].DATE.month << " " << arr[i].DATE.year << "\n";
				cout << "Курс: " << arr[i].COURSE.course << ", Группа: " << arr[i].COURSE.group << ", Оценка: " << arr[i].COURSE.point << ", Национальность: " << arr[i].COURSE.specialty << endl;
				count++;
			}
        }

		if (count == 0)
		{
			cout << "Люди с данной фамилией не найдены" << endl;
		}

		cout << endl;
		cout << "Продолжить поиск? Да - 1, Нет - другое число: ";
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
		cout << "Введите номер телефона: ";
		cin >> number;
		cout << endl;

		for (int i = 0; i < size; i++)
		{
			if (number == arr[i].phone_number)
			{
				cout << "ФИО: " << arr[i].NAME.surname << " " << arr[i].NAME.name << " " << arr[i].NAME.patronomyc << "\n";
				cout << "Пол: " << arr[i].sex << ", Национальность: " << arr[i].nationality << ", Рост: " << arr[i].height << ", Вес: " << arr[i].weight << ", Номер телефона: " << arr[i].phone_number << "\n";
				cout << "Почтовый инлекс: " << arr[i].COPY.index << ", Страна: " << arr[i].COPY.country << ", Регион:" << arr[i].COPY.region << ", Город: " << arr[i].COPY.city << "\n";
				cout << "Улица: " << arr[i].COPY.street << ", Дом: " << arr[i].COPY.home << ", Квартира: " << arr[i].COPY.apartment << "\n";
				cout << "Дата рождения: " << arr[i].DATE.date << " " << arr[i].DATE.month << " " << arr[i].DATE.year << "\n";
				cout << "Курс: " << arr[i].COURSE.course << ", Группа: " << arr[i].COURSE.group << ", Оценка: " << arr[i].COURSE.point << ", Национальность: " << arr[i].COURSE.specialty << endl;
				count++;
			}
		}

		if (count == 0)
		{
			cout << "Человека с данным номером не найдено" << endl;
		}

		cout << endl;
		cout << "Продолжить поиск? Да - 1, Нет - другое число: ";
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
		cout << "ФИО: " << arr[i].NAME.surname << " " << arr[i].NAME.name << " " << arr[i].NAME.patronomyc << "\n";
		cout << "Пол: " << arr[i].sex << ", Национальность: " << arr[i].nationality << ", Рост: " << arr[i].height << ", Вес: " << arr[i].weight << ", Номер телефона: " << arr[i].phone_number << "\n";
		cout << "Почтовый инлекс: " << arr[i].COPY.index << ", Страна: " << arr[i].COPY.country << ", Регион:" << arr[i].COPY.region << ", Город: " << arr[i].COPY.city << "\n";
		cout << "Улица: " << arr[i].COPY.street << ", Дом: " << arr[i].COPY.home << ", Квартира: " << arr[i].COPY.apartment << "\n";
		cout << "Дата рождения: " << arr[i].DATE.date << " " << arr[i].DATE.month << " " << arr[i].DATE.year << "\n";
		cout << "Курс: " << arr[i].COURSE.course << ", Группа: " << arr[i].COURSE.group << ", Оценка: " << arr[i].COURSE.point << ", Национальность: " << arr[i].COURSE.specialty << endl << endl;
	}
}

bool Birthday::isCorrect()
{
	bool result = false;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if ((date <= 31) && (date > 0))
			result = true;
		break;
	}

	case 4:
	case 6:
	case 9:
	case 11:
	{
		if ((date <= 30) && (date > 0))
			result = true;
		break;
	}

	case 2:
	{
		if (year % 4 != 0)
		{
			if ((date <= 28) && (date > 0))
				result = true;
		}
		else
			if (year % 400 == 0)
			{
				if ((date <= 29) && (date > 0))
					result = true;
			}
			else
				if ((year % 100 == 0) && (year % 400 != 0))
				{
					if ((date == 28) && (date> 0))
						result = true;
				}
				else
					if ((year % 4 == 0) && (year % 100 != 0))
						if ((date<= 29) && (date> 0))
							result = true;
		break;
	}

	default:
		result = false;
	}

	return result;
}

int main()
{
	setlocale(LC_ALL, "RU");

	Student* arr;
	int size;

	do
	{
		cout << "Введите количество человек, данные которых вы будете вводить: ";
		cin >> size;
	} while (size < 1);

	arr = new Student[size];

	for (int i = 0; i < size; i++)
	{
		cout << "Введите фамилию человека под номером " << i + 1 << ": ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].NAME.surname, 56);
		cout << endl;

		cout << "Введите имя: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].NAME.name, 56);
		cout << endl;

		cout << "Введите отчество: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].NAME.patronomyc, 56);
		cout << endl;

		cout << "Введите пол: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].sex, 10);
		cout << endl;

		cout << "Введите национальность: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].nationality, 56);
		cout << endl;

		do
		{
			do
			{
				cout << "Введите рост в метрах: ";
				cin >> arr[i].height;
				cout << endl;
			} while (arr[i].height > 2.5);
		} while (arr[i].height < 0.3);

		do
		{
			do
			{
				cout << "Введите вес: ";
				cin >> arr[i].weight;
				cout << endl;
			} while (arr[i].weight < 0);
		} while (arr[i].weight > 150);

		cout << "Введите номер телефона: ";
		cin >> arr[i].phone_number;
		cout << endl;

		do
		{
			cout << "Введите День Рождения: ";
			cin >> arr[i].DATE.date;
			cout << endl;
			cout << "Месяц: ";
			cin >> arr[i].DATE.month;
			cout << endl;
			cout << "Год: ";
			cin >> arr[i].DATE.year;
			cout << endl;
		} while (!arr[i].DATE.isCorrect());

		do
		{
			do
			{
				cout << "Введите почтовый индекс: ";
				cin.ignore(cin.rdbuf()->in_avail());
				cin >> arr[i].COPY.index;
				cout << endl;
			} while (arr[i].COPY.index >= 100000);
		} while (arr[i].COPY.index < 10000);

		cout << "Введите страну: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].COPY.country, 32);
		cout << endl;

		cout << "Введите регион: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].COPY.region, 32);
		cout << endl;

		cout << "Введите город: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].COPY.city, 32);
		cout << endl;

		cout << "Введите улицу: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].COPY.street, 32);
		cout << endl;

		cout << "Введите номер дома: ";
		cin >> arr[i].COPY.home;
		cout << endl;

		cout << "Введите номер квартиры: ";
		cin >> arr[i].COPY.apartment;
		cout << endl;

		do
		{
			do
			{
				cout << "Введите номер курса в университете: ";
				cin >> arr[i].COURSE.course;
				cout << endl;
			} while (arr[i].COURSE.course > 6);
		} while (arr[i].COURSE.course < 1);

		cout << "Введите название группы: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].COURSE.group, 16);
		cout << endl;

		do
		{
			do
			{
				cout << "Введите среднюю оценку: ";
				cin >> arr[i].COURSE.point;
				cout << endl;
			} while (arr[i].COURSE.point > 100);
		} while (arr[i].COURSE.point < 0);

		cout << "Введите специальность: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(arr[i].COURSE.specialty, 32);
		cout << endl << endl;

		if (i == size - 1)
		{
			arr[i].count = 0;

			cout << "Хотите добавить нового студента?(Если Да - введите 1, Нет - любое другое число)" << endl;
			cin >> arr[i].count;
			cout << endl;

			if (arr[i].count == 1)
			{
				//функция для выделения памяти если пользователь продолжит ввод;
				memory(arr, size);
			}
		}

	}
	
	if (size > 1)
	{
		//функция сортировки массива;
		sort(arr, size);

		//функция поиска нужной структуры по заданному значению;
		search(arr, size);
	}

	else
	{
		cout << "Так как вы ввели информацию только об 1 человеке функции сортировки и поиска недоступны" << endl << endl;
	}

	cout << "Вывод информации о введенных людях: " << endl;
	//функция вывода массива;
	massiv(arr, size);
}

