#include <iostream>
#include <vector>
using namespace std;

int main () {
    vector <int> user_integers (0);
    char menu_selection;
    
    do
    {
       cout << "-----------------------------------------" << endl;
       cout << "Welcome to menu." << endl;
       cout << "P - Print numbers" << endl;
       cout << "A - Add a number" << endl;
       cout << "M - Display the mean of numbers" << endl;
       cout << "S - Display the smallest number" << endl;
       cout << "L - Display the largest number" << endl;

       cout << "Please enter your choice" << endl;
       cin >> menu_selection;

       switch (menu_selection) {
           case 'P':
           case 'p': {
               if (user_integers.size() < 1) {
                   cout << "[] - Empty. Please add integers by selecting the 'A' menu option." << endl;
               } else {
                   cout << "[ ";
                   for (auto integer: user_integers){
                       cout << " " << integer;
                   }
                   cout << " ]";
               }
               break;
            default: cout << "Unknown selection please try again" << endl;
           }
       }
    } while (true);
    
    return 0;
}