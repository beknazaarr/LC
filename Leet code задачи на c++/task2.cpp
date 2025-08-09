#include <iostream>
#include <string>

using namespace std;

class Device {
    public:
    string name;
    string manufacturer;

public:
    Device(const string& name, const string& manufacturer) : name(name), manufacturer(manufacturer) {}

    virtual void info() const = 0; 

    virtual ~Device() {
        cout << "Device удален\n";
    }
};

class NetworkAdapter : virtual public Device {
public:
    string macAddress;

public:
    NetworkAdapter(const string& name, const string& manufacturer, const string& macAddress) : Device(name, manufacturer), macAddress(macAddress) {}

    void connectToWiFi(const string& ssid) {
        cout << name << " Подключен к WIFI: " << ssid << endl;
    }

    void info() const override {
        cout << "Инфа о сетевом адаптере:\n";
        cout << "название: " << name << ", Manufacturer: " << manufacturer
             << ", MAC адрес: " << macAddress << endl;
    }

    virtual ~NetworkAdapter() {
        cout << "сетевой адаптер удален\n";
    }
};

class StorageDevice : virtual public Device {
public:
    int capacityGB;
    string type;
    int usedSpace = 0;

public:
    StorageDevice(const string& name, const string& manufacturer, int capacityGB, const string& type) : Device(name, manufacturer), capacityGB(capacityGB), type(type) {}

    void storeData(int sizeGB) {
        if (usedSpace + sizeGB > capacityGB) {
            cout << "Not enough storage space!\n";
        } else {
            usedSpace += sizeGB;
            cout << sizeGB << " GB stored. Used: " << usedSpace
                 << "/" << capacityGB << " GB\n";
        }
    }

    void info() const override {
        cout << "инфа о устр. хранения:\n";
        cout << "название: " << name << ", производитель: " << manufacturer
             << ", Емкость: " << capacityGB << " GB, Type: " << type
             << ", Использовал: " << usedSpace << " GB\n";
    }

    virtual ~StorageDevice() {
        cout << "Устройство хранения удалено\n";
    }
};

class SmartPhone : public NetworkAdapter, public StorageDevice {
private:
    string os;

public:
    SmartPhone(const string& name, const string& manufacturer, const string& macAddress, int capacityGB, const string& type, const string& os) : Device(name, manufacturer),
          NetworkAdapter(name, manufacturer, macAddress),
          StorageDevice(name, manufacturer, capacityGB, type), os(os) {}

    void installApp(const string& appName, int sizeGB) {
        cout << "Установка приложения: " << appName << endl;
        storeData(sizeGB);
    }

    void info() const override {
        cout << "информация о смартфоне:\n";
        cout << "Название: " << name << ", производитель: " << manufacturer << "\n";
        cout << "OS: " << os << "\n";
        cout << "MAC Address: " << macAddress << "\n";
        cout << "хранилище: " << capacityGB << " GB " << type
             << ", Использовал: " << usedSpace << " GB\n";
    }

    ~SmartPhone() {
        cout << "SmartPhone destroyed\n";
    }
};

int main() {
    SmartPhone phone("Galaxy S25", "Samsung", "00:1A:2B:3C:4D:5E", 256, "SSD", "Android 14");

    phone.info();
    phone.connectToWiFi("HomeNetwork");
    phone.installApp("ganel", 2);
    phone.installApp("Game", 10);
    phone.info();

    return 0;
}