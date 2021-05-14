#include "../include/CarRentalCompany.hpp"
 using namespace std;

int main(){

    Localization currentLocalization;
    currentLocalization.latitude = 34.345345;
    currentLocalization.longitude = 34.345345;

    cout << "CRC class tests" <<endl;
    CarRentalCompany main_test = CarRentalCompany();

    {   
        
        // 1.1 Adding car to list 
        Car testCar = Car( TESLA,"Model 3", "123456789012", (STATUS)0, time(NULL), nullptr, 5.6);
        Car testCar2 = Car( AUDI, "A7", "123456789018", (STATUS)0, time(NULL), nullptr, 8.9);
        Car testCar3 = Car( BMW, "X3", "123456789018", (STATUS)0, time(NULL), nullptr, 3.9);
        main_test.addCar(testCar);

        if( main_test.getCar("123456789012") == testCar ){
            cout << "1.1 Success" << endl;
        }else{
            cout << "1.1 Fail" << endl;
        }

        // 1.2 Removing car from the list 

        main_test.removeCar("123456789012");

        if( main_test.getCar("123456789042") == testCar ){
            cout << "1.2 Fail" << endl;
        }else{
            cout << "1.2 Success" << endl;
        }

        // 1.3 Updating car from the list 
        main_test.addCar(testCar2);
        main_test.updateCar("123456789018",testCar3);

        if( main_test.getCar("123456789018") == testCar3 ){
            cout << "1.3 Success" << endl;
        }else{
            cout << "1.3 Fail" << endl;
        }

        Employee testEmployee = Employee("Tymon", "Żarski","662063094", 1,currentLocalization);
        Employee testEmployee2 = Employee("Jan", "Nowak","662063093", 4,currentLocalization);
        Employee testEmployee3 = Employee("Maciej", "Franczewksi","662063093", 2,currentLocalization);

        cout << main_test.getCar("123456789018");

        // 2.1 Adding Employee from the list 

        main_test.addEmployee(testEmployee);
        main_test.addEmployee(testEmployee2);

        if( main_test.getEmployee("662063094") == testEmployee ){
            cout << "2.1 Success" << endl;
        }else{
            cout << "2.1 Fail" << endl;
        }

        // 2.2 Removing Employee from the list 

        main_test.removeEmployee("662063094");

        if( main_test.getEmployee("662063093") == testEmployee2 ){
            cout << "2.2 Success" << endl;
        }else{
            cout << "2.2 Fail" << endl;
        }

        // 2.3 Updating Employee from the list 
        main_test.updateEmployee("662063093", testEmployee3);

        if( main_test.getEmployee("662063093") == testEmployee3 ){
            cout << "2.3 Success" << endl;
        }else{
            cout << "2.3 Fail" << endl;
        }

        Customer testCustomer = Customer("Tymzar", "Tymon", "Żarski", 20.6);
        Customer testCustomer2 = Customer("Marek99", "Marek", "Nowak", 12.8);
        Customer testCustomer3 = Customer("Marek99", "Franek", "Stzelski", 44.7);

        cout << main_test.getEmployee("662063093");

        // 3.1 Adding Customer from the list 

        main_test.addCustomer(testCustomer);

        if (main_test.getCustomer("Tymzar") == testCustomer ){
            cout << "3.1 Success" << endl;
        }else{
            cout << "3.1 Fail" << endl;
        }
                
        //4.1 Display report data
        
        RentalData testRentalRecord = RentalData(ACTIVE,20.9, 1589.8, 8.3, currentLocalization, currentLocalization, time(NULL),  time(NULL));
    
        cout << testRentalRecord;

        //4.2 Toggle status
        testRentalRecord.toggleRentalStatus();

        if(testRentalRecord.getRentalStatus() == UNACTIVE){
            cout << "4.1 Success" << endl;
        }else{
            cout << "4.1 Fail" << endl;
        }
    }

}