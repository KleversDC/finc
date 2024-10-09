#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
struct machinery {
	string instrument;
	string Producer;
	int year;
	int price;
};

void ShowBook(machinery household)
{
	cout << "------------------------------------" << endl;
	cout << "Device name : " << household.instrument << endl;
	cout << "Producer : " << household.Producer << endl;
	cout << "Year of hunting : " << household.year << endl;
	cout << "Price : " << household.price << "$" << endl;
}

void FillBook(machinery& household)
{
	cout << "Enter Device name : ";
	getline(cin, household.instrument);
	cout << "Enter Producer : ";
	getline(cin, household.Producer);
	cout << "Enter year : ";
	cin >> household.year;
	cout << "Enter Price  : ";
	cin >> household.price;
}

void saveToFile(const vector<machinery>& shop, const string& path)
{
	ofstream file(path, ios::app);
	if (file.is_open()) {
		for (auto household : shop)
		{
			file << household.instrument << "," << household.Producer << "," << household.year << "," << household.price << endl;
		}
		file.close();
		cout << "Data saved to file" << endl;
	}
	else {
		cout << "Error opening file" << endl;
	}
}

void loadFromFile(vector<machinery>& shop, const string& filename) {
	ifstream file(filename);
	if (file.is_open()) {
		shop.clear();
		string line;
		while (getline(file, line)) {
			machinery household;
			size_t pos = 0;

			pos = line.find(",");
			household.instrument = line.substr(0, pos);
			line.erase(0, pos + 1);

			pos = line.find(",");
			household.Producer = line.substr(0, pos);
			line.erase(0, pos + 1);

			pos = line.find(",");
			household.year = stoi(line.substr(0, pos));
			line.erase(0, pos + 1);

			pos = line.find(",");
			household.price = stoi(line.substr(0, pos));
			line.erase(0, pos + 1);

			shop.push_back(household);

		}
		file.close();
		cout << "Data loaded from file" << endl;
	}
	else {
		cout << "Error opening file" << endl;
	}
}

void ShowBooks(const vector<machinery>& shop)
{
	cout << "Books : " << endl;
	for (auto household : shop)
	{
		ShowBook(household);
	}
	cout << " ************************** \n";
}

void searchByAuthor(const vector<machinery>& shop, string instrument)
{
	for (auto household : shop)
	{
		if (household.instrument == instrument)
		{
			ShowBook(household);
		}
	}

}
void searchByAutho(const vector<machinery>& shop, string Producer)
{
	for (auto household : shop)
	{
		if (household.instrument == Producer)
		{
			ShowBook(household);
		}
	}

}
void searchByAuth(const vector<machinery>& shop, string year)
{
	for (auto household : shop)
	{
		if (household.instrument == year)
		{
			ShowBook(household);
		}
	}

}
void searchByAut(const vector<machinery>& shop, string price)
{
	for (auto household : shop)
	{
		if (household.instrument == price)
		{
			ShowBook(household);
		}
	}

}
int main()
{
	vector<machinery> shop;
	string filename = "books.txt";
	machinery myBook;
	FillBook(myBook);
	shop.push_back(myBook);
	saveToFile(shop, filename);
	//ShowBook(myBook);
	loadFromFile(shop, filename);
	//ShowBooks(shop);
	ShowBooks(shop);

}





















































