/*  Title: Student Record Keeping System
    Author: Ibrahim      Date: 06/04/2022
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Student node class that defines all the properties each student record will have
//as well as defining the methods that will run this program. It also has a property
//that points to the next student in the LinkedList
class Student
{
public:
    string fname, lname, id_no, course_id, total_score;

    Student* next;//pointer to next student node in the LinkedList

    //method protoypes
    void menu();
    void insert();
    void display();
    void sort();
    void modify();
    void search();
    void delete_record();

    //this method returns the details of the Student in a neat string format
    //and makes it easier to write each record to the database file
    string to_string() {
        return fname + "\t" + lname + "\t" + id_no + "\t" + course_id + "\t" + total_score + "\n";
    }

};

//LinkedList function prototypes
void push(class Student** head, string fname, string lname, string id_no, string course_id, string total_score);
void append(class Student** head, string fname, string lname, string id_no, string course_id, string total_score );
void displayList(class Student *node);
void selectionSort(Student* head);
Student* find(Student* head, string student_id);
Student* find2(Student* head, string course_id);
void deleteStudent(Student*& head, string id);
void deleteList(Student** head_ref);
Student* update(Student* head, string student_id);
bool check_id(Student* head, string student_id);

//create a LinkedList which contains Student objects to make data manipulation easier
Student *head = NULL;

//main method where the program starts and ends
int main()
{
    Student project; // create an instance of the student class
    project.menu();  // start the program by displaying the menu

    return 0;
}

//method definitions

//this method will start the program and display the menu
void Student::menu()
{
    //this is where the application starts
start:
    int first_choice;
    char second_choice;
    cout << "\n\t\t\t*********************************" << "\n";
    cout << "\t\t\t* STUDENT RECORD KEEPING SYSTEM *" << "\n";
    cout << "\t\t\t*********************************" << "\n";
    cout << "\t\t\t 1. Enter a New Record" << "\n";
    cout << "\t\t\t 2. Display Record" << "\n";
    cout << "\t\t\t 3. Sort using total score" << "\n";
    cout << "\t\t\t 4. Modify a record" << "\n";
    cout << "\t\t\t 5. Search for a record" << "\n";
    cout << "\t\t\t 6. Delete a record" << "\n";
    cout << "\t\t\t 7. Exit\n"
         << "\n";

    cout << "\t\t\t********************************" << "\n";
    cout << "\t\t\t* Choose Options:[1/2/3/4/5/6/7] *" << "\n";
    cout << "\t\t\t********************************" << "\n";
    cout << " Enter Your Choice: ";
    cin >> first_choice;
    switch (first_choice)
    {
    case 1:
        do
        {
            insert();
            cout << "\n\n\t\t\t Add Another Student Record (Y, N) : ";
            cin >> second_choice;
        } while (second_choice == 'y' || second_choice == 'Y');
        break;
    case 2:
        display();
        break;
    case 3:
        sort();
        break;
    case 4:
        modify();
        break;
    case 5:
        search();
        break;
    case 6:
        delete_record();
        break;
    case 7:
        cout << "\n\t\t\t The Program has been terminated succesfully \n";
        exit(0);
    default:
        cout << "\n\n\t\t\t Invalid Choice. Please Try Again. \n";
    }

    //use goto statement as a while loop to keep the program running until 
    //the user decides to quit
    goto start;
}

//this method will add a new student record to the database.txt file
void Student::insert()
{   

    //read the records from the database file and add them all to the LinkedList 
    //to make searching easier
    fstream file;
    file.open("database.txt", ios::in);
    if (file) {
        //delete the contents of the LinkedList before using it
        deleteList(&head);
        file >> fname >> lname >> id_no >> course_id >> total_score;

        while (!file.eof())
        {   
            //append the record to the back of the LinkedList
            append(&head, fname, lname, id_no, course_id, total_score);

            file >> fname >> lname >> id_no >> course_id >> total_score;
        } 
    }
    file.close();

    //Collect and store all the necessary information from the user
    cout << "\n*******************************************************************************************************" << "\n";
    cout << "************************************* Add New Student Record ******************************************" << "\n";
    cout << "\n\t\t\tEnter the student's first Name: ";
    //getline(cin, fname);
    cin >> fname;
    cout << "\t\t\tEnter the student's last name: ";
    cin >> lname;
    get_id:
    cout << "\t\t\tEnter the student's ID number: ";
    cin >> id_no;
    if(check_id(head, id_no)) {
        cout << "\t\t\tThis ID number is already in use. Please try again.\n";
        goto get_id;
    }
    cout << "\t\t\tEnter the student's Course ID: ";
    cin >> course_id;
    cout << "\t\t\tEnter the student's Total Score: ";
    cin >> total_score;

    //write the new record to the database file then close it
    file.open("database.txt", ios::app | ios::out);
    file << to_string();
    file.close();
}

//this method will read from the database.txt file and display the results
void Student::display() // Display data of student
{
    fstream file;
    string record; // this string will be used to store a record from the database
    cout << "\n*******************************************************************************************************" << "\n";
    cout << "************************************* Student Record Table ********************************************" << "\n";
    //cout << labels();
    file.open("database.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t Database file doesn't exist!";
        file.close();
    }
    else
    {
        int total = 0; //this variable represents the total number of records in the database
        string record; // this string will be used to store every record in the database

        //Read the records from the database line by line and print them
        while(getline(file, record)) {
            total++;
            cout << total << " " << record << "\n";
        }
    }

    file.close();
}

//this method will sort the records in the database in ascending based on total_score
//using the selection sort algorithm
void Student::sort() {
    //read the records from the database file and add them to the LinkedList 
    //to make sorting easier
    fstream file;
    file.open("database.txt", ios::in);
    if (!file) {
        cout << "Database doesn't exist or is empty. Please add some data first \n";
    } else {
        //delete the contents of the LinkedList before using it
        deleteList(&head);
        file >> fname >> lname >> id_no >> course_id >> total_score;

        while (!file.eof())
        {   
            //append the record to the back of the LinkedList
            append(&head, fname, lname, id_no, course_id, total_score);

            file >> fname >> lname >> id_no >> course_id >> total_score;
        } 

        //use the selection sort algorithm to sort the records in ascending order based on total_score
        selectionSort(head);
        //clear the database file then write the sorted LinkedList to it
        file.open("database.txt", ios::out);
        file << "";
        file.close();
    
        //iterate over the sorted LinkedList and write it's data to the database file
        file.open("database.txt", ios::out);
        while (head != NULL) {
            file << head->to_string();
            head = head->next;
        }
        file.close();
        cout << "Sorting has been successful.\n";

    }

}

//this method will search the records using Student ID or Course ID 
//depending on what the user wants and then display the results of the search
void Student::search() {

    //read the records from the database file and add them to the LinkedList 
    //to make searching easier
    fstream file;
    file.open("database.txt", ios::in);
    if (!file) {
        cout << "Database doesn't exist or is empty. Please add some data first \n";
    } else {
        //delete the contents of the LinkedList before using it
        deleteList(&head);
        file >> fname >> lname >> id_no >> course_id >> total_score;

        while (!file.eof())
        {   
            //append the record to the LinkedList
            append(&head, fname, lname, id_no, course_id, total_score);

            file >> fname >> lname >> id_no >> course_id >> total_score;
        } 

        file.close();

        search_choice:
        string user_choice;
        cout << "Enter \"S\" to search the records using Student ID or \"C\" to search"; 
        cout << " using Course ID: ";
        cin >> user_choice;

        if(user_choice == "S" || user_choice == "s") {
            string student_id;
            cout << "Enter the Student ID of the student you want to search for: ";
            cin >> student_id;
            find(head, student_id);
        } else if(user_choice == "C" || user_choice == "c") {
            string course_id;
            cout << "Enter the Course ID of the student you want to search for: ";
            cin >> course_id;
            find2(head, course_id);
        } else {
            cout << "Invalid choice. Please try again.\n";
            goto search_choice;
        }

    }
}

//this method is used to delete a record from the databse using a student ID
void Student::delete_record() {

    //read the records from the database file and add them to the LinkedList 
    //to make searching and deleting easier
    fstream file;
    file.open("database.txt", ios::in);
    if (!file) {
        cout << "Database doesn't exist or is empty. Please add some data first \n";
    } else {
        //delete the contents of the LinkedList before using it
        deleteList(&head);
        file >> fname >> lname >> id_no >> course_id >> total_score;

        while (!file.eof())
        {   
            //append the record to the LinkedList
            append(&head, fname, lname, id_no, course_id, total_score);

            file >> fname >> lname >> id_no >> course_id >> total_score;
        } 

        file.close();

        //remove the record based on id given by user from the list
        cout << "Enter the ID number of the Student record you want to delete: ";
        string id;
        cin >> id;
        deleteStudent(head, id);

        //now clear the database file then write the updated LinkedList to it
        file.open("database.txt", ios::out);
        file << "";
        file.close();
        
        //iterate over the updated LinkedList and write it's data to the database file
        file.open("database.txt", ios::out);
        while (head != NULL) {
            file << head->to_string();
            head = head->next;
        }
        file.close();
    }
}

//this method will modify the contents of any user selected record
void Student::modify() {
    //read the records from the database file and add them to the LinkedList 
    //to make searching and modifying the records easier
    fstream file;
    file.open("database.txt", ios::in);
    if (!file) {
        cout << "Database doesn't exist or is empty. Please add some data first \n";
    } else {
        //delete the contents of the LinkedList before using it
        deleteList(&head);
        file >> fname >> lname >> id_no >> course_id >> total_score;

        while (!file.eof())
        {   
            //append the record to the LinkedList
            append(&head, fname, lname, id_no, course_id, total_score);

            file >> fname >> lname >> id_no >> course_id >> total_score;
        } 

        file.close();

        cout << "Enter the Student ID of the record you want to modify: ";
        string id;
        cin >> id;
        //search for the record using the user provided student id
        //and if the record is found modify it
        Student* temp = update(head, id);
        if(temp != NULL) {
            cout << "Update the student's first Name: ";
            cin >> temp->fname;
            cout << "Update the student's last name: ";
            cin >> temp->lname;
            cout << "Update the student's Course ID: ";
            cin >> temp->course_id;
            cout << "Update the student's Total Score: ";
            cin >> temp->total_score;
            cout << "Record has been successfully updated.\n";

            //now clear the database file then write the updated LinkedList to it
            file.open("database.txt", ios::out);
            file << "";
            file.close();
        
            //iterate over the updated LinkedList and write it's data to the database file
            file.open("database.txt", ios::out);
            while (head != NULL) {
                file << head->to_string();
                head = head->next;
            }
            file.close();

        } else {
            cout << "Record not found.\n";
        }
    }
}


//LinkedList function definitions

//insert a new node in front of the list
void push(class Student** head, string fname, string lname, string id_no, string course_id, string total_score)
{
   /* 1. create and allocate node */
   class Student* newStudent = new Student;
 
   /* 2. assign data to node */
   newStudent->fname = fname;
   newStudent->lname = lname;
   newStudent->id_no = id_no;
   newStudent->course_id = course_id;
   newStudent->total_score = total_score;
 
   /* 3. set next of new node as head */
   newStudent->next = (*head);
 
   /* 4. move the head to point to the new node */
   (*head) = newStudent;
}
 
