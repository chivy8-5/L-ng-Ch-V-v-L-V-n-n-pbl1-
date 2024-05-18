#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <map>
#include <iomanip>
using namespace std;

class Sinhvien
{
protected:
    string tensinhvien;
    string masinhvien;
    string email;
    string khoahoc;
    string ngaydangky;
    string trangthai;

public:
    // Constructor
    Sinhvien(string tensinhvien,
            string masinhvien,
            string email,
            string khoahoc,
            string ngaydangky,
            string trangthai)
    {
        this->tensinhvien = tensinhvien;
        this->masinhvien = masinhvien;
        this->email = email;
        this->khoahoc = khoahoc;
        this->ngaydangky = ngaydangky;
        this->trangthai = trangthai;
    }

    Sinhvien()
    {
        tensinhvien = "0";
    }

    void nhapthongtin()
    {
        cin.ignore();
        cout << "1.Nhap ten sinh vien: ";
        getline(cin, tensinhvien);
        cout << "2.Nhap ma sinh vien: ";
        getline(cin, masinhvien);
        cout << "3. Nhap email: ";
        getline(cin, email);
        cout << "4. Nhap khoa hoc mong muon: ";
        getline(cin, khoahoc);
        cout << "5. Nhap ngay dang ky: ";
        getline(cin, ngaydangky);
        cout << "6. Nhap trang thai: ";
        getline(cin, trangthai);
        cin.ignore();
    }

    // Display information
    void xuatthongtin()
    {
        cout << "Ten sinh vien: " << tensinhvien << endl;
        cout << "Ma sinh vien: " << masinhvien << endl;
        cout << "Email: " << email << endl;
        cout << "Khoa hoc: " << khoahoc << endl;
        cout << "Ngay dang ky: " << ngaydangky << endl;
        cout << "trangthai: " << trangthai << endl;
    }

    string getFullInfo()
    {
        string nl = "\n";
        return tensinhvien + nl + masinhvien + nl + email + nl + khoahoc + nl + ngaydangky + nl + trangthai;
    }

    string gettensinhvien()
    {
        return this->tensinhvien;
    }

    string getmasinhvien()
    {
        return this->masinhvien;
    }
};

class TimSinhvien : public Sinhvien
{
public:
    static void Timsinhvienbangten(vector<Sinhvien> &sinhviens)
    {
        string tensinhvien;
        cin.ignore();
        cout << "\nHay nhap ten sinh vien can tim: ";
        getline(cin, tensinhvien);

        for (int i = 0; i < sinhviens.size(); i++)
        {
            if (strcmp(tensinhvien.c_str(), sinhviens[i].gettensinhvien().c_str()) == 0)
            {
                sinhviens[i].xuatthongtin();
            }
        }
        system("pause");
    }

    static void Timsinhvientheomasinhvien(vector<Sinhvien> &sinhviens)
    {
        string masinhvien;
        cin.ignore();
        cout << "\nHay nhap ma sinh vien can tim: ";
        getline(cin, masinhvien);

        for (int i = 0; i < sinhviens.size(); i++)
        {
            if (strcmp(masinhvien.c_str(), sinhviens[i].getmasinhvien().c_str()) == 0)
            {
                sinhviens[i].xuatthongtin();
                system("pause");
            }
        }
    }

    static void capnhatthongtinsinhvien(vector<Sinhvien> &sinhviens)
    {
        string masinhvien;
        cout << "Hay nhap ma sinh vien muon cap nhat thong tin: " << endl;
        cin.ignore();
        getline(cin, masinhvien);
        for (int i = 0; i < sinhviens.size(); i++)
        {
            if (strcmp(masinhvien.c_str(), sinhviens[i].getmasinhvien().c_str()) == 0)
            {
                sinhviens[i].nhapthongtin();
                system("pause");
            }
        }
        system("pause");
    }

    static void Xoathongtinsinhvien(vector<Sinhvien> &sinhviens)
    {
        string masinhvien;
        cout << "Hay nhap ma sinh vien de xoa thong tin: " << endl;
        cin.ignore();
        getline(cin, masinhvien);
        int deleteIndex = -1;
        for (int i = 0; i < sinhviens.size(); i++)
        {
            if (strcmp(masinhvien.c_str(), sinhviens[i].getmasinhvien().c_str()) == 0)
            {
                deleteIndex = i;
                break;
            }
        }
        if (deleteIndex == -1)
            cout << "Khong tim thay thong tin can xoa:" << endl;
        else
        {
            sinhviens.erase(sinhviens.begin() + deleteIndex);
        }
    }
};

// Enter student information
void nhapthongtinsinhvien(vector<Sinhvien> &sinhviens)
{
    Sinhvien x;
    x.nhapthongtin();
    sinhviens.push_back(x);
}

