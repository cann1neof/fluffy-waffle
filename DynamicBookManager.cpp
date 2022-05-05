#include "StaticBookManager.cpp"
#include <cstring>

using namespace std;

class DynamicBookManager : public StaticBookManager{
    private:
        typedef StaticBookManager super;
        Book* books;

        void deleteElement(int index){
            length--;
            Book* temp = new Book[length];
            
            for(int i = 0; i < length; i++){
                if(i >= index){
                    temp[i] = books[i+1];
                } else {
                    temp[i] = books[i];
                }
            }

            delete[] books;
            books = temp;            
        }

    public:
        DynamicBookManager(){
            length = 0;
            books = new Book[length];
        }

        void addBook(int _id, string _author, string _name, Date _issueDate, Date _returnDate){
            int newLength = length + 1;
            Book* temp = new Book[newLength];
            for(int i = 0; i < length; i++)
                temp[i] = books[i];
            
            delete[] books;
            books = temp;

            temp[length] = Book(_id, _author, _name, _issueDate, _returnDate);
            length++;
        }

        void showBooks(){
            cout << "id" << setw(10) << "Name:" << setw(10) << "Author" << setw(10) << "dates" << endl;
            for(int i = 0; i < length; i++){
                cout << "#" << this->books[i].id << ": " << this->books[i].name << " " << this->books[i].author;
                cout << " from: " << this->books[i].issueDate << " to: " << this->books[i].returnDate << endl;
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

};
