#include "header.h"

int main(int argc, char* argv[]) {
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
    cout << "Enter the command (ot 'exit' to exit):" << endl;
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
