#include "../include/studentas_testai.h"

bool testAll(){
    return testEmptyConstructor() &&
           testInputStreamConstructor() &&
           testCopyConstructor() &&
           testAssignmentOperator() &&
           testMoveConstructor() &&
           testMoveAssignmentOperator() &&
           testInputOperator() &&
           testOutputOperator() /*&&
           testDestructor()*/;
}

bool testEmptyConstructor() {
    Stud student;
    if (student.getVardas() != "" || student.getPavarde() != "" || student.getGalutinisVid() != -1 || student.getGalutinisMed() != -1) {
        return false;
    }
    return true;
}
bool testInputStreamConstructor() {
    std::istringstream input("Ona\nOnaite\n10 9 8 7 6\n10\n");
    Stud student(input, "failas");
    if (student.getVardas() != "Ona" || student.getPavarde() != "Onaite" || student.getGalutinisVid() != 9.2 || student.getGalutinisMed() != 9.2) {
        return false;
    }
    return true;
}
bool testCopyConstructor() {
    std::istringstream input("Ona\nOnaite\n10 9 8 7 6\n10\n");
    Stud student(input, "failas");
    Stud copyStudent(student);
    if (copyStudent.getVardas() != "Ona" || copyStudent.getPavarde() != "Onaite" || copyStudent.getGalutinisVid() != 9.2 || copyStudent.getGalutinisMed() != 9.2) {
        return false;
    }
    return true;
}
bool testAssignmentOperator() {
    std::istringstream input("Ona\nOnaite\n10 9 8 7 6\n10\n");
    Stud student(input, "failas");
    Stud copyStudent;
    copyStudent = student;
    if (copyStudent.getVardas() != "Ona" || copyStudent.getPavarde() != "Onaite" || copyStudent.getGalutinisVid() != 9.2 || copyStudent.getGalutinisMed() != 9.2) {
        return false;
    }
    return true;
}
bool testMoveConstructor() {
    std::istringstream input("Ona\nOnaite\n10 9 8 7 6\n10\n");
    Stud student(input, "failas");
    Stud movedStudent(std::move(student));
    if (movedStudent.getVardas() != "Ona" || movedStudent.getPavarde() != "Onaite" || movedStudent.getGalutinisVid() != 9.2 || movedStudent.getGalutinisMed() != 9.2) {
        return false;
    }
    return true;
}
bool testMoveAssignmentOperator() {
    std::istringstream input("Ona\nOnaite\n10 9 8 7 6\n10\n");
    Stud student(input, "failas");
    Stud movedStudent;
    movedStudent = std::move(student);
    if (movedStudent.getVardas() != "Ona" || movedStudent.getPavarde() != "Onaite" || movedStudent.getGalutinisVid() != 9.2 || movedStudent.getGalutinisMed() != 9.2) {
        return false;
    }
    return true;
}
bool testInputOperator() {
    std::istringstream input("Ona\nOnaite\n10 9 8 7 6\n10\n");
    Stud student;
    input >> student;
    if (student.getVardas() != "Ona" || student.getPavarde() != "Onaite" || student.getGalutinisVid() != 9.2 || student.getGalutinisMed() != 9.2) {
        return false;
    }
    return true;
}
bool testOutputOperator() {
    std::ostringstream output;
    std::istringstream input("Ona\nOnaite\n10 9 8 7 6\n10\n");
    Stud student(input, "failas");
    output << student;
    std::ostringstream expected;
    expected << std::left << std::setw(25) << "Ona"
         << std::setw(25) << "Onaite"
         << std::setw(25) << std::fixed << std::setprecision(2) << 9.2
         << std::setw(25) << 9.2;
    if (output.str() != expected.str()) return false;
    return true;
}
bool testDestructor() {
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    {
        Stud student;
        std::istringstream input("Ona\nOnaite\n10 9 8 7 6 -1\n10\n");
        student = Stud(input, "failas");
    }
    cout.rdbuf(old);
    std::string output = buffer.str();
    if (output.find("Destruktorius") != std::string::npos) {
        return true;
    }
    return false;
}
