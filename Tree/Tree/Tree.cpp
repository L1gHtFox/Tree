// Tree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

#include <cstdlib>
using std::rand;
using std::srand;

#include <ctime>
using std::time;

struct tnode {
    int index;
    string name;
    int year;
    struct tnode* mother;
    struct tnode* father;
};

void treeprint(tnode* tree) {
    if (tree != NULL) { //Пока не встретится пустой узел
        if (tree->mother == nullptr) 
        {
            cout << "Конец" << tree->index << "\n";
        }
        else 
        {
            if (tree->father == nullptr)
            {
                cout << "Конец" << tree->index << "\n";
            }
            else 
            {
                cout << "Mother: " << "\n";
                treeprint(tree->mother); //Рекурсивная функция для левого поддерева
                cout << "Father: " << "\n";
                treeprint(tree->father); //Рекурсивная функция для правого поддерева
                cout << tree->name << " " << tree->index << " | mother:  " << tree->mother->index << " | father: " << tree->father->index << "\n"; //Отображаем корень дерева
            }
        }
    }
}

struct tnode* addnode(string name, int x, int year, tnode* tree) {
    if (tree == NULL) { // Если дерева нет, то формируем корень
        tree = new tnode; // память под узел
        tree->index = x;   // поле данных
        tree->name = name;
        tree->year = year;
        tree->mother = NULL;
        tree->father = NULL; // ветви инициализируем пустотой
    }
    else  if (tree->mother != NULL)   // условие добавление левого потомка
        tree->father = addnode(name, x, year, tree->father);
    else    // условие добавление правого потомка
        tree->mother = addnode(name, x, year, tree->mother);
    
    return(tree);
}



const int NAME = 10;         // количество имен в массиве
const char* names[::NAME] = { "Саша", "Паша", "Даша", "Коля", "Оля",
                                "Юра", "Семен", "Артем", "Петя", "Лена" };


int getRandomNumber();
string getRandomName();

string getRandomName()
{
    setlocale(0, "");

    string name = names[getRandomNumber()];

    return name;
}

int getRandomNumber()
{
    return rand() % ::NAME;
}

int main()
{
    srand(time(NULL));

    struct tnode* root;
    root = NULL;
    root = addnode(getRandomName(), 0, 2010, root);
    root = addnode(getRandomName(), 1, 2008, root);
    root = addnode(getRandomName(), 2, 2008, root);
    root = addnode(getRandomName(), 3, 2016, root);
    root = addnode(getRandomName(), 4, 2016, root);
    root = addnode(getRandomName(), 5, 2016, root);
    root = addnode(getRandomName(), 6, 2016, root);
    treeprint(root);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
