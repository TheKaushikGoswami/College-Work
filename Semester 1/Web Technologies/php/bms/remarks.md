## Requirements:

<!-- Requirements and Remarks for our project: Book Management System -->

- PHP
- MySQL (Relational Database)
- UI - HTML, CSS, Bootstrap
- Validation - PHP, HTML, JavaScript

## Features:

<!-- Features of our project: Book Management System -->

- Control Panel (Admin Panel)

    - Company Employees
        - Name, Email ID, Password [fields in the database]
        - Superadmin (Default Entry)

    - Categories
        - Name, Details, Image [fields in the database]
    
    - Books
        - Category (from the categories table), Name, Author, Price, Details, Image, PDF, Gallery, YouTube link, Store Name, Rack, Publisher, Edition, Language [fields in the database]

    - Dashboard
        - Number Analysis

    - Daily Report
        - Total Books Read

- Customer End

    - Home Page
    
    - Categories Page

    - Books Page

    - Book Details Page

    - Contact Us Page

<!--



DATETIME Format: YYYY-MM-DD HH:MM:SS

-->

## Files to create:

1. header.php
2. footer.php
3. config/config.php
4. admin/dashboard.php
5. admin/role.php
    contains a table with field "name"
6. admin/role_manage.php
    fields: name
7. admin/employee.php
    contains a 