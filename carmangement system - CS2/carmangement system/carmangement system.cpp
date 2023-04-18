//important libraries to call builtin functions
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <chrono>
#include <iomanip>
#include <conio.h>


using namespace std;

using namespace std::chrono;

// creating a enumeration class to provide a way to declare company invoice order and customers types
enum class Types
{
	COMPANIES,
	INVOICES,
	ORDERS,
	CUSTOMERS
};

// creating a enumeration class to provide a way to declare Empty service and consultatioin material types
enum class ItemType
{
	EMPTY,
	SERVICE,
	CONSULTATION,
	MATERIAL
};

COORD coord = { 0, 0 };
//move the cursor in the console to the specific point and then print information from that point  
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
// Classes declaration
class Invoice;
class Company;
class Customer;
class Order;
struct OrderItem;

// Creating global constants that store important information
const float CarPrice = 10000.0f;
const float CarPartsPrice = 100.0f;
const float ServicePrice = 75.0f;
const float SaleServicePrice = 25.f;
const float PaymentArrangementPrice = 25.f;
const float RepairServicePrice = 25.f;
const float ShortTermConsultingPrice = 150.f;
const float MainRepairConsultingPrice = 500.f;
const std::string SaveFile = "save.txt";
const std::string companyfile = "Company.txt";
const std::string orderfile = "Order.txt";
const std::string customerfile = "Customer.txt";
const std::string invoicefile = "Invoice.txt";

// decleraing Creating a function to creat a file
void createFile();
// Used to create a vectore that tokenize the string line and split it wher comma occurs
std::vector<std::string> tokenizer(std::string& line, const char* delimiter = ",");
// decleraing function to save a read file 
void readSavedFile();
// decleraing funcion to update data in save file
void updateSavedFile();

// fucntion used to get real time from the sytem that is running the program
const std::string currentDateTime() {
	struct tm timeinfo;
	//localtime_s(&timeinfo, &rawtime);
	return "";
}

// Declearing some function that deals with companies orders invoice and custimers 
void printOrders();
void printCompanies();
void printCustomers();
void printInvoices();
bool checkCustomerCompany();


// Declearing functions that create menus that are used in the project 
void printMainMenu();
void printNewInvoiceMenu();
void printNewCompanyMenu();
void printNewCustomerMenu();
void printNewOrderMenu();
void printOthersMenu();
void printOthersMenuPrint();
void printOrderMenuServices();
void printOrderMenuConsultation();
void printOrderMenuMaterials();
void printspecficinvoice(int invoicenumber_option);
void getitem();
void updatecustomer();
void updatecompany();
void updateorder();
void updateinvoice();

// dynamic arrays that holds elements of types invoice company customers and orders class
std::vector<Invoice> Invoices;
std::vector<Company> Companies;
std::vector<Customer> Customers;
std::vector<Order> Orders;

//creating a order item structure that deals with the enumeration class declare before and assigne quantity and price 
struct OrderItem
{
	ItemType type = ItemType::EMPTY;
	unsigned int quantity = 0;
	float price = 0.f;
};

//creating functions in invoice class
class Invoice
{
	//creating public function
public:
	// This is the declaration of a default constructor of Invoice  
	Invoice() = default;
	// This is the declaration of a parameter constructor of invoice
	Invoice(const unsigned int invoiceNumber, const std::string& customer, const std::string& company) :
		mInvoiceNumber(invoiceNumber), mCustomer(customer), mCompany(company) {}

	// crrating a invoce function that will set the value of invoice number 
	void setInvoiceNumber(const unsigned int invoiceNumber) { mInvoiceNumber = invoiceNumber; }

	// crrating a set customer function that will set the value of Customer name 
	void setCustomerName(const std::string& customerName) { mCustomer = customerName; }

	// crrating a  set company function that will set the value of company name  
	void setCompany(const std::string& companyName) { mCompany = companyName; }

	// CREATING A FUNCTION THAT RETURNS THE INVOICE NUMBER TO BE USE LATER
	unsigned int number() const { return mInvoiceNumber; }
	// creating function that return the customer name to be use later
	std::string customerName() const { return mCustomer; }
	// creating function that return the company name to be use later
	std::string companyName() const { return mCompany; }

	//creating private functions
private:
	// creating private variables that store invoice number, customer name and company name 
	unsigned int mInvoiceNumber = 0;
	std::string mCustomer;
	std::string mCompany;
};

// creating methods and functions in company class 
class Company
{
	//creating public functions
public:

	// This is the declaration of a default constructor of Invoice 
	Company() = default;

	// This is the declaration of a parameter constructor of Invoice 
	Company(const std::string& name, const std::string& logo, const std::string& address, const std::string& desc, const std::string& notes, const std::string& terms, const float tax, const std::string& buildingno, const std::string& street, const std::string& city, const std::string& postcode, const std::string& phonenum) :
		mName(name), mLogo(logo), mAddress(address), mDescription(desc), mNotes(notes), mTerms(terms), mTax(tax), mbuildingno(buildingno), mstreet(street), mcity(city), mpostcode(postcode), mphonenumber(phonenum) {}


	// creating function to set the name, logo, address, description, notes, tems and tax of the company 
	void setName(const std::string& name) { mName = name; }
	void setLogo(const std::string& logo) { mLogo = logo; }
	void setAddress(const std::string& address) { mAddress = address; }
	void setbuildingno(const std::string& buildingno) { mbuildingno = buildingno; }
	void setstreet(const std::string& street) { mstreet = street; }
	void setcity(const std::string& city) { mcity = city; }
	void setpostcode(const std::string& postcode) { mpostcode = postcode; }
	void setphone(const std::string& phonenumber) { mphonenumber = phonenumber; }
	void setDescription(const std::string& description) { mDescription = description; }
	void setNotes(const std::string& notes) { mNotes = notes; }
	void setTerms(const std::string& terms) { mTerms = terms; }
	void setTax(const float tax) { mTax = tax; }


	// creating function to return the name, logo, address, description, notes, tems and tax of the company 
	std::string name() const { return mName; }
	std::string logo() const { return mLogo; }
	
	std::string address() const { return mAddress; }
	std::string buildingno() const { return mbuildingno; }
	std::string street() const { return mstreet; }
	std::string city() const { return mcity; }
	std::string postcode() const { return mpostcode; }
	std::string phonenumber() const { return mphonenumber; }

	std::string description() const { return mDescription; }
	std::string notes() const { return mNotes; }
	std::string terms() const { return mTerms; }
	float tax() const { return mTax; }

