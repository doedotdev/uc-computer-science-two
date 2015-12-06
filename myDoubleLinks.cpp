#include <iostream>
#include "LList.h"
using namespace std;

struct my_node{
    int my_data;
    my_node* next;
    my_node*last;

};

class myLinked{
public:
    myLinked(){
        head = NULL;
        tail = NULL;
        my_size = 0;
    }

    ~myLinked(){
        my_node* temp = head;
        while(temp) {
            my_node* to_delete = temp;
            temp = temp->next;
            delete to_delete;
        }
        head = NULL;
        tail = NULL;
    }

    void push_front(int value){
        my_size++;
        if(head == NULL){
            my_node* temp = new my_node;
            temp->my_data = value;
            temp->next = head;
            temp->last = NULL;
            head = temp; // only item in there
            tail = temp; // only item in there
            return;
        }
        else{
            my_node* temp = new my_node;
            temp->my_data = value;
            temp->next = head;
            temp->last = NULL;
            head = temp;
            my_node* second = temp->next;
            second->last = temp;
            return;
        }
    }

    void push_back(int value)
    {
  	  if(head == NULL) {
  	    push_front(value); // no nodes, just push it onto front.
  	    return;
  	  }
        my_size++;
        my_node* temp = head;
        while(temp->next){
            temp=temp->next ; // traverses to the end of the list
        }
        my_node* new_node = new my_node; // create a new node
        new_node->my_data= value;
        new_node->next= NULL; // because we are at the end
        new_node->last = temp;
        temp->next= new_node; // temp, the second to last node, points to the new_node, the last node
        tail = new_node;
    }

    void pre_show_list(){
        if(mySize() == 0){
            cout<<"[ empty ]"<<endl;
            return;
        }
        my_node* temp = head;
        cout<<"[";
        while(temp->next){
            cout<<temp->my_data<<" , ";
            temp= temp->next;
        }
        cout<<temp->my_data<<"]"<<endl;
    }

   void post_show_list(){
       if(mySize() == 0){
            cout<<"[ empty ]"<<endl;
            return;
        }
        my_node* temp = tail;
        cout<<"[";
        while(temp->last){
            cout<<temp->my_data<<" , ";
            temp= temp->last;
        }
        cout<<temp->my_data<<"]"<<endl;
    }

    int mySize(){
        return my_size;
    }


    void remove(int pos){
        if(mySize() == 0 || pos > mySize() - 1){
            return;
        }
        if (mySize() == 1 && pos == 0){
          my_node* to_delete = head;
          head = NULL;
          tail = NULL;
          delete to_delete;
          my_size--;
          return;
        }
        if (pos == 0){  // first element
          my_node* to_delete = head;
          head = head->next;
          head->last = NULL;
          delete to_delete;
          my_size--;
          return;
        }

        if(pos == mySize()-1){  // last element
          my_node* to_delete = tail;
          tail = tail->last;
          tail->next = NULL;
          delete to_delete;
          my_size--;
          return;
        }

        my_node* temp = head;
        int i=0;
        while((temp) && i!=pos-1)
        {
            temp=temp->next; // traverse to the node before the one to delete
            i++;
        }
        cout<<temp->my_data<<endl;

        my_node* to_delete = temp->next; // delete the next node

        if(temp->next->next){
            my_node* right_of_delete = temp->next->next;
            temp->next= right_of_delete;
            right_of_delete->last = temp;
        }
        else{
        temp->next=NULL;
        }

        delete to_delete;
    }


private:
    my_node * head;
    my_node * tail;
    int my_size;
};


int main(){
    myLinked a;
    for (int i = 0; i < 5; i++)
    {
        a.push_back(i);
    }
    a.remove(3);
    cout<<"A: "<<a.mySize()<<endl;

    a.pre_show_list();
    a.post_show_list();

    myLinked b;

    for (int i = 0; i < 5; i++)
    {
        b.push_back(i+1 *2 );
    }
    cout<<"B: "<<b.mySize()<<endl;

    b.pre_show_list();
    b.post_show_list();
}
