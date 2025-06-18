// insurance_quote_system.cpp (Updated Input Handling with Comments)
#include <iostream>
#include <cstring>
using namespace std;

// Struct to store applicant details: VIN, age, and vehicle type
struct Applicant {
    char vin[18];  // VIN length increased to 18 to allow for null-terminator
    int age;
    char vtype[10]; // Vehicle type (e.g., Sedan, SUV, Truck)
};

// Struct to define insurance premium brackets by age
struct Bracket {
    float minAge;
    float maxAge;
    float premium;
};

// Abstract base class for quote calculators
class QuoteCalculator {
public:
    Bracket* brackets; // Dynamic array of premium brackets
    int count;         // Number of brackets

    QuoteCalculator() {
        brackets = nullptr;
        count = 0;
    }

    // Abstract method to get premium for an applicant
    virtual float getPremium(const Applicant* applicant) = 0;

    // Add a new bracket to the list (resizes array)
    virtual void addBracket(Bracket b) {
        Bracket* newBrackets = new Bracket[count + 1];
        for (int i = 0; i < count; i++) {
            newBrackets[i] = brackets[i];
        }
        newBrackets[count] = b;
        delete[] brackets;
        brackets = newBrackets;
        count++;
    }

    // Remove bracket by index
    virtual void removeBracket(int index) {
        if (index < 0 || index >= count) return;
        Bracket* newBrackets = new Bracket[count - 1];
        for (int i = 0, j = 0; i < count; i++) {
            if (i != index) {
                newBrackets[j++] = brackets[i];
            }
        }
        delete[] brackets;
        brackets = newBrackets;
        count--;
    }

    virtual ~QuoteCalculator() {
        delete[] brackets;
    }
};

// Basic insurance calculator that returns base premium based on age
class BasicCalculator : public QuoteCalculator {
public:
    float getPremium(const Applicant* applicant) override {
        for (int i = 0; i < count; i++) {
            if (applicant->age >= brackets[i].minAge && applicant->age <= brackets[i].maxAge) {
                return brackets[i].premium;
            }
        }
        return -1.0f; // no matching bracket found
    }
};

// Premium insurance calculator that adds extra based on vehicle type
class PremiumCalculator : public QuoteCalculator {
public:
    float getPremium(const Applicant* applicant) override {
        for (int i = 0; i < count; i++) {
            if (applicant->age >= brackets[i].minAge && applicant->age <= brackets[i].maxAge) {
                float base = brackets[i].premium;
                if (strcmp(applicant->vtype, "SUV") == 0)
                    return base + 50.0f; // SUV surcharge
                else if (strcmp(applicant->vtype, "Truck") == 0)
                    return base + 75.0f; // Truck surcharge
                else
                    return base; // no surcharge
            }
        }
        return -1.0f; // no valid bracket found
    }
};

// Main function with terminal-based user interaction
int main() {
    // Create array of calculator pointers for basic and premium policies
    QuoteCalculator** calculators = new QuoteCalculator*[2];
    calculators[0] = new BasicCalculator();
    calculators[1] = new PremiumCalculator();

    // Prompt user to define insurance age brackets
    int numBrackets;
    cout << "Enter number of age brackets: ";
    cin >> numBrackets;
    cin.ignore(1000, '\n'); // flush newline

    // Get bracket details from user
    for (int i = 0; i < numBrackets; i++) {
        Bracket b;
        cout << "Bracket " << i + 1 << ": Min Age, Max Age, Premium: ";
        cin >> b.minAge >> b.maxAge >> b.premium;
        cin.ignore(1000, '\n');
        calculators[0]->addBracket(b);
        calculators[1]->addBracket(b);
    }

    // Process applicants in a loop
    char cont = 'y';
    while (cont == 'y' || cont == 'Y') {
        Applicant app;
        cout << "\nEnter Applicant VIN (17 characters): ";
        cin.getline(app.vin, 18);

        cout << "Enter Applicant Age: ";
        cin >> app.age;
        cin.ignore(1000, '\n');

        cout << "Enter Vehicle Type (Sedan/SUV/Truck): ";
        cin.getline(app.vtype, 10);

        // Get quotes from both calculators
        float basicQuote = calculators[0]->getPremium(&app);
        float premiumQuote = calculators[1]->getPremium(&app);

        // Display result
        if (basicQuote < 0 || premiumQuote < 0)
            cout << "No valid premium found for the applicant.\n";
        else {
            cout << "\n--- QUOTE RESULTS ---\n";
            cout << "Basic Policy Quote: RWF " << basicQuote << endl;
            cout << "Premium Policy Quote: RWF " << premiumQuote << endl;
        }

        cout << "\nDo you want to enter another applicant? (y/n): ";
        cin >> cont;
        cin.ignore(1000, '\n'); // flush leftover newline
    }

    // Cleanup dynamic memory
    for (int i = 0; i < 2; i++) {
        delete calculators[i];
    }
    delete[] calculators;

    return 0;
}
