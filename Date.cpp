using namespace std;

class Date{
    private:
        int day;
        int month;
        int year;
        
        bool validate(int _day, int _month, int _year){
            if(day < 1 || day > 31) {
                return false;
            } else if(month < 1 || month > 12) {
                return false;
            }

            if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31) {
                return false; 
            } else if ((month == 2) && (year % 4 == 0) && day > 29) {
                return false;

            } else if ((month == 2) && (year % 4 != 0) && day > 28) {
                return false; 
            }

            return true;
        }

    public:
        Date(){
            day = 1;
            month = 1;
            year = 1971;
        }


        Date(int _day, int _month, int _year){
            if(validate(_day, _month, _year)){
                day = _day;
                month = _month;
                year = _year;
            } else {
                Date();
            }
        }

        friend bool operator== (const Date &date1, const Date &date2){
            return (date1.day == date2.day && date1.month == date2.month && date1.year == date2.year);
        }
        friend bool operator< (const Date &date1, const Date &date2){
            return ((date1.day < date2.day && date1.month == date2.month && date1.year == date2.year) 
                    || (date1.month < date2.month && date1.year == date2.year) 
                    || date1.year < date2.year);
        }
        friend bool operator> (const Date &date1, const Date &date2){
            return ((date1.day > date2.day && date1.month == date2.month && date1.year == date2.year) 
                    || (date1.month > date2.month && date1.year == date2.year) 
                    || date1.year > date2.year);
        }

        friend ostream& operator<< (ostream &strm, const Date &date){
            string dot = ".";
            strm << to_string(date.day) << dot << to_string(date.month) << dot << to_string(date.year);
            return strm;
        }

        friend istream& operator>> (istream &strm, Date &date){
            string dot = ".";
            strm >> date.day >> date.month >> date.year;
            return strm;
        }
};