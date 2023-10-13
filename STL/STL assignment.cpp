#include<bits/stdc++.h>

using namespace std;

class Book {
public:
    string title;
    string author;
    int year_published;

    Book(string title,string author, int year_published) {
        this->title = title;
        this->author = author;
        this->year_published = year_published;
    }
};

int main()
{
    vector<Book> inventory;
Book new_book("The Great Gatsby", "F. Scott Fitzgerald", 1925);
inventory.push_back(new_book);

//  to update the title of the first book
inventory[0].title = "To Kill a Mockingbird";

//  to insert a new book at index 1
Book n_book("1984", "George Orwell", 1949);
auto position_to_insert = inventory.begin() + 1; // Iterator pointing to index 1
inventory.insert(position_to_insert, new_book);
//To view the books in the inventory:

cout<<"Before removing one element:"<<endl<<endl;
for (auto book = inventory.begin(); book != inventory.end(); ++book) {
    cout << "Title: " << book->title << endl;
    cout << "Author: " << book->author << endl;
    cout << "Year Published: " << book->year_published << endl;
}
cout<<endl<<endl;
//  to remove the first book
auto book_to_remove=inventory.begin()+0; // Iterator pointing to the first book
inventory.erase(book_to_remove);
//To view the books in the inventory:

cout<<"After removing one element:"<<endl<<endl;
for (auto book = inventory.begin(); book != inventory.end(); ++book) {
    cout << "Title: " << book->title << endl;
    cout << "Author: " << book->author << endl;
    cout << "Year Published: " << book->year_published << endl;
}
cout<<endl<<endl;
//To check the size of the inventory :
cout<<"Before clear:"<<endl;
int inventory_size = inventory.size();
cout << "Inventory size: " << inventory_size << endl;

//To check if the inventory is empty :


if (inventory.empty()) {
    cout << "Inventory is empty." << endl;
} else {
    cout << "Inventory is not empty." << endl;
}
//To clear the entire inventory of books:
inventory.clear();
cout<<endl;
cout<<"After clear:"<<endl;
//To check the size of the inventory :

 inventory_size = inventory.size();
cout << "Inventory size: " << inventory_size << endl;

//To check if the inventory is empty :


if (inventory.empty()) {
    cout << "Inventory is empty." << endl;
} else {
    cout << "Inventory is not empty." << endl;
}



}
