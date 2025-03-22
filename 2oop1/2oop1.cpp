#include <iostream>
#include <string>

using namespace std;

class Motors {
protected:
    string name;
    int ls;
public:
    //Постоянные:
    void start_motor() {
        cout << "Мотор " << name << " Запущен" << endl;
    };
    void stop_motor() {
        cout << "Мотор " << name << " Остановлен" << endl;
    };
    // Изменяемые:
    virtual void remont() {
        cout << "Мотор " << name << " - Обслуживание" << endl;
    };
    virtual void add_energy() {
        cout << "Мотор " << name << " - Заправка/Зарядка" << endl;
    };
    //Данные:
    virtual void set_motor(string name, int ls) {
        this->name = name;
        this->ls = ls;
    };
    virtual void get_motor() {
        cout << "Имя: " << this->name << endl;
        cout << "Л.С: " << this->ls << endl;
    };
    string get_name() {
        return name;
    };
    int get_ls() {
        return ls;
    };
};

class Electro : public Motors {
protected:
    int kVt;
    bool type;
public:
    //Свои:
    void malie_oborot() {
        cout << "Мотор " << name << " - Режим малых оборотов" << endl;
    };
    void obratna_zaryad() {
        cout << "Мотор " << name << " - Режим обратной зарядки" << endl;
    };
    //Изменяемые:
    void remont() {
        cout << "Мотор " << name << " - Обслуживание / Замена катушек" << endl;
    };
    void add_energy() {
        cout << "Мотор " << name << " - Зарядка" << endl;
    };
    //Данные:
    void set_motor(string name, int ls, int kVt, bool type) {
        this->name = name;
        this->ls = ls;
        this->kVt = kVt;
        this->type = type;
    };
    void get_motor() {
        Motors::get_motor();
        cout << "кВт: " << kVt << endl;
        cout << "Тип: " << (type == 1 ? "трехфазный" : "двухфазный") << endl;
    };
};

class DVS : public Motors {
protected:
    int rashod;
    bool type;
public:
    //Свои:
    void videl_gazov() {
        cout << "Мотор " << name << " - Выделение газов" << endl;
    };
    void videl_shyma() {
        cout << "Мотор " << name << " - Выделение шума" << endl;
    };
    //Изменяемые:
    void remont() {
        cout << "Мотор " << name << " - Обслуживание / Замена поршневой" << endl;
    };
    void add_energy() {
        cout << "Мотор " << name << " - Заправка топливом" << endl;
    };
    //Данные:
    void set_motor(string name, int ls, int rashod, bool type) {
        this->name = name;
        this->ls = ls;
        this->rashod = rashod;
        this->type = type;
    };
    void get_motor() {
        Motors::get_motor();
        cout << "Расход: " << rashod << endl;
        cout << "Тип: " << (type == 1 ? "Дизельный" : "Бензиновый") << endl;
    };
};

