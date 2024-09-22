#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  const int FIRST_TIER_LIMIT = 10;
  const int SECOND_TIER_LIMIT = 20;
  const double FIRST_TIER_RATE = 150.0;
  const double SECOND_TIER_RATE = 175.0;
  const double ADDITIONAL_RATE = 200.0;
  const double SURCHARGE_PERCENTAGE = 0.15; // 15% surcharge
  const double VAT_PERCENTAGE = 0.18;       // 18% VAT
  double balance, unitsConsumed, totalCost = 0.0;

  cout << "Enter the amount of money loaded onto your account (UGX): ";
  cin >> balance;
  cout << "Enter the number of water units consumed: ";
  cin >> unitsConsumed;

  // Calculate the cost based on the tiered pricing structure
  if (unitsConsumed <= FIRST_TIER_LIMIT)
  {
    // Case 1: All units are within the first 10 units
    totalCost = unitsConsumed * FIRST_TIER_RATE;
  }
  else if (unitsConsumed <= SECOND_TIER_LIMIT)
  {
    // Case 2: Units fall within the first 20 units
    totalCost = (FIRST_TIER_LIMIT * FIRST_TIER_RATE) +
                ((unitsConsumed - FIRST_TIER_LIMIT) * SECOND_TIER_RATE);
  }
  else
  {
    // Case 3: Units exceed 20
    totalCost = (FIRST_TIER_LIMIT * FIRST_TIER_RATE) +
                (10 * SECOND_TIER_RATE) +
                ((unitsConsumed - SECOND_TIER_LIMIT) * ADDITIONAL_RATE);
  }

  // Apply 15% surcharge
  double surcharge = totalCost * SURCHARGE_PERCENTAGE;
  totalCost += surcharge;

  // Calculate total cost with 18% VAT
  double vat = totalCost * VAT_PERCENTAGE;
  totalCost += vat;

  // Check if the user's balance is sufficient
  if (balance >= totalCost)
  {
    // Deduct total cost from the balance and display the remaining balance
    balance -= totalCost;
    cout << fixed << setprecision(2); // Set output precision to 2 decimal places
    cout << "Transaction successful. Remaining balance: " << balance << " UGX." << endl;
  }
  else
  {
    // Insufficient balance; display error message and the current balance
    cout << "Error: Insufficient balance." << endl;
    cout << "Your balance before usage was: " << balance << " UGX." << endl;
  }

  return 0;
}