void xuatthongtinsinhvien(vector<Sinhvien> &sinhviens)
{
    for (int i = 0; i < sinhviens.size(); i++)
    {
        cout << "\n\tThong tin sinh vien " << i + 1 << " : ";
        sinhviens[i].xuatthongtin();
    }
    system("pause");
}

// Menu for managing students
void Menusinhvien(vector<Sinhvien> &sinhviens)
{
    int choice;
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t ============= QUAN LY SINH VIEN HOC TIENG ANH TRUC TUYEN =============";
        cout << "\n\t\t1. Nhap thong tin sinh vien";
        cout << "\n\t\t2. Xuat thong tin sinh vien ";
        cout << "\n\t\t3. Tim kiem sinh vien theo ten";
        cout << "\n\t\t4. Tim kiem sinh vien theo ma sinh vien";
        cout << "\n\t\t5. Cap nhat thong tin sinh vien";
        cout << "\n\t\t6. Xoa thong tin sinh vien";
        cout << "\n\t\t7. Thoat va luu";

        cout << "\nVui long nhap lua chon cua ban: ";
        cin >> choice;

        if (choice == 1)
        {
            nhapthongtinsinhvien(sinhviens);
        }
        else if (choice == 2)
        {
            xuatthongtinsinhvien(sinhviens);
        }
        else if (choice == 3)
        {
            TimSinhvien::Timsinhvienbangten(sinhviens);
        }
        else if (choice == 4)
        {
            TimSinhvien::Timsinhvientheomasinhvien(sinhviens);
        }
        else if (choice == 5)
        {
            TimSinhvien::capnhatthongtinsinhvien(sinhviens);
        }
        else if (choice == 6)
        {
            TimSinhvien::Xoathongtinsinhvien(sinhviens);
        }
        else if (choice == 7)
        {
            return;
        }
    }
}

void writeToFile(string file, vector<Sinhvien> &sinhviens)
{
    ofstream fileOutput(file);

    if (fileOutput.fail())
    {
        cout << " Khong the mo file " << file << endl;
        return;
    }
    for (int i = 0; i < sinhviens.size(); i++)
    {
        fileOutput << sinhviens[i].getFullInfo();
        if (i != sinhviens.size() - 1)
            fileOutput << "\n";
    }
}

void readFromFile(string file, vector<Sinhvien> &sinhviens)
{
    ifstream fileInput(file);
    if (fileInput.fail())
    {
        cout << " khong the mo file " << file << endl;
        return;
    }

    while (!fileInput.eof())
    {
        char tensinhvien[255],
            masinhvien[255],
            email[255],
            khoahoc[255],
            ngaydangky[255],
            trangthai[255];

        fileInput.getline(tensinhvien, 255);
        fileInput.getline(masinhvien, 255);
        fileInput.getline(email, 255);
        fileInput.getline(khoahoc, 255);
        fileInput.getline(ngaydangky, 255);
        fileInput.getline(trangthai, 255);
        string ten = tensinhvien, ma = masinhvien, mail = email, kh = khoahoc,
               ndk = ngaydangky,
               tt = trangthai;
        Sinhvien s(ten, ma, mail, kh, ndk, tt);
        sinhviens.push_back(s);
    }
}


class Khoahoc
{
private:
    string tenkhoahoc;
    string giaovien;
    string makhoahoc;
    int thoigian;

public:
    Khoahoc() {}

    Khoahoc(string tenkhoahoc, string giaovien, string makhoahoc, int thoigian)
    {
        this->tenkhoahoc = tenkhoahoc;
        this->giaovien = giaovien;
        this->makhoahoc = makhoahoc;
        this->thoigian = thoigian;
    }

    void xuatthongtinkhoahoc() const
    {
        cout << "\nTen khoa hoc: " << tenkhoahoc;
        cout << "\nGiao vien giang day: " << giaovien;
        cout << "\nMa khoa hoc: " << makhoahoc;
        cout << "\nThoi gian: " << thoigian << endl;
    }

    void readFile(ifstream &infile) {
        getline(infile, tenkhoahoc);
        getline(infile, giaovien);
        getline(infile,  makhoahoc);
        infile >>  thoigian;
        infile.ignore(); // To skip the newline character after duration
    }

    void getInfo()
    {
        cin.ignore();
        cout << "\nHay nhap ten khoa hoc: ";
        getline(cin, tenkhoahoc);
        cout << "\nNhap giao vien: ";
        getline(cin, giaovien);
        cout << "\nHay nhap ma khoa hoc: ";
        getline(cin, makhoahoc);
        cout << "\nHay nhap thoi gian: ";
        cin >> thoigian;
    }

    string gettenkhoahoc() const
    {
        return tenkhoahoc;
    }

