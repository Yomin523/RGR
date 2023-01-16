#include <fstream>
#include <windows.h>
#include "Typography.h"

using namespace std;

char getCh();

void mainMenu();
void orderMenu();
void deleteOrderMenu();

void inputOrdersFromFile(Typography& typography);
void outOrdersInFile(const Typography& typography);
void outOrderOnScreen(const Typography& typography);

void order(Typography& typography);
void orderBook(Typography& typography);
void orderPoster(Typography& typography);
void orderBusinessCard(Typography& typography);

void deleteOrder(Typography& typography);
bool deleteBook(Typography& typography);
bool deletePoster(Typography& typography);
bool deleteBusinessCard(Typography& typography);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Typography typography;
	char ch;
		
	cout << "Добро пожаловать!" << endl << endl;
	mainMenu();
	while ((ch = getCh()) != '6')
	{
		switch (ch)
		{
		case '1':
			order(typography);
			break;
		case '2':
			deleteOrder(typography);
			break;
		case '3':
			outOrderOnScreen(typography);
			break;
		case '4':
			inputOrdersFromFile(typography);
			break;
		case '5':
			outOrdersInFile(typography);
			break;
		}
		mainMenu();
	}
		
	cout << "До свидания!" << endl;
	return 0;
}

void order(Typography& typography)
{
	char ch;
	orderMenu();
	while ((ch = getCh()) != '4')
	{
		switch (ch)
		{
		case'1':
			orderBook(typography);
			break;
		case'2':
			orderPoster(typography);		
			break;
		case'3':
			orderBusinessCard(typography);
			break;
		}
		cout << "Ваш заказ добавлен!" << endl << endl;
		orderMenu();
	}	
}

void orderBusinessCard(Typography& typography)
{
	BusinessCard businessCard;
	String string;

	cout << "Введите имя: " << endl;
	cin >> string;
	cout << endl;
	businessCard.ChangeName(string);

	cout << "Введите фамилию: " << endl;
	cin >> string;
	cout << endl;
	businessCard.ChangeSurname(string);

	cout << "Введите услугу: " << endl;
	cin >> string;
	cout << endl;
	businessCard.ChangeService(string);

	cout << "Введите номер телефона: " << endl;
	cin >> string;
	cout << endl;
	businessCard.ChangePhoneNumber(string);

	typography.AddBusinessCard(businessCard);

}
void orderPoster(Typography& typography)
{
	Poster poster;
	String string;

	cout << "Введите тип постера: " << endl;
	cin >> string;
	cout << endl;
	poster.ChangeTypePoster(string);

	typography.AddPoster(poster);
}

void orderBook(Typography& typography)
{
	Book book;
	String string;

	cout << "Введите название книги: " << endl;
	cin >> string;
	cout << endl;
	book.ChangeNameBook(string);	

	cout << "Введите имя автора: " << endl;
	cin >> string;
	cout << endl;
	book.ChangeNameAuthor(string);

	cout << "Введите фамилию автора: " << endl;
	cin >> string;
	cout << endl;
	book.ChangeSurnameAuthor(string);

	cout << "Введите количество книг: " << endl;
	cin >> string;
	cout << endl;
	book.ChangeNumberBooks(string);

	typography.AddBook(book);

}

void deleteOrder(Typography& typography)
{
	bool successDelete;
	char ch;
	deleteOrderMenu();
	while ((ch = getCh()) != '4')
	{
		switch (ch)
		{
		case'1':
			successDelete = deleteBook(typography);
			break;
		case'2':
			successDelete = deletePoster(typography);
			break;
		case'3':
			successDelete = deleteBusinessCard(typography);
			break;
		}

		if(successDelete)
			cout << "Ваш заказ удалён!" << endl << endl;
		else 
			cout << "Ваш не найден!" << endl << endl;
		deleteOrderMenu();
	}
}

bool deleteBook(Typography& typography)
{
	char temp[String::CINLIM];
	cout << "Введите название удаляемой книги:" << endl;
	cin.getline(temp, String::CINLIM);
	cout << endl;
	return typography.DeleteBook(temp);
}

bool deletePoster(Typography& typography)
{
	char temp[String::CINLIM];
	cout << "Введите тип удаляемого постера:" << endl;
	cin.getline(temp, String::CINLIM);
	cout << endl;
	return typography.DeletePoster(temp);
}

bool deleteBusinessCard(Typography& typography)
{
	char temp[String::CINLIM];
	cout << "Введите название услуги удаляемой визитки:" << endl;
	cin.getline(temp, String::CINLIM);
	cout << endl;
	return typography.DeleteBusinessCard(temp);
}

void outOrderOnScreen(const Typography& typography)
{
	cout << "Ваши заказы: " << endl << endl;
	cout << typography;
}

void inputOrdersFromFile(Typography& typography)
{
	ifstream file("input/Orders.txt");
	file >> typography;
	file.close();
	cout << "Заказы прочитаны из файла!" << endl << endl;
}

void outOrdersInFile(const Typography& typography)
{	
	ofstream file("input/Orders.txt");
	file << typography;
	file.close();
	cout << "Заказы сохранены в файл!" << endl << endl;
}

void mainMenu()
{	
	cout << "Выберите пункт меню:" << endl;
	cout << "1 - Оформить заказ" << endl;
	cout << "2 - Удалить заказ" << endl;
	cout << "3 - Посмотреть заказы" << endl;
	cout << "4 - Прочитать заказы из файла" << endl;
	cout << "5 - Сохранить заказы в файл" << endl;
	cout << "6 - Завершить программу" << endl;
	cout << endl;
}

void orderMenu()
{
	cout << "Выберите пункт меню:" << endl;
	cout << "1 - Заказать книгу" << endl;
	cout << "2 - Заказать плакат" << endl;
	cout << "3 - Заказать визитку" << endl;
	cout << "4 - Завершить оформление заказов" << endl;
	cout << endl;
}

void deleteOrderMenu()
{
	cout << "Выберите пункт меню:" << endl;
	cout << "1 - Удалить книгу" << endl;
	cout << "2 - Удалить плакат" << endl;
	cout << "3 - Удалить визитку" << endl;
	cout << "4 - Завершить удаление заказов" << endl;
	cout << endl;
}

char getCh()
{
	char ch;
	cin.get(ch);
	cout << endl;
	while (getchar() != '\n') 
		continue;
	return ch;
}