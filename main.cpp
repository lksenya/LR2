#include <iostream>
#include <cctype>
#include <locale>
#include "modAlphaCipher.h"
#include <codecvt>
#include <typeinfo>

using namespace std;

void check(const wstring& Text, const wstring& key, const bool destructCipherText=false)
{
    try {
        wstring cipherText;
        wstring decryptedText;
        modAlphaCipher cipher(key);
        cipherText = cipher.encrypt(Text); 
        if (destructCipherText) 
            cipherText.front() = tolower(cipherText.front()); 
        decryptedText = cipher.decrypt(cipherText);
        wcout<<L"KYE: "<<key<<endl;
        wcout<<Text<<endl;
        wcout<<cipherText<<endl;
        wcout<<decryptedText<<endl;
    } catch (const cipher_error & e) {
        wcerr<<"ERROR: "<<e.what()<<endl;
    }
}

int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    check(L"ПРИВЕТМИР",L"ПРИВЕТ");
    check(L"ПРИВЕТМИР",L"");
    check(L"ПРИВЕТМИР",L"ПРИВЕТ!2%");
    check(L"!2%",L"ПРИВЕТ");
}
