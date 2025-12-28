#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Student {
private:
    long long EnrollmentNo;
    string Name;
    string Branch;
    float Cgpa;

public:
    Student() {}
    long long getRoll() const { return EnrollmentNo; }
    float getCGPA() const { return Cgpa; }
    string getName() const { return Name; }

    void display() const {
        cout << EnrollmentNo << " " << Name << " (" << Branch << ") " << Cgpa << endl;
    }
    
    friend istream& operator>>(istream& in, Student& s) {
        string line;
        if (!getline(in, line) || line.empty())
            return in;
        
        int i = 0;
        string rollStr = "";
        while (i < line.size() && line[i] != ' ') {
            rollStr += line[i++];
        }
        s.EnrollmentNo = stoll(rollStr);

        int open = line.find('(');
        int close = line.find(')');
        s.Branch = line.substr(open + 1, close - open - 1);
        s.Name = line.substr(i + 1, open - i - 2);     
        string cgpaStr = line.substr(close + 2);
        s.Cgpa = stof(cgpaStr);
        return in;
    }
};

class StudentManager {
private:
    vector<Student> students;
    const string filename = "students.txt";
public:
    StudentManager() { loadFromFile(); }
    void loadFromFile() {
        ifstream file(filename);
        Student s;
        while (file >> s)
            students.push_back(s);
        file.close();
    }
    void viewStudents() const {
        for (int i = 0; i < students.size(); i++)
            students[i].display();
    }
    void sortByCGPA() const {
        vector<Student> temp = students;
        bubbleSort(temp);
        cout << "\n<--- SORTED BY CGPA (HIGH to LOW) --->\n";
        for (int i = 0; i < temp.size(); i++)
            temp[i].display();
    }
    void departmentRank() const {
        vector<Student> temp = students;
        bubbleSort(temp);
        cout << "\n<--- DEPARTMENT RANK (MECHANICAL) --->\n";
        for (int i = 0; i < temp.size(); i++) {
            cout << "Rank " << i + 1 << ": ";
            temp[i].display();
        }
    }
    void studentsAboveCGPA() const {
        float x;
        cout << "Enter CGPA threshold: ";
        cin >> x;
        bool found = false;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getCGPA() >= x) {
                students[i].display();
                found = true;
            }
        }
        if (!found) cout << "No students found.\n";
    }
    void countAboveCGPA() const {
        float x;
        cout << "Enter CGPA threshold: ";
        cin >> x;
        int count = 0;
        for (int i = 0; i < students.size(); i++)
            if (students[i].getCGPA() >= x)
                count++;
        cout << "Count: " << count << endl;
    }
    void averageCGPA() const {
        float sum = 0;
        for (int i = 0; i < students.size(); i++)
            sum += students[i].getCGPA();
        cout << "Average CGPA: " << sum / students.size() << endl;
    }
    void topNStudents() const {
        int N;
        cout << "Enter N : ";
        cin >> N;
        if (N <= 0 || N > students.size()) {
            cout << "Invalid N\n";
            return;
        }
        vector<Student> temp = students;
        bubbleSort(temp);
        cout << "\n<--- TOP " << N << " STUDENTS --->\n";
        for (int i = 0; i < N; i++)
            temp[i].display();
    }
    void searchByName() const {
        cin.ignore();
        string key;
        cout << "Enter Full Name: ";
        getline(cin, key);
        bool found = false;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getName().find(key) != string::npos) {
                students[i].display();
                found = true;
            }
        }
        if (!found) cout << "Oops, No matching student found.\n";
    }
    void gradeDistribution() const {
        int ex = 0, vg = 0, g = 0, avg = 0, prob = 0;
        for (int i = 0; i < students.size(); i++) {
            float c = students[i].getCGPA();
            if (c >= 9.0) ex++;
            else if (c >= 8.0) vg++;
            else if (c >= 7.0) g++;
            else if (c >= 6.0) avg++;
            else prob++;
        }
        cout << "\n<--- GRADE DISTRIBUTION --->\n";
        cout << "Excellent [A+] (>=9.0): " << ex << endl;
        cout << "Very Good [B+] (8-9): " << vg << endl;
        cout << "Good [B] (7-8): " << g << endl;
        cout << "Average [C+] (6-7): " << avg << endl;
        cout << "Probation (<6): " << prob << endl;
    }
    void probationList() const {
        cout << "\n<--- PROBATION LIST --->\n";
        bool found = false;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getCGPA() < 6.0) {
                students[i].display();
                found = true;
            }
        }
        if (!found) cout << "No students on probation.\n";
    }
    void placementEligibility() const {
        long long r;
        cout << "Enter Enrollment Number: ";
        cin >> r;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getRoll() == r) {
                if (students[i].getCGPA() >= 7.0)
                    cout << "Placement Eligible: YES\n";
                else
                    cout << "Placement Eligible: NO\n";
                return;
            }
        }
        cout << "Student not found.\n";
    }
    void menu() {
        int choice;
        do {
            cout << "\n<===== IIT ROORKEE STUDENTS MANAGEMENT SYSTEM =====>\n";
            cout << "1. View List of Students\n";
            cout << "2. Sort List by CGPA\n";
            cout << "3. Students Above CGPA\n";
            cout << "4. Count of Students Above CGPA\n";
            cout << "5. Average CGPA\n";
            cout << "6. Top N Students\n";
            cout << "7. Search by Student Name\n";
            cout << "8. Department Rankwise List\n";
            cout << "9. Grade Distribution\n";
            cout << "10. Probation List\n";
            cout << "11. Placement Eligibility\n";
            cout << "12. Close\n";
            cout << "Enter choice Number: ";
            cin >> choice;

            switch (choice) {
                case 1: viewStudents(); break;
                case 2: sortByCGPA(); break;
                case 3: studentsAboveCGPA(); break;
                case 4: countAboveCGPA(); break;
                case 5: averageCGPA(); break;
                case 6: topNStudents(); break;
                case 7: searchByName(); break;
                case 8: departmentRank(); break;
                case 9: gradeDistribution(); break;
                case 10: probationList(); break;
                case 11: placementEligibility(); break;
                case 12: cout << "Closing\n"; break;
                default: cout << "Invalid choice\n";
            }
        } while (choice != 12);
    }
private:
    static void bubbleSort(vector<Student>& v) {
        for (int i = 0; i < v.size() - 1; i++)
            for (int j = 0; j < v.size() - i - 1; j++)
                if (v[j].getCGPA() < v[j + 1].getCGPA()) {
                    Student t = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = t;
                }
    }
};
int main() {
    StudentManager manager;
    manager.menu();
    return 0;
}
// THANK YOU :)