#include <iostream>
#include <vector>
using namespace std;

int main () {
    vector <int> user_integers (0);
    char menu_selection;
    bool exit = true;
    
    do
    {
       cout << "\n-----------------------------------------" << endl;
       cout << "Welcome to menu." << endl;
       cout << "P - Print numbers" << endl;
       cout << "A - Add a number" << endl;
       cout << "C - Clear the list" << endl;
       cout << "F - Find an integer in the list" << endl;
       cout << "M - Display the mean of numbers" << endl;
       cout << "S - Display the smallest number" << endl;
       cout << "L - Display the largest number" << endl;
       cout << "Q - Quit" << endl;

       cout << "Please enter your choice" << endl;
       cin >> menu_selection;

       switch (menu_selection) {
           case 'P':
           case 'p': {
               if (user_integers.size() < 1) {
                   cout << "[] - Your list is empty. You can use the 'A' option in the menu to add integers to your list" << endl;
               } else {
                   cout << "[";
                   for (auto integer: user_integers){
                       cout << " " << integer;
                   }
                   cout << " ]" << endl;
               }
               break;
           }

           case 'A':
           case 'a':{
               cout << "Please type an integer and then press 'Enter'" << endl;

               int additonal_number;
               cin >> additonal_number;
               user_integers.push_back(additonal_number);

               cout << additonal_number << " Has been added to the list" << endl;
               break;
           }

           case 'C':
           case 'c':{
               user_integers.clear();
               cout << "List successfully cleared" << endl;
               break;
           }

           case 'F':
           case 'f':{
               int search_integer {0};
               cout << "Please enter an integer: ";
               cin >> search_integer;

               int occurrences {0}; 
               for ( auto integer: user_integers){
                   if (integer == search_integer){
                       occurrences += 1;
                   }
               }

               if  (occurrences > 0) {
                   cout << search_integer <<" Appears " << occurrences << " time(s) in your list" << endl;
               }
               break;
           }

           case 'M':
           case 'm':{
               int sum = {0};
               for ( auto integer: user_integers){
                   sum += integer;
               }
               float mean = sum/user_integers.size();
               cout << "The mean of your numbers is: " << mean << endl; 
               break;
           }

           case 'S':
           case 's':{
               if (user_integers.size() < 1) {
                   cout << "[] - Your list is empty. You can use the 'A' option in the menu to add integers to your list" << endl;
               } else {
                   int smallest_number = user_integers[0];
                   for (auto integer: user_integers) {
                      if (integer < smallest_number){
                          smallest_number = integer;
                      }
                   }
                   cout << "The smallest number in your list is: " << smallest_number << endl;
               }
               break;
           }

           case 'L':
           case 'l':{
               if (user_integers.size() < 1) {
                   cout << "[] - Your list is empty. You can use the 'A' option in the menu to add integers to your list" << endl;
               } else {
                   int largest_number = user_integers[0];
                   for (auto integer: user_integers) {
                      if (integer > largest_number){
                          largest_number = integer;
                      }
                   }
                   cout << "The largest number in your list is: " << largest_number << endl;
               }
               break;
           }

           case 'Q':
           case 'q':{
               cout << "Goodbye!" << endl;
               exit = false;
               break;
           }

           default: cout << "Unknown selection please try again" << endl;
       }
    } while (exit);
    
    return 0;
}