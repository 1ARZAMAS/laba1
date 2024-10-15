#include "header.h"

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
    return 0;
}
