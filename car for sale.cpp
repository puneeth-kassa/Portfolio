#include <iostream> 
#include <vector> 
#include <string> 
#include<bits/stdc++.h> 
class Car { 
public: 
Car(int id, std::string model, std::string brand, double costPerDay) 
: id(id), model(model), brand(brand), costPerDay(costPerDay), booked(false) {} 
int getId() const { return id; } 
std::string getModel() const { return model; } 
std::string getBrand() const { return brand; } 
double getCostPerDay() const { return costPerDay; } 
bool isBooked() const { return booked; } 
void book() { booked = true; } 
void release() { booked = false; } 
private: 
int id; 
std::string model; 
std::string brand; 
double costPerDay; 
bool booked; 
}; 
class Customer { 
public: 
Customer(std::string name, std::string contactNumber, std::string email) 
: name(name), contactNumber(contactNumber), email(email) {} 
std::string getName() const { return name; } 
std::string getContactNumber() const { return contactNumber; } 
std::string getEmail() const { return email; } 
private: 
std::string name; 
std::string contactNumber; 
std::string email; 
}; 
class Booking { 
public: 
Booking(Customer customer, Car car, std::string startDate, std::string endDate) 
: customer(customer), car(car), startDate(startDate), endDate(endDate), extraAmount(0) { 
calculateAmount(); 
} 
Customer getCustomer() const { return customer; } 
Car getCar() const { return car; } 
std::string getStartDate() const { return startDate; } 
std::string getEndDate() const { return endDate; } 
double getAmount() const { return amount; } 
private: 
Customer customer; 
Car car; 
std::string startDate; 
std::string endDate; 
double amount; 
double extraAmount; 
void calculateAmount() { 
int totalDays = 1; 
if (endDate != startDate) { 
totalDays = 1 + std::stoi(endDate.substr(8, 2)) - std::stoi(startDate.substr(8, 2)); 
} 
amount = totalDays * car.getCostPerDay(); 
} 
std::string returnDate; 
friend class CarBookingSystem; 
}; 
class CarBookingSystem { 
public: 
void addCar(Car car) { cars.push_back(car); } 
void displayAvailableCars() { 
std::cout << "Available Cars:" << std::endl; 
for (const Car& car : cars) { 
std::cout << "ID: " << car.getId() << ", Brand: " << car.getBrand() << ", Model: " << 
car.getModel() 
<< ", Cost per day: ?." << car.getCostPerDay(); 
if (car.isBooked()) { 
std::cout << " (Booked)"; 
} else { 
std::cout << " (Available for booking)"; 
} 
std::cout << std::endl; 
} 
std::cout << std::endl; 
} 
void displayCarDetails() { 
int totalCars = cars.size(); 
int bookedCars = 0; 
for (const Car& car : cars) { 
if (car.isBooked()) { 
bookedCars++; 
} 
} 
int availableCars = totalCars - bookedCars; 
std::cout << "Total Cars: " << totalCars << std::endl; 
std::cout << "Booked Cars: " << bookedCars << std::endl; 
std::cout << "Available Cars: " << availableCars << std::endl; 
std::cout << "Car Details:" << std::endl; 
for (const Car& car : cars) { 
std::cout << "ID: " << car.getId() << ", Brand: " << car.getBrand() << ", Model: " << 
car.getModel() 
<< ", Cost per day: ?." << car.getCostPerDay(); 
if (car.isBooked()) { 
std::cout << " (Booked)"; 
} else { 
std::cout << " (Available for booking)"; 
} 
std::cout << std::endl; 
} 
} 
void bookCar(std::string name, std::string contactNumber, std::string email, int carId, 
std::string startDate, std::string endDate) { 
for (Car& car : cars) { 
if (car.getId() == carId && !car.isBooked()) { 
car.book(); 
Customer customer(name, contactNumber, email); 
Booking booking(customer, car, startDate, endDate); 
bookings.push_back(booking); 
std::cout << "Booking successful! Amount to be paid: ?." << booking.getAmount() << 
std::endl; 
return; 
} 
} 
std::cout << "Car not available for booking." << std::endl; 
} 
void returnCar(int carId) { 
for (Booking& booking : bookings) { 
if (booking.getCar().getId() == carId && !booking.returnDate.empty()) { 
std::cout << "Car has already been returned." << std::endl; 
return; 
} 
if (booking.getCar().getId() == carId) { 
std::string returnDate; 
std::cout << "Enter return date (YYYY-MM-DD): "; 
std::cin >> returnDate; 
booking.returnDate = returnDate; 
int extraDays = std::stoi(returnDate.substr(8, 2)) - 
std::stoi(booking.getEndDate().substr(8, 2)); 
booking.extraAmount = extraDays * booking.getCar().getCostPerDay(); 
if (extraDays > 0) { 
double fineAmount = 100.0 + booking.extraAmount; 
std::cout << "Car returned late on " << returnDate << ". Fine to be paid:?. " << 
fineAmount << std::endl; 
} else { 
std::cout << "Car returned on time. No fine to be paid." << std::endl; 
} 
for (Car& car : cars) { 
if (car.getId() == carId) { 
car.release(); 
break; 
} 
} 
return; 
} 
} 
std::cout << "Car not found or not booked." << std::endl; 
} 
private: 
std::vector<Car> cars; 
std::vector<Booking> bookings; 
}; 
int main() { 
CarBookingSystem carSystem; 
carSystem.addCar(Car(1, "Thar", "Mahindra", 2000)); 
carSystem.addCar(Car(2, "Innova", "Toyota", 2000)); 
carSystem.addCar(Car(3, "XUV100", "Suzuki", 1000)); 
carSystem.addCar(Car(4, "Innova", "Mahindra", 4200)); 
carSystem.addCar(Car(5, "Series-5", "BMW", 10000)); 
carSystem.addCar(Car(6, "Scorpio", "Mahindra",3000)); 
carSystem.addCar(Car(7, "Nexon", "Tata", 4000)); 
carSystem.addCar(Car(8, "AltraZ", "Tata", 2800)); 
carSystem.addCar(Car(9, "F-Type", "Jaguar", 12000)); 
carSystem.addCar(Car(10, "Series-2", "BMW", 8000)); 
int choice; 
do { 
// Display a title banner 
std::cout << "*******************************" << std::endl; 
std::cout << "        
CARS FOR SALE         
" << std::endl; 
std::cout << "*******************************" << std::endl; 
std::cout << "1. Display available cars" << std::endl; 
std::cout << "2. Book a car" << std::endl; 
std::cout << "3. Return a car" << std::endl; 
std::cout << "4. Exit" << std::endl; 
std::cout << "Choose an option:" << std::endl; 
std::cin >> choice; 
switch (choice) { 
case 1: 
carSystem.displayAvailableCars(); 
break; 
case 2: { 
std::string customerName, contactNumber, email; 
int selectedCarId; 
std::string startDate, endDate; 
std::cin.ignore(); 
std::cout << "Enter your name: "; 
std::getline(std::cin, customerName); 
std::cout << "Enter your contact number: "; 
std::getline(std::cin, contactNumber); 
std::cout << "Enter your email: "; 
std::getline(std::cin, email); 
std::cout << "Enter the car ID you want to book: "; 
std::cin >> selectedCarId; 
std::cout << "Enter start date (YYYY-MM-DD): "; 
std::cin >> startDate; 
std::cout << "Enter end date (YYYY-MM-DD): "; 
std::cin >> endDate; 
carSystem.bookCar(customerName, contactNumber, email, selectedCarId, startDate, 
endDate); 
} 
break; 
case 3: { 
int returnCarId; 
std::cout << "Enter the car ID you want to return: "; 
std::cin >> returnCarId; 
carSystem.returnCar(returnCarId); 
break; 
} 
case 4: 
std::cout << "Exiting program." << std::endl; 
exit(0); 
default: 
std::cout << "Invalid choice. Please try again." << std::endl; 
break; 
} 
} while (choice != 0); 
return 0; 
} 
