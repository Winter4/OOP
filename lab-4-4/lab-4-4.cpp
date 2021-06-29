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

class Time {
public:
    int h, m;

    Time() {
        this->h = 0;
        this->m = 0;
    }

    Time(int h, int m) {
        this->h = h;
        this->m = m;
    }

    friend std::wostream& operator<< (std::wostream& out, const Time& t);

    Time& operator+ (Time& t) {
        Time* res = new Time();

        res->h = this->h + t.h;
        res->m = this->m + t.m;
        if (res->m > 59) {
            res->m -= 60;
            res->h += 1;
        }

        return *res;
    }

    Time operator= (Time t) {
        if (&t == this) return *this;

        h = t.h;
        m = t.m;

        return *this;
    }
};

std::wostream& operator<< (std::wostream& out, const Time& t)
{
    if (t.h < 10) out << "0" << t.h;
    else out << t.h;

    out << ":";

    if (t.m < 10) out << "0" << t.m;
    else out << t.m;

    return out;
}

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

Time check_time(std::wstring time) {
    size_t dots = time.find(L":");
    if (dots == std::string::npos) dots = time.find(L".");
    if (dots == std::string::npos) throw TimeCheckerError();

    std::wstring t1 = trim(time.substr(0, dots));
    std::wstring t2 = trim(time.substr(dots + 1, time.length() - dots));

    int t1_int = t1.empty() ? 0 : stoi(t1);
    int t2_int = t2.empty() ? 0 : stoi(t2);

    if (t1_int < 0 || t1_int > 23) throw TimeCheckerError();
    if (t2_int < 0 || t2_int >= 60) throw TimeCheckerError();

    Time t = { t1_int, t2_int };

    return t;
}

// строка таблицы
class Line {
public:
    int tabNumber;
    std::wstring name;
    int sp;
    Time spTime;
    int v;
    Time vTime;
    Time prTime;
    Time hundredForty;
    Time work;

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

