#include <iostream>
#include <vector>
#include <fstream>

struct Contact
{
    std::string name{};            //can be repeated.
    std::string surname{};         //can be repeated.
    std::string dob{};             //can be repeated.
    std::string passportID{};      //can not be repeated!
    std::string phoneNumber{};     //can not be repeated!
    std::string email{};           //can not be repeated!
};

std::vector<Contact> myContacts;

void downloadData(const std::string&);
void listAllContacts();
void searchForContacts();
void addNewContact();
void editContact();
void deleteContact();
void exit();
void interface();

int main()
{
    std::string FILE = "data.txt";
    downloadData(FILE);
    interface();

    return 0;
}

void downloadData(const std::string& file)
{
    std::string info{};
    std::string token{};
    std::ifstream text;
    text.open(file);
    text >> info;
    text >> info;
    const int COUNT = stoi(info);
    if(COUNT)
    {
        Contact newContact{};
        while (!text.eof())
        {
            text >> token;
            text >> info;
            if (token == "next" && info == "contact" || token == "end")
            {
                myContacts.push_back(newContact);
                myContacts.shrink_to_fit();
            }
            else if (info == "name"){
            newContact.name = token;
            }

            else if (info == "surname"){
                newContact.surname = token;
            }

            else if (info == "dob"){
                newContact.dob = token;
            }

            else if (info == "passportID"){
                newContact.passportID = token;
            }

            else if (info == "phoneNumber"){
                newContact.phoneNumber = token;
            }

            else if (info == "email"){
                newContact.email = token;
            }    
        }   
    }
    text.close();
}

void listAllContacts()
{
    const int SIZE = myContacts.size();
    for (size_t i = 0; i < SIZE; ++i)
    {
        std::cout << "Contact No" << i+1 << std::endl;
        std::cout << "NAME: " << myContacts[i].name << std::endl;
        std::cout << "SURNAME: " << myContacts[i].surname << std::endl;
        std::cout << "DATE OF BIRTH: " << myContacts[i].dob << std::endl;
        std::cout << "EMAIL ADDRESS: " << myContacts[i].email << std::endl;
        std::cout << "PASSPORT ID: " << myContacts[i].passportID << std::endl;
        std::cout << "PHONE NUMBER: (+374)" << myContacts[i].phoneNumber << std::endl;
        std::cout << std::endl;    
    }    
}

void searchForContacts()
{
    short choice{};
    std::cout << "Your going to search contact from your list, choose methot for searching" << std::endl;
    std::cout << "ENTER [1] FOR SEARCH VIA NAME" << std::endl;
    std::cout << "ENTER [2] FOR SEARCH VIA NUMBER" << std::endl;
    std::cout << "[-]\b\b";
    std::cin >> choice;
    if(choice == 1)
    {
        std::string name{};
        std::cout << "Please enter the name that you want to search: ";
        std::cin >> name;
        int count{};
        for (int i = 0; i < myContacts.size(); ++i)
        {
            if (name == myContacts[i].name)
            {
                ++count; 
                std::cout << std::endl;
                std::cout << "SURNAME: " << myContacts[i].surname << std::endl;
                std::cout << "DATE OF BIRTH: " << myContacts[i].dob << std::endl;
                std::cout << "EMAIL ADDRESS: " << myContacts[i].email << std::endl;
                std::cout << "PASSPORT ID: " << myContacts[i].passportID << std::endl;
                std::cout << "PHONE NUMBER: (+374)" << myContacts[i].phoneNumber << std::endl;
            }    
        }
        if (count)
        {
            std::cout << "\n" << count << " CONTACTS WERE FOUND" << std::endl;
            return;
        }
        std::cout << "On your contact list don't have any item with name " << name << std::endl;
    }
    else if (choice == 2)
    {
        std::string number{};
        std::cout << "Please enter the number that you want to search:";
        std::cout << "(+374)--------\b\b\b\b\b\b\b\b";
        std::cin >> number;
        for (int i = 0; i < myContacts.size(); ++i)
        {
            if (number == myContacts[i].phoneNumber)
            {
                std::cout << std::endl;
                std::cout << "NAME: " << myContacts[i].name << std::endl;
                std::cout << "SURNAME: " << myContacts[i].surname << std::endl;
                std::cout << "DATE OF BIRTH: " << myContacts[i].dob << std::endl;
                std::cout << "EMAIL ADDRESS: " << myContacts[i].email << std::endl;
                std::cout << "PASSPORT ID: " << myContacts[i].passportID << std::endl;
                return;
            }    
        }
        std::cout << "On your contact list don't have any item with number (+374)" << number << std::endl;
    }
}
    
void addNewContact()
{  
    Contact newContact;
    std::cout << std::endl;
    std::cout << "You are going to add a new contact" << std::endl;
    std::cout << "Please fill in all the required information" << std::endl;
    std::cout << "NAME: ";
    std::cin >> newContact.name;
    std::cout << "SURNAME: ";
    std::cin >> newContact.surname;
    std::cout << "DATE OF BIRTH: (dd,mm,yyyy)\b\b\b\b\b\b\b\b\b\b\b";
    std::cin >> newContact.dob;
    std::string forTest{};
    bool test{}; 
    do {
        std::cout << "PHONE NUMBER: (+374)--------\b\b\b\b\b\b\b\b";
        std::cin >> forTest;
        test = false;
        for (size_t i = 0; i < myContacts.size(); i++)
        {
            if(forTest == myContacts[i].phoneNumber){
                std::cout << "This number has already used, please try another number" << std::endl;
                test = true;
                break;
            }    
        }    
    } while (test);
    newContact.phoneNumber = forTest;
    forTest.clear();

    do {
        std::cout << "PASSPORT ID: ";
        std::cin >> forTest;
        test = false;
        for (size_t i = 0; i < myContacts.size(); i++)
        {
            if(forTest == myContacts[i].passportID){
                std::cout << "This passport has already used, please try another one" << std::endl;
                test = true;
                break;
            }    
        }    
    } while (test);
    newContact.passportID = forTest;
    forTest.clear();

    do{
        std::cout << "EMAIL ADDRESS: ";
        std::cin >> forTest;
        test = false;
        for (size_t i = 0; i < myContacts.size(); i++)
        {
            if(forTest == myContacts[i].email){
                std::cout << "This email address has already used, please try another one" << std::endl;
                test = true;
                break;
            }    
        }    
    } while (test);
    newContact.email = forTest;
    forTest.clear();

    myContacts.push_back(newContact);
    myContacts.shrink_to_fit();    
}

