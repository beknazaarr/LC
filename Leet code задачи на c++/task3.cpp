#include <iostream>
#include <string>
using namespace std;

class Device {
protected:
    string name;
    string manufacturer;

public:
    Device(const string& name, const string& manufacturer)
        : name(name), manufacturer(manufacturer) {}

    virtual void info() const = 0;

    virtual ~Device() {
        cout << "Device destroyed\n";
    }
};

class NetworkAdapter : virtual public Device {
protected:
    string macAddress;

public:
    NetworkAdapter(const string& name, const string& manufacturer,
                   const string& macAddress)
        : Device(name, manufacturer), macAddress(macAddress) {}

    void connectToWiFi(const string& ssid) {
        cout << name << " connected to WiFi: " << ssid << endl;
    }

    void info() const override {
        cout << "Network Adapter Info:\n";
        cout << "Name: " << name << ", Manufacturer: " << manufacturer
             << ", MAC Address: " << macAddress << endl;
    }

    virtual ~NetworkAdapter() {
        cout << "NetworkAdapter destroyed\n";
    }
};

class StorageDevice : virtual public Device {
protected:
    int capacityGB;
    string type;
    int usedSpace = 0;

public:
    StorageDevice(const string& name, const string& manufacturer,
                  int capacityGB, const string& type)
        : Device(name, manufacturer), capacityGB(capacityGB), type(type) {}

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
        cout << "Storage Device Info:\n";
        cout << "Name: " << name << ", Manufacturer: " << manufacturer
             << ", Capacity: " << capacityGB << " GB, Type: " << type
             << ", Used: " << usedSpace << " GB\n";
    }

    virtual ~StorageDevice() {
        cout << "StorageDevice destroyed\n";
    }
};

class SmartPhone : public NetworkAdapter, public StorageDevice {
private:
    string os;

public:
    SmartPhone(const string& name, const string& manufacturer,
               const string& macAddress, int capacityGB,
               const string& type, const string& os)
        : Device(name, manufacturer),
          NetworkAdapter(name, manufacturer, macAddress),
          StorageDevice(name, manufacturer, capacityGB, type),
          os(os) {}

    void installApp(const string& appName, int sizeGB) {
        cout << "Installing app: " << appName << endl;
        storeData(sizeGB);
    }

    void info() const override {
        cout << "SmartPhone Info:\n";
        cout << "Name: " << name << "\nManufacturer: " << manufacturer << "\n";
        cout << "OS: " << os << "\n";
        cout << "MAC Address: " << macAddress << "\n";
        cout << "Storage: " << capacityGB << " GB " << type
             << ", Used: " << usedSpace << " GB\n";
    }

    ~SmartPhone() {
        cout << "SmartPhone destroyed\n";
    }
};

// 🎯 Пример использования
int main() {
    SmartPhone phone("Galaxy S25", "Samsung", "00:1A:2B:3C:4D:5E", 256, "SSD", "Android 14");

    phone.connectToWiFi("Home_Network");
    phone.installApp("Maps", 2);
    phone.info();

    return 0;
}
