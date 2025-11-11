//menu driven cpp program to manage patient records in a hospital using BST where every node stores patient ID and name.
/*
1) insert a patient record
2) display patient in sorted order (inorder traversal)
3) Find record with minimum and maximum patient ID
4) Search for a patient by ID
5) Find no. of nodes, leaf nodes and height of the tree.
*/

#include<iostream>
#include<string>
using namespace std;

class patient{
    public:
        int P_ID;
        string Name;
        patient *left, *right;
};

class hospital{
    public:
        patient *root;
        hospital(){root = nullptr;}
        void insert();
        void display(); //inorder traversal
        void FindMin();
        void FindMax();
        void Search(int ID);
        void inorder(patient * temp);
        int countNodes(patient* temp);
        int countLeafNodes(patient* temp);
        int height(patient* temp);

};
void hospital::insert(){
    patient *newPatient = new patient();
    cout<<"Enter Patient ID: ";
    cin.ignore();
    cin>>newPatient->P_ID;
    cout<<"Enter Patient Name: ";
    cin>>newPatient->Name;
    newPatient->left=newPatient->right=nullptr;
    if(root==nullptr){
        root=newPatient;
    }
    else{
        patient *temp = root;
        while(true){
            if(newPatient->P_ID < temp->P_ID){
                if(temp->left==nullptr){
                    temp->left = newPatient;
                    break;
                }else{
                    temp = temp->left;
                }
            }else if (newPatient->P_ID > temp->P_ID){
                if(temp->right==nullptr){
                    temp->right = newPatient;
                    break;
                }else{
                    temp = temp->right;
                }
            }else{
                cout << "Patient with ID "<< newPatient->P_ID <<" already exists."<<endl;
            }
        }
    }
    
}
void hospital :: Search(int ID){
    patient* temp = root;
    if(root==nullptr){
        cout<<"No records found."<<endl;
        return;
    }
    while(temp!=nullptr){
        if(ID > temp->P_ID){
            temp = temp->right;
        }else if(ID < temp->P_ID){
            temp = temp->left;
        }else{
            cout<<"Patient found: ID = "<<temp->P_ID<<", Name = "<<temp->Name<<endl;
            return;
        }

    }
    cout<< " Patient with ID "<< ID << "not found." <<endl;
}
void hospital:: FindMin(){
    if(root ==  nullptr){
        cout << " No Records " << endl;
        return;
    }
    patient * temp = root;
    while(temp->left != nullptr){
        temp=temp->left;
    }
    cout<<"Minimun Patient Id " << temp->P_ID <<endl;
}

void hospital:: FindMax(){
    if(root ==  nullptr){
        cout << " No Records " << endl;
        return;
    }
    patient * temp = root;
    while(temp->right != nullptr){
        temp=temp->right;
    }
    cout<<"MAximum Patient Id " << temp->P_ID <<endl;
}

void hospital:: inorder(patient * temp){
    if(temp != nullptr){
        inorder(temp->left);
        cout<<temp->P_ID << "  " << temp->Name << " | ";
        inorder(temp->right);
    }
}

void hospital:: display(){
    inorder(root);
    cout<<endl;
}

int hospital::countNodes(patient* temp) {
    if (temp == nullptr)
        return 0;
    return 1 + countNodes(temp->left) + countNodes(temp->right);
}

int hospital::countLeafNodes(patient* temp) {
    if (temp == nullptr)
        return 0;
    if (temp->left == nullptr && temp->right == nullptr)
        return 1;
    return countLeafNodes(temp->left) + countLeafNodes(temp->right);
}

int hospital::height(patient* temp) {
    if (temp == nullptr)
        return -1;
    int leftHeight = height(temp->left);
    int rightHeight = height(temp->right);
    return 1 + max(leftHeight, rightHeight);
}

int main(){
    int ch;
    hospital ht;
    while(true){
        cout<<"1. Insert Patient Records\n2. Display Patients\n3. Find Min Id\n4. Find Max Id\n5. Search Patient by Id\n6. Find Number of Nodes\n7. Find number of leaf nodes\n8. Find height\n9 exit\nENTER YOUR CHOICE :: ";
        cin>>ch;
        cout<<endl;
        switch(ch){
            case 1 : {
                char con = 'y';
                while (con == 'y') {
                    ht.insert();
                    cout<<"would you like to insert more(y/n) :: ";
                    cin>>con;
                }
            }
            break;
            case 2 :
                cout<<" INORDER TRAVERSAL :: ";
                ht.display();
            break;
            case 3 :
                ht.FindMin();
            break;
            case 4 :
                ht.FindMax();
            break;
            case 5 : {
                int ID;
                cout<<"Enter the ID you want to search: ";
                cin>>ID;
                ht.Search(ID);
            }
            break;
            case 6 :
                cout<<"Number of nodes in the tree: " << ht.countNodes(ht.root) << endl;
            break;
            case 7 :
                cout<<"Number of leaf nodes in the tree: " << ht.countLeafNodes(ht.root) << endl;
            break;
            case 8 :
                cout<<"Height of the tree: " << ht.height(ht.root) << endl;
            break;
            case 9 :
                return 0;
            break;
            default :
                cout<<"Invalid choice"<<endl;
        }
    }
    return 0;
}