#include "DynamicBookManager.cpp"
#include <cstring>
#include <vector>

using namespace std;

class VectorBookManager : public DynamicBookManager{
    private:
        vector<Book*> books;

    public:
        VectorBookManager(){
            books = vector<Book*>(0, nullptr);
        }

        void addBook(int _id, string _author, string _name, Date _issueDate, Date _returnDate){
            books.push_back(new Book(_id, _author, _name, _issueDate, _returnDate));
        }

        void showBooks(){
            cout << "id" << setw(10) << "Name:" << setw(10) << "Author" << setw(10) << "dates" << endl;
            for(auto each : books){
                cout << "#" << each->id << ": " << each->name << " " << each->author;
                cout << " from: " << each->issueDate << " to: " << each->returnDate << endl;
            }
        }

        void deleteBooks(Date targetDate, int lastIndex){
            int li = 0;
            if(countOverdueBooks(targetDate) > 0){
                for(int i = lastIndex; i < books.size(); i++){
                    if(books[i]->returnDate < targetDate || books[i]->returnDate == targetDate){
                        books.erase(books.begin() + i);
                        li = i;
                        break;
                    }
                }
                deleteBooks(targetDate, li);
            }

        }

        int countOverdueBooks(Date targetDate){
            int counter = 0;
            for(auto each : books){
                if(each->returnDate < targetDate || each->returnDate == targetDate){
                    counter++;
                }
            }
            return counter;
        }

       void updateExisting(int targetId, Date _issueDate, Date _returnDate){
            for(auto each : books){
                if(each->id == targetId){
                    each->issueDate = _issueDate;
                    each->returnDate = _returnDate;
                    break;
                }
            }
        }

};
