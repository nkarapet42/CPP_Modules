#include <iostream>

using namespace std;

int main() {
    const string check = "youit"; // Берём паттерн
    int argc; // количество аргументов которые будут вводиться
    cin >> argc; // получаем количество через input
    
    while (argc--) { //Цикл работает пока количество не будет ровно 0
        string s;
        cin >> s; // получаем строку из input
        int max_len = 0, cur_len = 0, index = 0;

        for (char c : s) { // проходим посимвольно по строке
            if (c == check[index]) { // если c ровна патерн[индексу]
                cur_len++;
                index = (index + 1) % 5; // плюсуем индкс патерна.%5 для того если дойдёт до конца патерна то это будет 5 индкус и %5 будет 0,вернёться в начало
            } else {
                if (c == 'y') { // для проверки случая если после y идёт опять y
                    cur_len = 1;
                    index = 1;
                } else {
                    cur_len = 0;
                    index = 0;
                }
            }
            max_len = max(max_len, cur_len);// выбираем то что больше
        }

        cout << max_len << '\n';
    }

    return 0;
}
