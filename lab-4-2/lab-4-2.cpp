#include "iostream"
#include "string"
#include "algorithm" //Для transform
#include "iomanip"   //Для setw

// Автомобиль
class Car {
private:
    std::string model;   
    unsigned serialNumber; 
    unsigned mileage;   
    unsigned productionYear;   

public:
    Car() 
    {
        model = "none";
        serialNumber = mileage = productionYear = 0;
    }

    Car(std::string modelToSet, unsigned serialNumberToSet, unsigned mileageToSet, unsigned productionYearToSet) 
    {
        model = modelToSet;
        serialNumber = serialNumberToSet;
        mileage = mileageToSet;
        productionYear = productionYearToSet;
    }

    Car(const Car& object) {
        model = object.model;
        serialNumber = object.serialNumber;
        mileage = object.mileage;
        productionYear = object.productionYear;
    }

    void setModel(std::string modelToSet) 
    {
        model = modelToSet;
    }

    void setSerialNumber(unsigned serialNumberToSet) 
    {
        if (serialNumberToSet > 0) serialNumber = serialNumberToSet;
        else throw std::out_of_range("Serial number should be > 0");
    }

    void setMileage(unsigned mileageToSet) 
    {
        if (mileageToSet > 0) mileage = mileageToSet;
        else throw std::out_of_range("Mileage should be > 0");
    }

    void setProductionYear(unsigned productionYearToSet) 
    {
        if (productionYearToSet > 0) productionYear = productionYearToSet;
        else throw std::out_of_range("Production year should be > 0");
    }

    std::string getModel() { return model; }

    unsigned getSerialNumber() { return serialNumber; }

    unsigned getMileage() { return mileage; }

    unsigned getProductionYear() { return productionYear; }


    void print() 
    {
        std::cout << "Model: " << model << std::endl;
        std::cout << "Serial number: " << serialNumber << std::endl;
        std::cout << "Mileage: " << mileage << std::endl;
        std::cout << "Production year: " << productionYear << std::endl;
        std::cout << std::endl;
    }
};

// узел стека
class StackNode {
public:
    Car* data;  // информация
    StackNode* prev; // предыдущий элемент

    StackNode()
    {
        data = nullptr;
        prev = nullptr;
    }

    StackNode(Car& car)
    {
        data = new Car(car);
        prev = nullptr;
    }

    ~StackNode() { if (data != nullptr) delete data; }

    void print() { data->print(); }
};

// стек
class Stack {
protected:
    StackNode* head; //Верхний элемент

public:
    Stack() 
    {
        head = nullptr;
    }

    ~Stack() 
    {
        if (head != nullptr) {
            StackNode* buf;
            while (head != nullptr) {
                buf = head;
                head = head->prev;
                delete buf;
            }
        }
    }

    // добавить в стек
    void push(Car& car) 
    {
        if (head == nullptr) 
            head = new StackNode(car);
        else {
            StackNode* tmp = new StackNode(car);
            tmp->prev = head;
            head = tmp;
        }
    }

    // достать из стека
    Car& pop() 
    {
        if (head == nullptr) 
            throw std::exception("Trying to pop an empty stack.");
        else {
            Car* car = new Car(*head->data);
            head = head->prev;
            return *car;
        }
    }

    void printAll() 
    {
        Stack tmp;

        while (head != nullptr) {
            head->print();
            tmp.push(pop());
        }
        while (tmp.head != nullptr) {
            push(tmp.pop());
        }
    }
};

// класс-наследник "сортировщик"
class StackSorter : public Stack {
private:
    //Реверс стека
    void reverse() {
        Stack* tmp = new Stack;
        StackNode* newNode = nullptr;

        while (head != nullptr) {
            newNode = StackNode(pop());
            tmp->add(*eNew);
        }

        this->head = tmp->head;
    }
    //Забор из стека элемента с максимальной ценой
    elemStack& _maxValuable() {
        stackSorter temp;
        elemStack* eTemp = NULL;
        elemStack* eOut = NULL;
        float maxVal = INT_MIN;
        int maxN = 0, n = 0;

        //Находим самый дорогой товар, запоминаем его
        //позицию относительно верхнего элемента
        while (head != NULL) {
            eTemp = &pop();
            if (eTemp->info->getPrice() > maxVal) {
                maxN = n;
                maxVal = eTemp->info->getPrice();
            }
            temp.add(*eTemp);
            n++;
        }

        //Делаем реверс, чтобы порядок элементов в темп
        //был такой же как в начальном стеке
        temp.reverse();

        //Делаем копию запомненного элемента
        //(не возвращаем ее в стек)
        n = 0;
        while (temp.head != NULL) {
            eTemp = &temp.pop();
            if (n == maxN) {
                eOut = new elemStack(*eTemp);
            }
            else
                add(*eTemp);
            n++;
        }

        //Возвращаем эту копию самого дорогого элемента
        return *eOut;
    }
    //Получение первого по алфавиту элемента стека
    elemStack& _minAlphabetical() {
        stackSorter temp;
        elemStack* eTemp = NULL;
        elemStack* eOut = NULL;
        string minVal = "z";
        int minN = 0, n = 0;

        //Находим перввый по алфавиту элемент
        while (head != NULL) {
            eTemp = &pop();
            //std::string позволяет сравнивать две строки по
            //аски кодам элемента, так что можно привести обе
            //строки в нижний регистр и проверять простым <
            if (toLower(eTemp->info->getName()) < minVal) {
                minN = n;
                minVal = eTemp->info->getName();
            }
            temp.add(*eTemp);
            n++;
        }

        //Делаем реверс, чтобы порядок элементов в темп
        //был такой же как в начальном стеке
        temp.reverse();

        //Делаем копию запомненного элемента
        //(не возвращаем ее в стек)
        n = 0;
        while (temp.head != NULL) {
            eTemp = &temp.pop();
            if (n == minN) {
                eOut = new elemStack(*eTemp);
            }
            else
                add(*eTemp);
            n++;
        }

        //Возвращаем  копию первого по алфавиту элемента
        return *eOut;
    }