/* insert new node at the end of the linked list */
void append(class Student** head, string fname, string lname, string id_no, string course_id, string total_score )
{
/* 1. create and allocate node */
class Student* newStudent = new Student;
 
class Student *last = *head; /* used in step 5*/
 
/* 2. assign data to the node */
   newStudent->fname = fname;
   newStudent->lname = lname;
   newStudent->id_no = id_no;
   newStudent->course_id = course_id;
   newStudent->total_score = total_score;
 
/* 3. set next pointer of new node to null as its the last node*/
newStudent->next = NULL;
 
/* 4. if list is empty, new node becomes first node */
if (*head == NULL)
{
*head = newStudent;
return;
}
 
/* 5. Else traverse till the last node */
while (last->next != NULL)
last = last->next;
 
/* 6. Change the next of last node */
last->next = newStudent;
return;
}
 
// this function can display the linked list contents and is helpful for debugging
void displayList(class Student *node)
{
   //traverse the list to display each node
   while (node != NULL)
   {
      cout<< node->fname << " " <<node->total_score<<"-->";
      node = node->next;
   }
 
if(node== NULL)
cout<<"null"; 
} 

//Selection sorting algorithm to sort the LinkedList in ascending order
void selectionSort(Student* head)
{
	Student* temp = head;

	// Traverse the List
	while (temp) {
		Student* min = temp;
		Student* r = temp->next;

		// Traverse the unsorted sublist
		while (r) {
			if (stoi(min->total_score) > stoi(r->total_score))
				min = r;

			r = r->next;
		}

		// Swap all the data
		string a = temp->fname;
        string b = temp->lname;
        string c = temp->id_no;
        string d = temp->course_id;
        string e = temp->total_score;

        temp->fname = min->fname;
		temp->lname = min->lname;
        temp->id_no = min->id_no;
        temp->course_id = min->course_id;
        temp->total_score = min->total_score;

		min->fname = a;
        min->lname = b;
        min->id_no = c;
        min->course_id = d;
        min->total_score = e;

		temp = temp->next;
	}
}

