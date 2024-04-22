#pragma warning(disable : 4996)
#include <iostream>
#include <string.h>
#include <ctime>
#include <vector>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

string getCurrentDateTime()
{
	// Get the current date and time
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);

	// Format the date and time as YYYY-MM-DD HH:mm:ss
	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", now);

	return buffer;
}
class Department;
class Employee;
class Manager;
class User;
class Complaint;
class System;
class Teacher;
class Administration;

enum DeptName
{
	admin,it,accounts
};

class User
{
public:
	int id;
	string userName;
	string userType;
public:
	User()
	{
		id = 0;
		userName = "NULL";
		userType = "NULL";
	}
	User(int id,string name,string type)
	{
		this->id = id;
		this->userName = name;
		this->userType = type;
	}
	virtual int getid() const = 0;
};
class Manager;
class Department
{
private:
	int id;
	string name;
	vector <Employee> emp;
	Manager* manager;
public:
	Department()
	{
		id = 0;
		name = "NULL";
	}
	void setName(string name)
	{
		this->name = name;
	}
	void setId(int id)
	{
		this->id = id;
	}
	int getid() const
	{
		return id;
	}
	void addEmployee(const Employee& employee)
	{
		emp.push_back(employee);
	}
	void addManager(const Manager& manager);
	

	void ComplaintReceived();
};
class Teacher :public User
{
private:
	
	vector <int> complaints;
public:
	Teacher()
	{
	
	}
	Teacher(int id,string name):User (id,name,"Teacher")
	{
		
	}
	virtual int getid() const
	{
		return id;
	}
	string getName() const
	{
		return userName;
	}
	void FileComplaint(string discription,string deptname);
	void notifyTeacher(int complaintId, const string& message,Teacher* t);
	void viewComplaintStatusTeacher();

};
class Employee :public User
{
private:
	Department* dept;
	bool assignedJob;
public:
	Employee()
	{
		id = 0;
		dept = nullptr;
		assignedJob = false;
	}
	Employee(int id, string name, Department *dept) :User(id, name, "Employee")
	{
		this->dept = dept;
		this->assignedJob = false;
	}
	Employee(const Employee& other)
		: User(other.id, other.userName, "Employee"), dept(new Department(*other.dept))
	{
	}
	virtual int getid() const
	{
		return id;
	}
	int getDeptId() const
	{
		return dept->getid();
	}
	string getName() const
	{
		return userName;
	}
	void setassignedJob(bool job)
	{
		this->assignedJob = job;
	}
	bool hasassignedJob() const
	{
	
		return assignedJob;
	}
	void completeJob(int complaintId);
	
};
class Department;
class Manager :public User
{
	
	
private:
	Department *dept;
public:
	Manager()
	{
		id = 0;
		dept = nullptr;
	}
	Manager(int id, string name, Department* obj) : User(id, name, "Manager") {
		this->dept = obj;
		// Add the manager to the department
		obj->addManager(*this);
	}
	void assignJob(int comliantid,vector <Employee> emp)
	{

	}
	virtual int getid() const
	{
		return id;
	}
	int getDeptId()  const
	{
		return dept->getid();
	}
	string getUserName() const
	{
		return userName;
	}
	void assignComplaint(int complaintId);
	
};



class Complaint
{
	int id,e_Id;
	string discription;
	string status;
	string feedback;
	string complaint_date;
	string assignment_date;
	Teacher* t;
	int c_dept_id;
	string assignedEmployee;
	string relevantManager;
	string comlaintDepartment;
	string comlaintTeacher;
public:
	Complaint()
	{
		id = 0;
		discription = status = feedback = complaint_date = assignment_date = "NULL";
	}
	Complaint(int id,string discription,Teacher *t)
	{
		this->id = id;
		this->discription = discription;
		this->t = t;
	}
	void setDiscription(string discription)
	{
		this->discription = discription;
	}
	void setStatus(string status)
	{
		this->status = status;
	}
	string getStatus() const
	{
		return status;
	}
	
