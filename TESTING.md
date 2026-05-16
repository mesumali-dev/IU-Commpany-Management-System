# How to Test the Company Management System

Follow these steps to compile and test all the modules of the system.

## 1. Compilation
Open your terminal in the project directory and run the following command:
```powershell
gcc main.c src/auth.c src/dashboard.c src/task.c src/attendance.c src/salary.c src/transaction.c src/reports.c src/utils.c -o app.exe -I include
```

## 2. Initial Setup
Make sure you have a `data` folder in your project directory. The system will store all CSV files there.

## 3. Recommended Testing Flow

### Step A: Registration
1. Run the program: `./app.exe`
2. Choose **2. Register** from the main menu.
3. Create three users with different roles:
   - **Admin**: (e.g., username: `admin1`)
   - **Accountant**: (e.g., username: `acc1`)
   - **Employee**: (e.g., username: `emp1`)

### Step B: Employee Actions
1. Login as the Employee (`emp1`).
2. Choose **1. Mark Attendance**. Enter today's date.
3. Choose **4. Logout**.

### Step C: Admin Actions
1. Login as the Admin (`admin1`).
2. Choose **2. Assign Task**. Assign a task to `emp1`.
3. Choose **5. View Attendance** to see if the employee's attendance is recorded.
4. Choose **6. View Tasks** to see the newly assigned task.
5. Choose **3. Search Employee** and search for `emp1`.
6. Choose **7. Logout**.

### Step D: Employee (Update Task)
1. Login again as `emp1`.
2. Choose **2. View Assign Task** to see the task from the Admin.
3. Choose **3. Update Your Task Status**. Enter the Task ID to mark it as **Completed**.
4. Choose **4. Logout**.

### Step E: Accountant Actions
1. Login as the Accountant (`acc1`).
2. Choose **1. Add Transactions**. Add a sample expense or income.
3. Choose **2. Calculate Salary**. Enter `emp1` to calculate their salary based on the attendance marked earlier.
4. Choose **3. View Salary Records**.
5. Choose **4. Search Transactions** to find your sample transaction.
6. Choose **5. View All Transactions**.
7. Choose **6. Logout**.

### Step F: Final Report
1. Login as the Admin (`admin1`) one last time.
2. Choose **4. View Reports** to see the overall system summary.

## 4. Manual File Verification
You can also open the files in the `data/` folder (using Notepad or Excel) to verify the data is saved correctly:
- `users.csv`
- `tasks.csv`
- `attendance.csv`
- `transactions.csv`
- `salary.csv`
