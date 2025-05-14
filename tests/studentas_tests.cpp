#include <gtest/gtest.h>
#include <memory>
#include "../include/studentas.h"

TEST(StudTest, CopyConstructorWorks) {
    std::istringstream input("Ona\nOnaite\n10 9 8 7 6\n10\n");
    Stud student(input, "failas");
    Stud copyStudent(student);
    EXPECT_EQ(copyStudent.getVardas(), "Ona");
    EXPECT_EQ(copyStudent.getPavarde(), "Onaite");
    EXPECT_DOUBLE_EQ(copyStudent.getGalutinisVid(), 9.2);
    EXPECT_DOUBLE_EQ(copyStudent.getGalutinisMed(), 9.2);
}

TEST(StudTest, CopyAssignmentOperatorWorks) {
    std::istringstream input("Ona\nOnaite\n10 9 8 7 6\n10\n");
    Stud student(input, "failas");
    Stud copyStudent;
    copyStudent = student;
    EXPECT_EQ(copyStudent.getVardas(), "Ona");
    EXPECT_EQ(copyStudent.getPavarde(), "Onaite");
    EXPECT_DOUBLE_EQ(copyStudent.getGalutinisVid(), 9.2);
    EXPECT_DOUBLE_EQ(copyStudent.getGalutinisMed(), 9.2);
}

TEST(StudTest, MoveConstructorWorks) {
    std::istringstream input("Ona\nOnaite\n10 9 8 7 6\n10\n");
    Stud student(input, "failas");
    Stud movedStudent(std::move(student));
    EXPECT_EQ(movedStudent.getVardas(), "Ona");
    EXPECT_EQ(movedStudent.getPavarde(), "Onaite");
    EXPECT_DOUBLE_EQ(movedStudent.getGalutinisVid(), 9.2);
    EXPECT_DOUBLE_EQ(movedStudent.getGalutinisMed(), 9.2);
    EXPECT_EQ(student.getVardas(), "");
    EXPECT_EQ(student.getPavarde(), "");
    EXPECT_DOUBLE_EQ(student.getGalutinisVid(), 0);
    EXPECT_DOUBLE_EQ(student.getGalutinisMed(), 0);
}

TEST(StudTest, MoveAssignmentOperatorWorks) {
    std::istringstream input("Ona\nOnaite\n10 9 8 7 6\n10\n");
    Stud student(input, "failas");
    Stud movedStudent;
    movedStudent = std::move(student);
    EXPECT_EQ(movedStudent.getVardas(), "Ona");
    EXPECT_EQ(movedStudent.getPavarde(), "Onaite");
    EXPECT_DOUBLE_EQ(movedStudent.getGalutinisVid(), 9.2);
    EXPECT_DOUBLE_EQ(movedStudent.getGalutinisMed(), 9.2);
    EXPECT_EQ(student.getVardas(), "");
    EXPECT_EQ(student.getPavarde(), "");
    EXPECT_DOUBLE_EQ(student.getGalutinisVid(), 0);
    EXPECT_DOUBLE_EQ(student.getGalutinisMed(), 0);
}

TEST(StudTest, InputOperatorWorks) {
    std::istringstream input("Ona\nOnaite\n10 9 8 7 6\n10\n");
    Stud student;
    input >> student;
    EXPECT_EQ(student.getVardas(), "Ona");
    EXPECT_EQ(student.getPavarde(), "Onaite");
    EXPECT_DOUBLE_EQ(student.getGalutinisVid(), 9.2);
    EXPECT_DOUBLE_EQ(student.getGalutinisMed(), 9.2);
}

TEST(StudTest, DefaultConstructorWorks) {
    Stud student;
    EXPECT_EQ(student.getVardas(), "");
    EXPECT_EQ(student.getPavarde(), "");
    EXPECT_DOUBLE_EQ(student.getGalutinisVid(), -1);
    EXPECT_DOUBLE_EQ(student.getGalutinisMed(), -1);
}

TEST(StudTest, DestructorWorks) {
    std::weak_ptr<Stud> weakRef;
    {
        auto ptr = std::make_shared<Stud>();
        weakRef = ptr;

        EXPECT_FALSE(weakRef.expired());
    }

    EXPECT_TRUE(weakRef.expired());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