//this function implements the  serial searching algorithm on our LinkedList 
//and uses Student ID as the search key
Student* find(Student* head, string student_id)
{
    // Base case
    if (head == NULL) {
        cout << "Record not found\n";
        return head;
    } 
     
    // If the Student ID is present in current node, return current node
    if (head->id_no == student_id) {
        cout << head->to_string();
        return head;
    }
 
    // Use recursion to go thru the remaining records in the list
    return find(head->next, student_id);
}

//this function implements the  serial searching algorithm on our LinkedList 
//and uses Course ID as the search key
bool found = false;
Student* find2(Student* head, string course_id)
{
    // Base case
    if (head == NULL) {
        if(!found)
            cout << "Record not found\n";
        return head;
    } 
     
    // If the Course ID is present in current node, keep looking for more students with
    // the same Course ID in the list until you iterate thru the entire list
    if (head->course_id == course_id) {
        found = true;
        cout << head->to_string();
    }
 
    // Use recursion to go thru the remaining records in the list
    return find2(head->next, course_id);
}


//this function deletes the Student node containing the same student ID as the 
//student id passed as an argumentand and alters the head of the linked list using recursion
void deleteStudent(Student*& head, string id)
{
    // Check if list is empty or we
    // reach at the end of the
    // list.
    if (head == NULL) {
        cout << "Record not present in the list\n";
        return;
    }
    // If current node is the node to be deleted
    if (head->id_no == id) {
        Student* t = head;
        head = head->next; // If it's start of the Student node head
                           // Student node points to second node
        delete (t); // Else changes previous Student node's next to
                    // current node's next
        cout << "Record has been successfully deleted\n";
        return;
    }
    deleteStudent(head->next, id);
}

//this function will delete the entire linked list when it's not needed to save memory
void deleteList(Student** head_ref)
{
 
    /* deref head_ref to get the real head */
    Student* current = *head_ref;
    Student* next = NULL;
 
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
 
    /* deref head_ref to affect the real head back
        in the caller. */
    *head_ref = NULL;
}

//this function implements the  serial searching algorithm on our LinkedList 
//and uses Student ID as the search key and then returns the Student node to be modified
Student* update(Student* head, string student_id)
{
    // Base case
    if (head == NULL) {
        return head;
    } 
     
    // If the Student ID is present in current node, return current node
    if (head->id_no == student_id) {
        return head;
    }
 
    // Use recursion to go thru the remaining records in the list
    return update(head->next, student_id);
}

//this function uses serial searching algorithm to avoid duplicate Student IDs
bool check_id(Student* head, string student_id)
{
    // Base case
    if (head == NULL) {
        return false;
    } 
     
    //If the Student ID is present in current node, return true
    if (head->id_no == student_id) {
        return true;
    }
 
    // Use recursion to go thru the remaining records in the list
    return check_id(head->next, student_id);
}