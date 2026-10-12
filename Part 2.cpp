#include <iostream>
#include <string>
using namespace std;

// ---------- Node design ----------
struct PatientNode
{
    int patientID;
    string patientName;
    string condition;
    int priority;          // 1 = Critical, 2 = Serious, 3 = Minor
    PatientNode* next;
};

// ---------- Priority Queue ----------
class PatientPriorityQueue
{
private:
    PatientNode* front;
    PatientNode* rear;
    int count;

public:
    PatientPriorityQueue() : front(nullptr), rear(nullptr), count(0) {}

    // Add according to priority (FIFO among equal priorities)
    void Add(PatientNode* patient)
    {
        patient->next = nullptr;

        if (front == nullptr)
        {
            front = rear = patient;
        }
        else if (patient->priority < front->priority)
        {
            patient->next = front;
            front = patient;
        }
        else
        {
            PatientNode* current = front;
            while (current->next != nullptr &&
                   current->next->priority <= patient->priority)
            {
                current = current->next;
            }
            patient->next = current->next;
            current->next = patient;

            if (patient->next == nullptr)
                rear = patient;
        }
        count++;
    }

    // Remove highest-priority patient
    PatientNode* Remove()
    {
        if (front == nullptr) return nullptr;

        PatientNode* patient = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;

        patient->next = nullptr;
        count--;
        return patient;
    }

    // Supporting operations
    bool IsEmpty()    { return front == nullptr; }
    bool IsNotEmpty() { return front != nullptr; }
    int  Size()       { return count; }

    PatientNode* Peek() { return front; }   // view next patient without removing

    void PrintQueue()
    {
        PatientNode* current = front;
        while (current != nullptr)
        {
            cout << "ID: " << current->patientID
                 << " | Name: " << current->patientName
                 << " | Condition: " << current->condition
                 << " | Priority: " << current->priority << endl;
            current = current->next;
        }
    }

    // Copy constructor
    PatientPriorityQueue(const PatientPriorityQueue& other)
        : front(nullptr), rear(nullptr), count(0)
    {
        for (PatientNode* c = other.front; c != nullptr; c = c->next)
        {
            PatientNode* n = new PatientNode(*c);
            Add(n);
        }
    }

    // Assignment operator
    PatientPriorityQueue& operator=(const PatientPriorityQueue& other)
    {
        if (this == &other) return *this;

        while (front != nullptr)
        {
            PatientNode* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
        count = 0;

        for (PatientNode* c = other.front; c != nullptr; c = c->next)
        {
            PatientNode* n = new PatientNode(*c);
            Add(n);
        }
        return *this;
    }

    // Destructor
    ~PatientPriorityQueue()
    {
        while (front != nullptr)
        {
            PatientNode* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }
};

PatientNode* CreatePatient(int id, string name, string condition, int priority)
{
    PatientNode* p = new PatientNode;
    p->patientID = id;
    p->patientName = name;
    p->condition = condition;
    p->priority = priority;
    p->next = nullptr;
    return p;
}

// ---------- Demonstration with project data ----------
int main()
{
    PatientPriorityQueue er;

    er.Add(CreatePatient(1, "Usman",  "Sprained ankle",  3));
    er.Add(CreatePatient(2, "Sara",   "Heart attack",    1));
    er.Add(CreatePatient(3, "Hina",   "Broken arm",      2));
    er.Add(CreatePatient(4, "Zain",   "Severe bleeding", 1));

    cout << "===== Waiting Patients =====" << endl;
    er.PrintQueue();

    cout << "\n===== Treating Next Patient =====" << endl;
    PatientNode* treated = er.Remove();
    if (treated != nullptr)
    {
        cout << treated->patientName << " (" << treated->condition
             << ") - Priority " << treated->priority << endl;
        delete treated;
    }

    cout << "\n===== Remaining Patients =====" << endl;
    er.PrintQueue();

    return 0;
}
