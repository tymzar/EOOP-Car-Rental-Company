#include "../include/CarRentalCompany.hpp"


        CarRentalCompany::CarRentalCompany(){ std::cout << "CRC created!"<<std::endl;}
        CarRentalCompany::~CarRentalCompany(){
              std::cout << "CRC close!"<<std::endl;  
        }

        struct carUnique {
                bool operator() (Car first, Car second)
                { return (first.getVIN() == second.getVIN()); }
        };
        struct employeeUnique {
                bool operator() (Employee first, Employee second)
                { return (first.getPhoneNumber() == second.getPhoneNumber()); }
        };

        void CarRentalCompany::addCar(Car& car){

                carsAmount++;
                this->Cars.push_back(car);
                this->Cars.unique(carUnique());
        }
        void CarRentalCompany::addCustomer(Customer& customer){
                this->Customers.push_back(customer);
        }
        void CarRentalCompany::addEmployee(Employee& employee){
                this->Employees.push_back(employee);
                this->Employees.unique(employeeUnique());
        }
        void CarRentalCompany::addRentalData(RentalRecord& rentalData){
                this->RentalHistory.push_back(rentalData);

        }

        void CarRentalCompany::removeCar(std::string VINnumber){

                if(VINnumber == ""){
                        for (std::list<Car>::const_iterator iterator = Cars.begin(), end = Cars.end(); iterator != end; ++iterator) {
                                std::cout << "Car Model: " << iterator->getModel() << "Car VIN: " << iterator->getVIN() << std::endl;
                        }
                        std::cout << "Enter VIN number: ";
                        std::cin >> VINnumber;
                }

                std::list<Car>::const_iterator res;
                for (std::list<Car>::const_iterator iterator = Cars.begin(), end = Cars.end(); iterator != end; ++iterator) {
                        if( iterator->getVIN() == VINnumber){
                                res = iterator;
                                break;
                        }
                }
                Cars.erase(res);
                carsAmount--;
        }
        void CarRentalCompany::removeCustomer(std::string username){

                if(username == ""){
                        for (std::list<Customer>::const_iterator iterator = Customers.begin(), end = Customers.end(); iterator != end; ++iterator) {
                                std::cout << "Customer nickname: " << iterator->getUsername() << std::endl;
                        }
                        std::cout << "Enter Custmer username: ";
                        std::cin >> username;
                }
                
                std::list<Customer>::const_iterator res;
                for (std::list<Customer>::const_iterator iterator = Customers.begin(), end = Customers.end(); iterator != end; ++iterator) {
                        if( iterator->getUsername() == username){
                                res = iterator;
                                break;
                        }
                }
                Customers.erase(res);
                customersAmount--;
        }
        void CarRentalCompany::removeEmployee(std::string phoneNumber){

                if(phoneNumber == ""){
                        for (std::list<Employee>::const_iterator iterator = Employees.begin(), end = Employees.end(); iterator != end; ++iterator) {
                                std::cout << "Emplyee phone number: " << iterator->getPhoneNumber() << std::endl;
                        }
                        std::cout << "Enter Emplyee phone number: ";
                        std::cin >> phoneNumber;
                }

                std::list<Employee>::const_iterator res;
                for (std::list<Employee>::const_iterator iterator = Employees.begin(), end = Employees.end(); iterator != end; ++iterator) {
                        if( iterator->getPhoneNumber() == phoneNumber){
                                res = iterator;
                        }
                }
                Employees.erase(res);
        }

        Car CarRentalCompany::getCar(std::string VINnumber){
                std::list<Car>::const_iterator res = Cars.begin();
                for (std::list<Car>::const_iterator iterator = Cars.begin(), end = Cars.end(); iterator != end; ++iterator) {
                        if( iterator->getVIN() == VINnumber){
                                res = iterator;
                                return *res;
                        }
                }
                return *res;
        }
        Customer CarRentalCompany::getCustomer(std::string username){
                std::list<Customer>::const_iterator res;
                for (std::list<Customer>::const_iterator iterator = Customers.begin(), end = Customers.end(); iterator != end; ++iterator) {
                        if( iterator->getUsername() == username){
                                res = iterator;
                                return *res;
                        }
                }   
                return *res;       
        }
        Employee CarRentalCompany::getEmployee(std::string phoneNumber){
                std::list<Employee>::const_iterator res;
                for (std::list<Employee>::const_iterator iterator = Employees.begin(), end = Employees.end(); iterator != end; ++iterator) {
                        if( iterator->getPhoneNumber() == phoneNumber){
                                res = iterator;
                                return *res;
                        }
                }   
                return *res;   
        }
        void CarRentalCompany::updateCar(std::string VINnumber, Car& car){
                removeCar(VINnumber);
                addCar(car);
        }
        void CarRentalCompany::updateCustomer(std::string username, Customer& customer){
                removeCustomer(username);
                addCustomer(customer);
        }
        void CarRentalCompany::updateEmployee(std::string phoneNumber, Employee& employee){
                removeEmployee(phoneNumber);
                addEmployee(employee);
        }

        void CarRentalCompany::updateCar(){

                std::string model, newVINNumber, srtLastRental, VINnumber, userPtr;
                double avgFuel;
                bool carStatus;
                time_t lastcarRental;
                Customer * newPtrCus;

                for (std::list<Car>::const_iterator iterator = Cars.begin(), end = Cars.end(); iterator != end; ++iterator) {
                                std::cout << "Car Model: " << iterator->getModel() << "Car VIN: " << iterator->getVIN() << std::endl;
                }
                std::cout << "Enter VIN number of Car to update: ";
                std::cin >> VINnumber;
                

                std::list<Car>::const_iterator res = Cars.begin();
                for (std::list<Car>::const_iterator iterator = Cars.begin(), end = Cars.end(); iterator != end; ++iterator) {
                        if( iterator->getVIN() == VINnumber){
                                res = iterator;
                        }
                }
                

                
                std::cout << "Type Car model: ";
                std::cin >> model;
                std::cout << "Type VIN number: ";
                std::cin >> newVINNumber;
                std::cout << "Type car status 0(INACTIVE)/1(ACTIVE): ";
                std::cin >> carStatus;
                std::cout << "Type rental start time (YYYYmmDDhhMMss): ";
                std::cin >> srtLastRental;
                lastcarRental = timeToTimeStamp(srtLastRental);
                std::cout << "Select last rentee: ";

                for (std::list<Customer>::const_iterator iterator = Customers.begin(), end = Customers.end(); iterator != end; ++iterator) {
                                std::cout << "Customer username: " << iterator->getUsername() << std::endl;
                }
                std::cout << "Enter username of customer to update (or NULL): ";
                std::cin >> userPtr;
                std::list<Customer>::iterator lastRenteeIter = Customers.begin();

                if(userPtr == "NULL"){
                        newPtrCus = nullptr;
                }else{

                        for (std::list<Customer>::iterator iterator = Customers.begin(), end = Customers.end(); iterator != end; ++iterator) {
                                if( iterator->getUsername() == userPtr){
                                        lastRenteeIter = iterator;
                                }
                        }
                        newPtrCus = &*lastRenteeIter;
                
                }
                
                
                std::cout << "Type AVG fuel compenstion: ";
                std::cin >> avgFuel;

                Car newCar = Car(model, newVINNumber, (STATUS)carStatus, lastcarRental, newPtrCus, avgFuel);
                updateCar(res->getVIN(), newCar);


        }
        void CarRentalCompany::updateCustomer(){
                
                std::string customerUsername;

                for (std::list<Customer>::const_iterator iterator = Customers.begin(), end = Customers.end(); iterator != end; ++iterator) {
                                std::cout << "Customer username: " << iterator->getUsername() << std::endl;
                }
                std::cout << "Enter username of Customer to update: ";
                std::cin >> customerUsername;
                

                std::list<Customer>::const_iterator res = Customers.begin();
                for (std::list<Customer>::const_iterator iterator = Customers.begin(), end = Customers.end(); iterator != end; ++iterator) {
                        if( iterator->getUsername() == customerUsername){
                                res = iterator;
                        }
                }
                

                
                std::string username, name, surname;
                double accountBalace;
                
                std::cout << "Type Customer username: ";
                std::cin >> username;
                std::cout << "Type Customer name: ";
                std::cin >> name;
                std::cout << "Type Customer surname: ";
                std::cin >> surname;
                std::cout << "Type account balance: ";
                std::cin >> accountBalace;

                Customer newCustomer = Customer(username, name, surname, accountBalace);
                updateCustomer(res->getUsername(), newCustomer);

        }
        void CarRentalCompany::updateEmployee(){

                std::string customerUsername;

                for (std::list<Employee>::const_iterator iterator = Employees.begin(), end = Employees.end(); iterator != end; ++iterator) {
                                std::cout << "Emplyee phone number: " << iterator->getPhoneNumber() << std::endl;
                }
                std::cout << "Enter phone number of car to update: ";
                std::cin >> customerUsername;
                

                std::list<Employee>::const_iterator res = Employees.begin();
                for (std::list<Employee>::const_iterator iterator = Employees.begin(), end = Employees.end(); iterator != end; ++iterator) {
                        if( iterator->getPhoneNumber() == customerUsername){
                                res = iterator;
                        }
                }
                

                
                std::string name, surname, phoneNumber;
                double fueledCars;
                
                std::cout << "Type Customer username: ";
                std::cin >> name;
                std::cout << "Type Customer name: ";
                std::cin >> surname;
                std::cout << "Type Customer surname: ";
                std::cin >> phoneNumber;
                std::cout << "Type account balance: ";
                std::cin >> fueledCars;

                Employee newEmployee = Employee(name, surname, phoneNumber, fueledCars);
                updateEmployee(res->getPhoneNumber(),newEmployee);

        }

        void CarRentalCompany::inputCar(){
               
                std::string model, newVINNumber;
                double avgFuel;
                
                std::cout << "Type Car model: ";
                std::cin >> model;
                std::cout << "Type VIN number: ";
                std::cin >> newVINNumber;
                std::cout << "Type AVG fuel compenstion: ";
                std::cin >> avgFuel;
                Car newCar = Car(model, newVINNumber, (STATUS)0, time(NULL), nullptr, avgFuel);
                addCar(newCar);
        }

        void CarRentalCompany::inputCustomer(){
        
                std::string username, name, surname;
                double accountBalace;
                
                std::cout << "Type Customer username: ";
                std::cin >> username;
                std::cout << "Type Customer name: ";
                std::cin >> name;
                std::cout << "Type Customer surname: ";
                std::cin >> surname;
                std::cout << "Type account balance: ";
                std::cin >> accountBalace;

                Customer newCustomer = Customer(username, name, surname, accountBalace);
                addCustomer(newCustomer);
        }

        void CarRentalCompany::inputEmployee(){
        
                std::string name, surname, phoneNumber;
                double fueledCars;
                
                std::cout << "Type Customer username: ";
                std::cin >> name;
                std::cout << "Type Customer name: ";
                std::cin >> surname;
                std::cout << "Type Customer surname: ";
                std::cin >> phoneNumber;
                std::cout << "Type account balance: ";
                std::cin >> fueledCars;

                Employee newEmployee = Employee(name, surname, phoneNumber, fueledCars);
                addEmployee(newEmployee);
        }

        void CarRentalCompany::inputRentalData(){
        
                bool status;
                double travelledDistance, rentalUserCharge, rentalFuelUsed;
                std::string rentalStart, rentalEnd, username, renVINnumber;
                time_t rentalTimeStart, rentalTimeEnd;
                
                std::cout << "Type rental status 0(INACTIVE)/1(ACTIVE): ";
                std::cin >> status;
                std::cout << "Type travelled distance: ";
                std::cin >> travelledDistance;
                std::cout << "Type rental user charge: ";
                std::cin >> rentalUserCharge;
                std::cout << "Type rental fuel used: ";
                std::cin >> rentalFuelUsed;

                std::cout << "Type rental start time (YYYYmmDDhhMMss): ";
                std::cin >> rentalStart;
                std::cout << "Type rental end time (YYYYmmDDhhMMss): ";
                std::cin >> rentalEnd;

                rentalTimeStart = timeToTimeStamp(rentalStart);
                rentalTimeEnd = timeToTimeStamp(rentalEnd);
                
                std::cout << "Enter Custmer username: ";
                std::cin >> username;
                
                std::list<Customer>::iterator selectedCustomer;
                for (std::list<Customer>::iterator iterator = Customers.begin(), end = Customers.end(); iterator != end; ++iterator) {
                        if( iterator->getUsername() == username){
                                selectedCustomer = iterator;
                                break;
                        }
                }

                std::cout << "Enter Car VIN number: ";
                std::cin >> renVINnumber;

                std::list<Car>::iterator selectedCar;
                for (std::list<Car>::iterator iterator = Cars.begin(), end = Cars.end(); iterator != end; ++iterator) {
                        if( iterator->getVIN() == renVINnumber){
                                selectedCar = iterator;
                                break;
                        }
                }

                RentalData newRentalData = RentalData(((STATUS)status), travelledDistance,  rentalUserCharge,  rentalFuelUsed, rentalTimeStart , rentalTimeEnd);
                
                selectedCustomer->addUserRentalHistory(newRentalData);

                RentalRecord newRentalRecord = RentalRecord( &*selectedCar, &*selectedCustomer,((STATUS)status), travelledDistance,  rentalUserCharge,  rentalFuelUsed, rentalTimeStart , rentalTimeEnd);
                
                addRentalData(newRentalRecord);
        }

        void CarRentalCompany::addData(){
                getchar();
                char menuOption;
                bool exit = true;
                std::cout<< "1 - Add car, 2 - Add customer, 3 - Add employee, 4 - Add rental, 5 - Exit" << std::endl;
                std::cout<< "Enter int to add data: ";
                while(exit && (menuOption = getchar())){

                        switch(menuOption){

                                case '1':
                                
                                        inputCar();
                                        break;
                                
                                case '2':

                                        inputCustomer();
                                        break;

                                case '3':

                                        inputEmployee();
                                        break;

                                case '4':

                                        inputRentalData();
                                        break;
                               
                                case '5':

                                        std::cout << "exit" << std::endl;
                                        exit = false;
                                        std::cout<< "Enter char to enter option: " << std::endl;
                                        break;

                                default:
                                        std::cout<< "Enter valid char to enter data type add: " << std::endl;
                                        continue;

                        }
                        exit = false;
                        getchar();
                }

        }
        void CarRentalCompany::removeData(){

                getchar();
                char menuOption;
                bool exit = true;
                std::cout<< "1 - Remove car, 2 - Remove customer, 3 - Remove employee, 4 - Exit" << std::endl;
                std::cout<< "Enter int to input data: ";
                while(exit && (menuOption = getchar())){

                        switch(menuOption){

                                case '1':
                                
                                        removeCar();
                                        break;
                                
                                case '2':

                                        removeCustomer();
                                        break;

                                case '3':

                                        removeEmployee();
                                        break;
                               
                                case '4':

                                        std::cout << "exit" << std::endl;
                                        exit = false;
                                        std::cout<< "Enter char to enter option: " << std::endl;
                                        break;

                                default:
                                        std::cout<< "Enter valid char to enter data type add: " << std::endl;
                                        continue;

                        }
                        exit = false;
                        getchar();
                }

        }
        void CarRentalCompany::updateData(){
                
                getchar();
                char menuOption;
                bool exit = true;
                std::cout<< "1 - Update car, 2 - Update customer, 3 - Update employee, 4 - Exit" << std::endl;
                std::cout<< "Enter int to input data: ";

                while(exit && (menuOption = getchar())){



                        switch(menuOption){

                                case '1':
                                
                                        updateCar();
                                        break;
                                
                                case '2':

                                        updateCustomer();
                                        break;

                                case '3':

                                        updateEmployee();
                                        break;

                               
                                case '4':

                                        std::cout << "exit" << std::endl;
                                        exit = false;
                                        std::cout<< "Enter char to enter option: " << std::endl;
                                        break;

                                default:
                                        std::cout<< "Enter valid char to enter data type add: " << std::endl;
                                        continue;

                        }
                        exit = false;
                        getchar();
                } 
        }
        
        void CarRentalCompany::saveData(std::string path){}
        void CarRentalCompany::loadData(DATA_TYPE type, std::string path){}

        void CarRentalCompany::findData(DATA_TYPE type, int memberDBID){}
        void CarRentalCompany::outData(std::ostream& out){}

        void CarRentalCompany::exportStatisticsToCSV(){
                getchar();
                const int nameWidth = 30;
                std::ofstream CompanyStatsCSV;
                CompanyStatsCSV.open("CompanyStats.csv");


                CompanyStatsCSV << "Company Statistics: " << std::endl;                
                CompanyStatsCSV << std::left<< std::setw(nameWidth) << "Total Cars: " <<carsAmount << std::endl;                
                CompanyStatsCSV << std::left<< std::setw(nameWidth) << "Total Customers: " << customersAmount << std::endl;            
                CompanyStatsCSV << std::left<< std::setw(nameWidth) << "Total Active Customers: " << Customers.back().getactiveCustomersAmount() << std::endl;            
                CompanyStatsCSV << std::left<< std::setw(nameWidth) << "Total Employees" << Employees.back().getEmployeeAmount() << std::endl;            
                CompanyStatsCSV << std::left<< std::setw(nameWidth) << "Total Cars Fueled: " << Employees.back().getTotalCarsFueled() << std::endl;            
                CompanyStatsCSV << std::left<< std::setw(nameWidth) << "Employee Most Fueled Cars: " << Employees.back().getMostCarsFueed() <<std::endl;            
                CompanyStatsCSV << std::left<< std::setw(nameWidth) << "Total rented Cars: " << Cars.back().getCarsRented() << std::endl;            
                CompanyStatsCSV << std::left<< std::setw(nameWidth) << "Total User Charge: " << RentalHistory.back().getRentalDetails()->getTotalUserCharge() << std::endl;            
                CompanyStatsCSV << std::left<< std::setw(nameWidth) << "Total Rentals: " << RentalHistory.back().getRentalDetails()->getTotalRentals() << std::endl;            
                CompanyStatsCSV << std::left<< std::setw(nameWidth) << "Average Rental Time: " << RentalHistory.back().getRentalDetails()->getAvgRentalTime() << std::endl;            
                CompanyStatsCSV << std::left<< std::setw(nameWidth) << "Average travelled distance: " << RentalHistory.back().getRentalDetails()->getAvgTravelledDistance() << std::endl;            
 
                CompanyStatsCSV.close();
        }

        void CarRentalCompany::getStatistics(){
                const int nameWidth = 30;

                std::cout << "Company Statistics: " << std::endl;                
                std::cout << std::left<< std::setw(nameWidth) << "Total Cars: " <<carsAmount << std::endl;                
                std::cout << std::left<< std::setw(nameWidth) << "Total Customers: " << customersAmount << std::endl;            
                std::cout << std::left<< std::setw(nameWidth) << "Total Active Customers: " << Customers.back().getactiveCustomersAmount() << std::endl;            
                std::cout << std::left<< std::setw(nameWidth) << "Total Employees" << Employees.back().getEmployeeAmount() << std::endl;            
                std::cout << std::left<< std::setw(nameWidth) << "Total Cars Fueled: " << Employees.back().getTotalCarsFueled() << std::endl;            
                std::cout << std::left<< std::setw(nameWidth) << "Employee Most Fueled Cars: " << Employees.back().getMostCarsFueed() <<std::endl;            
                std::cout << std::left<< std::setw(nameWidth) << "Total rented Cars: " << Cars.back().getCarsRented() << std::endl;            
                std::cout << std::left<< std::setw(nameWidth) << "Total User Charge: " << RentalHistory.back().getRentalDetails()->getTotalUserCharge() << std::endl;            
                std::cout << std::left<< std::setw(nameWidth) << "Total Rentals: " << RentalHistory.back().getRentalDetails()->getTotalRentals() << std::endl;            
                std::cout << std::left<< std::setw(nameWidth) << "Average Rental Time: " << RentalHistory.back().getRentalDetails()->getAvgRentalTime() << std::endl;            
                std::cout << std::left<< std::setw(nameWidth) << "Average travelled distance: " << RentalHistory.back().getRentalDetails()->getAvgTravelledDistance() << std::endl;            
        }
        int CarRentalCompany::returnNumberOfCars(){ return carsAmount;}
        int CarRentalCompany::returnNumberOfCustomers(){ return customersAmount;}

        void CarRentalCompany::displayMenu(){ 
                
                char menuOption;
                bool exit = true;
                std::cout<< "1 - Add data, 2 - Remove data, 3 - Update data, 4 - Print data, 5 - Export Statistics to XLSX, 6 - Exit, 7 - Testing"<< std::endl;
                std::cout<< "Enter int to select option: ";
                
                while(exit && (menuOption = getchar())){
                        
                        switch(menuOption){

                                case '1':

                                        std::cout << "Data additon!" << std::endl;

                                        addData();

                                        break;
                                
                                case '2':

                                        std::cout << "Data removal!" << std::endl;

                                        removeData();

                                        break;

                                case '3':

                                        std::cout << "Data update!" << std::endl;

                                        updateData();

                                        break;

                                case '4':

                                        std::cout << "Data display!" << std::endl;

                                        printData();

                                        break;

                                case '5':

                                        std::cout << "Exporintg statistics to CSV!" << std::endl;

                                        exportStatisticsToCSV();
                                        exit = false;
                                        break;

                               
                                case '6':

                                        std::cout << "Exit!" << std::endl;
                                        exit = false;
                                        break;
                                        continue;

                                case '7':
                                        std::cout << "Testing!" << std::endl;
                                        testing();
                                        exit = false;
                                        break;
                                        continue;                              

                                default:
                                        std::cout<< "1 - Add data, 2 - Remove data, 3 - Update data, 4 - Print data, 5 - Load file, 6 - Save file, 7 - Exit, 8 - Testing" << std::endl;
                                        std::cout<< "Enter int to select option: ";
                                        continue;

                        }
                        if(exit){
                                std::cout<< "1 - Add data, 2 - Remove data, 3 - Update data, 4 - Print data, 5 - Load file, 6 - Save file, 7 - Exit, 8 - Testing" << std::endl;
                                std::cout<< "Enter int to select option: ";
                        }        
                }
        }


        void CarRentalCompany::printData(){
                getchar();
                char menuOption;
                bool exit = true;
                std::cout<< "1 - Print car, 2 - Print customer, 3 - Print employee, 4 - Print rental" << std::endl;
                std::cout<< "Enter int to input data: ";
                while(exit && (menuOption = getchar())){
                        getchar();
                        switch(menuOption){

                                case '1':
                                
                                        for (std::list<Car>::const_iterator iterator = Cars.begin(), end = Cars.end(); iterator != end; ++iterator) {
                                                                std::cout << *iterator;
                                        }
                                        break;
                                
                                case '2':

                                        for (std::list<Customer>::const_iterator iterator = Customers.begin(), end = Customers.end(); iterator != end; ++iterator) {
                                                                std::cout << *iterator;
                                        }
                                        break;

                                case '3':
                                        for (std::list<Employee>::const_iterator iterator = Employees.begin(), end = Employees.end(); iterator != end; ++iterator) {
                                                                std::cout << *iterator;
                                        }
                                        break;

                                case '4':
                                        for (std::list<RentalRecord>::const_iterator iterator = RentalHistory.begin(), end = RentalHistory.end(); iterator != end; ++iterator) {
                                                                std::cout << *iterator;
                                        }
                                        break;
                               
                                case '5':

                                        std::cout << "exit" << std::endl;
                                        break;

                                default:
                                        std::cout<< "1 - Print car, 2 - Print customer, 3 - Print employee, 4 - Print rental" << std::endl;
                                        std::cout<< "Enter valid char to enter data type add: " << std::endl;
                                        continue;

                        }
                        exit = false;
                }
        }

        void testing(){   
        
        CarRentalCompany * main_test = new CarRentalCompany();
        
        // 1.1 Adding car to list 
        Car testCar = Car( "Model 3", "123456789012", (STATUS)0, time_t(12354), nullptr, 5.6);
        Car testCar2 = Car("A7", "123456789018", (STATUS)0, time_t(333554), nullptr, 8.9);
        Car testCar3 = Car( "X3", "123456789018", (STATUS)0, time_t(409354), nullptr, 3.9);
        main_test->addCar(testCar);
        main_test->addCar(testCar2);

        if( main_test->getCar("123456789012") == testCar ){
            std::cout << "1.1 Success" << std::endl;
        }else{
            std::cout << "1.1 Fail" << std::endl;
        }

        // 1.2 Removing car from the list 

        main_test->removeCar("123456789012");

        if( main_test->getCar("123456789042") == testCar ){
            std::cout << "1.2 Fail" << std::endl;
        }else{
            std::cout << "1.2 Success" << std::endl;
        }

        // 1.3 Updating car from the list 
        main_test->updateCar("123456789018",testCar3);

        if( main_test->getCar("123456789018") == testCar3 ){
            std::cout << "1.3 Success" << std::endl;
        }else{
            std::cout << "1.3 Fail" << std::endl;
        }

        Employee testEmployee = Employee("Tymon", "Żarski","662063094", 1);
        Employee testEmployee2 = Employee("Jan", "Nowak","662063093", 4);
        Employee testEmployee3 = Employee("Maciej", "Franczewksi","662063093", 2);

        // 2.1 Adding Employee from the list 

        main_test->addEmployee(testEmployee);
        main_test->addEmployee(testEmployee2);

        if( main_test->getEmployee("662063094") == testEmployee ){
            std::cout << "2.1 Success" << std::endl;
        }else{
            std::cout << "2.1 Fail" << std::endl;
        }

        // 2.2 Removing Employee from the list 

        main_test->removeEmployee("662063094");

        if( main_test->getEmployee("662063093") == testEmployee2 ){
            std::cout << "2.2 Success" << std::endl;
        }else{
            std::cout << "2.2 Fail" << std::endl;
        }

        // 2.3 Updating Employee from the list 
        main_test->updateEmployee("662063093", testEmployee3);

        if( main_test->getEmployee("662063093") == testEmployee3 ){
            std::cout << "2.3 Success" << std::endl;
        }else{
            std::cout << "2.3 Fail" << std::endl;
        }

        Customer testCustomer = Customer("Tymzar", "Tymon", "Żarski", 20.6);
        Customer testCustomer2 = Customer("Marek99", "Marek", "Nowak", 12.8);
        Customer testCustomer3 = Customer("Marek99", "Franek", "Stzelski", 44.7);

        // 3.1 Adding Customer from the list 

        main_test->addCustomer(testCustomer);
        main_test->addCustomer(testCustomer2);

        if( main_test->getCustomer("Tymzar") == testCustomer ){
            std::cout << "3.1 Success" << std::endl;
        }else{
            std::cout << "3.1 Fail" << std::endl;
        }

        // 2.2 Removing Employee from the list 

        main_test->removeCustomer("Tymzar");

        if( main_test->getCustomer("Marek99") == testCustomer ){
            std::cout << "3.2 Fail" << std::endl;
        }else{
            std::cout << "3.2 Success" << std::endl;
        }

        // 2.3 Updating Employee from the list 
        main_test->updateCustomer("Marek99", testCustomer3);

        if( main_test->getCustomer("Marek99") == testCustomer3 ){
            std::cout << "3.3 Success" << std::endl;
        }else{
            std::cout << "3.3 Fail" << std::endl;
        }
                
        //4.1 Toggle status
       
        RentalData * testRentalRecord = new RentalData(ACTIVE,20.9, 1589.8, 8.3, time_t(12354),  time_t(22354));
    
        testRentalRecord->toggleRentalStatus();

        if(testRentalRecord->getRentalStatus() == UNACTIVE){
            std::cout << "4.1 Success" << std::endl;
        }else{
            std::cout << "4.1 Fail" << std::endl;
        }
    }



