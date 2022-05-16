#include "Admin.h"
#include "DataSets.h"

void UserDataCell::Remove()
{
    for (User* user : *Global::Users->getValues()) {

        if (user->ID == this->user->ID) {
            Global::Users->getValues()->remove(user);
            return;
        }
    }

    for (UserKey* userKey : *Global::Keys->getValues()) {

        if (userKey->userId == this->user->ID) {
            Global::Keys->getValues()->remove(userKey);
            return;
        }
    }
}

void ApartmentDataCell::Remove()
{
    for (Apartment* apartment : *Global::Apartments->getValues()) {

        if (apartment->ID == this->apartment->ID) {
            Global::Apartments->getValues()->remove(apartment);
            return;
        }
    }
}

void BookedApartmentDataCell::Remove()
{
    for (BookedApartment* bookedApartment : *Global::BookedApartments->getValues()) {

        if (bookedApartment->ID == this->bookedApartment->ID) {
            Global::BookedApartments->getValues()->remove(bookedApartment);
            return;
        }
    }
}