	//creating private variables to be use in the class
private:
	//creating variables to store logo,  name, address, description, notes, terms and tax for the company
	std::string mLogo;
	std::string mName;
	std::string mAddress;
	std::string mbuildingno;
	std::string mstreet;
	std::string mcity;
	std::string mpostcode;
	std::string mphonenumber;
	std::string mDescription;
	std::string mNotes;
	std::string mTerms;
	float mTax = 0.f;
};

// declearing functions in the customer class
class Customer
{
public:

	// This is the declaration of a default constructor of Invoice 
	Customer() = default;

	// This is the declaration of a parameter constructor of Invoice 	
	Customer(const std::string& name, const std::string& address, const std::string& building, const std::string& street, const std::string& city, const std::string& postcode, const std::string& phonenumber, unsigned int ordersAmount = 0) :
		mName(name), mAddress(address), mOrdersAmount(ordersAmount),mbuildingno(building), mcity(city), mpostcode(postcode), mstreet(street), mphonenumber(phonenumber) {}

	// creating functions that set names, address , order amount , increase the order amount and decrease the order amount. 
	void setName(const std::string& name) { mName = name; }
	void setAddress(const std::string& address) { mAddress = address; }
	void setbuildingno(const std::string& buildingno) { mbuildingno = buildingno; }
	void setstreet(const std::string& street) { mstreet = street; }
	void setcity(const std::string& city) { mcity = city; }
	void setpostcode(const std::string& postcode) { mpostcode = postcode; }
	void setphone(const std::string& phonenumber) { mphonenumber = phonenumber; }


	void setOrdersAmount(const unsigned int amount) { mOrdersAmount = amount; }
	void increaseOrders() { mOrdersAmount++; }
	void decreaseOrders() { if (mOrdersAmount > 0) mOrdersAmount--; }

	// creating function that return the name address and order amount of the customer
	std::string name() const { return mName; }
	std::string address() const { return mAddress; }
	std::string buildingno() const { return mbuildingno; }
	std::string street() const { return mstreet; }
	std::string city() const { return mcity; }
	std::string postcode() const { return mpostcode; }
	std::string phonenumber() const { return mphonenumber; }

	unsigned int ordersAmount() const { return mOrdersAmount; }

	//declearing private variables
private:
	// creating variables that store name address and order amount 
	std::string mName;
	std::string mAddress;
	std::string mbuildingno;
	std::string mstreet;
	std::string mcity;
	std::string mpostcode;
	std::string mphonenumber;
	unsigned int mOrdersAmount = 0;
};

//delearing order class to deal with orders
class Order
{
public:

	// This is the declaration of a default constructor of Invoice 	
	Order() = default;

	// This is the declaration of a parameter constructor of Invoice 	
	Order(const std::string& issuedDate, const std::string& dueDate, const unsigned int invoiceNumber, const float amountDue) :
		mIssuedDate(issuedDate), mDueDate(dueDate), mInvoiceNumber(invoiceNumber), mSubTotal(amountDue) {}

	// creating functions that set issue date, due data and invoice number 
	void setIssuedDate(const std::string& issuedDate) { mIssuedDate = issuedDate; }
	void setDueDate(const std::string& dueDate) { mDueDate = dueDate; }
	void setInvoiceNumber(const unsigned int invoiceNumber) { mInvoiceNumber = invoiceNumber; }
	// creating a fucntion that add orders to the vector
	void addItem(OrderItem order) { mItems.push_back(order); }

	// creating a vector a dynamic array  of orderitem type to store order items 
	std::vector<OrderItem>& items() { return mItems; }

	// creating a function to return issuedate
	std::string issuedDate() const { return mIssuedDate; }

	// creating a function to return duedate
	std::string dueDate() const { return mDueDate; }

	//creating a function to return invoice number
	unsigned int invoiceNumber() const { return mInvoiceNumber; }
	//creating a function to calculate the subtotal of the order of the customer and return it
	float subTotal() { calculateSubTotal(); return mSubTotal; }

	//creating a function to return the subtotal after giving discount 
	float discount() { return subTotal() * 0.1f; }

	// creating fucntion to add service price and item price  and return the new service price 
	float getService_price()
	{
		float service_price = 0.f;
		for (OrderItem& item : mItems)
		{
			if (item.type == ItemType::SERVICE) {
				service_price += item.price;
				break;
			}
		}

		return service_price;
	}

	// function to add item quantity to service quantity and return the new sevice quanity.
	unsigned int getService_quantity()
	{
		unsigned int service_quantity = 0;
		for (OrderItem& item : mItems)
		{
			if (item.type == ItemType::SERVICE) {
				service_quantity += item.quantity;
				break;
			}
		}

		return service_quantity;
	}

	//function to get the new consultation price by adding consultation price with item price. 
	float getConsultation_price()
	{
		float consult_price = 0.f;
		for (OrderItem& item : mItems)
		{
			if (item.type == ItemType::CONSULTATION) {
				consult_price += item.price;
				break;
			}
		}

		return consult_price;
	}

	//function to get the new consultation quantity by adding consultation price with item quantity. 
	unsigned int getConsultation_quantity()
	{
		unsigned int consult_quantity = 0;
		for (OrderItem& item : mItems)
		{
			if (item.type == ItemType::CONSULTATION) {
				consult_quantity += item.quantity;
				break;
			}
		}

		return consult_quantity;
	}


	// function to get the new material price  of the item.
	float getMaterial_price()
	{
		float Material_price = 0.f;
		for (OrderItem& item : mItems)
		{
			if (item.type == ItemType::MATERIAL) {
				Material_price += item.price;
				break;
			}
		}

		return Material_price;
	}

	// function to get the new material quantity
	unsigned int getMaterial_quantity()
	{
		unsigned int Material_quantity = 0;
		for (OrderItem& item : mItems)
		{
			if (item.type == ItemType::MATERIAL) {
				Material_quantity += item.quantity;
				break;
			}
		}

		return Material_quantity;
	}

	//private functions
private:
	// calculating the total of the order 
	void calculateSubTotal()
	{
		float totalPrice = 0.f;
		for (OrderItem& item : mItems)
		{
			totalPrice += item.price * item.quantity;
		}

		mSubTotal = totalPrice;

	}

	// a private dynamic array to store innformation of the items
	std::vector<OrderItem> mItems;
	std::string mIssuedDate;
	std::string mDueDate;
	unsigned int mInvoiceNumber = 0;
	float mSubTotal = 0.f;
};

//function that create and open the file 
void createFile()
{
	// open file name Savefile 
	std::fstream f;
	f.open(SaveFile);
	if (f.good())
	{
		f.close();
		readSavedFile();
		return;
	}
	f.close();

	// writing a empty string in the file
	std::ofstream of;
	of.open(SaveFile);
	of << "";
	of.close();
}

