#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Manager {
public:
    virtual void display() = 0;
    virtual void add() = 0;
    virtual void remove() = 0;
    virtual void update() = 0;
    virtual ~Manager() {}
};

class ClassRoomManager : public Manager {
private:
    struct ClassRoom {
        string id;
        string name;
        string major;
        string type; 
    };

    vector<ClassRoom> classes;

public:

    ClassRoomManager() {
        ClassRoom c1;
        c1.id = "ID01";
        c1.name = "Lop Cong nghe thong tin 7";
        c1.major = "Cong nghe thong tin";
        c1.type = "CNTT";
        classes.push_back(c1);

        ClassRoom c2;
        c2.id = "ID02";
        c2.name = "Lop Cong nghe thong tin 8";
        c2.major = "Cong nghe thong tin";
        c2.type = "CNTT";
        classes.push_back(c2);

        ClassRoom c3;
        c3.id = "ID03";
        c3.name = "Lop Ngoai ngu 1";
        c3.major = "Ngoai ngu";
        c3.type = "Ngoai ngu";
        classes.push_back(c3);

        ClassRoom c4;
        c4.id = "ID04";
        c4.name = "Lop Ngoai ngu 2";
        c4.major = "Ngoai ngu";
        c4.type = "Ngoai ngu";
        classes.push_back(c4);

        ClassRoom c5;
        c5.id = "ID05";
        c5.name = "Lop Cong nghe thong tin 3";
        c5.major = "Cong nghe thong tin";
        c5.type = "CNTT";
        classes.push_back(c5);
    }

    void display() {
        cout << "\n";
        cout << "+-------------------------------------------------------------------------------------+\n";
        cout << "|                                  DANH SACH LOP HOC                                  |\n";
        cout << "+--------+----------------------------------+--------------------------+--------------+\n";
        cout << "| Ma lop | Ten lop                          | Chuyen nganh             | Phan loai    |\n";
        cout << "+--------+----------------------------------+--------------------------+--------------+\n";
        
        if (classes.empty()) {
            cout << "|                                    Danh sach rong!                                  |\n";
            cout << "+----------------------------------------------------------------------------------------+\n";
            return;
        }
        
        for (size_t i = 0; i < classes.size(); i++) {
            cout << "| " << classes[i].id;
            for (int j = classes[i].id.length(); j < 6; j++) cout << " ";
            
            cout << " | " << classes[i].name;
            for (int j = classes[i].name.length(); j < 32; j++) cout << " ";
            
            cout << " | " << classes[i].major;
            for (int j = classes[i].major.length(); j < 24; j++) cout << " ";
            
            cout << " | " << classes[i].type;

            for (int j = classes[i].type.length(); j < 12; j++) cout << " ";
            
            cout << " |\n";
        }
        cout << "+--------+----------------------------------+--------------------------+--------------+\n";
        cout << "Tong so: " << classes.size() << " lop hoc\n";
    }

    void add() {
        ClassRoom c;
        cout << "Ma lop: "; getline(cin, c.id);
        cout << "Ten lop: "; getline(cin, c.name);
        cout << "Chuyen nganh: "; getline(cin, c.major);
        cout << "Phan loai (CNTT / Ngoai ngu): "; getline(cin, c.type);
        classes.push_back(c);
        cout << "Them lop thanh cong!\n";
    }

    void remove() {
        string id;
        cout << "Nhap Ma Lop can xoa: ";
        getline(cin, id);

        for (size_t i = 0; i < classes.size(); i++) {
            if (classes[i].id == id) {
                classes.erase(classes.begin() + i);
                cout << "Da xoa thanh cong!\n";
                return;
            }
        }
        cout << "Khong tim thay lop!\n";
    }

    void update() {
        string id;
        cout << "Nhap ma lop can cap nhat: ";
        getline(cin, id);

        for (size_t i = 0; i < classes.size(); i++) {
            if (classes[i].id == id) {
                cout << "Ten moi: "; getline(cin, classes[i].name);
                cout << "Chuyen nganh moi: "; getline(cin, classes[i].major);
                cout << "Phan loai moi: "; getline(cin, classes[i].type);
                cout << "Cap nhat thanh cong!\n";
                return;
            }
        }
        cout << "Khong tim thay lop!\n";
    }
};

class StudentManager : public Manager {
private:
    struct Student {
        string id;
        string name;
        string birth;
        string email;
        string phone;
    };

    vector<Student> students;

public:
    StudentManager() {
        Student s1;
        s1.id = "SV01";
        s1.name = "Nguyen Tuan M";
        s1.birth = "29/01/2007";
        s1.email = "nguyentuanM@email.com";
        s1.phone = "0123456789";
        students.push_back(s1);

        Student s2;
        s2.id = "SV02";
        s2.name = "Nguyen Thi Nhi T";
        s2.birth = "25/08/2008";
        s2.email = "nguyenthinhiT@email.com";
        s2.phone = "0987654321";
        students.push_back(s2);

        Student s3;
        s3.id = "SV03";
        s3.name = "Le Van L";
        s3.birth = "10/12/2007";
        s3.email = "levanL@email.com";
        s3.phone = "0111222333";
        students.push_back(s3);

        Student s4;
        s4.id = "SV04";
        s4.name = "Pham Thi Minh N";
        s4.birth = "25/03/2007";
        s4.email = "phamthiminhN@email.com";
        s4.phone = "0444555666";
        students.push_back(s4);

        Student s5;
        s5.id = "SV05";
        s5.name = "Lo Vi S";
        s5.birth = "05/07/2007";
        s5.email = "loviS@email.com";
        s5.phone = "0777888999";
        students.push_back(s5);
    }