    //ПУбличные методы сортировщика
public:
    stackSorter() {}
    stackSorter(Stack& obj) {
        Stack* temp = new Stack;
        elemStack* eTemp = NULL;
        elemStack* eTemp2 = NULL;

        while (obj.head != NULL) {
            eTemp = new elemStack(obj.pop());
            eTemp2 = new elemStack(*eTemp);
            temp->add(*eTemp);
            add(*eTemp2);
        }

        obj.head = temp->head;
    }

    //Получаем стек с элементами, норма отпуска
    //которых меньше либо равна двум в одни руки
    Stack& limitLower(float limit = 2) {
        Stack temp;
        Stack* out = new Stack;
        elemStack eTemp;
        elemStack* eNew = NULL;

        while (head != NULL) {
            eTemp = pop();
            if (eTemp.info->getLimit() <= limit) {
                eNew = new elemStack(eTemp);
                out->add(*eNew);
            }
            temp.add(eTemp);
        }
        while (temp.head != NULL) {
            add(temp.pop());
        }

        return *out;
    }
    //Получаем стек с пятью самыми дорогими товарами
    Stack mostValuable(int amount = 5) {
        elemStack temp;
        Stack* out = new Stack;

        while (head != NULL && amount > 0) {
            temp = _maxValuable();
            out->add(temp);
            amount--;
        }

        return *out;
    }
    //Получаем отсортированный по алфавиту стек
    Stack alphabetSort() {
        elemStack temp;
        stackSorter* out = new stackSorter;

        while (head != NULL) {
            temp = _minAlphabetical();
            out->add(temp);
        }

        out->reverse();
        return *out;
    }

};

int main() {
    //Создаем товары
    Item item1("Alpha", "m^2", 9000, 0);
    Item item2("Betta", "m^3", 8000, 100);
    Item item3("Gamma", "m^4", 7000, 200);
    Item item4("Pencil", "pics", 20, 5000);
    Item item5("Computer", "pics", 20000, 1);
    Item item6("Monitor", "pics", 5000, 3);
    Item item7("Notebook", "pics", 25000, 2);
    Item item8("MousePad", "pics", 200, 5);

    //Создаем элементы стека
    elemStack es1(item1);
    elemStack es2(item2);
    elemStack es3(item3);
    elemStack es4(item4);
    elemStack es5(item5);
    elemStack es6(item6);
    elemStack es7(item7);
    elemStack es8(item8);

    //Создаем стек
    Stack stack;
    stack.add(es1);
    stack.add(es2);
    stack.add(es3);
    stack.add(es4);
    stack.add(es5);
    stack.add(es6);
    stack.add(es7);
    stack.add(es8);

    //Создаем сортировщик
    stackSorter sorter(stack);

    //Выведем начальный стек
    cout << endl << "-------------------INITIAL STACK------------------" << endl;
    stack.printAll();

    //Норма отпуска в одни руки <= 2 + по алфавиту
    stackSorter byLimit = sorter.limitLower();
    Stack limitAlphabet = byLimit.alphabetSort();
    cout << endl << "\n--------------LIMIT <= 2 + ALPHABET---------------" << endl;
    limitAlphabet.printAll();

    //5 самых дорогих товаров + по алфавиту
    stackSorter byPrice = sorter.mostValuable();
    Stack priceAlphabet = byPrice.alphabetSort();
    cout << endl << "\n-------------PRICE (5pcs) + ALPHABET--------------" << endl;
    priceAlphabet.printAll();

    cout << endl << endl;
    system("pause");
    return 0;
}