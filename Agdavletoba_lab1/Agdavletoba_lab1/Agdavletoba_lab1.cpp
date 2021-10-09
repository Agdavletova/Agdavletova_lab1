// Agdavletoba_lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;
struct CompressionStation
{
	
	int id_cs;
	string title;
	int number;
	int number_workshops;
	double efficiency;
};
struct pipe
{
	int id;
	double length;
	double diameter;
	int number;
	string sign;
};
void PrintCompressionStation(CompressionStation& cs)
{
	cout << "You entered title:" << cs.title << endl;
	cout << "You entered number manufactories:" << cs.number << endl;
	cout << "You entered number of working manufactories:" << cs.number_workshops << endl;
	cout << "You entered efficiency:" << cs.efficiency << endl;

}


void PrintPipe(pipe&p)
{
	cout << "You entered length=" << p.length << endl;
	cout << "You enetered diameter=" << p.diameter << endl;
	cout << "You entered number=" << p.number << endl;
	cout << "Sign a pipe:" << p.sign << endl;

}

void EditPipe(pipe& p)
{
	string sign2;
	cout<< "Enter a new sign a pipe"<< endl;
	cin >> p.sign;
	sign2 == p.sign;
		
}

void MenuEditPipe()
{
	cout <<  "1.Edit priznak\n";
}

void menu()
{
	cout << "1.Enter the pipe\n" << "2.Enter the Compression Station\n" << "3.Viewing objects\n" << "4.Edit a pipe\n" << "5.Edit a Comression Station\n" << "6.Save\n" << "7.Download\n" << "0.Exit";


}
CompressionStation CreateCompressionStation()
{
	CompressionStation cs;
	cs.id_cs = 0;
	cout << "Enter title:";
	cin >> cs.title;
	cout << "Enter number manufactories:";
	cin >> cs.number;
	cout << "Enter the number of workshops:";
	cin >> cs.number_workshops;
	cout << "Enter efficiency:";
	cin >> cs.efficiency;
	return cs;
}

pipe CreatePipe()
{
	pipe p;
	p.id = 0;
	p.sign = "Under repair";
	cout << "Enter length:";
	cin >> p.length;
	cout << "Enter diameter:";
	cin >> p.diameter;
	cout << "Number of stations under repair:";
	cin >> p.number;
	return p;
}
int get_vari(int count)
{
	int vari;
	string s;
	getline(cin, s); 

	while (sscanf_s(s.c_str(), "%d", &vari) != 1 || vari < 1 || vari > count)
	{
		cout << "Incorrect input. Try again: "; 
		getline(cin, s);

	}

		return vari;

	
};
int main()
{
	pipe p;
	CompressionStation cs;

	int h;
	int vari;
	do
	{
		menu();
		vari = get_vari(7);
		cin >> vari;
		switch (vari)
		{
		case 1:p = CreatePipe();
			PrintPipe(p);
			break;
		case 2:
			cs = CreateCompressionStation();
			PrintCompressionStation(cs);
			break;
		case 4:
			system("cls");
			MenuEditPipe();
			cin >> h;
			switch (h)
			{
			case 1:  EditPipe(p);
				PrintPipe(p);
				break;
				{
			default: cout << "Data not correct";
				break;
				}

				break;
			}



			return 0;
		}

		if (vari != 7)
			system("pause");
	}
while (vari != 7);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
