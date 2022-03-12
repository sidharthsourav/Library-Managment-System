#include<iostream>
using namespace std;

class BookData
{
    public:
    string tittle,author;
    int isbn;
};
class library
{
    private:

  struct book
    {
        string title;
        string author;
        int isbn;

        book *next;

    };
    
        book *head;
    public:
        library() 
		{ 
		head = NULL;
		}
        ~library(){}
        void printList();
        void insertNode();
        void insertNode(string tittle, string author, int isbn);
       void deleteNode(string title1);
       int searchbook(int isbn);
       BookData bookdetails(int isbn)
       {
           BookData details;
           book *temp = new book; 
           temp = head;

           while (temp != NULL)
           {
               if (isbn == temp->isbn)
               {
                   details.tittle = temp->title;
                   details.author = temp->author;
                   details.isbn = temp->isbn;
               }
               temp = temp->next;
           }
           return details;  
       }
};

void library::insertNode()
{
    book *newNode, *nodePtr, *previousNode;
    newNode = new book;

   	cout << "Title:\t\t\t";
	cin.ignore(500,'\n');
	getline(cin,  newNode->title);
	cout << "Author:\t\t\t";
	getline(cin,  newNode->author);
	cout << "ISBN:\t\t\t";
	cin>>newNode->isbn;


    if (!head)
    {
        head = newNode;
        newNode->next = NULL;
    }
    else
    {
        nodePtr = head;

        while ((nodePtr != NULL))
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (previousNode == NULL)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
    cout<<"\n \n Returning to main menu.\n\n";
}
void library ::insertNode(string tittle, string author, int isbn)
{
    book *newNode, *nodePtr, *previousNode;
    newNode = new book;

   	newNode->title=tittle;
	newNode->author=author;
	newNode->isbn=isbn;


    if (!head)
    {
        head = newNode;
        newNode->next = NULL;
    }
    else
    {
        nodePtr = head;

        while ((nodePtr != NULL))
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (previousNode == NULL)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }    
}
int library::searchbook(int isbn)
{

	book *temp=new book;
	temp=head;
    int found=0;

	while (temp != NULL)
	{
		if (isbn == temp->isbn)
		{
            cout<<" Book Found !! \n Book details are :\n\n";
			cout <<"Tittle :   "<< temp->title << "\n";
			cout <<"Aithor :   "<< temp->author << "\n";
			cout <<"ISBN   :   "<< temp->isbn << "\n\n";
			found=1;
		}
		temp = temp->next;
	}
	cout << "\n";
    cout<<" Retrunibg to main menu.\n\n";
	return found;
}
void library::deleteNode(string title1)
{
   book *nodePtr, *previousNode;

    if (!head) cout<<"No Entry ";
    if (head->title == title1)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        nodePtr = head;
        while (nodePtr->title!=title1)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        previousNode->next = nodePtr->next;
        delete nodePtr;
    }
    cout<<" \n\nDeleted "<<title1<<" from the library.\n\n";
    cout<<"Returning back to main menu.\n\n";
}
void library::printList()
{

    book *temp=head;

    cout<<" \nAll available books are :\n\n";  
	while (temp != NULL)
	{
		
        cout <<"Title:  " <<temp->title << "\n";
		cout <<"Author: "<< temp->author << "\n";
		cout <<"ISBN:   " <<temp->isbn << "\n\n";
		temp = temp->next;
	}
    cout<<" \n\t Returning to main menu.\n\n";

}

class Student
{
    struct Node
    {
        string name;
        string tittle, author;
        int isbn,rollNo;
        Node* next;
        Node* right;
    };
    Node* head=NULL;
    public:
    string	isb;
    int found;
    int insertNodeStudent();
    void insertNodeStudent(string name , int rollno);
    void addbook(string titte, string author , int isbn,int roll);
    bool studentcheck(int roll);  
    void ListAllottedBooks();   

};	

int Student::insertNodeStudent()
{ 
    Node *newNode = new Node;
    int rol;

   	cout << "Student Name:\t\t\t";
	cin.ignore(500,'\n');
	getline(cin,  newNode->name);
	cout << "Roll NO :\t\t\t";
	cin>>newNode->rollNo;
    
    newNode->next= NULL;
    newNode->right= NULL;

    if (head==NULL) head = newNode;
    else
    {
        newNode->next = head;
        head = newNode;
    }
    rol= newNode->rollNo;
    return rol;
}
void Student:: insertNodeStudent(string name , int rollno)
{
    Node *newNode = new Node;
    
    newNode->name=name;
	newNode->rollNo=rollno;
    
    newNode->next= NULL;
    newNode->right= NULL;

    if (head==NULL) head = newNode;
    else
    {
        newNode->next = head;
        head = newNode;
    }    
}
void Student::addbook(string tittle, string author , int isbn,int roll)
{
    Node *BookNode=new Node;
    BookNode->tittle=tittle;
    BookNode->author= author;
    BookNode->isbn=isbn;
    BookNode->next=NULL;
    BookNode->right=NULL;

    Node *temp = head;
    while (temp != NULL)
    {
        if(temp->rollNo==roll) 
        {
            if(temp->right==NULL)  temp->right =BookNode;
            else
            {
                BookNode->right= temp->right;
                temp->right = BookNode;
            }
        }
        temp= temp->next;
    }
}
bool Student:: studentcheck(int roll)
{
    if (head == NULL) return false;
    else
    {
        struct Node *temp = head;
        while(temp != NULL)
        {
            if (temp->rollNo == roll) return true;
            else
            {
                temp= temp->next;
            }
        }
        return false;
    }
}     
void Student :: ListAllottedBooks()
{
    Node *temp1= head;
    Node *temp2;
    cout<<" LIST of Students along the Books they have been allotted are :"<<endl;
    cout<<"\n\n";
    while(temp1!=NULL)
    {
        cout<<"***---> Student Name: "<<temp1->name<<" \t Roll no. : "<<temp1->rollNo<<"\n"<<endl;
        temp2 = temp1->right;
        if(temp2==NULL) cout<<" No books are allotted to the student.\n"<<endl;
        while (temp2!=NULL)
        {
            cout <<"Tittle :   "<< temp2->tittle << "\n";
			cout <<"Aithor :   "<< temp2->author << "\n";
			cout <<"ISBN   :   "<< temp2->isbn << "\n\n";     
            temp2= temp2->right;       
        }
        temp1=temp1->next;
    }
}

