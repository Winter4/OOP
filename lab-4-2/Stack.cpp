#include "Stack.h"

// самая новая машина
Car& Stack::newestCar()
{
    Stack tmp;
    Car* curCar = nullptr;
    Car* resultCar = nullptr;
    unsigned short latestYear = 0;
    unsigned resultPos = 0, count = 0;

    // находит расстояние позиции самой новой машины от верхнего элемента
    while (head != nullptr) {
        curCar = &pop();
        unsigned short curProductionYear = curCar->getProductionYear();
        if (curProductionYear > latestYear) {
            resultPos = count;
            latestYear = curProductionYear;
        }

        tmp.push(*curCar);
        count++;
    }

    // восстанавливаем порядок элементов
    tmp.reverse();

    // забираем самый новый автомобиль из стека
    count = 0;
    while (tmp.head != nullptr) {
        curCar = &tmp.pop();
        if (count == resultPos)
            resultCar = new Car(*curCar);
        else
            push(*curCar);
        count++;
    }

    // возвращается самый новый автомобиль
    return *resultCar;
}

Stack::Stack()
{
    head = nullptr;
}

Stack::Stack(Stack& stackToCopy)
{
    std::cout << "ONE\n";
    Stack* saveSource = new Stack;
    //StackNode* tmp;
    std::cout << "TWO\n";
    while (stackToCopy.head != nullptr) {
        std::cout << "1\n";
        saveSource->push(stackToCopy.peek());
        std::cout << "2\n";
        push(stackToCopy.pop());
        std::cout << "3\n";
    }
    std::cout << "THREE\n";
    reverse();

    stackToCopy.head = saveSource->head;
    stackToCopy.reverse();
}


    Stack::~Stack()
    {
        if (head != nullptr) {
            StackNode* tmp;
            while (head != nullptr) {
                tmp = head;
                head = head->prev;
                delete tmp;
            }
        }
    }

    // добавить в стек
    void Stack::push(Car& car)
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
    Car& Stack::pop()
    {
        if (head == nullptr)
            throw std::exception("Trying to pop an empty stack.");
        else {
            Car* car = new Car(*head->data);
            head = head->prev;
            return *car;
        }
    }

    Car& Stack::peek()
    {
        if (head == nullptr)
            throw std::exception("Trying to pop an empty stack.");
        else {
            Car* car = new Car(*head->data);
            return *car;
        }
    }

    // вывести стек
    void Stack::print()
    {
        Stack tmp;

        while (head != nullptr) {
            head->data->print();
            tmp.push(pop());
        }
        head = tmp.getHeadPointer();
    }

    // получить указатель на верхний элемент
    StackNode* Stack::getHeadPointer() { return head; }

    // перевернуть стек
    void Stack::reverse()
    {
        Stack* tmp = new Stack;
        StackNode* newNode = nullptr;

        while (head != nullptr) {
            newNode = new StackNode(pop());
            tmp->push(*newNode->data);
        }

        this->head = tmp->getHeadPointer();
    }

    // сортировка по году выпуска
    void Stack::productionYearSort() {
        Car* tmpCar;
        Stack* result = new Stack;

        while (head != nullptr)
            result->push(newestCar());

        head = result->getHeadPointer();
        reverse();
    }