    string getgiaovien() const
    {
        return giaovien;
    }

    string getmakhoahoc() const
    {
        return makhoahoc;
    }

    int getthoigian() const
    {
        return thoigian;
    }
};

void readCoursesFromFile(vector<Khoahoc> &khoahocs, string fileName) {
    ifstream infile(fileName);
    if (!infile.is_open()) {
        cout << "Khong the mo file: " << fileName << endl;
        return;
    }

    while (!infile.eof()) {
        Khoahoc khoahoc;
        khoahoc.readFile(infile);
        khoahocs.push_back(khoahoc);
    }

    infile.close();
}

void xuattatcathongtinkhoahoc(const vector<Khoahoc> &khoahocs)
{
    for (int i = 0; i < khoahocs.size(); i++)
    {
        cout << "\n\tThong tin khoa hoc " << i + 1 << " : ";
        khoahocs[i].xuatthongtinkhoahoc();
    }
    system("pause");
}

void nhapthongtinkhoahoc(vector<Khoahoc> &khoahocs)
{
    Khoahoc c;
    c.getInfo();
    khoahocs.push_back(c);
}

class TimKhoahoc : public Khoahoc
{
public:
    static void timkhoahoctheoten(vector<Khoahoc> &khoahocs)
    {
        string tenkhoahoc;
        cin.ignore();
        cout << "\nHay nhap ten khoa hoc can tim: ";
        getline(cin, tenkhoahoc);

        for (int i = 0; i < khoahocs.size(); i++)
        {
            if (strcmp(tenkhoahoc.c_str(), khoahocs[i].gettenkhoahoc().c_str()) == 0)
            {
                khoahocs[i].xuatthongtinkhoahoc();
            }
        }
        system("pause");
    }

    static void timkhoahoctheomakhoahoc(vector<Khoahoc> &khoahocs)
    {
        string makhoahoc;
        cin.ignore();
        cout << "\nHay nhap ma khoa hoc can tim: ";
        getline(cin, makhoahoc);

        for (int i = 0; i < khoahocs.size(); i++)
        {
            if (strcmp(makhoahoc.c_str(), khoahocs[i].getmakhoahoc().c_str()) == 0)
            {
                khoahocs[i].xuatthongtinkhoahoc();
                system("pause");
            }
        }
    }

    static void capnhatthongtinkhoahoc(vector<Khoahoc> &khoahocs)
    {
        string makhoahoc;
        cout << "Hay nhap ma khoa de cap nhat thong tin: " << endl;
        cin.ignore();
        getline(cin, makhoahoc);
        for (int i = 0; i < khoahocs.size(); i++)
        {
            if (strcmp(makhoahoc.c_str(), khoahocs[i].getmakhoahoc().c_str()) == 0)
            {
                khoahocs[i].getInfo();
                system("pause");
            }
        }
        system("pause");
    }

    static void xoathongtinkhoahoc(vector<Khoahoc> &khoahocs)
    {
        string makhoahoc;
        cout << "Hay nhap ma khoa hoc de xoa thong tin: " << endl;
        cin.ignore();
        getline(cin, makhoahoc);
        int deleteIndex = -1;
        for (int i = 0; i < khoahocs.size(); i++)
        {
            if (strcmp(makhoahoc.c_str(), khoahocs[i].getmakhoahoc().c_str()) == 0)
            {
                deleteIndex = i;
                break;
            }
        }
        if (deleteIndex == -1)
            cout << "Khong tim thay thong tin de xoa:" << endl;
        else
        {
            khoahocs.erase(khoahocs.begin() + deleteIndex);
        }
    }
};

// Menu for managing courses
void Menukhoahoc(vector<Khoahoc> &khoahocs)
{
    int choice;
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t ============= QUAN LY KHOA HOC =============";
        cout << "\n\t\t1. Nhap thong tin khoa hoc";
        cout << "\n\t\t2. Xuat thong tin khoa hoc";
        cout << "\n\t\t3. Tim kiem khoa hoc theo ten ";
        cout << "\n\t\t4. Tim kiem khoa hoc theo ma khoa hoc";
        cout << "\n\t\t5. Cap nhat thong tin khoa hoc";
        cout << "\n\t\t6. Xoa thong tin khoa hoc";
        cout << "\n\t\t7. Thoat va luu";

        cout << "\nVui long nhap lua chon cua ban: ";
        cin >> choice;

        if (choice == 1)
        {
            nhapthongtinkhoahoc(khoahocs);
        }
        else if (choice == 2)
        {
            xuattatcathongtinkhoahoc(khoahocs);
        }
        else if (choice == 3)
        {
            TimKhoahoc::timkhoahoctheoten(khoahocs);
        }
        else if (choice == 4)
        {
            TimKhoahoc::timkhoahoctheomakhoahoc(khoahocs);
        }
        else if (choice == 5)
        {
            TimKhoahoc::capnhatthongtinkhoahoc(khoahocs);
        }
        else if (choice == 6)
        {
            TimKhoahoc::xoathongtinkhoahoc(khoahocs);
        }
        else if (choice == 7)
        {
            return;
        }
    }
}

