
#include "header.h"
#include "node.h"

using namespace std;

int main(int argc, char* argv[]) {
    system("chcp 65001");
    std::string filename;

    // Обработка аргументов командной строки
    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg == "--file") {
            if (i + 1 < argc) {
                filename = argv[++i];
            }
        }
    }

    // Загружаем данные из файла
    if (!filename.empty()) {
        loadFromFile(filename);
    }

    // Интерактивный ввод команд
    std::string query;
    cout << "Введите команды (или 'exit' для выхода):" << endl;
    while (true) {
        cout << "> ";
        getline(cin, query);
        if (query == "exit") {
            break; // Выход из цикла
        }
        processQuery(query);
    }

    // Сохраняем данные обратно в файл
    if (!filename.empty()) {
        saveToFile(filename);
    }

    return 0;
}
