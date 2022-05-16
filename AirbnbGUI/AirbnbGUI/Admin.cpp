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
