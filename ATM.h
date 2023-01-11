#ifndef ATM_H
#define ATM_H

// ATM_H
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <ctime>
using namespace std;

class Account{
private:
    string id;
    string pass;
    int soDu;
public:
    void Dangnhap(int count);// count la bien dem so lan dang nhap sai de khoa the
    void LuuSoDu(); // Luu so du vao file sau moi lan thuc hien cac thao tac
    void GuiTien(int Bank[6][2]);
    void KTSoDu();
    void ChuyenTien();
    void RutTien(int Bank [6][2]);
    void LichSu();
    void DoiPass();
};
void Dangky();
void screen (string s); // IN MAN HINH
bool checkLogin(string ID, string PASS); // Kiem tra ID, pass khi dang nhap
bool checkAccount(string ID); // KT tai khoan co ton tai hay khong
void LuuBank(int Bank[6][2]); // Luu so to tien vao file
void InBank(int Bank[6][2]);

#endif