	int getid() const
	{
		return id;
	}
	void setAssignmentDate()
	{
		this->assignment_date = getCurrentDateTime();
	}
	string getAssignmentDate() const
	{
		return assignment_date;
	}
	void setComplaintDeptId(int id)
	{
		this->c_dept_id=id;
	}
	int getComplaintDeptId() const
	{
		return c_dept_id;
	}
	void setrelevantManager(string name)
	{
		this->relevantManager = name;
	}
	void setassignedEmployee(string name)
	{
		this->assignedEmployee = name;
	}
	void setcomlaintDepartment(string name)
	{
		this->comlaintDepartment = name;
	}
	void setcomlaintTeacher(string name)
	{
		this->comlaintTeacher = name;
	}
	void setcomplaint_date()
	{
		this->complaint_date = getCurrentDateTime();
	}
	string getassignedEmployee() const
	{
		return assignedEmployee;
	}
	string getrelevantManager() const
	{
		return relevantManager;
	}

	string getdiscription() const
	{
		return discription;
	}
	string getcomlaintDepartment() const
	{
		return comlaintDepartment ;
	}
	string getcomlaintTeacher() const
	{
		return comlaintTeacher ;
	}
	string getcomplaint_date() const
	{
		return complaint_date ;
	}
	int getassignedEmployeeId() const
	{
		return e_Id;
	}
	void setassignedEmployeeId(int id)
	{
		this->e_Id=id;
	}
	
};
class System {
public:
	vector<Teacher> teachers;
	vector<Manager> managers;
	vector<Employee> employees;
	vector<Complaint> complaints;

	static System& getInstance() {
		static System instance;
		return instance;
	}

	void showNumOfComplaints();
	void showStatusOfComplaints();
	void addTeacher(const string& name);
	void addManager(const string& name, const string& department);
	void addEmployee(const std::string& name, const string& department);
	Employee* findEmployeeForComplaint(int complaintId);
	void notifyManager(int complaintId);
	
};
class Director : public User
{
public:
	Director()
	{
		id = 0;
		userName = "NULL";
		userType = "Director";
	}

	Director(int id, string name) : User(id, name, "Director")
	{
	}

	virtual int getid() const
	{
		return id;
	}

	// Function to view a summary of complaints for each department
	void viewComplaintSummary();

	// Function to get details about a specific complaint
	void viewComplaintDetails(int complaintId);
};
void Department::addManager(const Manager& manager)
{
	this->manager = new Manager(manager);
}
void System::addTeacher(const string& name) {
	Teacher teacher(teachers.size() + 1, name);
	teachers.push_back(teacher);
	cout << "Teacher added successfully. Teacher ID: "  << teacher.getid() <<"\n";
}
void Manager::assignComplaint(int complaintId)
{
	if (complaintId > 0 && complaintId <= System::getInstance().complaints.size())
	{
		Complaint& complaint = System::getInstance().complaints[complaintId - 1];

		if (complaint.getStatus() == "new")
		{
			// Find an employee with the same department ID as the complaint
			auto matchingEmployee = find_if(System::getInstance().employees.begin(), System::getInstance().employees.end(),
				[&complaint](const Employee& e) {
					return e.getDeptId() == complaint.getComplaintDeptId() && e.hasassignedJob();
				});

			if (matchingEmployee != System::getInstance().employees.end())
			{
				// Update the complaint status and assignment date
				complaint.setStatus("Assigned");
				complaint.setAssignmentDate();
				complaint.setassignedEmployee(matchingEmployee->getName());
				complaint.setrelevantManager(this->getUserName());
				complaint.setassignedEmployeeId(matchingEmployee->getid());
				matchingEmployee->setassignedJob(true);
				// Output the assigned employee's name
				cout << "Complaint " << complaintId << " assigned to Employee " << matchingEmployee->getName()
					<< " on " << complaint.getAssignmentDate() << "\n";

				
				
			}
			else
			{
				cout << "No employees available in the complaint department to assign the complaint.\n";
			}
		}
		else
		{
			cout << "Complaint " << complaintId << " is already assigned or resolved.\n";
		}
	}
	else
	{
		cout << "Invalid complaint ID.\n";
	}
}
void Director::viewComplaintSummary()
{
	// Display a summary of complaints for each department
	cout << "Complaint Summary for Director " << userName << ":\n";
	for (const auto& complaint : System::getInstance().complaints)
	{
		// Displaying department-wise complaint summary
		cout << "Department: " << complaint.getcomlaintDepartment() << ", "
			<< "Complaint ID: " << complaint.getid() << ", "
			<< "Status: " << complaint.getStatus() << "\n";
	}
}
void Director::viewComplaintDetails(int complaintId)
{
	// Display details about a specific complaint
	if (complaintId > 0 && complaintId <= System::getInstance().complaints.size())
	{
		const Complaint& complaint = System::getInstance().complaints[complaintId - 1];
		cout << "\n";
		cout << "Complaint Details for Director " << userName << ":\n";
		cout << "Complaint ID: " << complaint.getid() << "\n";
		cout << "Department: " << complaint.getcomlaintDepartment() << "\n";
		cout << "Status: " << complaint.getStatus() << "\n";
		cout << "Compliant Date: " << complaint.getcomplaint_date() << "\n";
		cout << "Assignment Date: " << complaint.getAssignmentDate() << "\n";
		cout << "Description: " << complaint.getdiscription() << "\n";
		cout << "Teacher Name: " << complaint.getcomlaintTeacher() << "\n";
		cout << "Relevant Manager: " << complaint.getrelevantManager() << "\n";
		cout << "Assigned Employees: " << complaint.getassignedEmployee() << "\n";
	
	}
	else
	{
		cout << "Invalid complaint ID.\n";
	}
}


