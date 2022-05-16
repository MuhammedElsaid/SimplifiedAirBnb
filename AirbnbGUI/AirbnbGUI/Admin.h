#pragma once
#include "Apartment.h"
#include "User.h"
#include <list>

using namespace System;
using namespace msclr::interop;

#define DefineProperty(name, stName, managedType, standardType, stVar)\
public: property managedType^ name {\
        managedType^ get(){\
            return gcnew managedType(stVar->stName);\
}\

#define DefineSet(name, stName, managedType, standardType, stVar)\
void set(managedType^ value){\
    stVar->stName = marshal_as<standardType>(value);\
}}\

#define DefineSetNoMarshal(name, stName, managedType, standardType, stVar)\
void set(String^ value){\
    stVar->stName = System::Convert::To##managedType(value);\
}}\

ref class ApartmentDataCell
{
    public: ApartmentDataCell(Apartment* apartment) {
        this->apartment = apartment;
    }
    public: void Remove();

    private: Apartment* apartment;

    DefineProperty(Address, address.c_str(), String, std::string, apartment)
    DefineSet(Address, address, String, std::string, apartment)

    DefineProperty(City, city.c_str(), String, std::string, apartment)
    DefineSet(City, city, String, std::string, apartment)

    DefineProperty(NumberOfRooms, availableRooms.ToString(), String, int, apartment)
    DefineSetNoMarshal(NumberOfRooms, availableRooms, Int32, int, apartment)

    DefineProperty(Capacity, capacity.ToString(), String, double, apartment)
    DefineSetNoMarshal(Capacity, capacity, Double, double, apartment)

    DefineProperty(Price, price.ToString(), String, double, apartment)
    DefineSetNoMarshal(Price, price, Double, double, apartment)
};

ref class UserDataCell
{
    public: UserDataCell(User* user) {

        this->user = user;
    }

    public: void Remove();
    private: User* user;

    DefineProperty(FullName, fullName.c_str(), String, std::string, user)
    DefineSet(FullName, fullName, String, std::string, user)

    DefineProperty(Email, email.c_str(), String, std::string, user)
    DefineSet(Email, email, String, std::string, user)

    DefineProperty(Gender, gender.c_str(), String, std::string, user)
    DefineSet(Gender, gender, String, std::string, user)

    DefineProperty(Age, age.ToString(), String, std::string, user)
    DefineSetNoMarshal(Age, age, Int32, std::string, user)
};

ref class BookedApartmentDataCell
{
    public: BookedApartmentDataCell(BookedApartment* bookedApartment) {

        this->bookedApartment = bookedApartment;
    }

    public: void Remove();

    private: BookedApartment* bookedApartment;

    DefineProperty(ApartmentID, apartmentID.ToString(), String, int, bookedApartment)
    DefineSetNoMarshal(ApartmentID, apartmentID, Int32, int, bookedApartment)

    DefineProperty(StartDate, startDate.c_str(), String, std::string, bookedApartment)
    DefineSet(StartDate, startDate, String, std::string, bookedApartment)

    DefineProperty(NumberOfDays, numberOfDays.ToString(), String, int, bookedApartment)
    DefineSetNoMarshal(NumberOfDays, numberOfDays, Int32, int, bookedApartment)
};