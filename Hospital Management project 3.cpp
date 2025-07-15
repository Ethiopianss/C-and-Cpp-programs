#include <iostream>
#include <string>
#include <limits>

using namespace std;


struct Patient {
    int id;
    string name;
    int age;
    string disease;
    Patient* next;
};

struct Doctor {
    int id;
    string name;
    string specialization;
    Doctor* prev;
    Doctor* next;
};

struct Appointment {
    int patientID;
    string date;
    Appointment* next;
};


Patient* patientHead = NULL;
Doctor* doctorHead = NULL;
Appointment* appointmentFront = NULL;
Appointment* appointmentRear = NULL;


void addPatient();
void viewPatients();
void addDoctor();
void viewDoctors();
void bookAppointment();
void viewAppointments();
void mainMenu();
bool patientExists(int id);
void shutdown();


int main() {
    mainMenu();
    shutdown();
    return 0;
}


void addPatient() {
    Patient* newPatient = new Patient();
    cout << "Enter Patient ID: ";
    while (!(cin >> newPatient->id)) {
        cout << "Invalid input. Please enter a number for Patient ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    Patient* temp_check = patientHead;
    while (temp_check != NULL) {
        if (temp_check->id == newPatient->id) {
            cout << "Patient with this ID already exists.\n";
            delete newPatient;
            return;
        }
        temp_check = temp_check->next;
    }

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, newPatient->name);
    cout << "Enter Age: ";
    while (!(cin >> newPatient->age)) {
        cout << "Invalid input. Please enter a number for Age: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore();
    cout << "Enter Disease: ";
    getline(cin, newPatient->disease);
    newPatient->next = NULL;

    if (patientHead == NULL)
        patientHead = newPatient;
    else {
        Patient* temp = patientHead;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newPatient;
    }
    cout << "Patient added successfully!\n";
}

void viewPatients() {
    Patient* temp = patientHead;
    if (!temp) {
        cout << "No patients found.\n";
        return;
    }
    cout << "Patient Records:\n";
    while (temp) {
        cout << "ID: " << temp->id << ", Name: " << temp->name
             << ", Age: " << temp->age << ", Disease: " << temp->disease << "\n";
        temp = temp->next;
    }
}

void addDoctor() {
    Doctor* newDoc = new Doctor();
    cout << "Enter Doctor ID: ";
    while (!(cin >> newDoc->id)) {
        cout << "Invalid input. Please enter a number for Doctor ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    Doctor* temp_check = doctorHead;
    while (temp_check != NULL) {
        if (temp_check->id == newDoc->id) {
            cout << "Doctor with this ID already exists.\n";
            delete newDoc;
            return;
        }
        temp_check = temp_check->next;
    }

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, newDoc->name);
    cout << "Enter Specialization: ";
    getline(cin, newDoc->specialization);
    newDoc->next = newDoc->prev = NULL;

    if (!doctorHead)
        doctorHead = newDoc;
    else {
        Doctor* temp = doctorHead;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newDoc;
        newDoc->prev = temp;
    }
    cout << "Doctor added successfully!\n";
}

void viewDoctors() {
    Doctor* temp = doctorHead;
    if (!temp) {
        cout << "No doctors found.\n";
        return;
    }
    cout << "Doctor Records:\n";
    while (temp) {
        cout << "ID: " << temp->id << ", Name: " << temp->name
             << ", Specialization: " << temp->specialization << "\n";
        temp = temp->next;
    }
}

void bookAppointment() {
    Appointment* newApp = new Appointment();
    cout << "Enter Patient ID: ";
    while (!(cin >> newApp->patientID)) {
        cout << "Invalid input. Please enter a number for Patient ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (!patientExists(newApp->patientID)) {
        cout << "Patient with ID " << newApp->patientID << " not found.\n";
        delete newApp;
        return;
    }

    cin.ignore();
    cout << "Enter Appointment Date (YYYY-MM-DD): ";
    getline(cin, newApp->date);
    newApp->next = NULL;

    if (!appointmentFront) {
        appointmentFront = appointmentRear = newApp;
    } else {
        appointmentRear->next = newApp;
        appointmentRear = newApp;
    }
    cout << "Appointment booked successfully!\n";
}

void viewAppointments() {
    Appointment* temp = appointmentFront;
    if (!temp) {
        cout << "No appointments found.\n";
        return;
    }
    cout << "Appointments:\n";
    while (temp) {
        cout << "Patient ID: " << temp->patientID
             << ", Date: " << temp->date << "\n";
        temp = temp->next;
    }
}

void mainMenu() {
    int choice;
    do {
        cout << "\nHOSPITAL MANAGEMENT SYSTEM\n";
        cout << "1. Add Patient\n";
        cout << "2. View Patients\n";
        cout << "3. Add Doctor\n";
        cout << "4. View Doctors\n";
        cout << "5. Book Appointment\n";
        cout << "6. View Appointments\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        while (!(cin >> choice)) {
            cout << "Invalid choice! Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter your choice: ";
        }
        switch (choice) {
            case 1: addPatient(); break;
            case 2: viewPatients(); break;
            case 3: addDoctor(); break;
            case 4: viewDoctors(); break;
            case 5: bookAppointment(); break;
            case 6: viewAppointments(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n"; break;
        }
    } while (choice != 0);
}

bool patientExists(int id) {
    Patient* temp = patientHead;
    while (temp != NULL) {
        if (temp->id == id) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void shutdown() {
    cout << "Freeing all allocated memory...\n";

    // Free patients
    Patient* patientTemp = patientHead;
    while (patientTemp != NULL) {
        Patient* next = patientTemp->next;
        delete patientTemp;
        patientTemp = next;
    }

    // Free doctors
    Doctor* doctorTemp = doctorHead;
    while (doctorTemp != NULL) {
        Doctor* next = doctorTemp->next;
        delete doctorTemp;
        doctorTemp = next;
    }

    // Free appointments
    Appointment* appointmentTemp = appointmentFront;
    while (appointmentTemp != NULL) {
        Appointment* next = appointmentTemp->next;
        delete appointmentTemp;
        appointmentTemp = next;
    }

    cout << "Shutdown complete.\n";
}


