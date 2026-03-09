#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node *list = NULL;

//Insert
void Insert(int value){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    if(list == NULL){
        list = temp;
        temp->next = list;  //pionter for circular
    }
    else{
        Node *cur = list;
        while(cur->next != list){
            cur = cur->next;
        }
        cur->next = temp;
        temp->next = list;  //complete the list
    }
}

//search
int search(int value){
    Node *cur = list;
    if(cur == NULL){
        return -1 ;
    }
    int index = 0;

    do{
        if(cur->data == value){
            cout<< "value found at: " << index << "at address: " << cur <<endl;
           // return cur;
        }
        cur = cur->next;
        index++;
    }
    while(cur != list);  //stop when we complete the circle
    cout<< "value not found\n";
   // return NULL;
}


//Display
void display(){
    Node *cur = list;
    if(cur == NULL){
        cout << "List Is Empty!";
        return;
    }
    do{
       cout << cur->data << " ";
       cur = cur->next;
    }
    while(cur != list);{
    cout<< "\n";
    } 
}

//Delete
int Delete(int value){
    if(list == NULL){
        cout<< "list is empty\n";
        return -1 ;
    }
    if(list->next == list && list->data == value){
        //for on;y one node
        free(list);
        list == NULL;
        return -1;
    }
    if(list->data != value){
        Node *cur = list;

     while(cur->next != list){
        cur = cur->next;
     }
    Node *temp = list;
    cur->next = list->next;
    list = list->next;  //move list pointer
    free(temp);
    return 0;
    }

    //for other elements
    Node *cur = list;
    do{
        if(cur->next->data == value){
            Node *temp = cur->next;
            cur->next = temp->next;
            free(temp);
           // cout<< "value deleted\n; 
            return 0;
        }
        cur = cur->next;
    }
    while(cur != list);
    cout<< "value not found\n";
}

int main(){

    while(true){
       cout<<"1- Insert\n";
       cout<<"2- Search\n";
       cout<<"3- Delete\n";
       cout<<"4- Display\n";
       cout<<"5- Exit\n";
       int choice;
       cout<< "ENTER YOUR CHOICE: ";
       cin>> choice;

      switch (choice){
       case 1: { int value;
        cout << "Enter Your Value To Insert: ";
        cin >> value;
        Insert(10);
        break;
       }

       case 2: {int value;
        cout<< "Enter your value to search: \n";
        cin>> value;
        search(value);
        break;
       }

       case 3: {
        int value;
        cout<< "Enter your value to Delete: \n";
        cin>> value;
        Delete(value);
        break;
       }

       case 4: display();
        break;

        case 5: cout<< "EXIT!\n";
        break;
       
       default: cout << "INVALID CHOICE\n";
        break;
        }

      if(choice == 5){
        break;
       }
    }
    return 0;
}