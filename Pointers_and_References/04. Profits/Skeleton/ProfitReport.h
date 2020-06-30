#ifndef PROFIT_REPORT_H
#define PROFIT_REPORT_H

#include "Company.h"
#include "ProfitCalculator.h"
#include <sstream>

std::string getProfitReport(const Company* fromInclusive, const Company* toInclusive,
	const std::map<int, ProfitCalculator>& profitCalculatorsByCompany)
{	
	std::ostringstream report;
	for (const Company* c = fromInclusive; c <= toInclusive; c++)
	{
		ProfitCalculator profit = profitCalculatorsByCompany.find(c->getId())->second;
		report << c->getName() << " = " << profit.calculateProfit(*c) << "\n";
	}

	return report.str();
}

#endif // !PROFIT_REPORT_H
