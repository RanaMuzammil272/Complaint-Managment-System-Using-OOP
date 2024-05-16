# Complaint Management System for University

## Overview
This project is a Complaint Management System tailored for a university setting. It streamlines the process of filing complaints, assigning tasks to relevant departments, monitoring job progress, and efficiently closing complaints.

## Functionality
- **Complaint Filing:** Teachers can submit complaints regarding any encountered issues or requirements.
- **Department Assignment:** Complaints are directed to specific supporting departments (e.g., IT, accounts, admin) based on their nature.
- **Task Assignment:** Managers evaluate complaints and delegate tasks to employees within their departments.
- **Job Progress Tracking:** The system logs task assignment dates and updates as employees work on them.
- **Completion Notification:** Upon task completion, the system notifies the manager for review and closure.
- **Feedback Recording:** Teachers provide feedback upon task completion. If satisfied, the complaint is closed; otherwise, it remains open.
- **Status Tracking:** Complaints progress through various states (new, assigned, resolved, closed) visible to teachers and managers.
- **Reporting:** Reports summarizing complaints filed within a given period are generated. Department-wise complaint statistics are provided.
- **Administrative Functions:** An administrator manages employee, manager, and teacher information.

## Implementation Details
- **Language:** Implemented using C++.
- **Data Persistence:** Files are used for data persistence instead of a DBMS.
- **Architecture:** Utilizes three-tier architecture for efficient management. Data is loaded into objects before display, and objects are populated before writing to files.
