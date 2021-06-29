#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "fstream"
#include "locale"
#include "conio.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"
#include "iomanip"
#include "io.h"
#include "fcntl.h"
#include "string"

// супперкласс-исключение
class Exception {
public:
    virtual const wchar_t* what() const noexcept = 0;
};

// исключение при открытии файла
class FileOpeningError : public Exception {
public:
    virtual const wchar_t* what() const throw() {
        return L"Файл не был открыт";
    }
};

// исключение при считывании данных
class DataReadingError : public Exception {
public:
    virtual const wchar_t* what() const throw() {
        return L"Ошибка чтения данных";
    }
};

// исключение при считывании данных
class TimeCheckerError : public Exception {
public:
    virtual const wchar_t* what() const throw() {
        return L"Ошибка чтения данных времени";
    }
};

std::wstring trim(std::wstring s)
{
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !isspace(ch);
        }));

    s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !isspace(ch);
        }).base(), s.end());

    return s;
}

std::wstring check_time(std::wstring time) {
    size_t dots = time.find(L":");
    if (dots == std::string::npos) dots = time.find(L".");
    if (dots == std::string::npos) throw TimeCheckerError();

    std::wstring t1 = trim(time.substr(0, dots));
    std::wstring t2 = trim(time.substr(dots + 1, time.length() - dots));

    int t1_int = t1.empty() ? 0 : stoi(t1);
    int t2_int = t2.empty() ? 0 : stoi(t2);

    if (t1_int < 0 || t1_int > 23) throw TimeCheckerError();
    if (t2_int < 0 || t2_int >= 60) throw TimeCheckerError();

    return time;
}

// строка таблицы
class Line {
public:
    int tabNumber;
    std::wstring name;
    int sp;
    std::wstring spTime;
    int v;
    std::wstring vTime;
    std::wstring prTime;
    std::wstring hundredForty;
    std::wstring work;

    Line(std::wstring str)
    {
        std::wstring tmp;
        try
        {
            tabNumber = stoi(trim(str.substr(6, 6)));
            if (tabNumber < 0) throw DataReadingError();

            name = trim(str.substr(13, 18));

            sp = stoi(trim(str.substr(32, 3)));
            spTime = check_time(trim(str.substr(36, 5)));

            v = stoi(trim(str.substr(42, 3)));
            vTime = check_time(trim(str.substr(46, 5)));

            prTime = check_time(trim(str.substr(56, 5)));

            hundredForty = check_time(trim(str.substr(62, 5)));

            work = check_time(trim(str.substr(68, 6)));
        }
        catch (...) { throw DataReadingError(); }
    }

    void print()
    {
        std::wcout << L" ";
        std::wcout << std::setw(6) << std::right << tabNumber << L" ";
        std::wcout << std::setw(18) << std::left << name << L" ";
        std::wcout << std::setw(3) << std::right << sp << L" ";
        std::wcout << std::setw(5) << std::right << spTime << L" ";
        std::wcout << std::setw(3) << std::right << v << L" ";
        std::wcout << std::setw(5) << std::right << vTime << L" ";
        std::wcout << std::setw(5) << std::right << L"    ";
        std::wcout << std::setw(5) << std::right << prTime << L" ";
        std::wcout << std::setw(5) << std::right << hundredForty << L" ";
        std::wcout << std::setw(6) << std::right << work << std::endl;
    }
};

class Department {
public:
    std::wstring name;

    Line** lines;
    int size;
    int count;

    Department() : name(L""), size(20), count(0)
    {
        lines = new Line * [size];
    }

    ~Department() {
        delete[] lines;
    }

    void add_mem()
    {
        Line** tmp = new Line * [count];
        memcpy(tmp, lines, count * sizeof(Line*));

        delete[] lines;
        size += 20;
        lines = new Line * [size];
        memcpy(lines, tmp, count * sizeof(Line*));

        delete[] tmp;
    }

    void print(int& start)
    {
        std::wcout << L"              Участок -> " << name << L"." << std::endl;

        for (int i = 0; i < count; i++, start++) {
            std::wcout << std::right << std::setw(4) << start;
            lines[i]->print();
        }

        std::wcout << L"--------------------------------------------------------------------------" << std::endl << std::endl;
    }