class Admin : public User
{
public:
	Admin()
	{
		id = 0;
		userName = "NULL";
		userType = "Admin";
	}

	Admin(int id, string name) : User(id, name, "Admin")
	{
	}

	virtual int getid() const
	{
		return id;
	}

	// Function to add a new employee to the system
	void addEmployee(const string& name,string department);

	// Function to remove an employee from the system
	void removeEmployee(int employeeId);

	// Function to add a new manager to the system
	void addManager(const string& name,string department);

	// Function to remove a manager from the system
	void removeManager(int managerId);
};

void Admin::addEmployee(const string& name,string department)
{
	int choice;
	Department obj;
	if (department == "admin" || department == "Admin")
	{
		choice = 0;
	}
	else if (department == "it" || department == "It")
	{
		choice = 1;
	}
	else if (department == "accounts" || department == "Accounts")
	{
		choice = 2;
	}
	switch (choice)
	{
	case admin:
		obj.setName("Admin");
		obj.setId(1);
		break;
	case it:
		obj.setName("It");
		obj.setId(2);
		break;
	case accounts:
		obj.setName("Accounts");
		obj.setId(3);
		break;
	default:
		cout << "Invalid Department \n";
		break;
	}
	Employee employee(System::getInstance().employees.size() + 1, name, &obj);
	System::getInstance().employees.push_back(employee);
	obj.addEmployee(employee);
	cout << "Employee added successfully. Employee ID: " << employee.getid() << ", Name: " << name << "\n";
}

void Admin::removeEmployee(int employeeId)
{
	auto& employees = System::getInstance().employees;

	auto it = find_if(employees.begin(), employees.end(), [employeeId](const Employee& e) {
		return e.getid() == employeeId;
		});

	if (it != employees.end())
	{
		employees.erase(it);
		cout << "Employee removed successfully. Employee ID: " << employeeId << "\n";
	}
	else
	{
		cout << "Employee not found with ID: " << employeeId << "\n";
	}
}

void Admin::addManager(const string& name,string department)
{
	int choice;
	Department obj;
	if (department == "admin" || department == "Admin")
	{
		choice = 0;
	}
	else if (department == "it" || department == "It")
	{
		choice = 1;
	}
	else if (department == "accounts" || department == "Accounts")
	{
		choice = 2;
	}
	switch (choice)
	{
	case admin:
		obj.setName("Admin");
		obj.setId(1);
		break;
	case it:
		obj.setName("It");
		obj.setId(2);
		break;
	case accounts:
		obj.setName("Accounts");
		obj.setId(3);
		break;
	default:
		cout << "Invalid Department \n";
		break;
	}
	
	
	Manager manager(System::getInstance().managers.size() + 1, name, &obj);
	System::getInstance().managers.push_back(manager);
	obj.addManager(manager);
	cout << "Manager added successfully. Manager ID: " << manager.getid() << ", Name: " << name << "\n";
}

