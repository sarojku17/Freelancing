#include "STACK.H"
//task--8
//this is the Driver program

//task--9 & 10 are done already
int main()
{
    LinkedStack st;
    int arr[]={-6, 4, 2, 10, 8};
    cout<<setw(20) <<"   Let's  create a Stack  "<<endl;
    cout<<setw(25)<<" ________________________________"<<endl<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<setw(5)<<arr[i]<<setw(15) <<" inserted into Stack"<<endl;
        st.pushStack(arr[i],i);//task-4
                               //we are accessing only the stack of caller object
    }
        cout<<endl<<" All Insertions are into Complete "<<endl<<endl;
        cout<<" All elements are stored in stack as : "<<endl;
        cout<<" ________________________________"<<endl<<endl;
        st.print_helper();  //task-4
                            //we are accessing only the stack of caller object
        cout<<" Let's  do summation of all elements  "<<endl;
        cout<<" ________________________________"<<endl<<endl;

        cout<<" After Summation Sum is "<<st.stackSum()<<endl<<endl;//task-6
                                                                    //st.stackSum returns the correct sum
        cout<<" After summation elements are stored in stack as : "<<endl;
        cout<<" ________________________________"<<endl<<endl;
        st.print_helper();   //task-4
                            //we are accessing only the stack of caller object
        //st.printStack();
}
