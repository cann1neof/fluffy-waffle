#include "Book.cpp"
using namespace std;

class StaticBookManager{
    protected:
        Book books[1024];
        void deleteElement(int target){
            for(int i = target; i < this->length+1; i++){
                this->books[i] = this->books[i+1];
            }
            this->length--;
        }
    protected:
        int length;

    public:
        StaticBookManager(){
            length = 0;
        }

        void addBook(int _id, string _author, string _name, Date _issueDate, Date _returnDate){
            if(length < 1024){
                length++;
                books[length-1] = Book(_id, _author, _name, _issueDate, _returnDate);
            }
        }

        void deleteBooks(Date targetDate, int lastIndex){
            int li = 0;
            if(countOverdueBooks(targetDate) > 0){
                for(int i = lastIndex; i < length; i++){
                    if(books[i].returnDate < targetDate || books[i].returnDate == targetDate){
                        deleteElement(i);
                        li = i;
                        break;
                    }
                }
                deleteBooks(targetDate, li);
            }
        }

        int countOverdueBooks(Date targetDate){
            int counter = 0;
            for(int i = 0; i < length; i++){
                if(books[i].returnDate < targetDate || books[i].returnDate == targetDate){
                    counter++;
                }
            }
            return counter;
        }

        void updateExisting(int targetId, Date _issueDate, Date _returnDate){
            for(int i = 0; i < length; i++){
                if(books[i].id == targetId){
                    books[i].issueDate = _issueDate;
                    books[i].returnDate = _returnDate;
                    break;
                }
            }
        }
        void showBooks(){
            cout << "id" << setw(10) << "Name:" << setw(10) << "Author" << setw(10) << "dates" << endl;
            for(int i = 0; i < length; i++){
                cout << "#" << this->books[i].id << ": " << this->books[i].name << " " << this->books[i].author;
                cout << " from: " << this->books[i].issueDate << " to: " << this->books[i].returnDate << endl;
            }
        }
};