void Admin::removeManager(int managerId)
{
	auto& managers = System::getInstance().managers;

	auto it = find_if(managers.begin(), managers.end(), [managerId](const Manager& m) {
		return m.getid() == managerId;
		});

	if (it != managers.end())
	{
		managers.erase(it);
		cout << "Manager removed successfully. Manager ID: " << managerId << "\n";
	}
	else
	{
		cout << "Manager not found with ID: " << managerId << "\n";
	}
}

void System::addManager(const string& name, const string& department) {
	int choice;
	Department obj;
	if (department=="admin" || department == "Admin")
	{
		choice = 0;
	}
	else if (department == "it" || department == "It")
	{
		choice = 1;
	}
	else if (department == "accounts" || department == "Accounts")
	{
		choice = 2;
	}
	switch (choice)
	{
	case admin:
		obj.setName("Admin");
		obj.setId(1);
		break;
	case it:
		obj.setName("It");
		obj.setId(2);
		break;
	case accounts:
		obj.setName("Accounts");
		obj.setId(3);
		break;
	default:
		cout << "Invalid Department \n";
		break;
	}
	Manager manager(managers.size() + 1, name, &obj);
	managers.push_back(manager);
	obj.addManager(manager);
	cout << "Manager added successfully. Manager ID: " << manager.getid() << " Deparment ID: " <<
		manager.getDeptId()<<  "\n";
}

void System::addEmployee(const string& name, const string& department) {
	int choice;
	Department obj;
	if (department == "admin" || department == "Admin") {
		choice = 0;
	}
	else if (department == "it" || department == "It") {
		choice = 1;
	}
	else if (department == "accounts" || department == "Accounts") {
		choice = 2;
	}
	switch (choice) {
	case admin:
		obj.setName("Admin");
		obj.setId(1);
		break;
	case it:
		obj.setName("It");
		obj.setId(2);
		break;
	case accounts:
		obj.setName("Accounts");
		obj.setId(3);
		break;
	default:
		cout << "Invalid Department \n";
		return; // Exit the function if the department is invalid
	}

	Employee employee(employees.size() + 1, name, &obj);
	employees.push_back(employee);
	// Add the employee to the department
	obj.addEmployee(employee);

	cout << "Employee added successfully. Employee ID: " << employee.getid() << " Department ID: " <<
		employee.getDeptId() << "\n";
}
void System::showNumOfComplaints() {
	cout << "Total Number of Complaints: " << complaints.size() << "\n";
}

void System::showStatusOfComplaints() {
	cout << "Complaint Status:\n";
	for (const auto& complaint : complaints) {
		cout << "Complaint ID: " << complaint.getid() << ", Status: " << complaint.getStatus() << "\n";
	}
}

Employee* System::findEmployeeForComplaint(int complaintId) {
    if (complaintId > 0 && complaintId <= complaints.size()) {
        const Complaint& complaint = complaints[complaintId - 1];
        int assignedEmployeeId = complaint.getassignedEmployeeId();
		for ( auto& employee : employees) {
			cout << "Checking employee with ID: " << employee.getid() << endl;
			
		}
		cout << "Number of employees: " << employees.size() << endl;
		for (auto & employee : employees) {
			cout << "Checking employee with ID: " << employee.getid() << endl;
			if (employee.getid() == assignedEmployeeId) {
				return &employee;;
			}
			
		}
       

        cout << "Invalid employee ID or complaint not assigned to you.\n";
    } else {
        cout << "Invalid complaint ID.\n";
    }

    return nullptr;
}

