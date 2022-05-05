#include <iomanip>
#include <iostream>
#include <string>

#include "./StaticBookManager.cpp"

using namespace std;

int main()
{
    StaticBookManager bm;

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
    
    cin >> date3;
    // определить, сколько книг не сдано во время
    cout << bm.countOverdueBooks(date3) << endl;
    
    // удаление записей по дате
    bm.deleteBooks(date3, 0);
    
    bm.showBooks();
    
    
    // добавить запись о вновь выданной книге
    id = 0;
    cin >> id >> date1 >> date2;
    bm.updateExisting(id, date1, date2);

    bm.showBooks();

    return 0;
}
