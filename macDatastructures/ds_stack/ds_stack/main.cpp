//
//  main.cpp
//  ds_stack
//
//  Created by Sureshkumar SP on 5/13/20.
//  Copyright © 2020 Sureshkumar SP. All rights reserved.
//

#include <iostream>
struct Node{
    int data;
    struct Node* link;
};
class StackDs{
private:
    Node* _stackHead;
    int topIndex=-1;
public:
    void push(int data){
        Node* element =new Node();
        element->data=data;
        element->link =_stackHead;
        _stackHead=element;
        topIndex++;
    }
    int pop(){
        if(_stackHead==NULL) throw ("No elements to pop");
        Node topNode=*_stackHead;
        _stackHead=_stackHead->link;
        topIndex--;
        return topNode.data;
    }
    bool isEmpty(){
    return topIndex>=0;
    }
    void print(){
        Node* temp=_stackHead;
        while (temp!=NULL) {
          std::cout<<temp->data;
          std::cout<<"\n";
          temp=temp->link;
        }
    }
};
int main(int argc, const char * argv[]) {
    StackDs stack= StackDs();
    stack.push(1);
     stack.print();
    stack.push(2);
     stack.print();
    stack.push(3);
     stack.print();
    stack.pop();
    stack.print();
    stack.push(3);
    stack.print();
    return 0;
}