void editContact()
{
    std::string passportID{};
    std::cout << "Please input contact's Passport ID that you want to edit: ";
    std::cin >> passportID;
    for (size_t i = 0; i < myContacts.size(); ++i)
    {
        if (passportID == myContacts[i].passportID)
        {
            std::cout << "NAME: ";
            std::cin >> myContacts[i].name;
            std::cout << "SURNAME: ";
            std::cin >> myContacts[i].surname;
            std::cout << "DATE OF BIRTH: (dd,mm,yyyy)\b\b\b\b\b\b\b\b\b\b\b";
            std::cin >> myContacts[i].dob;
            std::string forTest{};
            bool test{}; 

            do {
                std::cout << "PHONE NUMBER: (+374)--------\b\b\b\b\b\b\b\b";
                std::cin >> forTest;
                test = false;
                for (size_t i = 0; i < myContacts.size(); i++)
                {
                    if(forTest == myContacts[i].phoneNumber){
                        std::cout << "This number has already used, please try another number" << std::endl;
                        test = true;
                        break;
                    }    
                } 
            }   
           while (test);
           myContacts[i].passportID = forTest;
           forTest.clear();
 
            do {
                std::cout << "PASSPORT ID: ";
                std::cin >> forTest;
                test = false;
                for (size_t i = 0; i < myContacts.size(); i++)
                {
                    if(forTest == myContacts[i].passportID){
                        std::cout << "This passport has already used, please try another one" << std::endl;
                        test = true;
                        break;
                    }    
                }    
            } while (test);
            myContacts[i].passportID = forTest;
            forTest.clear();

            do {
                std::cout << "EMAIL ADDRESS: ";
                std::cin >> forTest;
                test = false;
                for (size_t i = 0; i < myContacts.size(); i++)
                {
                    if(forTest == myContacts[i].email){
                        std::cout << "This email address has already used, please try another one" << std::endl;
                        test = true;
                        break;
                    }    
                }    
            } while (test);
            myContacts[i].email = forTest;
            forTest.clear();
            
            return;
        }
    } 
    std::cout << "Ther is no any item with Passport ID: " << passportID << std::endl;
}

void deleteContact()
{
    std::string passportID{};
    std::cout << "Please input passportID of contact that you want to delete" << std::endl;
    std::cout << "PASSPORT ID: ";
    std::cin >> passportID;
    for (size_t i = 0; i < myContacts.size(); ++i)
    {
        if (myContacts[i].passportID == passportID)
        {
            myContacts.erase(myContacts.begin() + i);
            std::cout << "This conatac was deleted successfully!\n" << std::endl;
            return;
        }   
    }
    std::cout << "Ther is no any item with Passport ID: " << passportID << std::endl;
    std::cout << std::endl;   
}

void exit()
{
    std::ofstream text;
    const std::string save_to = "data.txt";
    text.open(save_to);
    text.clear();
    text << "contactsCount: " << myContacts.size() << "\n";
    for (size_t i = 0; i < myContacts.size(); ++i)
    {
        text << myContacts[i].name << " name\n";
        text << myContacts[i].surname << " surname\n";
        text << myContacts[i].dob << " dob\n";
        text << myContacts[i].passportID << " passportID\n";
        text << myContacts[i].phoneNumber << " phoneNumber\n";
        text << myContacts[i].email << " email\n";
        if (i != (myContacts.size() - 1))
        {
            text << "next contact\n";
        }    
    }    
    text.close();
}

void interface()
{
    int choice = -1;
    do {
        std::cout << "          MAIN MENU          " << std::endl;
        std::cout << "=============================" << std::endl;
        std::cout << "[1] LIST ALL CONTACTS" << std::endl;
        std::cout << "[2] SEARCH FOR CONTACT" << std::endl;
        std::cout << "[3] ADD NEW CONTACT" << std::endl;
        std::cout << "[4] EDIT A CONTACT" << std::endl;
        std::cout << "[5] DELETE A CONTACT" << std::endl;
        std::cout << "[0] EXIT" << std::endl;
        std::cout << "=============================" << std::endl;
        std::cout << "ENTER YOUR CHOICE [-]\b\b";
        std::cin >> choice;
        std::cout << std::endl;
        if (choice < 0 || choice > 5) 
        {
            std::cout << "Undifined instruction, please try again\n" << std::endl;
            continue;
        }
        switch (choice)
        {
        case 1:
            listAllContacts();
            break;
        
        case 2:
            searchForContacts();
            break;

        case 3:
            addNewContact();
            break;
        
        case 4:
            editContact();
            break;
        
        case 5:
            deleteContact();
            break;
        
        case 0:
            exit();
            break;
        }        
    } while (choice != 0);    
}

