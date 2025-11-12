#include <iostream>
#include <string>
#include <map>

using namespace std;

void remove_author(multimap<string, string> &book, string author)
{
    auto range = book.equal_range(author);
    if (range.first != range.second)
    {
        book.erase(range.first, range.second);
    }
    else
        cout << "No books for author: " << author << endl;
}

void print_books(multimap<string, string> &book)
{
    for (auto iter = book.begin(); iter != book.end(); ++iter)
    {
        cout << iter->first << "has book : " << iter->second << endl;
    }
    cout << endl;
}

int main()
{
    multimap<string, string> books;
    books.insert({"Tom A", "Tom & Jerry"});
    books.insert({"Tom A", "Tom book2"});    
    books.insert({"Tom A", "Tom book3"});    
    books.insert({"Sam B", "Sam book1"});
    books.insert({"Sam B", "Sam book2"});

    print_books(books);

    remove_author(books, "May");
    remove_author(books, "Tom A");
    print_books(books);
    return 0;
}