#include <iomanip>
#include <iostream>
#include <string>

#include "./DynamicBookManager.cpp"

using namespace std;

int main()
{
    DynamicBookManager bm;

    // Заполнение таблицы
    int id, day = 0, month = 0, year = 0;
    string author;
    string name;
    Date date1, date2, date3;

    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> id >> author >> name >> date1 >> date2; 
        bm.addBook(id, author, name, date1, date2);
    }
    
    bm.showBooks();
    
    // удаление записей по дате
    cin >> date3;
    cout << bm.countOverdueBooks(date3) << endl;
    bm.deleteBooks(date3, 0);
    
    bm.showBooks();
    
    // определить, сколько книг не сдано во время
    cin >> date3;
    cout << bm.countOverdueBooks(date3) << endl; 

    bm.showBooks();
    
    // добавить запись о вновь выданной книге
    id = 0;
    cin >> id >> date1 >> date2;
    bm.updateExisting(id, date1, date2);

    bm.showBooks();

    return 0;
}
