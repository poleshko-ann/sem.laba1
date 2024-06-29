#include <iostream>
#include <sstream>
#include <list>
#include <algorithm>
#include <utility>
#include <random>
using namespace std;

void show(list<int>& a) {
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    cout << "Введите свой лист:" << endl;
    string input;
    getline(cin, input);
    stringstream ss(input);
    list<int> myList;
    while (ss.good()) {
        int i;
        ss >> i;
        myList.push_back(i);
    }
    int choice;
    do {
        cout << "Меню:" << endl;
        cout << "1. Добавить несколько элементов в заданную позицию c другого list" << endl;//gotovo
        cout << "2. Удалить элемент равный заданному" << endl;//gotovo
        cout << "3. Переместить часть элементов(диапазон) в заданную позицию" << endl;//gotovo
        cout << "4. Перемешивает элементы на заданном диапазоне случайным образом" << endl;
        cout << "5. Изменяет порядок расположения элементов на противоположный" << endl;
        cout << "6. Выход из программы" << endl;//gotovo
        cout << "Введите команду (1-6): ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Введите свой лист вставки:" << endl;
            string ianput;
            cin.ignore();
            getline(cin, ianput);
            stringstream sa(ianput);
            list<int> otherList;
            while (sa.good()) {
                int i;
                sa >> i;
                otherList.push_back(i);
            }
            int pos, numElements;
            cout << "Введите позицию для добавления элементов: ";
            cin >> pos;
            cout << "Введите количество элементов для добавления: ";
            cin >> numElements;
            auto it = myList.begin();
            auto it2 = otherList.begin();
            advance(it, pos);
            advance(it2, numElements);
            otherList.erase(it2, otherList.end());
            myList.insert(it, otherList.begin(), otherList.end());
            show(myList);
            break;
        }

        case 2: {
           int value;
            cout << "Введите значение для удаления: ";
            cin >> value;
            myList.remove(value);
            show(myList);
            break;}

        case 3: {
            int start, end, newPos;
             cout << "Введите начальный индекс диапазона: ";
             cin >> start;
             cout << "Введите конечный индекс диапазона: ";
             cin >> end;
             cout << "Введите новую позицию, чтобы переместить диапазон: ";
             cin >> newPos;

             auto startIt = myList.begin();
             auto endIt = myList.begin();
             auto newPosIt = myList.begin();
             advance(startIt, start);
             advance(endIt, ++end);
             advance(newPosIt, newPos);
             myList.splice(newPosIt, myList, startIt, endIt);
             show(myList);
             break;
        }

        case 4: {
            int start, end;
            cout << "Введите начальный индекс диапазона для перемешивания: ";
            cin >> start;
            cout << "Введите конечный индекс диапазона для перемешивания: ";
            cin >> end;

            vector<int> temp(myList.begin(), myList.end());

            auto startIt = temp.begin();
            auto endIt = temp.begin();
            advance(startIt, start);
            advance(endIt, end);

            shuffle(startIt, endIt, default_random_engine{});
            copy(temp.begin(), temp.end(), myList.begin());
            show(myList);
            break;
        }

        case 5: {
            myList.reverse();
             show(myList);
             break;
        }

        case 6: {
            cout << "Выход из программы" << endl;
             break;

         default:
             cout << "Неверный выбор, попробуйте еще раз." << endl;
        }
        }
    } while (choice != 6);
   return 0;
}
//void printList(const list<int>& lst) {
//    for (const auto& elem : lst) {
//        cout << elem << " ";
//    }
//    cout << endl;
//}