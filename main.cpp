#include <iostream>
#include <vector>
#include "GPACalculator.h"

int main() {

    int numCourses;
    std::vector<GPACalculator> courses;

    std::cout << "Enter the number of courses: ";
    std::cin >> numCourses;
    std::cin.ignore(); // Clear the newline character from the input buffer

    for (int i = 0; i < numCourses; ++i) {
        std::string courseName;
        double creditHours, creditGrade;

        std::cout << "Enter the name of course " << i + 1 << ": ";
        std::getline(std::cin, courseName);

        std::cout << "Enter the credit hours for course " << i + 1 << ": ";
        std::cin >> creditHours;

        std::cout << "Enter the credit grade for course " << i + 1 << ": ";
        std::cin >> creditGrade;

        GPACalculator course(courseName, creditHours, creditGrade);
        courses.push_back(course);

        std::cin.ignore(); // Clear the newline character from the input buffer
    }


    double totalPoints = 0;
    double totalHours = 0;

    for (GPACalculator course : courses) {
        double* gradePoint = course.gradePoint();
        totalPoints += gradePoint[1];
        totalHours += gradePoint[0];
        delete[] gradePoint;
    }

    double averageGPA = (totalHours > 0) ? totalPoints / totalHours : 0.0;

    std::cout << "Course-wise GPA details:" << std::endl;
    for (const auto& course : courses) {
        std::cout << "Course Name: " << course.getCourseName() << std::endl;
        std::cout << "Credit Hours: " << course.getCreditHours() << std::endl;
        std::cout << "Credit Grade: " << course.getCreditGrade() << std::endl;
        std::cout << std::endl;
    }

    std::cout << "Overall GPA: " << averageGPA << std::endl;

    return 0;
}

