#ifndef STACK_H
#define STACK_H

#include<iostream>
#include<iomanip>
using namespace std;
//task--1
//all functions and classes are implemented using common template.

//task--2
//all functions  are implemented using correct signature as given in problem .
//like there is getinfo(),getlink() and stackSum with same signature.
//note : stackSum returns int and has no parameters as given in the problem.


class LSNode{//a class to create node for stack
public :
    int info;
    LSNode * link;// stores link to the previous stack node
};

class LinkedStack{//A class to create stack
private:
    LSNode top;//stores the top element
    LSNode node[5];//stack elements ;stack size is 5 as written in the manual
public :
    int getInfo(LSNode );//returns info field of stack node
    LSNode * getlink(LSNode );//returns link field of stack node
    void pushStack(int ,int);//To push elements into the stack
    void print_helper();//it is the caller function the utility function print(LSNode *)
    void print(LSNode*);//prints elements recursively

                        //returns sum of the stack elements
    int  stackSum();    //(1)--does not contain input arguments
                        //(2)--uses recursion
                        //as written in the problem
};
int LinkedStack ::getInfo(LSNode mynode){
    return mynode.info;
}

LSNode* LinkedStack :: getlink(LSNode mynode){
    return mynode.link;
}
void LinkedStack ::pushStack(int x,int i){//x is the data and i is the node index
    node[i].info=x;
    if(i>0)//when the stack is not empty
        {
            node[i].link=&node[i-1];
            top=node[i];
        }
    else//when the stack is  empty or first element is inserted
        {
            node[i].link=NULL;
            top=node[i];
        }

}

void LinkedStack ::print_helper(){

    LSNode *temp_top=&top;//to avoid changes on stack
    print(temp_top);
}
void LinkedStack ::print(LSNode *temp_top)
{

        if(temp_top==NULL)

        return ;//task-5
                //recursive case for recursion
                //this is for print function
        else
        {
            cout<<setw(5) <<getInfo(*temp_top)<<endl;
            temp_top=getlink(*temp_top);//go the next node in stack
            print(temp_top);
        }

}
//task--6
//stackSum() access top element of the stack and recursively call the next stack element
//and sums the node info

int LinkedStack::stackSum(){ //task--6
                            //Implementation of stackSum
        LSNode static  mynode=top;//due to static keyword assignment is performed only once.
        int x=getInfo(mynode);
                            //task--7
                            //we get a copy of the top member(i.e mynode) so now there is no
                            //risk of the stack elements get changed
        if(getlink(mynode)==NULL)
        return x;//task-5
                //base case for recursion
                //this is for stackSum
        else
        {       //task-5
                //recursive case for recursion
                //this is for stackSum

          mynode=*(getlink(mynode));
          return x+stackSum();
        }
}
#endif
