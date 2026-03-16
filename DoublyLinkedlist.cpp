#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

   Node* list = NULL;

  //Insert
void Insert(int value){
    Node* temp = new Node;
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;
    if(list == NULL){
        list = temp;    
    }
    Node* cur = list;
    while(cur->next != NULL){
        cur = cur->next;
    }
    cur->next = temp;
    temp->prev = cur;          //this line makes singlylist to doubly
    cout<< "Value Inserted\n";
}

//search
void Search(int value){
    Node* cur = list;
    int position;
    while(cur != NULL){
        if(cur->data == value){
            cout<< "Value Found at position: " << position <<endl;
            return;
        }
        cur = cur->next;
        position ++;
    }
    cout << "Value Not Found\n";
}

//Delete
void Delete(int value){
    if(list == NULL){
        cout<< "List Is Empty\n";
        return;
    }
    Node* cur = list;

   //delete first node
   if(cur->data == value){
       list = cur->next;
        if(list != NULL){   // only for doublylist
        list->prev = NULL;
        free(cur);
        return;
        }
    }
    // Other Than first Node
    cur = list->next;
    Node* pre = list;   //"pre" is temporary pointer for traversal of previous value
    while(cur != NULL){
        if(cur->data == value){
            pre->next = cur->next;
            if(cur->next != NULL){
                cur->next->prev = pre;
                free(cur);
                return;
            }
            pre = cur;
            cur = cur->next;
        }
        cout << "Value Not Found\n";
    }
}

 //Display
void display(){
        if(list == NULL){
            cout << "List Is Empty\n";
            return;
        }
        Node* temp = list;
        while(temp != NULL){
            cout << temp->data;
            cout << "->";
            temp = temp->next;
        }
    cout << "NULL" <<endl;
}

//BubbleSort
void BubbleSort(Node* list){
    if(list == NULL){
        cout<< "list is empty\n";
        return;
        bool swapped;
        do{
            swapped = false;
            Node* cur = list;
            while(cur->next != NULL){
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
}

//SelectionSort
void SelectionSort(Node* list){
    if(list == NULL){
        cout<<"List is empty\n";
        return;
    }
    for(Node* i=list; i; i=i->next){
        Node* min = i;
        for(Node* j=i->next; j; j=j->next){
            if(j->data > min->data){
                min = j;
            }
            int temp = j->data;
            j->data = min->data;
            min->data = temp;
        }
    }
}

//InsertionSort
void InsertionSort(Node* list){
    if(list == NULL){
        cout<< "List is empty\n";
        return;
    }
    for(Node* i=list->next; i != NULL; i=i->next){
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
    }
}



int main(){
    int choice,value;

    while(true){
        cout<< "--------DoublyLinked List--------\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "6- BubbleSort\n";
        cout << "7- selectionSort\n";
        cout << "8- InsertionSort\n";

        cout << "ENTER YOUR CHOICE\n";
        cin>> choice;

        switch (choice){
        
         case 1: { 
            cout << "ENTER VALUE TO INSERT: \n";
            cin>>value;
            Insert(value);
            break;
         }

         case 2: cout << "ENTER VALUE TO SEARCH: \n";
                cin>> value;
                Search(value);
                break;

         case 3:  cout << "ENTER VALUE TO DELETE: \n";
            cin>> value;
            Delete(value);
            break;
             
         case 4: display();
                break;

         case 5:  cout<< "Exiting!\n";
                 break;

         case 6:  BubbleSort(list);
         display();
         break;
         
         case 7: SelectionSort(list);
         display();
         break;

         case 8: InsertionSort(list);
         display();
         break;
        
         default:  cout << "INVALID CHOICE.!";
            break;
        }

        if(choice == 5){
            break;
        }
    }

    return 0;
}
