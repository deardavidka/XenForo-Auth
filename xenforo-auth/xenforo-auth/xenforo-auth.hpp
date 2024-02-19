#pragma once

#include "json.hpp"
#include "wnetwrap.h"
#include <Windows.h>
#include <winhttp.h>
#include <iostream>

#pragma comment(lib, "winhttp.lib")


using namespace std;
using json = nlohmann::json;


class auth_vars {
public:
    string temp;
    json data;
    bool success = false;
    wrap::Response r;
    void set_url(string set) { this->api_url = set; temp.clear(); }
    string get_url() { return this->api_url; }
    void set_key(string set) { this->api_key = set; temp.clear(); }
    string get_key() { return this->api_key; }
    void set_username(string set) { this->username = set; temp.clear(); }
    string get_username() { return this->username; }
    void set_password(string set) { this->password = set; temp.clear(); }
    string get_password() { return this->password; }

private:
    string api_url = "https://xenforo_auth.ru/index.php/api/auth";
    string api_key = "XXxX1XXxXXXxX1xXxxxX-XXX1xXXxXX11";
    string username = "DeArDaVidKa";
    string password = "SuPeRmEgApAsSwOrD";
}var;

class auth_triks {
public:
    void cls() { system("cls"); Sleep(200); }
    void auth() {
        std::cout << "\n\n    Enter API url (like: " << var.get_url() << ").\n    >\\  ";
        std::cin >> var.temp;
        var.set_url(var.temp); this->cls();

        std::cout << "\n\n    Enter API key (like: " << var.get_key() << ").\n    >\\  ";
        std::cin >> var.temp;
        var.set_key(var.temp); this->cls();

        std::cout << "\n\n    Enter username (like: " << var.get_username() << ").\n    >\\  ";
        std::cin >> var.temp;
        var.set_username(var.temp); this->cls();

        std::cout << "\n\n    Enter password (like: " << var.get_password() << ").\n    >\\  ";
        std::cin >> var.temp;
        var.set_password(var.temp); this->cls();
        std::cin.get();
        Sleep(100); std::cout << "\n\n    Wait...";
    }
    void request() {
        try {
            var.r = wrap::HttpsRequest(wrap::Url{ var.get_url() },
                wrap::Header{ {"Content-Type", "application/x-www-form-urlencoded"}, { "XF-Api-Key", var.get_key()} },
                wrap::Body{ "&login=" + var.get_username() + "&password=" + var.get_password() },
                wrap::Method{ "POST" }
            );
        }
        catch (const std::exception& e1) {
            std::cerr << "\n\n    Request failed, error:\n    " << e1.what() << "\n\n    Press any key for get the fuck out" << std::endl;
            system("pause");
            exit(0);
        }

    }
    void parse() {
        try {
            this->cls();
            var.data = json::parse(var.r.text);
            cout << var.r.text << "\n\n\n" << endl;
            var.success = var.data["success"]; //can be removed
        }
        catch (const exception& e2) {
            cout << "\n\n    Parse failed, error:\n" << e2.what() << "\n\n    Press any key for get the fuck out" << endl;
            system("pause");
            exit(0);
        }

    }
    void parse_selfdata() {
        if (var.success) {
            cout << "user_name: " << var.data["user"]["username"] << endl;
            cout << "user_id: " << var.data["user"]["user_id"] << endl;
            cout << "is_admin: " << var.data["user"]["is_admin"] << endl;
            cout << "profile_url: " << var.data["user"]["view_url"] << endl;
            cout << "avatar_url: " << var.data["user"]["avatar_urls"]["m"] << endl;
        }
        else {
            std::cout << "\n\n    Invalid login or password\n" << "\n\n    Press any key for get the fuck out" << std::endl;
        }
    }
}trik;



