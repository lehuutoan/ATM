#include "atm.h"

int main()
{
    // Dang ky hoac dang nhap
    screen ("    DANG NHAP    ");
    cout << "  1 - Dang nhap." << endl;
    cout << "  2 - Dang ky neu ban chua co tai khoan." << endl;
    int choice;
    cin >> choice;
    if (choice == 1) system("cls");
    if (choice == 2)
    {
        system ("cls");
        Dangky();
    }
    // Khoi tao bien account, tien hanh Dang nhap
    Account a;
    a.Dangnhap(0);
    // Tao 1 mang gom 6 dong 2 cot, cot 1 luu cac menh gia, cot 2 luu so to
    int Bank[6][2];
    Bank[0][0] = 10000;
    Bank[1][0] = 20000;
    Bank[2][0] = 50000;
    Bank[3][0] = 100000;
    Bank[4][0] = 200000;
    Bank[5][0] = 500000;
    ifstream file("BANK.txt"); // so to duoc luu vao file, doc lai so to vao mang
    int soto;
    int i = 0;
    while (file >> soto)
    {
        Bank[i][1] = soto;
        i++;
    }

    int num;
    while(1)
    {
        cout << "------------------------------------------------------------"
             << "------------------------------------------------------------" << endl;
        cout << "     1 - Gui tien" << endl
             << "     2 - Rut tien" << endl
             << "     3 - Chuyen tien" << endl
             << "     4 - Kiem tra tai khoan" << endl
             << "     5 - Xem lich su" << endl
             << "     6 - Xem so luong cac to tien trong ATM" << endl
             << "     7 - Rut the" << endl << endl;
        cin >> num;
        switch (num)
        {
        case 1:
            system("cls");
            a.GuiTien(Bank);
            break;
        case 2:
            system("cls");
            a.RutTien(Bank);
            break;
        case 3:
            system("cls");
            a.ChuyenTien();
            break;
        case 4:
            system("cls");
            a.KTSoDu();
            break;
        case 5:
            system("cls");
            a.LichSu();
            break;
            break;
        case 6:
            system("cls");
            InBank(Bank);
            break;
        case 7:
            exit(0);
            break;
        default:
            cout << "Lua chon khong phu hop. Vui long lua chon lai." << endl;
        }
    }
}
