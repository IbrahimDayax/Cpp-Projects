#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::sort;

vector <int> list;
char get_user_input();
void process_user_input(char user_input);
bool PROGRAM_STATE = true;

int main () {
    
    while (PROGRAM_STATE)
    {
      char user_input =  get_user_input();
      process_user_input(user_input);
    }
    
    return 0;
}

char get_user_input() {

    cout << "\n" << "P - Print numbers" << "\n";
    cout << "A - Add numbers" << "\n";
    cout << "M - Display the mean of the numbers" << "\n";
    cout << "S - Display the smallest number" << "\n";
    cout << "L - Display the largest number" << "\n";
    cout << "Q - Quit" << "\n";
    cout << "Enter your choice: ";
    char user_input;
    cin >> user_input;
    return user_input;
}

void process_user_input(char user_input) {


    if (user_input == 'p' || user_input == 'P')
        { 
            if (list.size() > 0)
            {
                 cout << "\n" << "[";
                for (size_t i = 0; i < list.size(); i++)
                {
                cout << " " << list.at(i) << " ";
                }
                cout << "]" << "\n"; 
            }
            else
            {
                cout << "\n" << "[] - The list is empty" << "\n";
            }
            
        }

        else if (user_input == 'a' || user_input == 'A')
        {
            cout << "\n" << "Enter an integer to add to the list: ";
            long double new_user_input;
            cin >> new_user_input;

            list.push_back(new_user_input);

            cout  << "\n" << new_user_input << " added" << "\n";
        }

        else if (user_input == 'm' || user_input == 'M')
        {
            if (list.size() > 0)
            {
                double average, total {0};
                for (size_t i = 0; i < list.size(); i++)
                {
                total += list.at(i);
                };
                average = total/list.size();

                cout << "\n" << "The mean is: " << average << "\n";
            } else {
                cout << "\n" << "Unable to calculate the mean - no data" << "\n";
            }
            
        } 

        else if (user_input == 's' || user_input == 'S') 
        { 
            if (list.size() > 0)
            {
                sort(list.begin(), list.end());
                cout << "\n" << "The smallest number is: " << list.at(0) << "\n";
            } else {
                cout << "\n" << "Unable to calculate the smallest number - no data" << "\n";
            }
        }

        else if (user_input == 'l' || user_input == 'L') 
        { 
            if (list.size() > 0)
            {
                sort(list.begin(), list.end());
                cout << "\n" << "The largest number is: " << list.at(list.size()-1) << "\n";
            } else {
                cout << "\n" << "Unable to calculate the largest number - no data" << "\n";
            }
        }

        else if (user_input == 'q' || user_input == 'Q') 
        {
            PROGRAM_STATE = false;
        }
        
        else
        {
            cout << "Unknown selection, please try again." << "\n";
        }

}