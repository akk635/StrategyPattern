#include <iostream>

enum class Department {
    Development,
    Quality_Check,
    Sales,
    Marketting
};

struct GetWorkingHoursPercent {
    double operator()(Department department){
        if (department == )
    }    
};

struct GetPaymentPercentForKurzArbeit {
    double operator()(bool isMarried, int numChildren = 0) {
        auto reducedHoursCategory = CreateReducedHoursCategory(isMarried, numChildren);
    }    
};

struct Person {
    bool       isMarried;
    int        numChildren;
    Department department;
    double CalcCrisisNetSalary_Percent() {
        auto workingHoursPercent = GetWorkingHoursPercent{}(department);
        return workingHoursPercent + (100. - workingHoursPercent) * GetPaymentPercentForKurzArbeit(isMarried, numChildren);     
    }
};

int main()
{
    Person person1{true, Department::Development};
    auto crisisSalaryPercent = person1.CalcCrisisNetSalary_Percent();
    std::cout<< "person1 salary during crisis : " << crisisSalaryPercent << std::endl;
}