void Teacher::FileComplaint(string discription, string deptname)
{
	Complaint complaint(System::getInstance().complaints.size() + 1, discription, this);
	if (deptname == "admin")
	{
		complaint.setComplaintDeptId(1);
		complaint.setStatus("new");
		complaint.setcomlaintDepartment("admin");
		complaint.setcomlaintTeacher(this->getName());
		complaint.setcomplaint_date();
	}
	else if (deptname == "it")
	{
		complaint.setComplaintDeptId(2);
		complaint.setStatus("new");
		complaint.setcomlaintDepartment("it");
		complaint.setcomlaintTeacher(this->getName());
		complaint.setcomplaint_date();
	}
	else if (deptname == "accounts")
	{
		complaint.setComplaintDeptId(3);
		complaint.setStatus("new");
		complaint.setcomlaintDepartment("accounts");
		complaint.setcomlaintTeacher(this->getName());
		complaint.setcomplaint_date();
	}
	System::getInstance().complaints.push_back(complaint);  // Add the complaint to the system's vector
	cout << "Complaint filed successfully. Complaint ID: " << complaint.getid() << "\n";
	notifyTeacher(complaint.getid(), "Your complaint has been filed.", this);
}
void Employee::completeJob(int complaintId) {
	if (complaintId > 0 && complaintId <= System::getInstance().complaints.size()) {
		Complaint& complaint = System::getInstance().complaints[complaintId - 1];

		if (complaint.getStatus() == "Assigned") {
			// Perform the job completion logic here
			complaint.setStatus("resolved");
			// Notify the manager
			this->setassignedJob(false);
			System::getInstance().notifyManager(complaintId);
		}
		else {
			cout << "Job for Complaint " << complaintId << " is not assigned to you or already completed.\n";
		}
	}
	else {
		cout << "Invalid complaint ID.\n";
	}
}
void System::notifyManager(int complaintId) {
	if (complaintId > 0 && complaintId <= System::getInstance().complaints.size()) {
		

		
		cout << "Manager notified for Complaint " << complaintId << " \n";
		cout << "Manager reviewed the complaint: " << complaintId << ": Job has completed. \n";

		
		
	}
	else {
		cout << "Invalid complaint ID.\n";
	}
}
void Teacher::notifyTeacher(int complaintId, const string& message,Teacher * t)
{
	cout << "Notification sent to teacher " << t->userName << " for complaint " << complaintId << ": " << message << "\n";
}
void Teacher::viewComplaintStatusTeacher()
{
	cout << "Complaint Status for Teacher " << userName << ":\n";
	for (const auto& complaint : System::getInstance().complaints)
	{
		if (complaint.getid() == id)
		{
			cout << "Complaint ID: " << complaint.getid() << ", Status: " << complaint.getStatus() << "\n";
		}
	}
}
void saveTeacherToFile(const System& systemInstance) {
	ofstream file("teachers.txt");
	if (file.is_open()) {
		file << "TeacherID UserName UserType\n";

		for (const auto& teacher : systemInstance.teachers) {
			file << teacher.getid() << " " << teacher.userName << " " << teacher.userType << "\n";
		}
		file.close();
	}
}
void saveComplaintToFile(const System& systemInstance) {
	ofstream file("complaints.txt");
	if (file.is_open()) {
		file << "ComplaintID DeptID Status \n";
		for (const auto& complaint : systemInstance.complaints) {
			file << complaint.getid() << " " << complaint.getComplaintDeptId() << " "
				<< complaint.getStatus() << "\n";
		}
		file.close();
	}
}

// Function to save manager data to file
void saveManagerToFile(const System& systemInstance) {
	ofstream file("managers.txt");
	if (file.is_open()) {
		file << "ManagerID DeptID UserName\n";

		for (const auto& manager : systemInstance.managers) {
			file << manager.getid() << " " << manager.getDeptId() << " " << manager.getUserName() << "\n";
		}
		file.close();
	}
}

