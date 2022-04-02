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
       cout << "Welcome to the menu. Please select an operation" << endl;
       cout << "P - Print list" << endl;
       cout << "A - Add a number to your list" << endl;
       cout << "C - Clear the list" << endl;
       cout << "F - Find an integer in the list" << endl;
       cout << "M - Display the mean of list numbers" << endl;
       cout << "S - Display the smallest list number" << endl;
       cout << "L - Display the largest list number" << endl;
       cout << "Q - Quit" << endl;

       cout << "Please enter your choice" << endl;
       cin >> menu_selection;

       switch (menu_selection) {
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
           case 'L':
           case 'l':{
               if (user_integers.size() < 1) {
                   cout << "[] - Your list is empty. You can use the 'A' option in the menu to add integers to your list" << endl;
                   break;
               } else {
                   int largest_number = user_integers.at(0);
                   for (auto integer: user_integers) {
                      if (integer > largest_number){
                          largest_number = integer;
                      }
                   }
                   cout << "The largest number in your list is: " << largest_number << endl;
               }
               break;
           }
           case 'M':
           case 'm':{
               if (user_integers.size() < 1) {
                   cout << "Your list is empty, unable to calculate mean. You can use the 'A' option in the menu to add integers to your list" << endl;
                   break;    
               }
               int sum = {0};
               for ( auto integer: user_integers){
                   sum += integer;
               }
               
               cout << "The mean of your numbers is: " << static_cast<double>(sum)/user_integers.size() << endl; 
               break;
           }

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
           case 'Q':
           case 'q':{
               cout << "Goodbye!" << endl;
               exit = false;
               break;
           }
           case 'S':
           case 's':{
               if (user_integers.size() < 1) {
                   cout << "[] - Your list is empty. You can use the 'A' option in the menu to add integers to your list" << endl;
                   break;
               } else {
                   int smallest_number = user_integers.at(0);
                   for (auto integer: user_integers) {
                      if (integer < smallest_number){
                          smallest_number = integer;
                      }
                   }
                   cout << "The smallest number in your list is: " << smallest_number << endl;
               }
               break;
           }
           default: cout << "Unknown selection. Please select a valid option" << endl;
       }
    } while (exit);
    
    return 0;
}