#include "atm.h"

void screen(string s)
{
    cout << "\n ToanBANK"<< endl
         << "------------------------"
         << "------------------------"
         << "--" << s <<"----"
         << "------------------------"
         << "------------------------"
         << endl << endl;
}

void Dangky()
{
    string id, pass1, pass2;
    screen ("    DANG KY    ");
    cout << "NHAP ID (8 ky tu): ";
    cin >> id;
    cout << "NHAP MAT KHAU(3 ky tu): ";
    cin >> pass1;
    cout << "NHAP LAI MAT KHAU: ";
    cin >> pass2;
    if (pass1 == pass2)
    {
        cout << "TAO TAI KHOAN THANH CONG.";
        ofstream file ("accounts.txt", ios::app);
        file << id << ' ' << pass1 << endl;
        ofstream HistoryFile(id + "_history.txt");
        ofstream MoneyFile (id + "_sodu.txt");
        int x = 0;
        MoneyFile << x;
        sleep(1);
        system ("cls");
    }
    else
    {
        cout << "Mat khau khong trung khop. Vui long dang ky lai.";
        sleep(1);
        system("cls");
        Dangky();
    }
}

bool checkLogin(string ID, string PASS)
{
    ifstream file ("accounts.txt");
    string id, pass;
    while (file >> id >> pass)
    {
        if (ID == id && PASS == pass)
        {
            return true;
            break;
        }
        else continue;
    }
    return false;
}
bool checkAccount(string ID)
{
    ifstream file ("accounts.txt");
    string id, pass;
    while (file >> id >> pass)
    {
        if (ID == id) {return true; break;}
        else continue;
    }
    return false;
}

void LuuBank(int Bank[6][2])
{
    ofstream file ("BANK.txt");
    for (int i = 0; i < 6; i++)
    {
        file << Bank[i][1] << endl;
    }
}
int MinBank(int Bank[6][2])
{
    int Min = 500000;
    for (int i = 5; i >= 0; i--)
    {
        if (Bank[i][0] <= Min && Bank[i][1] != 0) Min = Bank[i][0];
    }
    return Min;
}
void InBank(int Bank[6][2])
{
    cout << "     MENH GIA VA SO TO TRONG ATM" << endl << endl;
    cout << " - 10.000 VND: " << Bank[0][1] << " to." << endl;
    cout << " - 20.000 VND: " << Bank[1][1] << " to." << endl;
    cout << " - 50.000 VND: " << Bank[2][1] << " to." << endl;
    cout << " - 100.000 VND: " << Bank[3][1] << " to." << endl;
    cout << " - 200.000 VND: " << Bank[4][1] << " to." << endl;
    cout << " - 500.000 VND: " << Bank[5][1] << " to." << endl;
}
void Account::Dangnhap(int count)
{
    screen ("    DANG NHAP    ");
    cout << "NHAP ID: ";
    cin >> id;
    cout << "NHAP MAT KHAU: ";
    cin >> pass;
    if (checkLogin(id,pass))
    {
        ifstream file ("accounts.txt");
        string _id, _pass;
        while (file >>_id >> _pass)
        {
            if (id == _id && pass == _pass)
            {
                ifstream MoneyFile (id + "_sodu.txt");
                int n;
                while (MoneyFile >> n) soDu = n;
            }
        }

        cout << "..." << endl;
        sleep(1);
        cout << "Dang nhap thanh cong." << endl;
        sleep(1);
        system ("cls");
        screen ("XIN CHAO QUY KHACH");
    }
    else
    {   count++;
        if (count == 5)
        {
            cout << "Ban da nhap sai mat khau qua so lan quy dinh. Tai khoan cua ban da bi khoa." << endl;
            exit(0);
        }
        else{
            cout << "..." << endl;
            sleep(1);
            cout << "Sai tai khoan hoac mat khau. Vui long dang nhap lai." << endl;

            sleep (1);
            system ("cls");
            Dangnhap(count);
        }
    }
}

