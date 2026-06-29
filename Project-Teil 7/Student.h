//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

class Student
{
public:
    Student();
    Student(unsigned int matNr, std::string name, std::string geburtstag, std::string address);
    unsigned int getMatNr() const;
    std::string getName() const;
    std::string getGeburtstag() const;
    std::string getAdresse() const;
    bool operator == (const Student& student);
    bool operator < (const Student& student);
    bool operator > (const Student& student);
    void ausgabe(std::ostream& out) const;
private:
    unsigned int matNr;
    std::string name;
    std::string geburtstag;
    std::string adresse;
};

std::ostream& operator<<(std::ostream& out, const Student& student); //no need {}, tell this function exists elsewhere in the code or in file .cpp
																     //but not enough by itself
#endif
