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


void PrintPipe(const pipe&p)//?????????????
{
	if (p.length != 0)
	{
		cout << "You entered length=" << p.length << endl;
		cout << "You enetered diameter=" << p.diameter << endl;
		cout << "Sign a pipe:" << p.sign << endl;
	}
	else
	{
		cout << "Pipe not added" << endl;
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
void SavePipeAndCompressionStation( const pipe& p,  const CompressionStation& cs)
{
	ofstream fout;
	fout.open("data.txt", ios::out);
	if (p.diameter != 0 && p.length != 0)
	{
		fout << "Pipe:" << endl;
		fout << p.id << endl;
		fout << p.length << endl;
		fout  << p.diameter << endl;
		fout  << p.sign << endl;
	}
	else
		cout << "Pipe not added" << endl;
	if (cs.number != 0)
	{
		fout << "Compression Station:" << endl;
		fout <<  cs.id << endl;
		fout <<  cs.title << endl;
		fout << cs.number << endl;
		fout << cs.number_workshops << endl;
		fout  << cs.efficiency << endl;
	}
	else
		cout << "Compression Station not added" << endl;
	fout.close();
}
void LoadPipeAndCompressionStation( pipe& p,  CompressionStation& cs)
{
	ifstream fin;
	string str;
	fin.open("data.txt", ios::in);
	getline(fin, str);
	if (str == "Pipe:")
	{
		getline(fin, str);
		p.id = stoi(str);
		getline(fin, str);
		p.length = stod(str);
		getline(fin, str);
		p.diameter = stod(str);
		getline(fin, str);
		p.sign = str=="1";
	}
	getline(fin, str);
	if (str == "Compression Station:")
	{
		getline(fin, str);
		cs.id = stoi(str);
		getline(fin, str);
		cs.title = str;
		getline(fin, str);
		cs.number = stoi(str);
		getline(fin, str);
		cs.number_workshops = stoi(str);
		getline(fin, str);
		cs.efficiency = stod(str);
	}
}

void menu() //МЕНЮ
{
	system("cls");
	cout << "1.Enter the pipe\n"
		<< "2.Enter the Compression Station\n"
		<< "3.Print objects\n"
		<< "4.Edit a pipe\n"
		<< "5.Edit a Comression Station\n"
		<< "6.Save\n"
		<< "7.Load\n"
		<<"8.Exit\n";


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
string Mas_string(int lines)
{
	string* mas = new string [lines];
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
		cout << " The pipe wih name: " << choice << " has number " << index << endl; 
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
		cout << "This pipe not create";
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
			Search_pipe_name(vector_p);

			break;
		}
		case 3:
			
			PrintVectors(vector_p, vector_cs);
			//PrintCompressionStation(vector_cs);
			break;
		case 5: EditCompessionStation(cs);
			break;
		case 6:
			SavePipeAndCompressionStation(p, cs);
			break;
		case 7:
			LoadPipeAndCompressionStation(p, cs);
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
