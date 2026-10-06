// pract7_bodrof_pr32.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// pr32_pract7_Bodroff.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <fstream>

#include <string>

#include <stdexcept>

#define DEBUG_MODE


struct ServiceСenter
{
    int number;
    std::string client;
    std::string device;
    std::string description;
    double price;
    std::string status;

};




int main()
{

    //показ файла

    setlocale(LC_ALL, "Russian");

    ServiceСenter service;
    

    try {


    std::ifstream file("file.txt");


    if (!file.is_open()) {

        throw std::invalid_argument("не удалось открыть файл");

    }

    std::string line;

    //загрузка из файла:

    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
    }

    file.close();

    #ifdef DEBUG_MODE
     std::cout << "DEBUG = прочитали файл" << std::endl;
    #endif // DEBUG



    //поиск по номеру заявки 


    std::cout << "введите номер заявки :";

    int number;

    std::string pricetext;

    bool cheks = false;

    std::string text;

    std::cin >> number;

    std::ifstream file2("file.txt");

    if (!file2.is_open()) {

        throw std::invalid_argument("не удалось открыть файл");

    }

    while (std::getline(file2, text, ';')) {

        service.number = std::stoi(text);

        std::getline(file2, service.client, ';');
        std::getline(file2, service.device, ';');
        std::getline(file2, service.description, ';');

        std::getline(file2, pricetext, ';');
        service.price = std::stod(pricetext);

        std::getline(file2, service.status);

        if (number == service.number) {

            std::cout << "номер найден!" << std::endl;
            std::cout << "номер = " << service.number << std::endl;
            std::cout << "имя  = " << service.client << std::endl;
            std::cout << "техника = " << service.device << std::endl;
            std::cout << "проблема = " << service.description << std::endl;
            std::cout << "цена = " << service.price << std::endl;
            std::cout << "статус = " << service.status << std::endl;


            cheks = true;
        }

    }

    if (cheks == false) {

        std::cout << "Номер не найден!!!" << std::endl;

    }


    file2.close();


    //поиск по фамилии 

    cheks = false;

    text = "";

    std::cout << "введите имя " << std::endl;

    std::string names;

    std::cin >> names;

    std::ifstream file3("file.txt");

    if (!file3.is_open()) {

        throw std::invalid_argument("не удалось открыть файл");

    }


    while (std::getline(file3, text, ';')) {

        service.number = std::stoi(text);

        std::getline(file3, service.client, ';');
        std::getline(file3, service.device, ';');
        std::getline(file3, service.description, ';');

        std::getline(file3, pricetext, ';');
        service.price = std::stod(pricetext);

        std::getline(file3, service.status);

        if (service.client.find(names) != std::string::npos) {

            std::cout << "имя найдено " << std::endl;

            std::cout << "номер найден!" << std::endl;
            std::cout << "номер = " << service.number << std::endl;
            std::cout << "имя  = " << service.client << std::endl;
            std::cout << "техника = " << service.device << std::endl;
            std::cout << "проблема = " << service.description << std::endl;
            std::cout << "цена = " << service.price << std::endl;
            std::cout << "статус = " << service.status << std::endl;

            cheks = true;

        }


    }

    if (cheks == false) {

        std::cout << "имя не найдено" << std::endl;

    }

    file3.close();

    // Показать заявки с выбранным статусом.


    std::cout << " Напишите статус : " << std::endl;

    std::string status;

    std::cin.ignore();
    std::getline(std::cin, status);

    cheks = false;


    std::ifstream file4("file.txt");

    if (!file4.is_open()) {

        throw std::invalid_argument("не удалось открыть файл");

    }


    std::cout << "вся информация с статусом :" << status << std::endl;



    while (std::getline(file4, text, ';')) {

        service.number = std::stoi(text);

        std::getline(file4, service.client, ';');
        std::getline(file4, service.device, ';');
        std::getline(file4, service.description, ';');

        std::getline(file4, pricetext, ';');
        service.price = std::stod(pricetext);

        std::getline(file4, service.status);


        if (service.status == status) {

            std::cout << "\n номер = " << service.number << std::endl;
            std::cout << "имя  = " << service.client << std::endl;
            std::cout << "техника = " << service.device << std::endl;
            std::cout << "проблема = " << service.description << std::endl;
            std::cout << "цена = " << service.price << std::endl;
            std::cout << "статус = " << service.status << std::endl;

            cheks = true;


        }
       
    }


    if (cheks == false)
    {
        std::cout << "Заявок с таким статусом нет" << std::endl;
    }

    file4.close();


    //Изменить статус заявки.

    cheks = false;

    std::cout << "введите новый статус заявки!";
  
    std::string newstatus;

    std::getline(std::cin, newstatus);



    std::cout << "введите номер заявки";

    int numbernew;

    std::cin >> numbernew;


    std::ifstream file5("file.txt");

    if (!file5.is_open()) {

        throw std::invalid_argument("не удалось открыть файл");

    }



    std::ofstream filetwo("filetwo.txt");

    if (!filetwo.is_open()) {

        throw std::invalid_argument("не удалось открыть файл");

    }


    while (std::getline(file5, text, ';')) {

        service.number = std::stoi(text);

        std::getline(file5, service.client, ';');
        std::getline(file5, service.device, ';');
        std::getline(file5, service.description, ';');

        std::getline(file5, pricetext, ';');
        service.price = std::stod(pricetext);

        std::getline(file5, service.status);

        if (service.number == numbernew)
        {
            service.status = newstatus;
            cheks = true;
        }

        filetwo << service.number << ';';
        filetwo << service.client << ';';
        filetwo << service.device << ';';
        filetwo << service.description << ';';
        filetwo << service.price << ';';
        filetwo << service.status << std::endl;

    }


    if (cheks == false) {

        std::cout << "номер не найден"<<std::endl;
    }

    file5.close();

    filetwo.close();

    std::ifstream filetwo2("filetwo.txt");

    std::ofstream file6("file.txt", std::ios::trunc);

    if (!file6.is_open()) {

        throw std::invalid_argument("не удалось открыть файл");
    }

    while (std::getline(filetwo2, line))
    {
        file6 << line << std::endl;
    }

    filetwo2.close();

    file6.close();



    //Вычислить стоимость всех завершённых ремонтов.



    std::ifstream file7("file.txt");

    if (!file7.is_open()) {

        throw std::invalid_argument("не удалось открыть файл");

    }
    

    double chekprice=0;

    std::cout << "\nсумма всех завершенныйх заказов :" << std::endl;

    while (std::getline(file7, text, ';')) {

        service.number = std::stoi(text);

        std::getline(file7, service.client, ';');
        std::getline(file7, service.device, ';');
        std::getline(file7, service.description, ';');

        std::getline(file7, pricetext, ';');
        service.price = std::stod(pricetext);

        std::getline(file7, service.status);

        if (service.status == "Completed") {
        chekprice += service.price;
        }





    }

    file7.close();


    std::cout << chekprice << std::endl;





    }
    catch (const std::invalid_argument& e) {

        std::cout << "ошибка = " << e.what();
    }
    
  




}


