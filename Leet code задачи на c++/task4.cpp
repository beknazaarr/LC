#include <iostream>
#include <string>
using namespace std;

class Device {
public:
    string name;        
    string manufacturer;
public:
    Device(const string& name, const string& manufacturer) : name(name), manufacturer(manufacturer) {
        cout << "Создано устройство: " << name << endl;
    }

    virtual void info() const = 0;

    virtual ~Device() {
        cout << "Устройство уничтожено: " << name << endl;
    }
};

class NetworkAdapter : virtual public Device {
public:
    string macAddress;

public:
    NetworkAdapter(const string& name, const string& manufacturer, const string& macAddress): Device(name, manufacturer), macAddress(macAddress) {
        cout << "Создан сетевой адаптер с MAC-адресом: " << macAddress << endl;
    }

    // Метод для подключения к Wi-Fi сети
    void connectToWiFi(const string& ssid) {
        cout << name << " подключён к Wi-Fi: " << ssid << endl;
    }

    // Переопределение метода info для вывода информации о сетевом адаптере
    void info() const override {
        cout << "Информация о сетевом адаптере:\n";
        cout << "Имя: " << name << "\nПроизводитель: " << manufacturer
             << "\nMAC-адрес: " << macAddress << endl;
    }

    // Виртуальный деструктор для корректного уничтожения объекта
    virtual ~NetworkAdapter() {
        cout << "Сетевой адаптер уничтожен: " << name << endl;
    }
};

// Класс StorageDevice, представляющий устройство хранения данных
// Использует виртуальное наследование от Device
class StorageDevice : virtual public Device {
protected:
    int capacityGB;    // Общий объём памяти в гигабайтах
    string type;       // Тип накопителя (например, "SSD" или "HDD")
    int usedSpace = 0; // Занятое пространство в гигабайтах, по умолчанию 0

public:
    // Конструктор класса StorageDevice
    // Инициализирует поля базового класса Device, capacityGB и type
    StorageDevice(const string& name, const string& manufacturer,
                  int capacityGB, const string& type)
        : Device(name, manufacturer), capacityGB(capacityGB), type(type) {
        cout << "Создано устройство хранения: " << name 
             << ", объём: " << capacityGB << " ГБ, тип: " << type << endl;
    }

    // Метод для сохранения данных на устройстве
    void storeData(int sizeGB) {
        if (usedSpace + sizeGB > capacityGB) {
            cout << "Недостаточно места на устройстве!\n";
        } else {
            usedSpace += sizeGB;
            cout << "Сохранено " << sizeGB << " ГБ. Использовано: " 
                 << usedSpace << "/" << capacityGB << " ГБ\n";
        }
    }

    // Переопределение метода info для вывода информации об устройстве хранения
    void info() const override {
        cout << "Информация об устройстве хранения:\n";
        cout << "Имя: " << name << "\nПроизводитель: " << manufacturer
             << "\nОбъём: " << capacityGB << " ГБ\nТип: " << type
             << "\nИспользовано: " << usedSpace << " ГБ\n";
    }

    // Виртуальный деструктор для корректного уничтожения объекта
    virtual ~StorageDevice() {
        cout << "Устройство хранения уничтожено: " << name << endl;
    }
};

// Класс SmartPhone, представляющий смартфон
// Использует множественное наследование от NetworkAdapter и StorageDevice
class SmartPhone : public NetworkAdapter, public StorageDevice {
private:
    string os; // Операционная система смартфона (например, "Android 14")

public:
    // Конструктор класса SmartPhone
    // Явно вызывает конструкторы всех базовых классов
    SmartPhone(const string& name, const string& manufacturer,
               const string& macAddress, int capacityGB,
               const string& type, const string& os)
        : Device(name, manufacturer),
          NetworkAdapter(name, manufacturer, macAddress),
          StorageDevice(name, manufacturer, capacityGB, type),
          os(os) {
        cout << "Создан смартфон: " << name << " с ОС: " << os << endl;
    }

    // Метод для установки приложения
    void installApp(const string& appName, int sizeGB) {
        cout << "Установка приложения: " << appName << endl;
        storeData(sizeGB); // Использует метод storeData из StorageDevice
    }

    // Переопределение метода info для вывода информации о смартфоне
    void info() const override {
        cout << "Информация о смартфоне:\n";
        cout << "Имя: " << name << "\n";
        cout << "Производитель: " << manufacturer << "\n";
        cout << "ОС: " << os << "\n";
        cout << "MAC-адрес: " << macAddress << "\n";
        cout << "Хранилище: " << capacityGB << " ГБ, тип: " << type
             << ", использовано: " << usedSpace << " ГБ\n";
    }

    // Деструктор для корректного уничтожения объекта
    ~SmartPhone() {
        cout << "Смартфон уничтожен: " << name << endl;
    }
};

// Главная функция программы
int main() {
    // Создание объекта смартфона с заданными параметрами
    SmartPhone phone("Galaxy S25", "Samsung", "00:1A:2B:3C:4D:5E", 
                    256, "SSD", "Android 14");

    // Подключение смартфона к Wi-Fi сети
    phone.connectToWiFi("Домашняя_сеть");

    // Установка приложения "Карты" размером 2 ГБ
    phone.installApp("Карты", 2);

    // Вывод информации о смартфоне
    phone.info();

    // Программа завершает выполнение, объект phone автоматически уничтожается
    return 0;
}