// tokenizer function to tokenize the file lines and split them from comma
std::vector<std::string> tokenizer(std::string& line, const char* delimiter)
{
	// dynamic array to store token
	std::vector<std::string> tokens;
	char* nextToken = NULL;
	char* str = strtok_s((char*)line.c_str(), delimiter, &nextToken);
	while (str) {
		tokens.push_back(str);
		str = strtok_s(NULL, delimiter, &nextToken);
	}

	return tokens;
}

// function that read the data from the file 
void readSavedFile()
{
	//opening string 
	std::ifstream f;
	f.open(SaveFile);
	if (!f.good())
	{
		std::cout << "Bad filename\n";
		exit(-1);
	}

	std::string line;
	while (std::getline(f, line))
	{
		// using function to tokenize the input string in lines formate 
		std::vector<std::string> tokens = tokenizer(line);
		// checking if the line start at C
		if (line[0] == 'C')
		{
			// Company
			// creating company class object
			Company company;
			// taking infomation from file and seting company name etc
			company.setName(tokens.at(1));
			company.setLogo(tokens.at(2));
			company.setAddress(tokens.at(3));
			company.setbuildingno(tokens.at(4));
			company.setstreet(tokens.at(5));
			company.setcity(tokens.at(6));
			company.setpostcode(tokens.at(7));
			company.setphone(tokens.at(8));
			company.setTax(std::stof(tokens.at(9)));
			company.setNotes(tokens.at(10));
			company.setTerms(tokens.at(11));

			// pushing the company object in the variable container 
			Companies.push_back(company);
		}
		else if (line[0] == 'O')
		{
			// creatin Orders class object
			Order order;
			//taking information from the file and storing it in order class
			order.setInvoiceNumber(std::stoi(tokens.at(3)));
			order.setIssuedDate(tokens.at(2));
			order.setDueDate(tokens.at(1));

			//The last token is a list {...}{...}
			std::string strList = tokens.at(4);
			// tokenizing the list of a string that ends with }
			std::vector<std::string> list = tokenizer(strList, "}");
			// running the loop untill list token ends 
			for (auto& s : list)
			{
				s = s.substr(1, s.size() - 1);
				// again creating a dynamic list to store the information which is separated by "-"
				std::vector<std::string> tok = tokenizer(s, "-");

				OrderItem item;
				item.price = std::stof(tok.at(0));
				item.quantity = std::stoi(tok.at(1));
				// storing the item serviice and consulating information from the file to their container
				if (tok.at(2) == "Service")
					item.type = ItemType::SERVICE;
				else if (tok.at(2) == "Consulting")
					item.type = ItemType::CONSULTATION;
				else
					item.type = ItemType::MATERIAL;

				//adding item in the order item class 
				order.addItem(item);
			}
			//storing the order information in the order containner 
			Orders.push_back(order);
		}
		else if (line[0] == 'I')
		{
			//  creatin Invoices class object
			Invoice invoice;
			//taking data from file and storing it in the Invoice class object
			invoice.setCompany(tokens.at(1));
			invoice.setInvoiceNumber(std::stoi(tokens.at(2)));
			invoice.setCustomerName(tokens.at(3));

			//storing the information of the invoice object in the Invoices dynamic array 
			Invoices.push_back(invoice);
		}
		else if (line[0] == 'U')
		{
			// Customer class object
			Customer customer;
			// saving information in the customer class
			customer.setName(tokens.at(1));
			customer.setAddress(tokens.at(2));
			customer.setbuildingno(tokens.at(3));
			customer.setstreet(tokens.at(4));
			customer.setcity(tokens.at(5));
			customer.setpostcode(tokens.at(6));
			customer.setphone(tokens.at(7));
			customer.setOrdersAmount(std::stoi(tokens.at(8)));

			//saving the customer object in the customers container 
			Customers.push_back(customer);
		}
	}
	//CLOSING THE FILE
	f.close();
}

// creating function to update the file information
void updateSavedFile()
{
	//creating container of string 
	std::vector<std::string> lines;
	std::ofstream f;
	std::ofstream c;
	std::ofstream o;
	std::ofstream cu;
	std::ofstream i;
	//opening file in write mode
	f.open(SaveFile);
	c.open(companyfile);
	o.open(orderfile);
	cu.open(customerfile);
	i.open(invoicefile);
	if (!f.good())
	{
		std::cout << "Bad filename\n";
		exit(-1);
	}
	// running the for loop untill the invoice object in the invoices containers donot end
	for (Invoice& invoice : Invoices)
	{
		//saving data to invoice file
		i<<"I,"
			<< invoice.companyName() << ","
			<< invoice.number() << ","
			<< invoice.customerName() << "\n";
		//displaying information
		f << "I,"
			<< invoice.companyName() << ","
			<< invoice.number() << ","
			<< invoice.customerName() << "\n";
	}
	// running the for loop untill the orders object in the invoices containers donot end
	for (Order& order : Orders)
	{
		o << "O,"
			<< order.dueDate() << ","
			<< order.issuedDate() << ","
			<< order.invoiceNumber() << ",";
		//displaying information realated to orders
		f << "O,"
			<< order.dueDate() << ","
			<< order.issuedDate() << ","
			<< order.invoiceNumber() << ",";


		for (OrderItem& item : order.items())
		{
			//checking the item type is it service type or consulting or material and displayin on screen
			std::string type;
			if (item.type == ItemType::SERVICE)
				type = "Service";
			else if (item.type == ItemType::CONSULTATION)
				type = "Consulting";
			else
				type = "Material";

			f << "{" << item.price << "-" << item.quantity << "-" << type << "}";
			o << "{" << item.price << "-" << item.quantity << "-" << type << "}";
		}

		f << "\n";
		o << "\n";
	}

	for (Company& company : Companies)
	{
		//displaying information of the company
		f << "C,"
			<< company.name() << ","
			<< company.logo() << ","
			<< company.address() << ","
			<< company.buildingno() << ","
			<< company.street() << ","
			<< company.city() << ","
			<< company.postcode() << ","
			<< company.phonenumber() << ","
			<< company.tax() << ","
			<< company.notes() << ","
			<< company.terms() << "\n";
		c << "C,"
			<< company.name() << ","
			<< company.logo() << ","
			<< company.address() << ","
			<< company.buildingno() << ","
			<< company.street() << ","
			<< company.city() << ","
			<< company.postcode() << ","
			<< company.phonenumber() << ","
			<< company.tax() << ","
			<< company.notes() << ","
			<< company.terms() << "\n";
	}

	for (Customer& customer : Customers)
	{

		//displaying information of the customer
		f << "U,"
			<< customer.name() << ","
			<< customer.address() << ","
			<< customer.buildingno() << ","
			<< customer.street() << ","
			<< customer.city() << ","
			<< customer.postcode() << ","
			<< customer.phonenumber() << ","
			<< customer.ordersAmount() << "\n";
		cu << "U,"
			<< customer.name() << ","
			<< customer.address() << ","
			<< customer.buildingno() << ","
			<< customer.street() << ","
			<< customer.city() << ","
			<< customer.postcode() << ","
			<< customer.phonenumber() << ","
			<< customer.ordersAmount() << "\n";
	}

	//closing the file
	f.close();
}

