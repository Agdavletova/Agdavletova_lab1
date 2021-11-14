// Agdavletoba_lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>


using namespace std;


struct CompressionStation// тип КС
{
	
	int id = 0;
	string title;
	int number = 0;
	int number_workshops = 0;
	double efficiency = 0;
	int percent;
};
struct pipe //тип труба
{
	string name;
	int id = 0;
	double length = 0;
	double diameter = 0;
	bool sign; //!!!!!!!!!!!!!!!!!!!!!
};
int Identification()
{
	int ID;
	srand(time(NULL));
	ID = 200 + rand() % 101;
	return ID;
}

void PrintCompressionStation( const CompressionStation& cs)//????????????
{
	if (cs.number != 0)
	{
		cout << "You entered title:" << cs.title << endl;
		cout << "You entered number manufactories:" << cs.number << endl;
		cout << "You entered number of working manufactories:" << cs.number_workshops << endl;
		cout << "You entered efficiency:" << cs.efficiency << endl;
	}
	else
	{
		cout << "Compression Station not added" << endl;
	}
}




void EditPipe(pipe& p)//редактирование трубы
{
	if (p.diameter != 0 && p.length != 0)
	{
	
		cout << "Enter a new sign a pipe" << endl;
		cin >> p.sign;
		
	}
	else
		cout << "Pipe not added" << endl;
}
int check()// проверка правильности ввода 
{
	int proverca;
	while (true)
	{
		cin >> proverca;
		if (cin.fail() || proverca < 0  || proverca>100000000  )
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
	if (cs.number != 0)
	{
		
		cout << "Enter a new number  of working manufactories" << endl;
		 cs.number_workshops = check();//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		while (cs.number_workshops > cs.number)
		{
			cout << "Error ";
			cs.number_workshops = check();
		}
	}
	else
		cout << "Compression Station not added" << endl;
}

	

void menu() //МЕНЮ
{
	system("cls");
	cout << "1.Add a pipe\n"
		<< "2.Add a Compression Station\n"
		<< "3.Print objects\n"
		<< "4.Pipe searh\n"
		<< "5.Compression Station search"
		<< "6.Save\n"
		<< "7.Load\n"
		<<"8.Exit\n";


}
void menu_1()
{
	system("cls");
		cout << "1.Search by name" << endl;
	cout << "2.Search by attribete" << endl;
}
void menu_2()
{
	system("cls");
	cout << "1.Search by name" << endl;
	cout << "2.Search by percent" << endl;
}
CompressionStation CreateCompressionStation()//создание кс
{
	CompressionStation cs;
	cs.id = 0;
	cout << "Enter title:";
	cin.ignore(10000, '\n');
	getline(cin, cs.title);
	cout << "Enter the  number of manufactories:";
	cs.number = check();
	cout << "Enter the number of working manufactories:";
	cs.number_workshops = check();
	while (cs.number_workshops > cs.number)
	{
		cout << "Error ";
		cs.number_workshops = check();
	}
	cout << "Enter efficiency:";
	cs.efficiency = check();
	return cs;
}



pipe CreatePipe()//создание трубы
{
	pipe p;
	p.id = 0;
	p.sign = "Under repair";
	cout << "Enter length:";
	p.length = check();
	cout << "Enter diameter:";
	p.diameter = check();
	return p;
}




void AddPipe_vector(vector <pipe> &vector_p)
{
	pipe p;
	cout << "Add a pipe" << vector_p.size() + 1 << endl;
	int Id_pipe;
	Id_pipe = Identification();
	p.id = Id_pipe;
	cout << "Enter a name  of pipe" << endl;
	cin >> p.name;
	cout << "Enter diameter  of pipe" << endl;
	p.diameter = check();
	cout << "Enter  length of pipe" << endl;
	p.length = check();
	cout << "Pipe sign :(0-No,1-Yes )" << endl;
	cin >> p.sign;
	vector_p.push_back(p);

}
void AddCompressionStation_vector(vector <CompressionStation>& vector_cs)
{
	CompressionStation cs;
	cout << "Add a Compression Station" << vector_cs.size() + 1 << endl;
	int Id_cs;
	Id_cs = Identification();
	cs.id = Id_cs;
	cout << "Enter title:";
	cin.ignore(10000, '\n');
	getline(cin, cs.title);
	cout << "Enter the  number of manufactories:  " << endl;
	cs.number = check();
	cout << "Enter the number of working manufactories:";
	cs.number_workshops = check();
	cout << "Enter efficiency:";
	cs.efficiency = check();
	vector_cs.push_back(cs);
	cs.percent = ((cs.number - cs.number_workshops) / cs.number) * 100;
}
void PrintVectors(const vector <pipe>& vector_p, const vector <CompressionStation>& vector_cs)
{
	int i;
	cout << "Pipes:" << endl;
	cout << "ID:" << endl;
	for (int i = 0; i < vector_p.size(); ++i)
	{
		cout << vector_p[i].id; cout << endl;
	}
	cout << "Diameter:" << endl;
	
	for (int i = 1; i < vector_p.size() + 1; ++i) 
	{ 
		cout << vector_p[i - 1].diameter; cout << endl; 
	}
	cout << "Length:" << endl;

	for (int i = 1; i < vector_p.size() + 1; ++i) 
	{ 
		cout << vector_p[i - 1].length; cout << endl;
	}
	cout << "Priznak: " << endl;
	
	for (int i = 1; i < vector_p.size() + 1; ++i) 
	{
		if (vector_p[i - 1].sign == 0)
		{
			cout << "The pipe is not in sign now" << endl;
		}
		if (vector_p[i - i].sign == 1) {
			cout << "The pipe is in sign now" << endl;
		}
	}
	cout << "Compression Station:" << endl;
	cout << "ID:" << endl;
	for (int i = 1; i < vector_cs.size() + 1; ++i)
	{ 
		cout << vector_cs[i - 1].id; cout << endl;
	}
	cout << "Titles" << endl;
	for (int i = 1; i < vector_cs.size() + 1; ++i)
	{ 
		cout << vector_cs[i - 1].title; cout << endl;
	}
	cout << "Number of manufactories : " << endl;
	for (int i = 1; i < vector_cs.size() + 1; ++i)
	{
		cout << vector_cs[i - 1].number; cout << endl;
	}
	cout << "Number of working manufactories:"<< endl;
	for (int i = 1; i < vector_cs.size() + 1; ++i)
	{
		cout << vector_cs[i - 1].number_workshops; cout << endl;
	}
	cout << "Efficiency:" << endl;

	for (int i = 1; i < vector_cs.size() + 1; ++i)
	{ 
		cout << vector_cs[i - 1].efficiency; cout << endl;
	}
}
string *Mas_string(int lines)
{
	string* mas = new string [lines];
	return mas;
}
bool *Mas_bool(int lines)
{
	bool* mas = new bool[lines];
	return mas;
}
int *Mas_int(int lines)
{
	int* mas = new int[lines];
	return mas;
}

void Search_pipe_name(vector <pipe>& vector_p)
{
	string name;
	int index = 0;
	string choice;
	string* mass = Mas_string(vector_p.size());
	for (int i = 0; i < vector_p.size(); i++)
	{
		mass[i] = vector_p[i].name;
	}
	cout << "Enter name of pipe" << endl;
	cin >> choice;
	for (int i = 0; i < vector_p.size(); i++)
	{
		if (mass[i] == choice)
		{
			index = i + 1;
		}
	}
	if (index != 0)
	{
		cout << " The name of the pipe: " << choice << endl << " Index: " << index << endl; 
		cout << "Id: " << endl
			<< vector_p[index-1].id << endl
			<< "Diameter: " << endl
			<< vector_p[index-1].diameter << endl
			<< "Length: " << endl
			<< vector_p[index-1].length << endl
			<< "In repair: " << endl
			<< vector_p[index-1].sign << endl;

	}
	else
	{
		cout << "This is no such pipe";
	}
	delete[] mass;
}
void  Search_Pipe_Sign(vector <pipe>& vector_p)
{
	bool sign;
	int k= 0;
	bool choice;
	bool* mass = Mas_bool(vector_p.size());
	int* mas_s = Mas_int(vector_p.size());
	for (int i = 0; i < vector_p.size(); i++)
	{
		mass[i] = vector_p[i].sign;
	}
	cout << "Enter the pipe attribute (0-ender repair; 1- not in repair)   ";;
	cin >> choice;
	for (int i = 0; i < vector_p.size(); i++)
	{
		if (mass[i] == choice)
		{
			mas_s[k++]= i;
		}
		
	}
	if (k != 0)
	{
		for (int i = 0; i < k; i++)
		{
			cout << " Pipes with the entered attribyte:  " << choice << endl << "has index  " << i+1 << endl;
			cout << "Name: ";
			cout << vector_p[i].name << endl;
	    	cout << "Id: ";
			cout << vector_p[i].id << endl;
				cout << "Diameter: ";
			cout << vector_p[i].diameter << endl;
				cout << "Length: ";
				cout << vector_p[i].length << endl;
		}
	}
	else
	{
		cout << "This is no such pipe";
	}
	delete[] mass;

}
void Search_CS_Name(vector <CompressionStation>& vector_cs)
{
	string title;
	int index = 0;
	string choice;
	string* mass = Mas_string(vector_cs.size());
	for (int i = 0; i < vector_cs.size(); i++)
	{
		mass[i] = vector_cs[i].title;
	}
	cout << "Enter the title of the Compression Station:   ";
	cin >> choice;
	for (int i = 0; i < vector_cs.size(); i++)
	{
		if (mass[i] == choice)
		{
			index = i + 1;
		}
	}
	if (index != 0)
	{
		cout << " The title of the compression station: " << choice << endl << " Index: " << index << endl;
		cout << "Id: " << endl
			<< vector_cs[index - 1].id << endl
			<< "Number of manufactories : " << endl
			<< vector_cs[index - 1].number << endl
			<< "Number of working manufactories: " << endl
			<< vector_cs[index - 1].number_workshops << endl
			<< "Efficiency: " << endl
			<< vector_cs[index - 1].efficiency << endl;

	}
	else
	{
		cout << "This is no such pipe";
	}
	delete[] mass;
}
void Search_CS_Percent( vector <CompressionStation>& vector_cs)
{
	int k = 0;
	int percent;
	int choice;
	int* mass = Mas_int(vector_cs.size());
	int* mass1 = Mas_int(vector_cs.size());
	for (int i = 0; i < vector_cs.size(); i++)
	{
		mass[i] = vector_cs[i].percent;

	}
	cout << "Enter";
	cin >> choice;
	for (int i = 0; i < vector_cs.size(); i++)
	{
		if (mass[i] == choice)
		{
			mass1[k++] = i;
		}

	}
	if (k != 0)
	{
		for (int i = 0; i < k; i++)
		{
			cout << " The  " << choice << endl << " Index: " << mass1[i] << endl;
			cout << "Title:" << endl
				<< vector_cs[i].title << endl
				<< "Id: " << endl
				<< vector_cs[i].id << endl
				<< "Number of manufactories : " << endl
				<< vector_cs[i].number << endl
				<< "Number of working manufactories: " << endl
				<< vector_cs[i].number_workshops << endl
				<< "Efficiency: " << endl
				<< vector_cs[i].efficiency << endl;
		}
	}
	else
	
	{
	cout << "This is no such pipe";
	}
	delete[] mass;
	
	
}

int get_vari()//считывание номера в меню
{
	int vari;
	while (true)
	{
		cin >> vari;
		if (vari < 1 || vari > 100000000 || cin.fail() || cin.peek() != '\n')
		{
			cout << "Incorrect input. Try again:\n" << endl;
		}
		else return vari;
	}
};

int main() //вызов
{
	vector <pipe> vector_p; vector_p.resize(0);
	pipe p{};
	vector <CompressionStation> vector_cs; vector_cs.resize(0);
	CompressionStation cs{};
	int vari;
	do
	{
		menu();
		vari = get_vari();
		switch (vari)
		{
		case 1:
		{   AddPipe_vector(vector_p);
		break;
		}
		case 2:
		{
			AddCompressionStation_vector(vector_cs);
			break;
		}
		case 4:
		{

			menu_1();
			int var;
			var = get_vari();
			switch (var)
			{
			case 1:
			{
				Search_pipe_name(vector_p);
				break;
			}
			case 2
			{
				Search_Pipe_Sign(vector_p);
				break;
			}


			}
			break;
		}
		case 3:
		{

			PrintVectors(vector_p, vector_cs);
			//PrintCompressionStation(vector_cs);
			break;
		}
		case 5:
		{
			menu_2();
			int v;
			v = get_vari();
			switch (v)
			{
				case 1
				{
					Search_CS_Name(vector_cs);
					break;
				}
				case 2
				{
					Search_CS_Percent(vector_cs;
					break;
				}

			}

			break;
		}
		case 6:
		{

			break;
		}
		case 7:
		{
			Search_CS_Name(vector_cs);
			break;
		}
		

		if (vari != 8) //бесконечный цикл
			system("pause");
		}
	
		while (vari != 8);
		return 0;

	
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
