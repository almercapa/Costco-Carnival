#include <math.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <array>

using namespace std;

int main() {
  // Declaring variables + array required for program
  int item, count = 0, sodattl, cartittl,index, counter = 0;

  string cart[10];

  float add, soda = 1.00, carti = 30.99, sub = 6.99, sample = 0.00, hotdog = 1.99, liver = 8.99, subtotal, total, taxrate, coupon;

  string sodas = "20 oz. Soda", cartis = "Carti Fingernail", subs = "Footlong Sub", samples = "Free Samples", hotdogs = "1/2 Pound Hot Dog", livers = "Rat Liver", order,dummy, confirm, discount;

  cout << "\nWould you like to place an order (Y/N)? ";//ask if the user wants to place an order
    cin >> order;
    if (order == "Y" || order == "y") {
      getline(cin, dummy);
    }
    //stores order
  
    //while order is equal to "Y"
    while (order == "Y" || order == "y") {
      //the Costco menu
        cout << "--------Costco Menu--------" << endl;
        cout << "What would you like to order:" << endl;
        cout << "1. 20 oz. Soda (1.00)" << endl;
        cout << "2. Carti's Fingernail ($30.99)" << endl;
        cout << "3. Footlong Sub ($6.99)" << endl;
        cout << "4. Free Samples ($0.00)" << endl;
        cout << "5. 1/2 Pound Hot Dog ($11.99)" << endl;
        cout << "6. Rat Liver ($8.99)(BEST SELLER)" << endl;
        cout << "7. Show cart :)" << endl;
        cout << "8. Check out!" << endl;

        cin >> item;
        
        // Set of conditionals for every single input (other than strings)
        if (item == 1 && counter < 10) {
          // Adds item to cart
            cart[counter] = sodas;
            // Prints statement
            cout << "You have added a 20 oz. Soda to your cart (1.00)!\n" << endl;
            // Adds price to total
            subtotal = subtotal + soda;
            // Increments counter
            counter++;
        }     
        // The previous conditional repeats for the next 5 items
        else if (item == 2 && counter < 10){
            cart[counter] = cartis;
            cout << "You have added Carti's Fingernail to your cart!\n" << endl;
            subtotal = subtotal + carti;
            counter++;
          }        

        else if (item == 3 && counter < 10){
          cart[counter] = subs;
          cout << "You have added a Footlong Sub to your cart!\n" << endl;
          subtotal = subtotal + sub;
          counter++;
        }
        else if (item == 4 && counter < 10){
          cart[counter] = samples;
          cout << "You have added a Free Sample to your cart!\n" << endl;
          subtotal = subtotal + sample;
          counter++;
        }
        else if (item == 5 && counter < 10){
          cart[counter] = hotdogs;
          cout << "You have added a 1/2 Pound Hot Dog to your cart!\n" << endl;
          subtotal = subtotal + hotdog;
          counter++;
        }
        else if (item == 6 && counter < 10){
          cart[counter] = livers;
          cout << "You have added Rat Liver to your cart!\n" << endl;
          subtotal = subtotal + liver;
          counter++;
        }
        // Conditional for when cart is equal to 10 and user attempts to add more
        else if (counter >= 10 && item != 7 && item != 8 && item < 10) {
          cout << "Your cart is full!\n" << endl;
        }
        // Conditional for when user places an invalid input
        else if (item > 8 || item < 1) {
          cout << "This input is invalid.\n" << endl;
        }
        // Conditional for viewing cart
        else if (item == 7){
          cout << "\n-----Cart-----" << endl;
          // For loop listing every item in array
          for(int i = 0; i < 10; i++){
            // Note: Leaves blank space if user did not purchase to cart
            cout << cart[i] << endl;
          }
          cout << endl;
        }
        // Conditional for when user wants to check out
        else if (item == 8) {
          // Asks user for validation to check out
           cout << "\nAre you sure you want to check out (Y/N)? ";
           cin >> confirm;
           // If statement for when user selects yes
          if (confirm == "Y" || confirm == "y") {
            getline(cin, dummy);
            cout << "This is your cart: " << endl;
            // For loop listing every item in cart
            for(int i = 0; i < 10; i++){
              cout << cart[i] << endl;
            }
            // Setting flags for decimal points
            cout.setf(ios::fixed);
            cout.setf(ios::showpoint);

            // Printing subtotal
            cout << "\nYour subtotal is: $" << setprecision(2) << subtotal << endl;
            // Calculating tax by multiplying subtotal by taxrate (0.625%)
            taxrate = subtotal*0.0625;
            // Finding total by adding tax to subtotal
            total = subtotal + taxrate;
            // Generating total statement
            cout << "Your total with tax: $" << setprecision(2) << total << endl; 
            
            // EXTRA: Promotes Carti with discount
            cout << "Would you like to sign up for our Carti Enjoyer Program and receive 25% off (Y/N)? ";
            getline(cin, discount);

            // Conditional if user answers yes
            if (discount == "Y" || discount == "y") {
              // Calculates coupon by multiplying total by 25%
              coupon = total * 0.25;
              // Subtracts coupon from total
              total = total - coupon;
              // Prints final statement
              cout << "Your new total: $" << setprecision(2) << total << endl;
            }
            else {
              // Alternative final statement if customer does not answer yes properly
              cout << "Mid customer" << endl;
            }
            // Ends loop
            order = "n";
          }
        }
  }
}
