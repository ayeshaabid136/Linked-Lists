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
        temp->next = list;  //pointer for circular
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
void search(int value){
    if(list == NULL){
        cout<<"List is empty\n";
        return;
    }
    Node *cur = list;
    int index = 0;

    do{
        if(cur->data == value){
            cout<< "value" << value << "found at index: " << index  <<endl;
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
    if(list == NULL){
        cout << "List Is Empty!";
        return;
    }
     Node *cur = list;
    do{
        cout<< cur->data;
        cout<< "->";
        cur = cur->next;
    }
     while(cur != list);
     cout<<"NULL\n";    
}


//BubbleSort
void BubbleSort(){
    if(list == NULL){
        cout<< "list is empty\n";
        return;
    }
        bool swapped;
        do{
            swapped = false;
            Node* cur = list;
            while(cur->next != list){
                if(cur->data > cur->next->data){
                    int temp = cur->data;
                    cur->data = cur->next->data;
                    cur->next->data = temp;
                    swapped = true;
                }
                cur = cur->next;
            }
        }
        while(swapped);
}

void SelectionSort(){
    if(list == NULL) return;

    Node* i = list;

    do{
        Node* min = i;
        Node* j = i->next;

        while(j != list){
            if(j->data < min->data){   // FIX
                min = j;
            }
            j = j->next;
        }

        // FIX: swap yahan hoga
        int temp = i->data;
        i->data = min->data;
        min->data = temp;

        i = i->next;

    }while(i != list);
}

//InsertionSort
void InsertionSort(){
    if(list == NULL) return;
   Node* i = list->next;
   while(i != list){
        int hold = i->data;
        Node* gap = list;
        while(gap != i){
            if(gap->data > hold){
                int temp = gap->data;
                gap->data = hold;
                hold = temp;
            }
            gap = gap->next;
        }
        i->data = hold;
        i= i->next;
    }
}

//Delete
void Delete(int value){
    if(list == NULL){
        cout<< "list is empty\n";
        return;
    }
    Node* cur = list;

     //for only one node
    if(list->next == list && list->data == value){
        free(list);
        list == NULL;
        cout<<"value deleted\n";
        return;
    }

    //delete head
    if(list->data == value){
        while(cur->next != list){
            cur= cur->next;
        }
        Node* temp = list;
        cur->next = list->next;
        list = list->next;
        free(temp);
        cout<<"value deleted\n";
        return;
    }
    do{
        if(cur->next->data == value){
            Node* temp = cur->next;
            cur->next = temp->next;
            free(temp);
            cout<<"value deleted\n";
            return;
        }
        cur = cur->next;
    } while(cur != list);
    cout<<"value not found\n";
}


int main(){

    while(true){
       cout<<"1- Insert\n";
       cout<<"2- Search\n";
       cout<<"3- Display\n";
       cout<<"4- BubbleSort\n";
       cout<<"5_ SelectionSort\n";
       cout<<"6- InsertionSort\n";
       cout<<"7- Delete\n";
       cout<<"8- Exit\n";
       int choice;
       cout<< "ENTER YOUR CHOICE: ";
       cin>> choice;

      switch (choice){
       case 1: { int value;
        cout << "Enter Your Value To Insert: ";
        cin >> value;
        Insert(value);
        break;
       }

       case 2: {int value;
        cout<< "Enter your value to search: \n";
        cin>> value;
        search(value);
        break;
       }

       case 3: display();
        break;

       case 4: {
        BubbleSort();
        display();
        break;
       }

       case 5: {
        SelectionSort();
        display();
        break;
       }

       case 6: {
        InsertionSort();
        display();
        break;
       }

       case 7: {
        int value;
        cout<< "Enter your value to Delete: \n";
        cin>> value;
        Delete(value);
        break;
       }

        case 8: cout<< "EXIT!\n";
        break;
       
       default: cout << "INVALID CHOICE\n";
        break;
        }

      if(choice == 8){
        break;
       }
    }
    return 0;
}