// check for customer company
bool checkCustomerCompany()
{
	//chekcing if there is a company and customers in the file 
	if (Companies.empty())
	{
		std::cout << "Please create a new Company at first!\n";
		_getch();
		return false;
	}
	else if (Customers.empty())
	{
		std::cout << "Please create a new Customer at first!\n";
		_getch();
		return false;
	}
	return true;
}
// function to print main menu
void printMainMenu()
{
	//creating a variable 
	short choice = -1;

	// Main menu loop
	// running the main loop untill the user type "0"
	while (choice != 0)
	{
		system("cls");
		std::cout <<
			"-------Main Menu-------\n"
			"1 - New Invoice\n"
			"2 - New Company\n"
			"3 - New Customer\n"
			"4 - New Order\n"
			"5 - Others\n"
			"0 - Exit\n";

		std::cout << "Insert an option: ";
		std::cin >> choice;
		std::cin.ignore();

		switch (choice)
		{
		case 1:
			// printing he new Invoice
			if (checkCustomerCompany())
				printNewInvoiceMenu();
			break;
		case 2:
			// New Company Menu
			printNewCompanyMenu();
			cout << "Company added sucessfully";
			_getch();
			break;
		case 3:
			// New Customermenu
			printNewCustomerMenu();
			cout << "Customer added sucessfully";
			_getch();
			break;
		case 4:
			// New Order menu
			if (checkCustomerCompany())
				printNewOrderMenu();
			break;
		case 5:
			// Others menu
			printOthersMenu();
			break;
		case 0:
			// Exit 
			std::cout << "Bye!\n";
			break;
		default:
			// Invalid input
			std::cout << "Please insert a valid option!\n";
			choice = -1;
			break;
		}

	}

}
// others menu 
void printOthersMenu()
{
	bool repeat = true;
	while (repeat)
	{
		system("cls");
		std::cout << "-------Others Menu-------\n"
			"1 - Get item\n"
			"2 - Print\n"
			"3 - Update\n"
			"0 - Back\n";

		short choice = -1;
		std::cout << "Enter option: ";
		std::cin >> choice;
		std::cin.ignore();
		if (choice == 1)
		{
			//get items
			getitem();
		}
		else if (choice == 2)
		{
			//print
			system("cls");
			printOthersMenuPrint();
		}
		else if (choice == 3)
		{
			system("cls");
			//update
			std::cout << "Which item do you want to update?\n";
			std::cout << "1 - Customers\n"
				"2 - Companies\n"
				"3 - Orders\n"
				"4 - Invoices: ";

			choice = -1;

			std::cin >> choice;
			std::cin.ignore();
			cout << endl;

			//opening the customer contaniner to uodate
			if (choice == 1 && Customers.size() != 0)
			{
				updatecustomer();

			}
			else if (choice == 2 && Companies.size() != 0)
			{
				updatecompany();
			}
			else if (choice == 3 && Orders.size() != 0)
			{
				updateorder();
				
			}
			else if (choice == 4 && Invoices.size() != 0)
			{
				updateinvoice();

			}

		}
		else if (choice == 0)
		{
			//exit
			return;
		}
		else
		{
			cout << "Chose the right option! ";
		}
		updateSavedFile();
	

	}
}

void updateinvoice()
{

	short internalChoice = -1;
	//displaying all invoices
	for (size_t i = 0; i < Invoices.size(); i++)
	{
		std::cout << i << " - Invoice number:" << Invoices.at(i).number();
	}

	std::cout << "Insert the one you want to update: ";
	std::cin >> internalChoice;
	std::cin.ignore();
	//taking inforamtion to update company name customer name
	std::string companyName, customerName;
	std::cout << "Insert company name: ";
	std::getline(std::cin, companyName);
	std::cout << "Insert customer name: ";
	std::getline(std::cin, customerName);

	unsigned int invoiceNumber = 0;
	std::cout << "Insert invoice number: ";
	std::cin >> invoiceNumber;
	std::cin.ignore();
	//updating invoice
	Invoices.at(internalChoice).setCompany(companyName);
	Invoices.at(internalChoice).setCustomerName(customerName);
	Invoices.at(internalChoice).setInvoiceNumber(invoiceNumber);
}