    void print(bool shortOut = false)
    {
        std::wcout << L" ";

        if (shortOut) std::wcout << L"       ";
        else std::wcout << std::setw(6) << std::right << tabNumber << L" ";

        if (shortOut) std::wcout << L"                   ";
        else std::wcout << std::setw(18) << std::left << name << L" ";

        std::wcout << std::setw(3) << std::right << sp << L" ";
        std::wcout << spTime << L" ";
        std::wcout << std::setw(3) << std::right << v << L" ";
        std::wcout << vTime << L" ";
        std::wcout << std::setw(5) << std::right << L"    ";
        std::wcout << prTime << L" ";
        std::wcout << hundredForty << L" ";
        std::wcout << work << std::endl;
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

    ~Department()
    {
        if (size > 0) {
            for (int i = 0; i < count; i++)
                delete lines[i];
            delete[] lines;
        }
    }

    Department(Department& dpt) {
        name = dpt.name;
        count = 0;
        size = 20;

        lines = new Line * [size];

        for (int i = 0; i < dpt.count; i++) {
            if (count == size) add_mem();
            lines[count] = new Line(*dpt.lines[i]);
            count++;
        }
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

        Time total;
        std::wstring temp_name = L"";
        int temp_count = 0;

        for (int i = 0; i < count; i++) {
            if (lines[i]->name != temp_name) {
                temp_name = lines[i]->name;
            }
            if (i > 0 && lines[i - 1]->name != temp_name) {
                total.h = 0;
                total.m = 0;
            }
            total = total + lines[i]->hundredForty;
            temp_count++;

            if (i > 0 && lines[i - 1]->name == lines[i]->name) {
                std::wcout << L"    ";
                lines[i]->print(true);
            }
            else {
                std::wcout << std::right << std::setw(4) << start;
                lines[i]->print();
                start++;
            }

            if (temp_count > 1 && (lines[i - 1]->name == temp_name) && (lines[i + 1]->name != temp_name) && i < count - 1) {
                std::wcout << std::left << L"                                 Итого потери: " << total << std::endl;
                temp_name = L"";
                temp_count = 0;
            }
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


    Department& operator+ (Department& dep)
    {
        Department* res = new Department();
        bool flag = false;

        // массив индексов добавленных строк
        int* added = new int[dep.count];
        int cnt = 0;

        // ставим попарно одинаковые фамилии
        for (int i = 0; i < this->count; i++) {
            if (res->count == res->size) res->add_mem();
            res->lines[res->count] = new Line(*this->lines[i]);
            res->count++;

            flag = false;
            for (int j = 0; j < dep.count; j++) {
                if (this->lines[i]->name == dep.lines[j]->name) {
                    if (res->count == res->size) res->add_mem();
                    res->lines[res->count] = new Line(*dep.lines[j]);
                    res->count++;
                    flag = true;

                    added[cnt] = j;
                    cnt++;

                    break;
                }
            }
        }

        // добавляем в результат уникальные фамилии из правого операнда
        for (int i = 0; i < dep.count; i++) {
            // проверяем, добавлен ли уже текущий индекс
            flag = false;
            for (int k = 0; k < cnt; k++)
                if (i == added[k]) flag = true;

            // если не добавлен, до добавляем в результат
            if (!flag) {
                if (res->count == res->size) res->add_mem();
                res->lines[res->count] = new Line(*dep.lines[i]);
                res->count++;
            }
        }

        res->name = this->name;

        return *res;
    }

    Department& operator= (Department& dpt) {
        if (&dpt == this) return *this;

        if (size > 0) {
            for (int i = 0; i < count; i++)
                delete lines[i];
            delete[] lines;
        }

        name = dpt.name;
        count = 0;
        size = 20;

        lines = new Line * [size];

        for (int i = 0; i < dpt.count; i++) {
            if (count == size) add_mem();
            lines[count] = new Line(*dpt.lines[i]);
            count++;
        }

        return *this;
    }
};

class Document {
public:
    std::wstring date;

    Department** departments;
    int size;
    int count;

    std::wifstream file;

    Document()
    {
        size = 20;
        count = 0;

        departments = new Department * [size];
    }

    Document(std::wstring path) : date(L""), size(20), count(0)
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
                    break;
                }
            }

            bool flag = true;
            while (flag) {
                Department* tmp = new Department();
                flag = tmp->load(file);

                if (flag) {
                    if (count == size) add_mem();
                    departments[count] = new Department(*tmp);
                    count++;
                }
            }
        }
        catch (Exception& e) {
            std::wcout << e.what() << std::endl;
        }
    }

    Document(Document& doc)
    {
        date = doc.date;

        count = 0;
        size = 20;

        departments = new Department * [size];

        for (int i = 0; i < doc.count; i++) {
            if (count == size) add_mem();
            departments[count] = new Department(*doc.departments[i]);
            count++;
        }
    }

    ~Document()
    {
        if (size > 0) {
            for (int i = 0; i < count; i++)
                delete departments[i];
            delete[] departments;
        }
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
        std::wcout << L"              Потери рабочего времени за " << date << L" г." << std::endl;
        std::wcout << L"--------------------------------------------------------------------------" << std::endl;
        std::wcout << L"| N |Таб.№ | Фамилия      |Гр.|Сп.|Время| В |Время|Пр.|Время| 140 |Работа|" << std::endl;
        std::wcout << L"|------------------------------------------------------------------------|" << std::endl;

        int start = 1;
        std::wcout << count;
        for (int i = 0; i < count; i++) {
            departments[i]->print(start);
        }
    }

    Document& operator+ (Document& doc)
    {
        Document* res = new Document(*this);

        int* added = new int[doc.count];
        int cnt = 0;

        int start = 0;

        for (int i = 0; i < res->count; i++) {
            for (int j = 0; j < doc.count; j++) {
                if (res->departments[i]->name == doc.departments[j]->name) {
                    Department* tmp = new Department(*res->departments[i] + *doc.departments[j]);
                    delete res->departments[i];
                    res->departments[i] = tmp;
                    added[cnt] = j;
                    cnt++;
                    break;
                }
            }
        }

        for (int i = 0; i < doc.count; i++) {
            // проверяем, добавлен ли уже текущий индекс
            bool flag = false;
            for (int k = 0; k < cnt; k++)
                if (i == added[k]) flag = true;

            // если не добавлен, до добавляем в результат
            if (!flag) {
                if (res->count == res->size) res->add_mem();
                res->departments[res->count] = new Department(*doc.departments[i]);
                res->count++;
            }
        }

        res->date = this->date + L" - " + doc.date;

        return *res;
    }

    Document& operator= (Document& doc)
    {
        if (&doc == this) return *this;

        if (size > 0) {
            for (int i = 0; i < count; i++)
                delete departments[i];
            delete[] departments;
        }

        date = doc.date;

        size = 20;
        count = 0;

        departments = new Department * [size];

        for (int i = 0; i < doc.count; i++) {
            if (count == size) add_mem();
            departments[count] = new Department(*doc.departments[i]);
            count++;
        }

        return *this;
    }
};


int wmain()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);

    Document doc1(L"var09_1.TXT"), doc2(L"var09_2.TXT"), doc3;
    doc3 = doc1 + doc2;
    doc3.print();

    system("pause");
    return 0;
}