void writeCoursesToFile(string file, vector<Khoahoc> &khoahocs)
{
    ofstream fileOutput(file);

    if (fileOutput.fail())
    {
        cout << " khong the mo file " << file << endl;
        return;
    }
    for (int i = 0; i < khoahocs.size(); i++)
    {
        fileOutput << khoahocs[i].gettenkhoahoc() << "\n";
        fileOutput << khoahocs[i].getgiaovien() << "\n";
        fileOutput << khoahocs[i].getmakhoahoc() << "\n";
        fileOutput << khoahocs[i].getthoigian();
        if (i != khoahocs.size() - 1)
            fileOutput << "\n";
    }
}

// Login and registration functions
string tenTaiKhoan = "";
void Login()
{
    int choice;
    string filetaikhoan = "D:/taikhoan.txt";
    map<string, string> maptk;

    ifstream inputFile(filetaikhoan);
    string key, value;
    while (inputFile >> key >> value)
    {
        maptk.insert(make_pair(key, value));
    }
    inputFile.close();

    while (tenTaiKhoan.length() == 0)
    {
        cout << "----- HOC TIENG ANH TRUC TUYEN -----" << endl;
        cout << "1. Dang nhap" << endl;
        cout << "2. Dang ki" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            string tk, mk;
            cout << "Nhap tai khoan:";
            cin >> tk; // tai khoan

            auto tim = maptk.find(tk);
            if (tim == maptk.end())
            {
                cout << "Tai khoan khong ton tai" << endl;
                break;
            }

            cout << endl
                 << "Nhap mat khau:";
            cin >> mk; // mat khau

            if (maptk[tk] == mk)
            {
                tenTaiKhoan = tk;
                cout << "Dang nhap thanh cong" << endl;

                // Ghi thông tin đăng nhập vào file nếu đăng nhập thành công
                ofstream outputFile(filetaikhoan, ofstream::app);
                outputFile << tk << ' ' << mk << '\n';
                outputFile.close();
            }
            else
            {
                cout << "Dang nhap that bai" << endl;
            }
            break;
        }
        case 2:
        {
            string tk, mk;
            cout << "Dang ki" << endl;
            cout << "Nhap tai khoan:";
            cin >> tk; // tai khoan

            // Kiểm tra xem tài khoản đã tồn tại chưa
            auto tim = maptk.find(tk);
            if (tim != maptk.end())
            {
                cout << "Tai khoan da ton tai" << endl;
                break;
            }

            cout << endl
                 << "Nhap mat khau:";
            cin >> mk; // mat khau

            // Mở file để ghi thông tin tài khoản mới
            ofstream outputFile(filetaikhoan, ofstream::app);
            // Ghi thông tin tài khoản mới vào file
            outputFile << tk << ' ' << mk << '\n';
            outputFile.close();

            // Cập nhật thông tin trong bộ nhớ
            maptk.insert(make_pair(tk, mk));
            tenTaiKhoan = tk;
            cout << "Dang ki thanh cong" << endl;
            break;
        }

       
        }
    }
}

// Main program
int main()
{
    vector<Sinhvien> sinhviens;
    vector<Khoahoc> khoahocs;
    string file;
    file = "sinhviens.txt";
    readFromFile(file, sinhviens);
    file = "khoahocs.txt";
    readCoursesFromFile(khoahocs, file);

    // Login before proceeding
    Login();

    if (tenTaiKhoan.length() > 0)
    {
        int choice;
        while (true)
        {
            system("cls");
            cout << "\n\n\t\t ============= HE THONG QUAN LY HOC TIENG ANH =============";
            cout << "\n\t\t1. Quan ly Khoa Hoc";
            cout << "\n\t\t2. Quan Ly Sinh Vien";
            cout << "\n\t\t3. Thoat";

            cout << "\nVui long nhap lua chon cua ban: ";
            cin >> choice;
            if (choice == 1)
            {
            Menukhoahoc(khoahocs);
            file = "khoahocs.txt";
            writeCoursesToFile(file, khoahocs);
            }
            else if (choice == 2)
            {
            	Menusinhvien(sinhviens);
                file = "sinhviens.txt";
                writeToFile(file, sinhviens);
                
            }
            else if (choice == 3)
            {
                cout << "\nThoat chuong trinh!";
                system("pause");
                return 0;
            }
        }
    }

    return 0;
}