void updatecompany()
{

	//displaying all the compains 
	short internalChoice = -1;
	for (size_t i = 0; i < Companies.size(); i++)
	{
		std::cout << i << " - " << Companies.at(i).name() << "\n";
	}

	std::cout << "Insert the one you want to update: ";
	std::cin >> internalChoice;
	std::cin.ignore();

	std::string companyName, companyLogo, companyAddress, companyphone, companyDescription, companyNotes, companyTerms, companybuilding, companystreet, companycity, companypostcode;
	float companyTax = 0.f;
	//taking inforamtion to update the selected company
	std::cout << "Enter company name: ";
	std::getline(std::cin, companyName);

	std::cout << "Enter company logo: ";
	std::getline(std::cin, companyLogo);

	std::cout << "----Company Address----";
	companyAddress = "em";

	std::cout << "\nEnter Building no : ";
	std::getline(std::cin, companybuilding);

	std::cout << "Enter street : ";
	std::getline(std::cin, companystreet);

	std::cout << "Enter city : ";
	std::getline(std::cin, companycity);

	std::cout << "Enter postcode : ";
	std::getline(std::cin, companypostcode);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, companyphone);

	std::cout << "Enter company description: ";
	std::getline(std::cin, companyDescription);

	std::cout << "Enter company notes: ";
	std::getline(std::cin, companyNotes);

	std::cout << "Enter company terms: ";
	std::getline(std::cin, companyTerms);

	std::cout << "Enter company tax: ";
	std::cin >> companyTax;
	std::cin.ignore();
	//updating the compaines container
	Companies.at(internalChoice) =
		Company(companyName, companyLogo, companyAddress, companyDescription, companyNotes, companyTerms, companyTax,companybuilding,companystreet,companycity,companypostcode,companyphone);
}
void updatecustomer()
{
	short internalChoice = -1;
	//displaying all custumers
	for (size_t i = 0; i < Customers.size(); i++)
	{
		std::cout << i << " - " << Customers.at(i).name() << "\n";
	}

	std::cout << "Insert the one you want to update: ";
	std::cin >> internalChoice;
	std::cin.ignore();
	//asking user to update the customer information
	std::string name, address, customerbuilding, customerstreet, customercity, customerpostcode,customerphone;
	std::cout << "Insert the new name: ";
	std::getline(std::cin, name);
	std::cout << "-----Address-----";
	address = "emp";
	std::cout << "\nEnter Building no : ";
	std::getline(std::cin, customerbuilding);

	std::cout << "Enter street : ";
	std::getline(std::cin, customerstreet);

	std::cout << "Enter city : ";
	std::getline(std::cin, customercity);

	std::cout << "Enter postcode : ";
	std::getline(std::cin, customerpostcode);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, customerphone);


	Customers.at(internalChoice).setName(name);
	Customers.at(internalChoice).setAddress(address);
	Customers.at(internalChoice).setbuildingno(customerbuilding);
	Customers.at(internalChoice).setstreet(customerstreet);
	Customers.at(internalChoice).setcity(customercity);
	Customers.at(internalChoice).setpostcode(customerpostcode);
	Customers.at(internalChoice).setphone(customerphone);


}
void updateorder()
{
	short internalChoice = -1;
	short itemChoice = -1;
	//displaying all orders
	for (size_t i = 0; i < Orders.size(); i++)
	{
		std::cout << "Order " << i << " : " << "\n";
		//using loop to display all orders and their type like service consultatuion materials
		for (size_t j = 0; j < Orders.at(i).items().size(); j++)
		{
			std::cout << j << " - ";
			std::cout << " Price:" << Orders.at(i).items().at(j).price << " " <<
				" Quantity:" << Orders.at(i).items().at(j).quantity << " Service:";
			if (Orders.at(i).items().at(j).type == ItemType::SERVICE)
				std::cout << "Service";
			else if (Orders.at(i).items().at(j).type == ItemType::CONSULTATION)
				std::cout << "Consultation";
			else
				std::cout << "Material";

			std::cout << "\n";
		}

		std::cout << "\n";

	}

	std::cout << "Insert the one you want to update: ";
	std::cin >> internalChoice;
	std::cin.ignore();
	//taking information to update the orders
	std::cout << "Insert the item you want to update: ";
	std::cin >> itemChoice;
	std::cin.ignore();

	float price = 0.f;
	std::cout << "Insert price: ";
	std::cin >> price;
	std::cin.ignore();

	unsigned int quantity = 0;
	std::cout << "Insert quantity: ";
	std::cin >> quantity;
	std::cin.ignore();
	//updating the price and quantity
	Orders.at(internalChoice).items().at(itemChoice).price = price;
	Orders.at(internalChoice).items().at(itemChoice).quantity = quantity;

}
void getitem()
{

	bool repeat = true;
	while (repeat)
	{
		system("cls");
		std::cout << "Get Item Of: \n"
			"1 - Invoice\n"
			"2 - Company\n"
			"3 - Customer\n"
			"4 - Order\n"
			"0 - Back\n";

		std::cout << "Enter an option: ";
		short choice = -1;
		std::cin >> choice;
		std::cin.ignore();

		switch (choice)
		{
		case 1:
			// Invoice

			cout << "\n What do you want to do\n";
			cout << "\n 1)Print\n";
			cout << "\n 2)Update\n";
			cin >> choice;
			cin.ignore();
			if (choice)
			{
				printInvoices();

			}
			else if (choice)
			{
				updateinvoice();
			}
			else
			{
				cout << "Wrong choice!";
			}
			_getch();
			break;
		case 2:
			// Company
			int choice;
			cout << "\n What do you want to do\n";
			cout << "\n 1)Print\n";
			cout << "\n 2)Update\n";
			cin >> choice;
			cin.ignore();
			if (choice)
			{
				printCompanies();
			}
			else if (choice)
			{
				updatecompany();
			}
			else
			{
				cout << "Wrong choice!";
			}
			_getch();
			break;
		case 3:
			// Customer

			cout << "\n What do you want to do\n";
			cout << "\n 1)Print\n";
			cout << "\n 2)Update\n";
			cin >> choice;
			cin.ignore();
			if (choice==1)
			{
				printCustomers();
			}
			else if (choice==2)
			{

				updatecustomer();
			}
			else
			{
				cout << "Wrong choice!";
			}

			_getch();
			break;
		case 4:
			// Order
			cout << "\n What do you want to do\n";
			cout << "\n 1)Print\n";
			cout << " 2)Update\n";
			cout << "Chose opion: ";
			cin >> choice;
			cin.ignore();
			if (choice)
			{
				printOrders();
			}
			else if (choice)
			{
				updateorder();
			}
			else
			{
				cout << "Wrong choice!";
			}
			_getch();
			break;
		case 0:
			repeat = false;
			break;
		default:
			std::cout << "Please insert a valid option\n";
			break;
		}
	}
}
//function to print the menu to ask what to print 
void printOthersMenuPrint()
{
	bool repeat = true;
	while (repeat)
	{
		system("cls");
		std::cout << "------Print Menu------\n"
			"1 - Invoice\n"
			"2 - Company\n"
			"3 - Customer\n"
			"4 - Order\n"
			"0 - Back\n";

		std::cout << "Enter an option: ";
		short choice = -1;
		std::cin >> choice;
		std::cin.ignore();

		switch (choice)
		{
		case 1:
			// Invoice
			printInvoices();
			_getch();
			break;
		case 2:
			// Company
			printCompanies();
			_getch();
			break;
		case 3:
			// Customer
			printCustomers();
			_getch();
			break;
		case 4:
			// Order
			printOrders();
			_getch();
			break;
		case 0:
			repeat = false;
			break;
		default:
			std::cout << "Please insert a valid option\n";
			break;
		}
	}
}
// function to print companies
void printCompanies()
{
	std::cout << "Companies:\n";
	// printing all companies
	for (Company& company : Companies)
	{
		std::cout << "Name: " << company.name()
			<<"------Address------"
			<< "\nBuilding: " << company.buildingno()
			<< "\nStreet: " << company.street()
			<< "\nCity: " << company.city()
			<< "\nPostcode: " << company.postcode()
			<< "\nPhonenumber: " << company.phonenumber()
			<< "\nLogo: " << company.logo()
			<< "\n";
		cout << "--------------------------------------------------------";
	}
}
//display all customers
void printCustomers()
{
	std::cout << "Customers: \n";
	//printing all customers
	for (Customer& customer : Customers)
	{
		std::cout << "Name: " << customer.name()
			<<"------Address------"
			<< "\nBuilding: " << customer.buildingno()
			<< "\nStreet: " << customer.street()
			<< "\nCity: " << customer.city()
			<< "\nPostcode: " << customer.postcode()
			<< "\nPhonenumber: " << customer.phonenumber()
			<< "\nOrders: " << customer.ordersAmount() << "\n";
		cout << "\n-------------------------------------------------------";
	}
}
//display all Invoice
void printInvoices()
{
	std::cout << "Invoices: \n";
	//printing all Invoice
	for (Invoice& invoice : Invoices)
	{
		std::cout << "Number:" << invoice.number()
			<< "  Company name:" << invoice.companyName()
			<< "  Customer name:" << invoice.customerName() << "\n";
	}
}
//display all orders
void printOrders()
{
	std::cout << "Orders:\n";
	std::cout << "--------------------\n";
	//printing all orders
	for (size_t i = 0; i < Orders.size(); i++)
	{
		std::vector<OrderItem> items = Orders.at(i).items();
		for (OrderItem& item : items)
		{
			std::cout << "Price:" << item.price << " Quantity:" << item.quantity << " Type:";
			if (item.type == ItemType::MATERIAL)
				std::cout << "Material\n";
			else if (item.type == ItemType::SERVICE)
				std::cout << "Service\n";
			else
				std::cout << "Consultation\n";
		}
		std::cout << "--------------------\n";
	}
}