int main()
{
 Student s;     
 library lib;

	int choice;
    int isb;
    int isbb;
	string title;
	int found=0;

    //Data is added to lists both linked list and binary tree.
    {
        lib.insertNode("Physics","HC verma",1);
        lib.insertNode("Mathematics","K.L Virumurthy",2);
        lib.insertNode("Mathematics","K.L Virumurthy",3);
        lib.insertNode("Computer Networks","VC Chatterjee",5);
        lib.insertNode("Computer Architecture","J Coleman",4);
        lib.insertNode("Arts and Literature","Roger Freedmorgie",6);
        s.insertNodeStudent("Rajat Gorphole",1);
        s.insertNodeStudent("Surbhi Shrivastawa",2);
        s.insertNodeStudent("Devgyani Mukherjee",3);
        s.insertNodeStudent("Abhash Kumar Singh",4);
        s.insertNodeStudent("Rahul Tyagi",5);
        s.addbook("Computer Architecture","J coleman",6,2);
        s.addbook("Computer Networks","VC Chaterjee",9,2);
        s.addbook("Mathematics","RD Sharma",12,2);
        s.addbook("C Programming","Pearson tech",14,1);
        s.addbook("Electronics Basics","Ratnesh Malahar",13,3);
        s.addbook("Computer Networks","VC Chaterjee",17,3);
        s.addbook("Computer Architecture","J coleman",36,4);
        s.addbook("Physics Fundamentals","JV Harold",23,5);


    }

    cout<<"/////////////*********************************************////////////\n"<<endl;
    cout<<"\t\t Welcome to Library Mangement System\n" <<endl;
    cout<<"/////////////*********************************************////////////\n\n"<<endl;
	do
	{
		cout << "Menu: Select your option\n\n";
		cout << "(1) Add a book to the list\n";
		cout << "(2) Delete a book based on Title\n";
		cout << "(3) Search for a book by ISBN.\n";
		cout << "(4) List all books.\n";
		cout << "(5) Book Issue\n";
		cout << "(6) List all Allotted books.\n\n";
		cout << "(7)  Quit.\n\n";
		cout << "Enter your choice ---> ";

		cin >> choice;

		if (1 <= choice && choice <= 7)
		{
			switch (choice)
			{
			case 1:
				lib.insertNode();
				break;
                
			case 2:
				cout<<"Enter Tilte of book to delete "<<endl;
			 	cin>>title;
			    lib.deleteNode(title);
				break;

			case 3:
                cout << "Book ISBN:\t\t\t";
                cin>>isb;
				found=lib.searchbook(isb);
				if(found==0)
                {
                    cout<<"Book not found in Database.\n ";
                }
				break;
            case 5:

                int isbb;
                cout << "Enter Book ISBN:\t\t";
                cin>>isbb;
                if(lib.searchbook(isbb)==0) cout<<"Book Not found in Database.\n";
                else
                {   

                    BookData Details=lib.bookdetails(isbb);
                    string tittle=Details.tittle;
                    string author=Details.author;
                    int isbn=Details.isbn;

                    int roll;
                    cout<<"Enter Student Roll no. : ";
                    cin>>roll;
                    bool StudentExist=s.studentcheck(roll);
                    if (StudentExist== true) 
                    {
                        s.addbook(tittle,author,isbn,roll);
                    }
                    else
                    {
                        int rollno=s.insertNodeStudent();
                        //cout<<" Insert node succefully."<<endl;
                        s.addbook(tittle, author, isbn, rollno);
                    }
                    lib.deleteNode(tittle);    
                }
                break;

			case 4:
                lib.printList()	;
				break;
            case 6:
                s.ListAllottedBooks();
                break; 
            case 7:
                cout<<" \n\n\t\tThank you for using Library amanagment system.";
                cout<<"\n\n\t*****************************************************************\n\n";
				break;
               
			default:
				cout << "Invalid choice.  Enter again.\n\n";
				break;
			}
		}
	}
	while (choice != 7);

  	return 0;
}
        