//#include <iostream>
//#include <string>
//#include <vector>
//#include <fstream>
//
//using namespace std;
//struct Book {
//	string author;
//	string title;
//	string genre;
//	string publisher;
//	int year;
//	int price;
//	int pages;
//	double rating;
//};
//
//void ShowBook(Book book)
//{
//	cout << "------------------------------------" << endl;
//	cout << "Author : " << book.author << endl;
//	cout << "Title : " << book.title << endl;
//	cout << "Genre : " << book.genre << endl;
//	cout << "Publisher : " << book.publisher << endl;
//	cout << "Year : " << book.year << endl;
//	cout << "Price : " << book.price << endl;
//	cout << "Pages : " << book.pages << endl;
//	cout << "Rating : " << book.rating << endl;
//}
//
//void FillBook(Book& book)
//{
//	cout << "Enter author : ";
//	getline(cin, book.author);
//	cout << "Enter title : ";
//	getline(cin, book.title);
//	cout << "Enter genre :";
//	getline(cin, book.genre);
//	cout << "Enter publisher : ";
//	getline(cin, book.publisher);
//	cout << "Enter year : ";
//	cin >> book.year;
//	cout << "Enter price : ";
//	cin >> book.price;
//	cout << "Enter pages : ";
//	cin >> book.pages;
//	cout << "Enter rating : ";
//	cin >> book.rating;
//}
//
//void saveToFile(const vector<Book>& books, const string& path)
//{
//	ofstream file(path, ios::app);
//	if (file.is_open()) {
//		for (auto book : books)
//		{
//			file << book.author << "," << book.title << "," << book.genre << "," << book.publisher << "," << book.year << "," << book.price << "," << book.pages << "," << book.rating << endl;
//		}
//		file.close();
//		cout << "Data saved to file" << endl;
//	}
//	else {
//		cout << "Error opening file" << endl;
//	}
//}
//
//void loadFromFile(vector<Book>& books, const string& filename) {
//	ifstream file(filename);
//	if (file.is_open()) {
//		books.clear();
//		string line;
//		while (getline(file, line)) {
//			Book book;
//			size_t pos = 0;
//
//			pos = line.find(",");
//			book.author = line.substr(0, pos);
//			line.erase(0, pos + 1);
//
//			pos = line.find(",");
//			book.title = line.substr(0, pos);
//			line.erase(0, pos + 1);
//
//			pos = line.find(",");
//			book.genre = line.substr(0, pos);
//			line.erase(0, pos + 1);
//
//			pos = line.find(",");
//			book.publisher = line.substr(0, pos);
//			line.erase(0, pos + 1);
//
//			pos = line.find(",");
//			book.year = stoi(line.substr(0, pos));
//			line.erase(0, pos + 1);
//
//			pos = line.find(",");
//			book.price = stoi(line.substr(0, pos));
//			line.erase(0, pos + 1);
//
//			pos = line.find(",");
//			book.pages = stoi(line.substr(0, pos));
//			line.erase(0, pos + 1);
//
//			book.rating = stod(line);
//
//			books.push_back(book);
//
//		}
//		file.close();
//		cout << "Data loaded from file" << endl;
//	}
//	else {
//		cout << "Error opening file" << endl;
//	}
//}
//
//void ShowBooks(const vector<Book>& books)
//{
//	cout << "Books : " << endl;
//	for (auto book : books)
//	{
//		ShowBook(book);
//	}
//	cout << " ************************** \n";
//}
//
//void searchByAuthor(const vector<Book>& books, string author)
//{
//	for (auto book : books)
//	{
//		if (book.author == author)
//		{
//			ShowBook(book);
//		}
//	}
//
//}
//void searchByAutho(const vector<Book>& books, string title)
//{
//	for (auto book : books)
//	{
//		if (book.author == title)
//		{
//			ShowBook(book);
//		}
//	}
//
//}
//void searchByAuth(const vector<Book>& books, string genre)
//{
//	for (auto book : books)
//	{
//		if (book.author == genre)
//		{
//			ShowBook(book);
//		}
//	}
//
//}
//void searchByAut(const vector<Book>& books, string publisher)
//{
//	for (auto book : books)
//	{
//		if (book.author == publisher)
//		{
//			ShowBook(book);
//		}
//	}
//
//}
//void searchByAu(const vector<Book>& books, string year)
//{
//	for (auto book : books)
//	{
//		if (book.author == year)
//		{
//			ShowBook(book);
//		}
//	}
//
//}
//void searchByA(const vector<Book>& books, string price)
//{
//	for (auto book : books)
//	{
//		if (book.author == price)
//		{
//			ShowBook(book);
//		}
//	}
//
//}
//void searchBy(const vector<Book>& books, string pages)
//{
//	for (auto book : books)
//	{
//		if (book.author == pages)
//		{
//			ShowBook(book);
//		}
//	}
//
//}
//void searchB(const vector<Book>& books, string rating)
//{
//	for (auto book : books)
//	{
//		if (book.author == rating)
//		{
//			ShowBook(book);
//		}
//	}
//
//}
//
//int main()
//{
//	vector<Book> books;
//	string filename = "books.txt";
//	Book myBook;
//	FillBook(myBook);
//	books.push_back(myBook);
//	saveToFile(books, filename);
//	ShowBook(myBook);
//	loadFromFile(books, filename);
//	ShowBooks(books);
//	searchByAuthor(books, "Mark Twain");
//	searchByAutho(books, "Mark Twain");
//	searchByAuth(books, "Mark Twain");
//	searchByAut(books, "Mark Twain");
//	searchByAu(books, "Mark Twain");
//	searchByA(books, "Mark Twain");
//	searchBy(books, "Mark Twain");
//	searchB(books, "Mark Twain");
//}