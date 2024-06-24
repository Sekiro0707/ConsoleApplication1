#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

using namespace std;

struct Task {
    int id;
    string deskrim;
};


void men_pr() {
    cout << "\nМеню:" << endl;
    cout << "1. Додати завдання" << endl;
    cout << "2. Видалити завдання" << endl;
    cout << "3. Переглянути список завдань" << endl;
    cout << "4. Редагувати завдання" << endl;
    cout << "5. Вихід" << endl;
    cout << "Виберіть дію (1-5): ";
}


vector<Task>::iterator find(vector<Task>& tasks, int id) {
    return find_if(tasks.begin(), tasks.end(), [id](const Task& task) {
        return task.id == id;
        });
}

int main() {


    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<Task> tasks;
    int chir;
    int nex = 1;
    string deskrim;

    do {
        men_pr();
        cin >> chir;

        switch (chir) {
        case 1:
            cin.ignore();
            cout << "Введіть опис завдання: ";
            getline(cin, deskrim);
            tasks.push_back({ nex++, deskrim });
            cout << "Завдання додано!" << endl;
            break;
        case 2:
            if (!tasks.empty()) {
                int id;
                cout << "Введіть номер завдання видалення (1-" << tasks.size() << "): ";
                cin >> id;
                if (id >= 1 && id <= tasks.size()) {
                    tasks.erase(tasks.begin() + id - 1);
                    cout << "Завдання видалено!" << endl;
                }
                else {
                    cout << "Список завдань порожній!" << endl;
                }
            }
            else {
                cout << "Список завдань порожній!" << endl;
            }
            break;
        case 3:
            if (!tasks.empty()) {
                cout << "\nСписок завдань:" << endl;
                for (const auto& task : tasks) {
                    cout << task.id << ". " << task.deskrim << endl;
                }
            }
            else {
                cout << "Список завдань порожній!" << endl;
            }
            break;
        case 4:
            if (!tasks.empty()) {
                int id;
                cout << "Введіть номер завдання для редагування (1-" << tasks.size() << "): ";
                cin >> id;
                if (id >= 1 && id <= tasks.size()) {
                    cin.ignore();
                    cout << "Введіть новий опис завдання: ";
                    getline(cin, deskrim);
                    auto it = find(tasks, id);
                    if (it != tasks.end()) {
                        it->deskrim = deskrim;
                        cout << "Завдання відредаговано!" << endl;
                    }
                    else {
                        cout << "Завдання не знайдено!" << endl;
                    }
                }
                else {
                    cout << "Неправильний номер завдання!" << endl;
                }
            }
            else {
                cout << "Список завдань порожній!" << endl;
            }
            break;
        case 5:
            cout << "До побачення!!" << endl;
            break;
        default:
            cout << "Неправильний вибір. Будь ласка, оберіть від 1 до 5." << endl;
            break;
        }

    } while (chir != 5);

    return 0;
}