void printNewInvoiceMenu()
{
	system("cls");
	cout << "------Invoice Menu------\n";
	//checking if their is an order or not 
	if (Orders.empty())
	{
		cout << "Order first." << endl;
		_getch();
	}
	else
	{
	invoices1:

		cout << "All invoices available:\n";
		for (size_t i = 0; i < Orders.size(); i++)
		{
			unsigned int invoiceNumber = Orders.at(i).invoiceNumber();
			cout << "Invoice number: " << invoiceNumber << endl;
		}

		std::cout << "Insert invoice number: ";
		unsigned int num = 0;
		std::cin >> num;
		std::cin.ignore();
		printspecficinvoice(num);
		_getch();
		char ch;
		cout << "\nDo you want to exit(y/n): ";
		cin >> ch;
		if (ch == 'y' || ch == 'Y')
		{
			return;
		}
		else
		{
			system("cls");
			goto invoices1;
		}
	}
	//getting information about the invoice

}

//printing specific invoice
void printspecficinvoice(int invoicenumber_option)
{
	bool con = true;
	for (size_t i = 0; i < Orders.size(); i++)
	{
		unsigned int invoiceNumber = Orders.at(i).invoiceNumber();
		if (invoiceNumber==invoicenumber_option)
		{
			con = false;
			//information about order
			float subTotal = Orders.at(i).subTotal();
			float discount = Orders.at(i).discount();
			float amountDue = (subTotal - discount) * 0.1;
			float tax = Companies.at(0).tax() * 0.17f;
		
			//getting information about the company
			std::string buldingno = Companies.back().buildingno();
			std::string street = Companies.back().street();
			std::string city = Companies.back().city();
			std::string postcode = Companies.back().postcode();
			std::string phonenumber = Companies.back().phonenumber();
			std::string name = Companies.back().name();
			std::string logo = Companies.back().logo();
			std::string terms = Companies.back().terms();
			std::string notes = Companies.back().notes();
			std::string dueDate = Orders.at(i).dueDate();
			
			//getting information about the service packs the client have takken 
			float price1 = Orders.at(i).getService_price();
			unsigned int quantity1 = Orders.at(i).getService_quantity();
			
			std::string dateIssued = Orders.at(0).dueDate();

			system("cls");
			
			
			std::cout << logo ;
			gotoxy(95,0);
			cout<< name << "\n";
			//std::cout << std::setw(95) << address << "\n";
			gotoxy(95, 1);
			std::cout << "Building No: " << buldingno;
			gotoxy(95, 2);
			std::cout << "Street: " << street ;
			gotoxy(95, 3);
			std::cout << "City: " << city ;
			gotoxy(95, 4);
			std::cout << "Postcode: " << postcode;
			gotoxy(95, 5);
			std::cout << "Phone No: " << phonenumber ;
			gotoxy(0, 7);
			std::cout << "Billed to ";
			gotoxy(39, 7);
			cout << "Date Issued";
			gotoxy(66, 7);
			cout << "Invoice Number";
			gotoxy(92, 7);
			cout << "Amount Due\n";
			gotoxy(0, 8);
			std::cout << Customers.back().name();
			gotoxy(39, 8);
			cout << dateIssued;
			gotoxy(66, 8);
			cout << invoiceNumber; 
			gotoxy(92, 8);
			cout << amountDue;
			gotoxy(0,9);
			std::cout << "Building No: " << Customers.back().buildingno();
			gotoxy(0, 10);
			std::cout << "Street: " << Customers.back().street();
			gotoxy(0, 11);
			std::cout << "City: " << Customers.back().city() << std::setw(31) << "Due Date";;
			gotoxy(0, 12);
			std::cout << "Postcode: " << Customers.back().postcode() << std::setw(29) << dueDate ;
			gotoxy(0, 13);
			std::cout << "Phone No: " << Customers.back().phonenumber();
			//std::cout << std::setw(40) << "Due Date\n";
			//std::cout << std::setw(47) << dueDate << "\n";
			std::cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
			std::cout << "-----------------------------------------------------------------------------------------------------------------------\n";
			std::cout << "DESCRIPTION" << std::setw(55) << "RATE" << std::setw(20) << "QTY" << std::setw(20) << "AMOUNT" << "\n";
			std::cout << "-----------------------------------------------------------------------------------------------------------------------\n\n";

			char buff[100];
			snprintf(buff, sizeof(buff), "%.02f", price1);
			std::string strRate = buff;

			for (int i = 0; i < sizeof(buff); i++)
				buff[i] = 0;
			snprintf(buff, sizeof(buff), "%.02f", price1 * quantity1);
			std::string strAmount = buff;
			gotoxy(0, 18);
			std::cout << "Services";
			gotoxy(62, 18);
			cout << "$" << strRate;
			gotoxy(83, 18);
			cout << quantity1;
			gotoxy(100, 18);
			cout << "$" << strAmount << "\n";
			gotoxy(0, 19);
			std::cout << "Cost of various services";
			gotoxy(62, 19); 
			cout << "+Tax\n";
			std::cout << "-----------------------------------------------------------------------------------------------------------------------\n";



			float consult_price = Orders.back().getConsultation_price();
			unsigned int consult_quantity = Orders.back().getConsultation_quantity();

			for (int i = 0; i < sizeof(buff); i++)
				buff[i] = 0;
			snprintf(buff, sizeof(buff), "%.02f", consult_price);
			std::string strConsult_price = buff;

			for (int i = 0; i < sizeof(buff); i++)
				buff[i] = 0;
			snprintf(buff, sizeof(buff), "%.02f", consult_price * consult_quantity);
			std::string strConsult_Amount = buff;
			gotoxy(0, 21);
			std::cout << "Consulting";
			gotoxy(62, 21);
			cout << "$" << strConsult_price;
			gotoxy(83, 21);
			cout << consult_quantity;
			gotoxy(100, 21);
			cout << "$" << strConsult_Amount << "\n";
			gotoxy(0, 22);
			std::cout << "Consultant for business";
			gotoxy(62, 22);
			cout<< "+Tax\n";
			std::cout << "-----------------------------------------------------------------------------------------------------------------------\n";

			float material_price = Orders.back().getMaterial_price();
			unsigned int material_quantity = Orders.back().getMaterial_quantity();

			for (int i = 0; i < sizeof(buff); i++)
				buff[i] = 0;
			snprintf(buff, sizeof(buff), "%.02f", material_price);
			std::string strMaterial_price = buff;

			for (int i = 0; i < sizeof(buff); i++)
				buff[i] = 0;
			snprintf(buff, sizeof(buff), "%.02f", material_price * material_quantity);
			std::string strMaterial_Amount = buff;


			gotoxy(0, 24);
			std::cout << "Materials";
			gotoxy(62, 24);
			cout << "$" << strMaterial_price;
			gotoxy(83, 24);
			cout << material_quantity;
			gotoxy(100, 24);
			cout << "$" << strMaterial_Amount << "\n";
			gotoxy(0, 25);
			std::cout << "Costs of materials and supplies to complete job";
			gotoxy(62, 25);
			cout << "+Tax\n";

			std::cout << "-----------------------------------------------------------------------------------------------------------------------\n";

			//**************************** subtotal *********************************
			for (int i = 0; i < sizeof(buff); i++)
				buff[i] = 0;
			snprintf(buff, sizeof(buff), "%.02f", subTotal);
			std::string strSubTotal = buff;
			std::cout << std::setw(70) << "SubTotal" << std::setw(28) << "$" << strSubTotal << "\n";

			//**************************** Discount *********************************

			for (int i = 0; i < sizeof(buff); i++)
				buff[i] = 0;
			snprintf(buff, sizeof(buff), "%.02f", discount);
			std::string strDiscount = buff;
			std::cout << std::setw(70) << "Discount" << std::setw(28) << "$" << strDiscount << "\n";


			//**************************** Tax *********************************

			for (int i = 0; i < sizeof(buff); i++)
				buff[i] = 0;
			snprintf(buff, sizeof(buff), "%.02f", tax);
			std::string strTax = buff;
			std::cout << std::setw(70) << "Tax" << std::setw(28) << "$" << strTax << "\n";

			std::cout << "                                                              ---------------------------------------------------------\n";
			//**************************** Total *********************************
			for (int i = 0; i < sizeof(buff); i++)
				buff[i] = 0;
			snprintf(buff, sizeof(buff), "%.02f", subTotal - discount + tax);
			std::string strTotal = buff;
			std::cout << std::setw(70) << "Total" << std::setw(28) << "$" << strTotal << "\n";

			std::cout << "-----------------------------------------------------------------------------------------------------------------------\n";
			std::cout << "\nNotes\n" << notes;

			std::cout << "\n\nTerms\n" << terms;

		}

	}
	if (con)
	{
		cout << "Invoice not available!";
	}return;
}

