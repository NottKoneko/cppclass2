#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm> // std::count_if , std::find_if
#include <numeric>   // std::accumulate


// Assuming the Item structure and Bag class are defined like this:
struct Item {
    std::string name;
    double scalarValue; // Representing some high-level scientific property

    bool operator==(const Item& other) const {
        return name == other.name;
    }
};

class Bag {
private:
    std::vector<Item> items;
    int capacity;

public:
    Bag(int capacity) : capacity(capacity) {}

    bool add(const Item& item) {
        if (items.size() < capacity) {
            items.push_back(item);
            return true;
        }
        return false;
    }

    void showItems() const {
        for (const auto& item : items) {
            std::cout << item.name << " (Scalar Value: " << item.scalarValue << ")\n";
        }
    }

    // Function implementations

    void most_expensive() const {
        if (items.empty()) {
            std::cout << "The bag is empty.\n";
            return;
        }

        const Item* maxItem = &items[0];
        for (const auto& item : items) {
            if (item.scalarValue > maxItem->scalarValue) {
                maxItem = &item;
            }
        }

        std::cout << "Item with highest scalar value: " << maxItem->name << " (Scalar Value: " << maxItem->scalarValue << ")\n";
    }

    void show_reverse() const {
        if (items.empty()) {
            std::cout << "The bag is empty.\n";
            return;
        }

        for (auto it = items.rbegin(); it != items.rend(); ++it) {
            std::cout << it->name << " (Scalar Value: " << it->scalarValue << ")\n";
        }
    }

    int get_frequency(const std::string& itemName) const {
        return std::count_if(items.begin(), items.end(), [&itemName](const Item& item) {
            return item.name == itemName;
        });
    }

    bool delete_item(const std::string& itemName) {
        auto it = std::find_if(items.begin(), items.end(), [&itemName](const Item& item) {
            return item.name == itemName;
        });

        if (it != items.end()) {
            items.erase(it);
            return true;
        }
        return false;
    }

    int get_index_of(const std::string& itemName) const {
        for (size_t i = 0; i < items.size(); ++i) {
            if (items[i].name == itemName) {
                return static_cast<int>(i);
            }
        }
        return -1; // Item not found
    }

    double sum_of_all() const {
        return std::accumulate(items.begin(), items.end(), 0.0, [](double sum, const Item& item) {
            return sum + item.scalarValue;
        });
    }
};

// Test the functions
int main() {
    Bag scientificBag(10);

    scientificBag.add({"Particle Alpha", 1.5});
    scientificBag.add({"Particle Beta", 0.75});
    scientificBag.add({"Particle Gamma", 1.25});
    scientificBag.add({"Particle Alpha", 1.5}); // Adding a duplicate

    std::cout << "Scientific items in the bag:\n";
    scientificBag.showItems();

    std::cout << "\nItem with highest scalar value:\n";
    scientificBag.most_expensive();

    std::cout << "\nScientific items in reverse order:\n";
    scientificBag.show_reverse();

    std::string particle = "Particle Alpha";
    std::cout << "\nFrequency of '" << particle << "': " << scientificBag.get_frequency(particle) << "\n";

    std::cout << "\nDeleting 'Particle Beta':\n";
    if (scientificBag.delete_item("Particle Beta")) {
        std::cout << "Particle Beta deleted successfully.\n";
    } else {
        std::cout << "Particle Beta not found.\n";
    }
    scientificBag.showItems();

    std::cout << "\nIndex of 'Particle Gamma': " << scientificBag.get_index_of("Particle Gamma") << "\n";
    std::cout << "Sum of all scalar values: " << std::fixed << std::setprecision(2) << scientificBag.sum_of_all() << "\n";

    return 0;
}


/*

Scientific items in the bag:
Particle Alpha (Scalar Value: 1.5)
Particle Beta (Scalar Value: 0.75)
Particle Gamma (Scalar Value: 1.25)
Particle Alpha (Scalar Value: 1.5)

Item with highest scalar value:
Item with highest scalar value: Particle Alpha (Scalar Value: 1.5)

Scientific items in reverse order:
Particle Alpha (Scalar Value: 1.5)
Particle Gamma (Scalar Value: 1.25)
Particle Beta (Scalar Value: 0.75)
Particle Alpha (Scalar Value: 1.5)

Frequency of 'Particle Alpha': 2

Deleting 'Particle Beta':
Particle Beta deleted successfully.
Particle Alpha (Scalar Value: 1.5)
Particle Gamma (Scalar Value: 1.25)
Particle Alpha (Scalar Value: 1.5)

Index of 'Particle Gamma': 1
Sum of all scalar values: 4.25

*/