    void display() {
        cout << "\n";
        cout << "+------------------------------------------------------------------------------------------------+\n";
        cout << "|                                        DANH SACH SINH VIEN                                     |\n";
        cout << "+--------+----------------------+------------+----------------------------------+----------------+\n";
        cout << "| Ma SV  | Ten SV               | Ngay sinh  | Email                            | So DT          |\n";
        cout << "+--------+----------------------+------------+----------------------------------+----------------+\n";
        
        if (students.empty()) {
            cout << "|                                                      Danh sach rong!                                              |\n";
            cout << "+------------------------------------------------------------------------------------------------------------------------+\n";
            return;
        }
        
        for (size_t i = 0; i < students.size(); i++) {
            cout << "| " << students[i].id;
            for (int j = students[i].id.length(); j < 6; j++) cout << " ";
            
            cout << " | " << students[i].name;
            for (int j = students[i].name.length(); j < 20; j++) cout << " ";
            
            cout << " | " << students[i].birth;
            for (int j = students[i].birth.length(); j < 10; j++) cout << " ";
            
            cout << " | " << students[i].email;
            for (int j = students[i].email.length(); j < 32; j++) cout << " ";
            
            cout << " | " << students[i].phone;
            for (int j = students[i].phone.length(); j < 14; j++) cout << " ";
            
            cout << " |\n";
        }
        cout << "+--------+----------------------+------------+----------------------------------+----------------+\n";
        cout << "Tong so: " << students.size() << " sinh vien\n";
    }

    void add() {
        Student s;
        cout << "Ma SV: "; getline(cin, s.id);
        cout << "Ten SV: "; getline(cin, s.name);
        cout << "Ngay sinh: "; getline(cin, s.birth);
        cout << "Email: "; getline(cin, s.email);
        cout << "So dien thoai: "; getline(cin, s.phone);
        students.push_back(s);
        cout << "Them sinh vien thanh cong!\n";
    }

    void remove() {
        string id;
        cout << "Nhap ma SV can xoa: ";
        getline(cin, id);

        for (size_t i = 0; i < students.size(); i++) {
            if (students[i].id == id) {
                students.erase(students.begin() + i);
                cout << "Da xoa sinh vien!\n";
                return;
            }
        }
        cout << "Khong tim thay sinh vien!\n";
    }

    void update() {
        string id;
        cout << "Nhap ma SV can cap nhat: ";
        getline(cin, id);

        for (size_t i = 0; i < students.size(); i++) {
            if (students[i].id == id) {
                cout << "Ten moi: "; getline(cin, students[i].name);
                cout << "Ngay sinh moi: "; getline(cin, students[i].birth);
                cout << "Email moi: "; getline(cin, students[i].email);
                cout << "So dien thoai moi: "; getline(cin, students[i].phone);
                cout << "Cap nhat thanh cong!\n";
                return;
            }
        }
        cout << "Khong tim thay sinh vien!\n";
    }
};

void subMenu(Manager* manager) {
    int choice;
    do {
    	cout << "\n--------MENU-------"; 
        cout << "\n|1. Hien thi      |\n";
        cout << "+-----------------+\n"; 
        cout << "|2. Them moi      |\n";
        cout << "+-----------------+\n"; 
        cout << "|3. Xoa           |\n";
        cout << "+-----------------+\n"; 
        cout << "|4. Cap nhat      |\n";
        cout << "+-----------------+\n"; 
        cout << "|0. Quay lai      |\n";
        cout << "-------------------\n"; 
        cout << "Chon chuc nang: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: manager->display(); break;
            case 2: manager->add(); break;
            case 3: manager->remove(); break;
            case 4: manager->update(); break;
        }
    } while (choice != 0);
}

int main() {
    Manager* classManager = new ClassRoomManager();  
    Manager* studentManager = new StudentManager();  

    int choice;
    do {
    	cout << "+-------------------------------------+";
        cout << "\n|     HE THONG QUAN LY RIKKEI EDU     |\n";
        cout << "+-------------------------------------+\n"; 
        cout << "|1. Quan ly lop hoc                   |\n";
        cout << "+-------------------------------------+\n"; 
        cout << "|2. Quan ly sinh vien                 |\n";
        cout << "+-------------------------------------+\n"; 
        cout << "|0. Thoat                             |\n";
        cout << "+-------------------------------------+\n"; 
        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            subMenu(classManager);
        } else if (choice == 2) {
            subMenu(studentManager);
        }
    } while (choice != 0);

    delete classManager;
    delete studentManager;
    return 0;
}
