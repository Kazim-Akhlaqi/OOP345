/**********************************************************
// OOP345 Final Project: ms3
// File: Task.cpp
// Version: 1
// Date of completion: November/30/2018
// Student: Kazim Akhlaqi
// Student_ID: 103638177
// Student_Email: kakhlaqi@myseneca.ca
// Section: OOP345 SEF
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.
***********************************************************/
#include <string>
#include "Task.h"

Task::Task(const std::string& record) : Item(record) {
	m_pNextTask = nullptr;
}

void Task::runProcess(std::ostream& os) {
	if (!m_orders.empty()) {
		if (!m_orders.back().getOrderFillState()) {
			while (!m_orders.back().getItemFillState(getName())) {
				m_orders.back().fillItem(*this, os);
			}
		}
	}
}

bool Task::moveTask() {
	if (!m_orders.empty()) {
		if (m_pNextTask) {
			if (m_orders.back().getItemFillState(getName())) {
				*m_pNextTask += std::move(m_orders.back());
				m_orders.pop_back();
			}
		}
		return true;
	}
	else {
		return false;
	}
}

void Task::setNextTask(Task& task) {
	m_pNextTask = &task;
}

bool Task::getCompleted(CustomerOrder& customerOrder) {
	if (!m_orders.empty() && m_orders.back().getOrderFillState()) {
		customerOrder = std::move(m_orders.back());
		m_orders.pop_back();
		return true;
	}
	else {
		return false;
	}
}

void Task::validate(std::ostream& os) {
	os << getName() << " --> ";
	if (m_pNextTask) {
		os << m_pNextTask->getName() << std::endl;
	}
	else {
		os << "END OF LINE" << std::endl;
	}
}

Task& Task::operator+=(CustomerOrder&& customerOrder) {
	m_orders.push_front(std::move(customerOrder));

	return *this;
}