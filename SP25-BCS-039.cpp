#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main ()
{
    cout << "\n"; 
    cout << "--------------------------------------------------" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "             Welcome to My Expense Buddy !!       " << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "\n";
   // Step 1                                      Ask the user to input weekly budget
   
   // Initialization of Variables
   
    double budget;
    double expense;
    double total_expense;
    double max_expense = -1e9;
    double min_expense = 1e9;
    double average_expense;
    string line;
    int count = 0;
    bool insight_message = false;

    do{
        cout << "Enter your Weekly Budget : ";
        cin >> budget;

        if(cin.fail() || budget < 0)
        {
            cout << "Enter the budget amount greter than zero or put Valid Input !! " << endl;
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Enter your Weekly Budget : ";
            cin >> budget;
        }
    } while(cin.fail() || budget < 0);

    ofstream outFile;
    outFile.open("budget.txt");                 // Save the weekly budget in file budjet.txt

    if(!outFile)
    {
        cout << "Error. Invalid File." << endl;
    }

    outFile << "The Given Weekly Budget : " << budget << endl;
    outFile.close();

    cout << "\n";
    cout << "***************************************************" << endl;
     cout << "\n";

    // Step  2                               Ask the user to input daily expense for seven days

    ofstream OUTFile;
    OUTFile.open("expenses.txt");

    if (!OUTFile)                                        // File Error Message
    {
        cout << "Error. Invalid File." << endl;
    }

    for (int day=1; day<=7; day++)                        // Using for loop to take daily expenses for seven days
    {
    do{
        cout << "Enter expense of Day " << day << " : ";
        cin >> expense;                                     // Using do-while loop for input-validation

        if (expense > 2000)
        {
            count++;
        }

        if (cin.fail() || expense < 0)
        {
            cout << "Expense cannot be negative. Try Again and put Valid Data !!" << endl;
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Enter expense of Day " << day << " : ";
            cin >> expense;  
        }
    }while (cin.fail() || expense < 0);

    OUTFile << "Expense of Day "<< day << ": "<< expense << endl;

}
    OUTFile.close();

    cout << "\n";
    cout << "***************************************************" << endl;
     cout << "\n";

     // Step 3                                     Read data from a file expenses.txt

   ifstream inFile("expenses.txt");

   if(!inFile)
   {
    cout << "Error. Invalid File." << endl;
   }

   while(getline(inFile,line))
   {
    cout << line << endl;
   }
   inFile.close();

    // Step 4                                                    Process data and perform Calculations 

    cout << "Reading Expenses from the file......" << endl;
    cout << "\n";

    ifstream infile ("expenses.txt");

    if(!infile)
    {
        cout << "Error. Invalid File." << endl;
    }

    while((infile.ignore(1000,':')) && (infile >> expense))
    {

        total_expense += expense;                   // Find Total Expense of week

        if(expense > max_expense)                   // Find maximum expense
        {
            max_expense = expense;
        }
        if(expense < min_expense)                   // Find minimum expense 
        {
            min_expense = expense;
        }
    }

    average_expense = total_expense / 7;            // Find Average
    if (average_expense < 2000)
    {
     insight_message = true;
    }

    cout << "\n";
    cout << "***************************************************" << endl;
    cout << "\n";
    cout << "            Weekly Expense Summary !!              " << endl;
    cout << "\n";
    cout << "***************************************************" << endl;
    cout << "\n";

   cout << "Total Expense of the Week : " << total_expense << endl;
   cout << "Average Daily  Expense : " << average_expense << endl;
   cout << "Maximum Expense :" << max_expense << endl;
   cout << "Minimum Expense :" << min_expense << endl;
    cout << "\n";

   infile.close();

   //  Step 5                                               Read and Compare Budget
   
    cout << "\n";
    cout << "***************************************************" << endl;
    cout << "\n";
    cout << "                Budget  Feedback   !!                " << endl;
    cout << "\n";

    ifstream INFILE("budget.txt");                         // Read Budget from Budget File
    INFILE.ignore(1000,':');
    INFILE >> budget;

    if(total_expense > budget)
    {
        cout << "You Exceed your budget by " << (total_expense - budget) << " Rs." << endl;
    }
    else
    if(total_expense==budget)
    {
        cout << "You used exactly your budget.Well Planned !!" << endl;
    }
    else
    if(total_expense < budget)
    {
        cout << "You saved " << (budget - total_expense) << " Rs this week.Great Job. " << endl;
    }
    INFILE.close();
    //  Step 6                                             Generate insightful messages

    cout << "\n";
    cout << "***************************************************" << endl;
    cout << "\n";
    cout << "                   Insights !!                     " << endl;
    cout << "\n";

     cout << "You had " << count << " large expenses in a week." << endl;

    if(insight_message)
    {
        cout << "Good Job.Keeping your expenses low average !!" << endl;
    }

    cout << "\n";
    cout << "***************************************************" << endl;
    cout << "\n";
    cout << "        Thank you for using my expense buddy !!    " << endl;
    cout << "\n";
    cout << "***************************************************" << endl;
    cout << "\n";
   
   return 0;
}