// order menu
void printNewOrderMenu()
{
	bool repeat = true;
	while (repeat)
	{
		system("cls");
		cout << "------Order Menu------\n";
		std::cout << "Choose order type:\n";
		std::cout << "1 - Services\n"
			"2 - Consultation\n"
			"3 - Materials\n"
			"0 - Back\n";
		std::cout << "Enter an option: ";

		short choice = -1;

		std::cin >> choice;
		std::cin.ignore();

		switch (choice)
		{
		case 1:
			// Services
			printOrderMenuServices();
			break;
		case 2:
			// Consultation
			printOrderMenuConsultation();
			break;
		case 3:
			// Materials
			printOrderMenuMaterials();
			break;
		case 0:
			repeat = false;
			break;
		default:
			std::cout << "Please insert a valid option\n";
			break;
		}
	}
}
// services provided menu 
void printOrderMenuServices()
{
	
	bool repeat = true, buy = false;
	while (repeat)
	{
		system("cls");
		cout << "------Order Service Menu------\n";
		std::cout << "1 - After sale guidance\n"
			"2 - Repair service time scheduler\n"
			"3 - Payment arrangement\n"
			"0 - Back\n";

		short choice = -1;
		std::cout << "Enter an option: ";
		std::cin >> choice;
		std::cin.ignore();

		unsigned int quantity = 0;
		if (choice == 1 || choice == 2 || choice == 3)
		{
			std::cout << "\Enter number of services: ";
			std::cin >> quantity;
			std::cin.ignore();
		}

		float price = 0.f;

		switch (choice)
		{
		case 1:
			// After sale guidance price
			price = SaleServicePrice;
			buy = true;
			break;
		case 2:
			// Repair service time scheduler price
			buy = true;
			price = RepairServicePrice;
			break;
		case 3:
			// Payment arrangement price
			buy = true;
			price = PaymentArrangementPrice;
			break;
		case 0:
			repeat = false;
			break;
		default:
			std::cout << "Please insert a valid option\n";
			_getch();
			break;
		}

		if (price != 0.f)
		{
			// seting due date on which the product is brought
			std::string dueDate1;
			std::string issuedDate1;

			std::cout << "Enter a dueDate of service: example( 25/02/2023 )";
			std::cin >> dueDate1;
			std::cin.ignore();

			std::cout << "Enter an issuedDate Of service: example( 25/01/2023 )";
			std::cin >> issuedDate1;
			std::cin.ignore();

			Order order;
			// adding te item brought 
			order.addItem({ ItemType::SERVICE, quantity, price });
			order.setDueDate(dueDate1);
			order.setIssuedDate(issuedDate1);
			Orders.push_back(order);
		}
		//printinng a thank you message on a sucessfull purchase 

	}
	if (buy)
		std::cout << "Thank you for using our repair service ,please make sure to remember your next visit date\n";

	//inserting data to the invoice
	if (buy)
	{
		//insert invoice number for future use
		std::cout << "Insert  invoice number : ";
		unsigned int number = 0;
		std::cin >> number;
		std::cin.ignore();

		Invoices.push_back(Invoice(number, Customers.back().name(), Companies.back().name()));
		Customers.back().increaseOrders();
		Orders.back().setInvoiceNumber(number);

		updateSavedFile();
	}
}
// fucnction that provide te consulatation
void printOrderMenuConsultation()
{
	bool repeat = true, buy = false;
	while (repeat)
	{
		system("cls");
		cout << "------Order Consultaion Menu------\n";
		std::cout << "1 - Short term service\n"
			"2 - Main repair\n"
			"0 - Back\n";

		std::cout << "Enter an option: ";
		short choice = -1;

		std::cin >> choice;
		std::cin.ignore();

		float price = 0.f;
		// aking quantity of te user
		unsigned int quantity = 0;
		if (choice == 1 || choice == 2 || choice == 3)
		{
			std::cout << "\Enter number of Consultation: ";
			std::cin >> quantity;
			std::cin.ignore();
		}

		switch (choice)
		{
		case 1:
			// Short term service price 
			buy = true;
			price = ShortTermConsultingPrice;
			break;
		case 2:
			// Main repair price function
			buy = true;
			price = MainRepairConsultingPrice;
			break;
		case 0:
			repeat = false;
			break;
		default:
			std::cout << "Please insert a valid option\n";
			_getch();
			break;
		}

		//adding consulatation type data into code
		if (price != 0.f)
			Orders.back().addItem({ ItemType::CONSULTATION, quantity, price });
		
	}
	//thnak you message on sucessfull sale
	if (buy)
		std::cout << "Thank you for using our service\n";
	//on sucessfull buy add invoice to include in the invoice container 
	if (buy)
	{
		//insert invoice number for future use
		std::cout << "Insert invoice number: ";
		unsigned int number = 0;
		std::cin >> number;
		std::cin.ignore();
		//adding data to inoives
		Invoices.push_back(Invoice(number, Customers.back().name(), Companies.back().name()));
		Customers.back().increaseOrders();
		Orders.back().setInvoiceNumber(number);
		//updaing the save file
		updateSavedFile();
	}
}