class Menu {
public:
    Motors* dvigatel;
    int punkt; 
    char ch;
    int vid = 0;
    int proverka() {
        int input;
        while (true) {
            cin >> input;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка: введите действительное число." << endl;
            }
            else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return input;
            }
        }
    };
    int prov01() {
        int input;
        while (true) {
            cin >> input;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка: введите 0 или 1." << endl;
            }
            else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (input == 0 || input == 1) {
                    return input;
                    break;
                }
                else
                    cout << "Ошибка: введите 0 или 1." << endl;
            }
        }
    };
    void start() {
        system("cls");
        cout << " 1 | Начать " << endl;
        cout << " 0 | Выход " << endl;
        punkt = prov01();
        if (punkt == 1) {
            system("cls");
            new_motors();
        }
        else 
            exit(0);
    };
    void new_motors() {
        string name;
        int ls;
        cout << " Введите имя мотора: " ;
        cin >> name;
        cout << " Введите кол-во лошадинных сил: " ;
        ls = proverka();
        dvigatel = new Motors();
        dvigatel->set_motor(name,ls);
        cout << "Мотор " << name << " Создан" << endl;
        menu_motors();
    };
    void menu_motors() {
        while (true) {
            system("cls");
            cout << " 1 | Показать характеристики " << endl;
            cout << " 2 | Запустить " << endl;
            cout << " 3 | Заглушить " << endl;
            cout << " 4 | Обслужить " << endl;
            cout << " 5 | Заправка/Зарядка " << endl;
            cout << " 6 | Дополнительно " << endl;
            cout << " 9 | Изменить класс двигателя " << endl;
            cout << " 0 | Выход " << endl;
            punkt = proverka();
            system("cls");
            switch (punkt)
            {
            case 1:
                dvigatel->get_motor();
                system("pause");
                break;
            case 2:
                dvigatel->start_motor();
                system("pause");
                break;
            case 3:
                dvigatel->stop_motor();
                system("pause");
                break;
            case 4:
                dvigatel->remont();
                system("pause");
                break;
            case 5:
                dvigatel->add_energy();
                system("pause");
                break;
            case 6:
                dop();
                system("pause");
                break;
            case 9:
                set_class();
                break;
            case 0:
                exit(0);
                break;
            default:
                cout << " неверный ввод " << endl;
                system("pause");
                break;
            }
        }
    };
    void dop() {
        if (vid == 1) {
            cout << "Дополнительные функции для электрического мотора:" << endl;
            cout << " 1 | Режим малых оборотов" << endl;
            cout << " 2 | Режим обратной зарядки" << endl;
            cout << " 0 | Назад" << endl;
            punkt = proverka();
            system("cls");
            switch (punkt) {
            case 1:
                ((Electro*)dvigatel)->malie_oborot();
                break;
            case 2:
                ((Electro*)dvigatel)->obratna_zaryad();
                break;
            case 0:
                return;
            default:
                cout << " неверный ввод " << endl;
                system("pause");
                break;
            }
        }
        else if (vid == -1) {
            cout << "Дополнительные функции для ДВС:" << endl;
            cout << " 1 | Выделение газов" << endl;
            cout << " 2 | Выделение шума" << endl;
            cout << " 0 | Назад" << endl;
            punkt = proverka();
            system("cls");
            switch (punkt) {
            case 1:
                ((DVS*)dvigatel)->videl_gazov();
                break;
            case 2:
                ((DVS*)dvigatel)->videl_shyma();
                break;
            case 0:
                return;
            default:
                cout << " неверный ввод " << endl;
                system("pause");
                break;
            }
        }
        else
        cout << " Для базового двигателя нет доп. опций, определите класс двигателя " << endl;
    };

    void set_class() {
        cout << " 1 | Сделать его Электрическим " << endl;
        cout << " 2 | Сделать его Двигателем Внутреннего Сгорания " << endl;
        cout << " 9 | Отмена " << endl;
        cout << " 0 | Выход " << endl;
        punkt = proverka();
        system("cls");
        switch (punkt)
        {
        case 1:
            get_electro();
            break;
        case 2:
            get_dvs();
            break;
        case 9:
            menu_motors();
            break;
        case 0:
            exit(0);
            break;
        default:
            cout << " неверный ввод " << endl;
            system("pause");
            break;
        }
    };
    void get_electro() {

        int kVt;
        bool type;
        vid = 1;
        cout << "Введите кВт: ";
        kVt = proverka();
        cout << "Тип? 0 - Двухфазный; 1 - Трехфазный : ";
        type = prov01();
        string name = dvigatel->get_name();
        int ls = dvigatel->get_ls();
        dvigatel = new Electro();
        ((Electro*)dvigatel)->set_motor(name, ls, kVt, type);
    }

    void get_dvs() {

        int rashod;
        bool type;
        vid = -1;
        cout << "Введите расход: ";
        rashod = proverka();
        cout << "Тип? 0 - Бензиновый; 1 - Дизельный: ";
        type = prov01();
        string name = dvigatel->get_name();
        int ls = dvigatel->get_ls();
        dvigatel = new DVS();
        ((DVS*)dvigatel)->set_motor(name, ls, rashod, type);
    }
};

int main() {
    setlocale(LC_ALL,"Russian");

    Menu menu;
    menu.start();

    return 0;
}