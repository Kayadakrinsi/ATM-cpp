#include<bits/stdc++.h>
using namespace std;
int flag = 0;
class Bank
{

private:
	string name = "name";
	string accnumber = "000000000";
	string type = "null";
	long long total = 0;

public:
	void setvalue()
	{
		cout << "\nEnter name\n";
		cin.ignore();

		getline(cin, name);

		cout << "Enter Account number\n";
		cin >> accnumber;
			if (accnumber.length() < 9 || accnumber.length() > 18)
			{
				cout << "Invalid account number! Please retry\n";
				return;
			}
		cout << "Enter Account type\n";
		cin >> type;
		cout << "Enter Balance\n";
		cin >> total;
		if(isdigit(total)){
			cout<<"\nEnter valid number!\n";
			return;
		}
		if (total <= 0)
		{
			cout << "Invalid amount! Please retry\n";
			return;
		}
		flag = 1;
	}

	void showdata()
	{
		cout << "\nName : " << name << endl;
		cout << "Account No. : " << accnumber << endl;
		cout << "Account Type : " << type << endl;
		cout << "Balance : " << total << endl;
	}

	void deposit()
	{
		int n, amount;
		cout << "\nEnter amount to be Deposited\n";
		cin >> amount;
		total = total + amount;
		if (amount <= 0)
		{
			cout << "Invalid amount! Please retry\n";
			return;
		}
		cout << "\n\nAre you willing to see final amount?\n";
		cout << "\nEnter your choice for further process : \n";
		cout << "\n1.Yes\n2.No\n";
		cin >> n;
		if (n == 1)
		{
			showbal();
		}
		else if (n == 2)
		{
			return;
		}
	}

	void showbal()
	{
		cout << "\ntotalal balance is : " << total;
	}

	void withdraw()
	{
		int amount, n;
		cout << "\nEnter amout to withdraw\n";
		cin >> amount;
		if (amount <= 0 || amount > total)
		{
			cout << "Invalid amount! Please retry\n";
			return;
		}
		total = total - amount;
		cout << "\n\nAre you willing to see final amount?\n";
		cout << "\nEnter your choice for further process : \n";
		cout << "\n1.Yes\n2.No\n";
		cin >> n;
		if (n == 1)
		{
			showbal();
		}
		else if (n == 2)
		{
			return;
		}
	}
};

int main()
{

	Bank bank_user;
	int choice;
	cout << "\n----------------------------------"
		 << "---------------------WELCOME----------------------"
		 << "------------------------------------\n\n";
	while (flag == 0)
	{
		cout << "\nPlease Enter name, Account number, Account type\n";
		bank_user.setvalue();
	}
	while (1)
	{
		cout << "\n----------------------------------"
			 << "---------------------WELCOME----------------------"
			 << "------------------------------------\n\n";
		cout << "Enter Your Choice\n";
		cout << "\t1. Balance Enquiry\n";
		cout << "\t2. Deposit Money\n";
		cout << "\t3. Show totalal balance\n";
		cout << "\t4. Withdraw Money\n";
		cout << "\t5. Cancel\n";
		cin >> choice;

		switch (choice)
		{
		case 1:
			bank_user.showdata();
			break;
		case 2:
			bank_user.deposit();
			break;
		case 3:
			bank_user.showbal();
			break;
		case 4:
			bank_user.withdraw();
			break;
		case 5:
			cout << "\n----------------------------------"
				 << "---------------------THANKS!----------------------"
			 << "------------------------------------\n";
			exit(1);
			break;
		default:
			cout << "\nInvalid choice\n";
		}
	}
}