// Function to save employee data to file
void saveEmployeeToFile(const System& systemInstance) {
	ofstream file("employees.txt");
	if (file.is_open()) {
		file << "EmployeeID DeptID UserName\n";
		for (const auto& employee : systemInstance.employees) {
			file << employee.getid() << " " << employee.getDeptId() << " " << employee.getName() << "\n";
		}
		file.close();
	}
}
int main() {
	System& systemInstance = System::getInstance();
	int choice;

	do {
		// Display main menu
		std::cout << "========== MAIN MENU ==========\n";
		std::cout << "1. System Menu\n";
		std::cout << "2. Manager Menu\n";
		std::cout << "3. Teacher Menu\n";
		std::cout << "4. Admin Menu\n";
		std::cout << "5. Employee Menu\n";
		std::cout << "6. Director Menu\n";
		std::cout << "0. Exit\n";
		std::cout << "Enter your choice: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			// System Menu
			int systemOption;
			std::cout << "========== SYSTEM MENU ==========\n";
			std::cout << "1. Add Teacher\n";
			std::cout << "2. Add Manager\n";
			std::cout << "3. Add Employee\n";
			std::cout << "4. Show Number of Complaints\n";
			std::cout << "5. Show Status of Complaints\n";
			std::cout << "0. Back to Main Menu\n";
			std::cout << "Enter your choice: ";
			std::cin >> systemOption;

			switch (systemOption) {
			case 1:
				// Add Teacher
			{
				string name;
				cout << "Enter teacher name: ";
				cin >> name;
				systemInstance.addTeacher(name);
				cout << "Teacher added successfully.\n";
				saveTeacherToFile(systemInstance);
			}
			break;

			case 2:
				// Add Manager
			{
				string name, department;
				cout << "Enter manager name: ";
				cin >> name;
				cout << "Enter manager department: ";
				cin >> department;
				systemInstance.addManager(name, department);
				cout << "Manager added successfully.\n";
				saveManagerToFile(systemInstance);
			}
			break;

			case 3:
				// Add Employee
			{
				string name, department;
				cout << "Enter employee name: ";
				cin >> name;
				cout << "Enter employee department: ";
				cin >> department;
				systemInstance.addEmployee(name, department);
				cout << "Employee added successfully.\n";
				saveEmployeeToFile(systemInstance);
			}
			break;
			case 4:
				systemInstance.showNumOfComplaints();
				break;
			case 5:
				systemInstance.showStatusOfComplaints();
				break;
			case 0:
				// Return to the main menu
				break;
			default:
				std::cout << "Invalid choice. Please enter a valid option.\n";
			}
			break;

		case 2:
			// Manager Menu
			int managerOption;
			std::cout << "========== MANAGER MENU ==========\n";
			std::cout << "1. Assign Complaint\n";
			std::cout << "0. Back to Main Menu\n";
			std::cout << "Enter your choice: ";
			std::cin >> managerOption;

			switch (managerOption) {
			case 1:
			{
				int complaintId;

				cout << "Enter complaint ID: ";
				cin >> complaintId;

				// Assigning complaints to employees by managers
				systemInstance.managers[0].assignComplaint(complaintId);

				// Displaying the updated status of complaints
				systemInstance.showStatusOfComplaints();
			}

				break;
			
			case 0:
				// Return to the main menu
				break;
			default:
				std::cout << "Invalid choice. Please enter a valid option.\n";
			}
			break;

		case 3:
			// Teacher Menu
			int teacherOption;
			std::cout << "========== TEACHER MENU ==========\n";
			std::cout << "1. File Complaint\n";
			std::cout << "2. View Complaint Status\n";
			std::cout << "0. Back to Main Menu\n";
			std::cout << "Enter your choice: ";
			std::cin >> teacherOption;

			switch (teacherOption) {
			case 1:
				
			{
				int teacherIndex;
				string description, deptname;

				cout << "Enter teacher index: ";
				cin >> teacherIndex;

				cout << "Enter complaint description: ";
				cin >> description;  // Clear the newline character in the input buffer
				saveComplaintToFile(systemInstance);


				cout << "Enter department name: ";
				cin >> deptname;

				if (teacherIndex > 0 && teacherIndex <= systemInstance.teachers.size()) {
					systemInstance.teachers[teacherIndex - 1].FileComplaint(description, deptname);
					cout << "Complaint filed successfully.\n";
				}
				else {
					cout << "Invalid teacher or department index.\n";
				}
				saveComplaintToFile(systemInstance);
			}
			break;
			case 2:
			{
				int teacherIndex;
				cout << "Enter teacher index: ";
				cin >> teacherIndex;

				if (teacherIndex > 0 && teacherIndex <= systemInstance.teachers.size()) {
					systemInstance.teachers[teacherIndex - 1].viewComplaintStatusTeacher();
				}
				else {
					cout << "Invalid teacher index.\n";
				}
			}
				break;
			case 0:
				// Return to the main menu
				break;
			default:
				std::cout << "Invalid choice. Please enter a valid option.\n";
			}
			break;

		case 4:
			// Admin Menu
			int adminOption;
			std::cout << "========== ADMIN MENU ==========\n";
			std::cout << "1. Add Employee/Manager\n";
			std::cout << "2. Remove Employee/Manager\n";
			std::cout << "0. Back to Main Menu\n";
			std::cout << "Enter your choice: ";
			std::cin >> adminOption;

			switch (adminOption) {
			case 1:
			{
				int selected;
				Admin admin(1, "AdminUser");
				string name, department;
				cout << "Press 1. Add Employee \n";
				cout << "Press 2. Add Manager \n";
				cin >> selected;
				cout << "Enter name: ";
				cin >> name;

				cout << "Enter department: ";
				cin >> department;

				if (selected == 1)
					admin.addEmployee(name, department);
				else
					admin.addManager(name, department);

				cout << (choice == 1 ? "Employee" : "Manager") << " added successfully.\n";
			}
				break;
			case 2:
			{
				int selected;
				Admin admin(1, "AdminUser");
				int id;
				cout << "Press 1. Remove Employee \n";
				cout << "Press 2. Remove Manager \n";
				cin >> selected;
				cout << "Enter ID to remove: ";
				cin >> id;

				if (choice == 10)
					admin.removeEmployee(id);
				else
					admin.removeManager(id);

				cout << (choice == 1 ? "Employee" : "Manager") << " removed successfully.\n";
			}
				break;
			case 0:
				// Return to the main menu
				break;
			default:
				std::cout << "Invalid choice. Please enter a valid option.\n";
			}
			break;

		case 5:
			// Employee Menu
			int employeeOption;
			std::cout << "========== EMPLOYEE MENU ==========\n";
			std::cout << "1. Complete Assigned Job\n";
			std::cout << "0. Back to Main Menu\n";
			std::cout << "Enter your choice: ";
			std::cin >> employeeOption;

			switch (employeeOption) {
			case 1:
				
			{
				int complaintId;
			cout << "Enter complaint ID to complete the job: ";
			cin >> complaintId;


			Employee* employee = systemInstance.findEmployeeForComplaint(complaintId);

			if (employee != nullptr) {
				systemInstance.employees[employee->getid() - 1].completeJob(complaintId);
			}
			else {
				cout << "Invalid employee ID or complaint not assigned to you.\n";
			}
			}

				break;
			case 0:
				// Return to the main menu
				break;
			default:
				std::cout << "Invalid choice. Please enter a valid option.\n";
			}
			break;
		case 6:
			// Director Menu
			int directorOption;
			std::cout << "========== DIRECTOR MENU ==========\n";
			std::cout << "1. View Complaint Summary\n";
			std::cout << "2. View Complaint Details\n";
			std::cout << "0. Back to Main Menu\n";
			std::cout << "Enter your choice: ";
			std::cin >> directorOption;

			switch (directorOption)
			{
			case 1:
			{
				// View Complaint Summary
				Director director(1, "DirectorUser");
				director.viewComplaintSummary();
			}
			break;

			case 2:
			{
				// View Complaint Details
				int complaintId;
				cout << "Enter complaint ID: ";
				cin >> complaintId;

				Director director(1, "DirectorUser");
				director.viewComplaintDetails(complaintId);
			}
			break;

			case 0:
				// Return to the main menu
				break;

			default:
				std::cout << "Invalid choice. Please enter a valid option.\n";
			}
			break;
		case 0:
			std::cout << "Exiting program...\n";
			break;

		default:
			std::cout << "Invalid choice. Please enter a valid option.\n";
		}


	} while (choice != 0);

	return 0;
}

