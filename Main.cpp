#include <iostream>
#include <vector>
#include <string>
#include <array>

struct InputCash
{
public:

	float PaymentTotal;

	InputCash(float Payment)
	{
		PaymentTotal = Payment;
	}
};

struct VendingMachineItems
{
	public:
		int m_DrinkID;
		std::string m_DrinkName;
		double m_DrinkCost;

		VendingMachineItems(int DrinkID, std::string DrinkName, double DrinkCost)
		{
			m_DrinkCost = DrinkCost;
			m_DrinkID = DrinkID;
			m_DrinkName = DrinkName;
		}
};

int main()
{
	// All items inside vending machine
	std::vector<VendingMachineItems> VendingItems;
	VendingItems.push_back(VendingMachineItems(0, "Gatorade", 6.50));
	VendingItems.push_back(VendingMachineItems(1, "Coca Cola", 4.50));
	VendingItems.push_back(VendingMachineItems(2, "Lemonade", 2.50));
	VendingItems.push_back(VendingMachineItems(3, "Powerade", 6.25));
	VendingItems.push_back(VendingMachineItems(4, "Rockstar", 5.00));
	VendingItems.push_back(VendingMachineItems(5, "Red bull", 6.25));
	VendingItems.push_back(VendingMachineItems(6, "Pepsi", 3.50));
	VendingItems.push_back(VendingMachineItems(7, "Water", 4.00));

	while (true)
	{
		for (const VendingMachineItems& item : VendingItems)
		{
			std::cout << " ItemID: " << item.m_DrinkID << " Name: " << item.m_DrinkName << " Cost: " << item.m_DrinkCost << std::endl;
		}

		size_t ChosenItem;
		std::cout << "Enter your choice: " << std::endl;
		std::cin >> ChosenItem;
		size_t Payment;

		if (ChosenItem >= 0 && ChosenItem < VendingItems.capacity())
		{
			// Purchasing System
			std::cout << "Your choice: " << VendingItems[ChosenItem].m_DrinkID << " and the price is: " << VendingItems[ChosenItem].m_DrinkCost;
			std::cout << " Please Insert Money: " << std::endl;
			std::cin >> Payment;
			std::cout << " You payed: " << Payment;
			float total = Payment - VendingItems[ChosenItem].m_DrinkCost;
			std::cout << " Here is your change " << total;
		}

		std::cout << " Thank you for your purchase!" << std::endl;
		// System to purchase another item
		std::string WantAnotherItem;
		std::cout << " Do you want another item? (Y/N)" << std::endl;
		std::cin >> WantAnotherItem;
		if (WantAnotherItem == "n" || WantAnotherItem == "N")
		{
			std::cout << "Thank you for your purchase!" << std::endl;
			break;
		}
		else if (WantAnotherItem == "y" || WantAnotherItem == "Y")
		{
			std::cout << std::endl;
		}
		else
		{
			return 0;
		}
	}
}
