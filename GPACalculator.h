//
// Created by mehme on 06/08/2023.
//



#ifndef CGPA_CALCULATOR_CGPACALCULATOR_H
#define CGPA_CALCULATOR_CGPACALCULATOR_H

#endif //CGPA_CALCULATOR_CGPACALCULATOR_

#include <iostream>
#include <utility>


class GPACalculator {

private:

    double creditHours, creditGrade;
    std::string courseName;

public:

    GPACalculator(std::string nameCourse, double hoursCredit, double gradeCredit);

    virtual ~GPACalculator();

    double * gradePoint();

    double averageGradePoints();


    double getCreditHours() const;

    void setCreditHours(double userCreditHours);

    double getCreditGrade() const;

    void setCreditGrade(double userCreditGrade);

    const std::string &getCourseName() const;

    void setCourseName(const std::string &userCourseName);


};



GPACalculator::GPACalculator(std::string nameCourse, double hoursCredit, double gradeCredit): courseName(std::move(nameCourse)),creditHours(hoursCredit),creditGrade(gradeCredit){




}


double * GPACalculator::gradePoint() {

    double* arrray=new double [2];


    double x=getCreditGrade();
    double y=getCreditHours();

    double result=x*y;

   arrray[0]=y;
   arrray[1]=result;


    return arrray;

}

double GPACalculator::averageGradePoints() {

    double*totalGradePoints=gradePoint();

    double totalPoints,totalHours=0;
    totalPoints+=totalGradePoints[0];
    totalHours+=totalGradePoints[1];

    delete[] totalGradePoints;// Deallocate the dynamically allocated array


    if (totalHours == 0) {
        // To avoid division by zero
        return 0.0;
    }

    return totalPoints / totalHours;


}


double GPACalculator::getCreditHours() const {
    return creditHours;
}

void GPACalculator::setCreditHours(double userCreditHours) {
    GPACalculator::creditHours = userCreditHours;
}

double GPACalculator::getCreditGrade() const {
    return creditGrade;
}

void GPACalculator::setCreditGrade(double userCreditGrade) {
    GPACalculator::creditGrade = userCreditGrade;
}


const std::string &GPACalculator::getCourseName() const {
    return courseName;
}

void GPACalculator::setCourseName(const std::string &userCourseName) {
    GPACalculator::courseName = userCourseName;
}

GPACalculator::~GPACalculator() {

    std::cout<<"Destructor worked"<<std::endl;

}













