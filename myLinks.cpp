#include <iostream>
#include "LList.h"
using namespace std;

struct my_node{
    int my_data;
    my_node* next;
};

class myLinked{
public:
    myLinked(){
        head = NULL;
        my_size = 0;
    }

    ~myLinked()
    {
        my_node* temp = head;
        while(temp) {
            my_node* to_delete = temp;
            temp = temp->next;
            delete to_delete;
        }
        head = NULL;
    }

    void push_front(int value)
    {
        my_size++;
        my_node* temp = new my_node;
        temp->my_data = value;
        temp->next = head;
        head = temp;
    }

    void push_back(int value)
    {
  	  if(head == NULL) {
  	    push_front(value); // no nodes, just push it onto front.
  	    return;
  	  }
        my_size++;
        my_node* temp = head;
        while(temp->next)
        {
            temp=temp->next ; // traverses to the end of the list
        }
        my_node* new_node = new my_node; // create a new node
        new_node->my_data= value;
        new_node->next= NULL; // because we are at the end
        temp->next= new_node; // temp, the second to last node, points to the new_node, the last node
    }

    void show_list(){
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

    int mySize(){
        return my_size;
    }


    void remove(int pos){
        if(mySize() == 0){
            return;
        }
        if (pos == 0){
          my_node* to_delete = head;
          head = head->next;
          delete to_delete;
          my_size--;
          return;
        }
        my_node* temp;
        temp=head;
        int i=0;
        while((temp) && i!=pos-1)
        {
            temp=temp->next;
            i++;
        }
        my_node* to_delete = temp->next;
            if(temp->next->next){
                temp->next=temp->next->next;
            }else
            {
            temp->next=NULL;
            }

        delete to_delete;
        my_size--;
    }


private:
    my_node * head;
    int my_size;
};

int main(){
    myLinked a;

    for (int i = 0; i < 4; i++)
    {
        a.push_front(i+1);
    }
    a.remove(0);
    a.show_list();
    cout<<a.mySize()<<endl;


    myLinked b;

    for (int i = 0; i < 15; i++)
    {
        b.push_back(i+1 *2 );
    }
    b.show_list();
    cout<<b.mySize()<<endl;
}