void Account::GuiTien(int Bank[6][2])
{
    cout << "Lua chon menh gia va so to ban muon gui (nhan phim 7 de hoan tat):" << endl;
    int choice;
    int tong = soDu;
    do
    {
        cout << "1 - 10.000 VND" << endl
             << "2 - 20.000 VND" << endl
             << "3 - 50.000 VND" << endl
             << "4 - 100.000 VND" << endl
             << "5 - 200.000 VND" << endl
             << "6 - 500.000 VND" << endl
             << "7 - Thoat" << endl;
        cin >> choice;
        switch (choice)
        {
        int soto;
        case 1:
            cout << "So to: ";
            cin >> soto;
            Bank[0][1] += soto;
            soDu += soto*10000;
            cout << "So du trong tai khoan cua ban hien tai la: " << soDu << " VND\n" << endl;
            break;
        case 2:
            cout << "So to: ";
            cin >> soto;
            Bank[1][1] += soto;
            soDu += soto*20000;
            cout << "So du trong tai khoan cua ban hien tai la: " << soDu << " VND\n" << endl;
            break;
        case 3:
            cout << "So to: ";
            cin >> soto;
            Bank[2][1] += soto;
            soDu += soto*50000;
            cout << "So du trong tai khoan cua ban hien tai la: " << soDu << " VND\n" << endl;
            break;
        case 4:
            cout << "So to: ";
            cin >> soto;
            Bank[3][1] += soto;
            soDu += soto*100000;
            cout << "So du trong tai khoan cua ban hien tai la: " << soDu << " VND\n" << endl;
            break;
        case 5:
            cout << "So to: ";
            cin >> soto;
            Bank[4][1] += soto;
            soDu += soto*200000;
            cout << "So du trong tai khoan cua ban hien tai la: " << soDu << " VND\n" << endl;
            break;
        case 6:
            cout << "So to: ";
            cin >> soto;
            Bank[5][1] += soto;
            soDu += soto*500000;
            cout << "So du trong tai khoan cua ban hien tai la: " << soDu << " VND\n" << endl;
            break;
        case 7:
            tong = soDu - tong;

            ofstream Hfile (id + "_history.txt",ios::app);
            time_t now = time(0);
            char* dt = ctime(&now);
            Hfile << "  GUI TIEN                  " << tong << " VND     " << dt << endl;

            LuuSoDu();
            LuuBank(Bank);
        }
    } while (choice != 7);
}
void Account::ChuyenTien()
{
    cout << "So du trong tai khoan cua ban la: " << soDu << " VND" << endl;
    string ID;
    int money;
    cout << "Ban muon chuyen khoan toi ID: ";
    cin >> ID;
    if (!checkAccount(ID))
    {
        cout << "Tai khoan khong ton tai. Vui long kiem tra lai ID" << endl;
        ChuyenTien();
    }
    cout << "So tien chuyen khoan: ";
    cin >> money;
    if (money > soDu)
    {
        cout << "Ban khong du tien" << endl;
        ChuyenTien();
    }
    else{
        sleep(1);
        soDu -= money;
        cout << "CHUYEN KHOAN THANH CONG" << endl
             << "So du cua ban hien tai: " << soDu << " VND" << endl;
        LuuSoDu();

        ifstream file (ID + "_sodu.txt");
        int n;
        file >> n;
        ofstream moneyFile (ID + "_sodu.txt");
        moneyFile << money + n;

        ofstream Hfile (id + "_history.txt",ios::app);
        time_t now = time(0);
        char* dt = ctime(&now);
        Hfile << "CHUYEN TIEN toi " << ID << "    " << money << " VND" << "     " << dt << endl;
    }

}
void Account::LuuSoDu()
{
    ofstream file (id + "_sodu.txt");
    file << soDu;
}
void Account::KTSoDu()
{
    cout << "Tai khoan cua ban hien dang co: " << soDu << " VND" << endl;
}

void Account::RutTien(int Bank[6][2])
{
    int withdraw;
    cout << "So du trong tai khoan: " << soDu << " VND" << endl;
    cout << "So tien nho nhat co the rut(chi duoc rut boi so cua so tien nay): " << MinBank(Bank) << " VND" << endl;
    cout << "Nhap so tien ban muon rut: ";
    cin >> withdraw;
    if (withdraw % MinBank(Bank) != 0)
    {
        cout << "So tien rut phai la boi so cua so tien nho nhat. Vui long chon so tien khac." << endl << endl;
        Account::RutTien(Bank);
    }
    else{
        int w = withdraw;
        cout << "..." << endl;
        sleep (1);
        cout << " So tien ban rut bao gom: " << endl;
        for (int i = 5; i>=0;i--)
        {
            int st = w/Bank[i][0];
            if(st > Bank[i][1]) st = Bank[i][1];
            w = w - st*Bank[i][0];
            Bank[i][1] -= st;
            cout << "+/ " << st << " to " << Bank[i][0] << " VND" << endl;
        }
        soDu -= withdraw;
        LuuSoDu();
        LuuBank(Bank);

        ofstream Hfile (id + "_history.txt",ios::app);
        time_t now = time(0);
        char* dt = ctime(&now);
        Hfile << "  RUT TIEN                  " << withdraw << " VND     " << dt << endl;
    }
}

void Account::LichSu()
{
    cout << "          LICH SU GIAO DICH" << endl << endl;
    cout << "  HOAT DONG" << "                  SO TIEN" << "     THOI GIAN" << endl;
    ifstream Hfile (id +"_history.txt");
    while (!Hfile.eof())
    {
        char temp[255];
        Hfile.getline(temp, 255);
        string line = temp;
        cout << line << endl;
    }
}