//prindint the materials
void printOrderMenuMaterials()
{
	bool repeat = true, buy = false;
	while (repeat)
	{

		system("cls");
		cout << "------Order Materials Menu------\n";
		std::cout << "1 - Cars\n"
			"2 - Car parts\n"
			"3 - Service items\n"
			"0 - Back\n";
		std::cout << "Enter an option: ";

		short choice = -1;

		std::cin >> choice;
		std::cin.ignore();

		unsigned int quantity = 0;
		if (choice == 1 || choice == 2 || choice == 3)
		{
			std::cout << "\Enter number of Materials: ";
			std::cin >> quantity;
			std::cin.ignore();
		}

		float price = 0.f;

		switch (choice)
		{
		case 1:
			// Cars price 
			price = CarPrice;
			buy = true;
			break;
		case 2:
			// Car parts price
			price = CarPartsPrice;
			buy = true;
			break;
		case 3:
			// Service items price
			price = ServicePrice;
			buy = true;
			break;
		case 0:
			repeat = false;
			break;
		default:
			std::cout << "Please insert a valid option\n";
			_getch();
			break;
		}

		if (price != 0.f)
			Orders.back().addItem({ ItemType::MATERIAL, quantity, price });

		
	}
	if (buy)
		std::cout << "Thanks for your purchase, looking forward to seeing you again\n";
	if (buy)
	{
		//insert invoice number for future use
		std::cout << "Insert invoice number: ";
		unsigned int number = 0;
		std::cin >> number;
		std::cin.ignore();
		//inserting data sai 
		Invoices.push_back(Invoice(number, Customers.back().name(), Companies.back().name()));
		Customers.back().increaseOrders();
		Orders.back().setInvoiceNumber(number);

		updateSavedFile();
	}
}
// taking information about the customer 
void printNewCustomerMenu()
{
	system("cls");
	cout << "------New Customer Menu------\n";
	std::string customerName, customerAddress, customerbuilding, customerstreet, customercity, customerpostcode, customerphone;

	std::cout << "Enter customer name: ";
	std::getline(std::cin, customerName);


	std::cout << "-----Address-----";
	customerAddress = "emp";
	std::cout << "\nEnter Building no : ";
	std::getline(std::cin, customerbuilding);

	std::cout << "Enter street address : ";
	std::getline(std::cin, customerstreet);

	std::cout << "Enter city : ";
	std::getline(std::cin, customercity);

	std::cout << "Enter postcode : ";
	std::getline(std::cin, customerpostcode);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, customerphone);
	Customer customer(customerName, customerAddress, customerbuilding, customerstreet, customercity, customerpostcode, customerphone);

	//pushing the customer information in the container
	Customers.push_back(customer);

	updateSavedFile();
}

void printNewCompanyMenu()
{

	system("cls");
	cout << "------New Company Menu------\n";
	std::string companyName, companyLogo, companyAddress, companyDescription, companyNotes, companyTerms, companybuilding, companystreet, companycity, companypostcode, companyphone;
	float companyTax = 0.f;
	//taking information to create a neew company
	std::cout << "Enter company name: ";
	std::getline(std::cin, companyName);

	std::cout << "Enter company logo: ";
	std::getline(std::cin, companyLogo);

	std::cout << "----Company Address----";
	companyAddress = "em";

	std::cout << "\nEnter Building no : ";
	std::getline(std::cin, companybuilding);

	std::cout << "Enter street address: ";
	std::getline(std::cin, companystreet);

	std::cout << "Enter city : ";
	std::getline(std::cin, companycity);

	std::cout << "Enter postcode : ";
	std::getline(std::cin, companypostcode);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, companyphone);

	std::cout << "Enter company description: ";
	std::getline(std::cin, companyDescription);

	std::cout << "Enter company notes: ";
	std::getline(std::cin, companyNotes);

	std::cout << "Enter company terms: ";
	std::getline(std::cin, companyTerms);

	std::cout << "Enter company tax: ";
	std::cin >> companyTax;
	std::cin.ignore();
	//creaating company object to initilaize company ingormation
	Company company(companyName, companyLogo, companyAddress, companyDescription, companyNotes, companyTerms, companyTax,companybuilding,companystreet,companycity,companypostcode,companyphone);
	//pusing the company object
	Companies.push_back(company);

	updateSavedFile();
}
//main funcion to call the oter functions
int main(int argc, char** argv)
{
	createFile();

	printMainMenu();

	return 0;
}