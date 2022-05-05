#include <string>
#include "./Date.cpp"

struct Book{
    int id;
    string author;
    string name;
    Date issueDate;
    Date returnDate;
    
    Book(){
        id = 0;
        author = "";
        name = "";
        issueDate = Date();
        returnDate = Date();
    }
    Book(int _id, string _author, string _name, Date _issueDate, Date _returnDate){
        id = _id;
        author = _author;
        name = _name;
        issueDate = _issueDate;
        returnDate = _returnDate;
    }
};