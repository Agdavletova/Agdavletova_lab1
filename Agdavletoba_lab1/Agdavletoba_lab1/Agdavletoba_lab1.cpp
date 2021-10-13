// Agdavletoba_lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;
struct CompressionStation// тип КС
{
	
	int id_cs;
	string title;
	int number;
	int number_workshops;
	double efficiency;
};
struct pipe //тип труба
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
	cout << "Sign a pipe:" << p.sign << endl;

}

void EditPipe(pipe& p)//редактирование трубы
{   
	string sign2;
	cout<< "Enter a new sign a pipe"<< endl;
	cin >> p.sign;
	sign2 == p.sign;

}
int check()// проверка правильности ввода 
{
	int proverca;
	while (true)
	{
		cin >> proverca;
		if (cin.fail() || proverca < 0  || proverca>100000000 )
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Error" << endl;

		}
		else
			return proverca;
	}

}


void EditCompessionStation(CompressionStation& cs)//редактирование КС
{
	int number_workshops2;
    cout << "Enter a new number  of working manufactories" << endl;
	cin >> cs.number_workshops;
	number_workshops2 == cs.number_workshops;
}

void menu() //МЕНЮ
{
	system("cls");
	cout << "1.Enter the pipe\n" << "2.Enter the Compression Station\n" << "3.Viewing objects\n" << "4.Edit a pipe\n" << "5.Edit a Comression Station\n" << "6.Save\n" << "7.Download\n" << "0.Exit\n";


}
CompressionStation CreateCompressionStation()//создание кс
{
	CompressionStation cs;
	cs.id_cs = 0;
	cout << "Enter title:";
	cin >> cs.title;
	cout << "Enteifr number manufactories:";
	cin >> cs.number;
	cs.number = check();
	cout << "Enter the number of working manufactories:";
	cin >> cs.number_workshops;
	cs.number_workshops = check();
	cout << "Enter efficiency:";
	cin >> cs.efficiency;
	cs.efficiency = check();
	return cs;
}


pipe CreatePipe()//создание трубы
{

	pipe p;
	p.id = 0;
	p.sign = "Under repair";
	cout << "Enter length:";
	cin >> p.length;
	p.length = check();
	cout << "Enter diameter:";
	cin >> p.diameter;
	p.diameter = check();
	return p;
}


int get_vari(int count)//считывание номера в меню
{
	int vari;
	string s;
	getline(cin, s); 
	while (sscanf_s(s.c_str(), "%d", &vari) != 1 || vari < 1 || vari > count)
	{
		cout << "Incorrect input. Try again:\n"; 
		getline(cin, s);

	}
		return vari;
};

int main() //вызов
{
	pipe p;
	CompressionStation cs;
	int k;
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
		case 4:  EditPipe(p);
			PrintPipe(p);
			break;

		case 5: EditCompessionStation(cs);
			PrintCompressionStation(cs);
			break;
		
		return 0;
	}


			if (vari != 7) //бесконечный цикл
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