    bool load(std::wifstream& file)
    {
        std::wstring line;

       
            while (getline(file, line)) {
                try {
                    if (line.find(L"->") != std::string::npos) {
                        name = line.substr(23, line.length() - 24);
                        break;
                    }
                }
                catch (DataReadingError& e) {
                    std::wcout << L"Ошибка: " << line << std::endl;
                }
            }

            line = L"";
            while (getline(file, line)) {
                try {
                    if (trim(line).empty())
                        continue;

                    if (line.find(L"-----") != std::string::npos)
                        return true;

                    if (line.find(L"Итого потери рабочего") != std::string::npos)
                        return false;

                    if (count == size) add_mem();
                    lines[count] = new Line(line);
                    count++;
                }
                catch (DataReadingError& e) {
                    std::wcout << L"Ошибка: " << line << std::endl;
                }
            }
            return false;
    }
};

class Document {
public:
    std::wstring date;
    int day_int, month_int, year_int;
    std::string day, month, year;
    char* buf;

    Department** departments;
    int size;
    int count;

    std::wifstream file;

    Document(std::wstring path) : date(L""), size(20), count(0), day_int(0), month_int(0), year_int(0)
    {
        file.open(path);
        if (!file.is_open())
            throw FileOpeningError();

        // ставим кодировку cp866
        file.imbue(std::locale("rus_rus.866"));

        departments = new Department * [size];
        std::wstring line;

        try {
            while (getline(file, line)) {
                if (line.find(L"Потери рабочего времени") != std::string::npos) {
                    date = line.substr(48, 8);

                    day_int = stoi(date.substr(0, 2));
                    month_int = stoi(date.substr(3, 5));
                    year_int = stoi(date.substr(6, 8));

                    if (day_int < 1 || day_int > 31) throw DataReadingError();
                    if (month_int < 1 || month_int > 12) throw DataReadingError();
                    if (year_int > 21) throw DataReadingError();

                    if ((month_int == 4 || month_int == 6 || month_int == 9 || month_int == 11) && day_int > 30)
                        throw DataReadingError();
                    if (month_int == 2 && day_int > 28)
                        throw DataReadingError();

                    day = day_int < 10 ? "0" + std::to_string(day_int) : std::to_string(day_int);
                    month = month_int < 10 ? "0" + std::to_string(month_int) : std::to_string(month_int);
                    year = year_int < 10 ? "0" + std::to_string(year_int) : std::to_string(year_int);

                    break;
                }
            }

            bool flag = true;
            while (flag) {
                Department* tmp = new Department();
                flag = tmp->load(file);

                if (flag) {
                    if (count == size) add_mem();
                    departments[count] = tmp;
                    count++;
                }
            }
        }
        catch (Exception & e) {
            std::wcout << e.what() << std::endl;
        }
    }

    ~Document() {
        delete[] departments;
    }

    void add_mem()
    {
        Department** tmp = new Department * [count];
        memcpy(tmp, departments, count * sizeof(Department*));

        delete[] departments;
        size += 20;
        departments = new Department * [size];
        memcpy(departments, tmp, count * sizeof(Department*));

        delete[] tmp;
    }

    void print()
    {
        std::wcout << std::endl;
        std::wcout << L"              Потери рабочего времени за " << day.c_str() << "/" << month.c_str() << "/" << year.c_str() << L" г." << std::endl;
        std::wcout << L"--------------------------------------------------------------------------" << std::endl;
        std::wcout << L"| N |Таб.№ | Фамилия      |Гр.|Сп.|Время| В |Время|Пр.|Время| 140 |Работа|" << std::endl;
        std::wcout << L"|------------------------------------------------------------------------|" << std::endl;

        int start = 1;
        std::wcout << count;
        for (int i = 0; i < count; i++) {
            departments[i]->print(start);
        }
    }
};


int wmain() 
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);

    Document doc(L"var09_2.TXT");
    doc.print();

    system("pause");
    return 0;
}

// departments[count] = new Department(tmp);